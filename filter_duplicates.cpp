#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>

using namespace std;
#include <map>

vector<int> filter_duplicates(vector<int> data)
{
    // Write your code here
    // To debug: cerr << "Debug messages..." << endl;
    std::map<int, bool> found;
    std::vector<int> result;
    for(const auto& d : data) {
        if(found.find(d) == found.cend()) {
            found[d] = true;
            result.push_back(d);
        }
    }
    return result;
}

/* Ignore and do not change the code below */
int main()
{
    int n;
    cin >> n; cin.ignore();
    vector<int> data;
    for (int i = 0; i < n; i++) {
        int data_tmp;
        cin >> data_tmp;
        data.push_back(data_tmp);
    }
    int std_out_fd = dup(1);
    dup2(2, 1);
    vector<int> filtered = filter_duplicates(data);
    dup2(std_out_fd, 1);
    for (int i = 0; i < filtered.size(); i++) {
        cout << filtered[i] << endl;
    }
}
/* Ignore and do not change the code above */