#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

#define CLEAN_BUFFER std::cin.ignore(100, '\n')

#define INIT_IO                                 \
    do {                                        \
        ios::sync_with_stdio(false);            \
        std::cin.tie(0);                        \
        std::cout.tie(0);                       \
    } while (0)


struct numeration {
    int position[5];
    int type;
};


int get_type(const char c) {
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
        return 0;
    } else {
        return 1;
    }
}

struct numeration get(const std::string num) {
    struct numeration instance;

    instance.position[0] = 0;
    instance.position[1] = 0;
    instance.position[2] = 0;
    instance.position[3] = 0;
    instance.position[4] = 0;

    instance.type = 0;

    int j = 1;
    for (int i = 1; i < num.length(); ++i) {
        if (get_type(num[i-1]) != get_type(num[i])) {
            instance.position[j++] = i;
        }
    }

    if (j == 2) {
        instance.type = 1;
    } else {
        instance.type = 2;
    }

    instance.position[j++] = num.length();

    // cout << "字符串的类型为: " << instance.type << endl;

    return instance;
}



int main() {

    INIT_IO;

    int n;
    cin >> n;

    CLEAN_BUFFER;



    while (n--) {
        string s;
        getline(cin, s);
        // cout << "当前输入的字符串: " << s << std::endl;

        struct numeration n = get(s);

        if (n.type == 1) {
            // BC23
            int base = 1;
            int sum = 0;
            for (int i = n.position[1] - 1; i >= 0; i--) {
                sum += (s[i] - 'A' + 1) * base;
                base *= 26;
            }

            cout << 'R' << s.substr(n.position[1], n.position[2] - n.position[1]) << 'C' << sum << endl;
        } else {
            // R23C55

            int sum = 0;
            int base = 1;
            for (int i = n.position[4] - 1; i >= n.position[3]; --i) {
                sum += base * (s[i] - '0');
                base *= 10;
            }

            // cout << "sum = " << sum << endl;

            string b26;
            while(sum) {
                int r = sum % 26;
                if (r) {
                    b26.push_back(r + 'A' - 1);
                    sum /= 26;
                } else {
                    b26.push_back('Z');
                    sum = sum / 26 - 1;
                }
            }

            // cout << "b26 = " << b26 << endl;

            for (int i = b26.length() - 1; i >= 0; --i) {
                cout << b26[i];
            }

            cout << s.substr(n.position[1], n.position[2] - n.position[1]) << endl;
        }
        
    }

    return 0;
}