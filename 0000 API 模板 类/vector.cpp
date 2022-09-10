
#ifndef MY_VECTOR_HELPER_H
#define MY_VECTOR_HELPER_H

#include <algorithm>
#include <vector>

using namespace std;

/*
如果想 sort 来降序, 可重写 comp 这个函数
另外重写排序规则这里有坑的, 比较函数中最好都不要用等于号
// 定义比较函数
*/


bool compare(int a, int b) {
    // 升序排列, 如果改为 return a>b, 则为降序
    return a < b;
}

void sort() {
    vector<int> a = {};
    // 调用
    sort(a.begin(), a.begin() + 20, compare);
}



#endif