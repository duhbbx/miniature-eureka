#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000;
int n, p[MAXN];
vector<int> G[MAXN];

void dfs(int u, int fa) {               // 递归转化为以u为根的子树，u的父亲为fa
    int d = G[u].size();                // 节点u的相邻点的个数
    for (int i = 0; i < d; ++i) {       // 循环遍历跟这个节点相连接的d个节点。
        int v = G[u][i];                // 节点u的第i个相邻点v
        if (fa != v) dfs(v, p[v] = u);  // 把v的父亲节点设为u，然后递归转化为以v为根的子树
        // 一定要判断v是否和其父亲节点相等！
    }
}

int main() {
    cout << "请输入节点个数: ";
    cin >> n;
    for (int i = 0; i < n - 1; i++) {   //输入n-1条边
        int u, v;
        cout << "请输入第 " << (i+1) << " 条边: ";
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int root;
    cout << "请指定根节点: ";
    cin >> root;    // 指定根节点。
    p[root] = -1;   // 设定根节点的父亲节点为-1，代表根节点没有父亲节点。
    dfs(root, -1);
    for (int i = 0; i < n; ++i) {
        cout << p[i] << (i == n - 1 ? "" : ", ");
    }
    cout << endl;
    return 0;
}