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
    int position[4];
    int type;
};


bool same_type(char a, char b) {
    

}

struct numeration get(const std::string num) {
    struct numeration instance;

    instance.position[0] = 0;
    instance.position[1] = 0;
    instance.position[2] = 0;
    instance.position[3] = 0;

    instance.type = 0;


    int j = 1;
    for (int i = 1; i < num.length(); ++i) {
        if (num[i-1] != num[i]) {
            instance.position[j++] = i;
        }
    }

    if (j == 2) {
        instance.type = 1;
    } else {
        instance.type = 2;
    }

    cout << "字符串的类型为: " << instance.type << endl;

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
        cout << "当前输入的字符串: " << s << std::endl;

        get(s);
        
    }

    return 0;
}