#include <map>
#include <iostream>

template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
		std::cout << "interval_map::assign " << keyBegin << ", " << keyEnd << ", " << val << std::endl;
		if(!(keyBegin < keyEnd)) return;

		// Find insertion for keyBegin
		auto it = m_map.find(keyBegin);
		auto previousValue = m_valBegin;
		if(it != m_map.end()) {
			previousValue = it->second;
			it->second = val;
			++it;
		} else {
			auto [insertIt, success] = m_map.insert(std::pair{keyBegin, val});
			it = ++insertIt;
		}

		// Overwrite the interval
		while (it != m_map.end() && it->first < keyEnd) {
			previousValue = it->second;
			it = m_map.erase(it);
		}
		if(it != m_map.end()) {
			if(!(it->first > keyEnd)) {
				if(val == it->second) {
					// Make it canonical
					it = m_map.erase(it);
				}
			} else { // it->first > keyEnd
				// Insert the valBegin: not sure if this is expected
				m_map.emplace(keyEnd, previousValue);
			}
		} else {
			m_map.emplace(keyEnd, m_valBegin);
		}
		std::cout << *this << std::endl;
	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}

	friend std::ostream &operator<<(std::ostream &out, const interval_map<K, V> &f); 
};

std::ostream &operator<<(std::ostream &out, const interval_map<int, char> &f) {
	for(auto p : f.m_map) {
		out << "(" << p.first << "," << p.second << ") ";
	}
  	return out;
}

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.
int main(int argc, char* argv[]) {
	interval_map<int, char> testMap('A');
	testMap.assign(1, 3, 'B');
	testMap.assign(7, 8, 'C');
	testMap.assign(3, 4, 'Z');
	testMap.assign(-3, -1, 'E');
	testMap.assign(1, 2, 'R');
	testMap.assign(5, 6, 'M');
	return 0;
}