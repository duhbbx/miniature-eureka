



#include <iostream>
#include <vector>
#include <algorithm>


int main() {


    std::vector<int> values{ 3, 5, 4, 4, 5, 1 };
    std::sort(values.begin(), values.end(), [](int v1, int v2) {

        if ((v1 % 2) == (v2 % 2)) {
            return v1 < v2;
        }

        return (v1 % 2) > (v2 % 2);
        }
    );


    for (auto v : values)
        std::cout << v << ", ";

    std::cout << std::endl;

    return 0;
}