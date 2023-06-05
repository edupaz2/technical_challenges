#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <map>

using namespace std;

float average_price(int index, const vector<vector<float>>& prices) {
    float result{0.0f};
    std::for_each(prices.cbegin(), prices.cend(), [&result, index](vector<float> day) {
        result += day[index];
    });
    return result / prices.size();
}

vector<string> get_top_stocks(vector<string> stocks, vector<vector<float>> prices)
{
    // Write your code here
    // To debug: cerr << "Debug messages..." << endl;
    vector<std::pair<string, float>> averages(stocks.size());
    // Compute averages
    for(int i = 0; i < stocks.size(); ++i) {
        averages[i] = std::pair(stocks[i], average_price(i, prices));
    }

    cerr << "After compute" << endl;
    for (int i = 0; i < averages.size(); i++) {
        cerr << averages[i].first << ": " << averages[i].second << endl;
    }
    // Order result
    std::sort(averages.begin(), averages.end(), [](std::pair<string, float> f, std::pair<string, float> s){
        return f.second > s.second;
    });

    cerr << "After ordering" << endl;
    for (int i = 0; i < averages.size(); i++) {
        cerr << averages[i].first << ": " << averages[i].second << endl;
    }

    vector<string> result(3);
    for(int i = 0; i < 3; ++i) {
        result[i] = averages[i].first;
    }
    return result;
}

/* Ignore and do not change the code below */
int main()
{
    int nbstocks;
    cin >> nbstocks; cin.ignore();
    int nbdays;
    cin >> nbdays; cin.ignore();
    vector<string> stocks;
    for (int i = 0; i < nbstocks; i++) {
        string stocks_tmp;
        getline(cin, stocks_tmp);
        stocks.push_back(stocks_tmp);
    }
    vector<vector<float>> prices;
    for (int i = 0; i < nbdays; i++) {
        prices.push_back(vector<float>());
        for (int j = 0; j < nbstocks; j++) {
            float prices_tmp;
            cin >> prices_tmp;
            prices[i].push_back(prices_tmp);
        }
    }
    int std_out_fd = dup(1);
    dup2(2, 1);
    vector<string> top = get_top_stocks(stocks, prices);
    dup2(std_out_fd, 1);
    for (int i = 0; i < 3; i++) {
        cout << top[i] << endl;
    }
}
/* Ignore and do not change the code above */