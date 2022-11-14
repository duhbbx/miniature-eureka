
#include <bits/stdc++.h>

using namespace std;


//6233. 温度转换

class Solution {
public:
    vector<double> convertTemperature(double celsius) {

        return {celsius + 273.15, celsius * 1.80 + 32.00};


    }
};


int main() {


    Solution solution;


    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}