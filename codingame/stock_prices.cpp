#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <map>

using namespace std;
/*
Objective
In this problem, you'll be given a list of daily stock prices, and you'll be asked to return the three stocks with the highest average price.

 
Implementation
Implement the function get_top_stocks(stocks, prices) which takes as input:

a vector of strings (stocks), representing the considered stocks.
a vector of 2 dimensions (prices), representing the stock prices (inner lists) for each day (outer list). 
An example input would look like this:

['AMZN', 'CACC', 'EQIX', 'GOOG', 'ORLY', 'ULTA']
[12.81, 11.09, 12.11, 10.93, 9.83, 8.14], [10.34, 10.56, 10.14, 12.17, 13.1, 11.22], [11.53, 10.67, 10.42, 11.88, 11.77, 10.21]
 
Your get_top_stocks function should return a vector containing the names of the three stocks with the highest average value. The vector should be sorted by decreasing average value. You're guaranteed that each stock will have a unique average value.

For the above example, the correct output would be:

['GOOG', 'ORLY', 'AMZN']
*/

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