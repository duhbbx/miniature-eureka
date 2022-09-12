//
// Created by duhbb on 2022/9/12.
//


#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows < 2) return s;
        vector<string> rows(numRows, "");

        int i = 0, flag = -1;
        for(char c : s) {
            rows[i].push_back(c);
            // flag 这里很妙，直接一个转向
            if (i == 0 || i == numRows - 1) flag = -flag;
            i += flag;
        }

        string res = "";
        for (auto& row : rows) {
            res.append(row);
        }
        return res;
    }
};


int main () {
    Solution s;

    string res = s.convert("PAYPALISHIRING", 4);

    cout << "res = " << res << endl;
}

