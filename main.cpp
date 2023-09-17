
#include "dbg.h"
#include <bits/stdc++.h>

#ifdef DBG_MACRO_DISABLE
#define dbg(...)
#endif

using namespace std;

class Player {
  public:
    string name;
    int score;
    vector<pair<int, int>> score_vec;

  public:
    Player(const string &name, int score, int n) {
        this->name = name;
        this->score = score;
        if (this->score > 0) {
            this->score_vec.push_back({n, this->score});
        }
    }

    pair<int, int> get_first_score_n() const {

        if (this->score <= 0) {
            return {-1, 0};
        }

        if (this->score_vec.size() <= 0) {
            return {-1, 0};
        }

        // Using a range-based for loop
        for (const auto &p : this->score_vec) {
            int n = p.first;
            int s = p.second;

            if (s == this->score) {
                return {n, s};
            }
        }

        return {-1, 0};
    }
};

#define ENABLE_DEBUG

using namespace std;

#define __output(...) printf(__VA_ARGS__);

#define __format(__fmt__) "%s(%d)-<%s>: " __fmt__ "\n"

#ifdef ENABLE_DEBUG
#define TRACE_ME(format, ...) printf("%s(%d)-<%s>: " format "\n", __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);
#endif

#ifndef ENABLE_DEBUG
#define TRACE_ME(__fmt__, ...)
#endif

int main() {

    map<string, Player> p_map;
    TRACE_ME("test");

    int n = 0;
    cin >> n;

    cin.ignore(100, '\n');

    for (int i = 1; i <= n; ++i) {
        string name = "";
        cin >> name;
        int score = 0;
        cin >> score;

        dbg("读取到了名字: ", name, "分数: ", score);

        // Find an element in the map by its key
        std::map<string, Player>::iterator it = p_map.find(name);

        // Check if the element was found
        if (it == p_map.end()) {
            dbg("没有找到了", name.c_str());
            Player p = Player(name, score, i);
            p_map.insert(make_pair(name, p));
        } else {
            dbg("已经存在了", name.c_str());

            it->second.score += score;
            if (it->second.score > 0) {
                it->second.score_vec.push_back({i, it->second.score});
            }
        }
    }

    tuple<string, int, int> curr = {"", 0, 0};

    // dbg(p_map);
    for (const auto &e : p_map) {
        dbg(e.first);

        if (e.second.score <= 0 || e.second.score < get<2>(curr)) {
            dbg(e.second.score);
            dbg(get<2>(curr));
            continue;
        }

        if (e.second.score > get<2>(curr)) {
            curr = {e.first,
                    e.second.get_first_score_n().first,
                    e.second.score};
        } else if (e.second.score == get<2>(curr)) {
            int index = e.second.get_first_score_n().first;
            if (index < get<1>(curr)) {
                curr = {e.first, index, e.second.score};
            }
        }
    }

    dbg("a vector:", (std::vector<int>{2, 3, 4}));
    dbg("最终结果是: ", get<0>(curr).c_str());

    return 0;
}
