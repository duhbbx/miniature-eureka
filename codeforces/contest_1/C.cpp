

// By 734xion, contest: Codeforces Beta Round 1, problem: (C) Ancient Berland
// Circus, Accepted, #, Copy

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string.h>

using namespace std;

const double pi = 3.1415926;

// 小数取模
double mod(double a, double b) {
    return a - (int)(a / b) * b;
}

// 小数gcd
double gcd(double x, double y) {
    if (y <= 0.0001)
        return x;
    return gcd(y, mod(x, y));
}

double x, y, x2, y2, x3, y3;
int main() {
    cin >> x >> y >> x2 >> y2 >> x3 >> y3;
    // 计算三角形三条边长
    double a = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
    double b = sqrt((x - x3) * (x - x3) + (y - y3) * (y - y3));
    double c = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    double p = (a + b + c) / 2;

    // 海伦公式求三角形的面积：(4 * sqrt(p * (p - a) * (p - b) * (p - c)))
    double r = (a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c))); // 通过r=(abc)/(4s)得出外接圆半径
    // 分别求出以三条边为底，外接圆半径为腰的三角形的顶角角度
    double angle1 = acos(1 - (a * a) / (2 * r * r));
    double angle2 = acos(1 - (b * b) / (2 * r * r));
    double angle3 = 2 * pi - angle1 - angle2;
    double angle = gcd(angle1, gcd(angle2, angle3)) / pi * 180;        // 题目所示的以正多边形边长为低接圆半径为腰的三角形的顶角角度
    double side = sqrt(2 * r * r - 2 * r * r * cos(angle / 180 * pi)); // 求出正多边形的边长
    double P = (r * 2 + side) / 2;

    double s = sqrt(P * (P - r) * (P - r) * (P - side)) * (360 / angle); // 计算面积 三角形面积 * 三角形个数
    cout << fixed << setprecision(6) << s;                               // 保留6位小数输出
    return 0;
}