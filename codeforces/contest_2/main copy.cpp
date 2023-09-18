
#define ENABLE_DEBUG

#include <bits/stdc++.h>

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

            // 这里只需要超过最后的分数就行
            if (s >= this->score) {
                return {n, s};
            }
        }

        return {-1, 0};
    }
};

#ifdef ENABLE_DEBUG
#define TRACE_ME(format, ...) printf("%s(%d)-<%s>: " format "\n", __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);
#define RELOCATE()                            \
    do {                                      \
        freopen("D:\\input.txt", "r", stdin); \
    } while (0)

#endif

#ifndef ENABLE_DEBUG
#define TRACE_ME(__fmt__, ...)
#define RELOCATE()
#endif

int main() {

    RELOCATE();
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

        // Find an element in the map by its key
        std::map<string, Player>::iterator it = p_map.find(name);

        // Check if the element was found
        if (it == p_map.end()) {
            Player p = Player(name, score, i);
            p_map.insert(make_pair(name, p));
        } else {
            it->second.score += score;
            if (it->second.score > 0) {
                it->second.score_vec.push_back({i, it->second.score});
            }
        }
    }

    tuple<string, int, int> curr = {"", 0, 0};

    for (const auto &e : p_map) {

        if (e.second.score <= 0 || e.second.score < get<2>(curr)) {
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

    cout << get<0>(curr) << endl;

    return 0;
}
