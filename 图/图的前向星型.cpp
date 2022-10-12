//
// Created by duhbb on 2022/10/12.
//
#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

// 边的结构体定义
struct Edge {
    int to;  // 表示该边的终点
    int pre; // 同起点的上一条边的位置, 值为 -1 表示没有上一条边
    int w;   // 该边权值
};

//增加一条 a -> b 的权值为 w 的边
inline void addEdge(int a, int b, int w, int head[], Edge edge[], int &ecnt) {
    edge[ecnt].w = w;
    edge[ecnt].to = b;
    edge[ecnt].pre = head[a];//该边上浮为起点 a 的所有边里最新的边
    head[a] = ecnt++;
}

int main() {
    ifstream ifs("./链式前向星-input.txt");
    int n, m;//n 表示顶点数, m 表示边数
    ifs >> n >> m;

    //初始化
    //head[a]表示顶点 a 的最新一条边的数组下标,-1 表示该点无边
    int head[n + 1];
    memset(head, -1, sizeof(head));
    Edge edge[2 * m + 2];
    //当前已录入边的数量
    int ecnt = 0;

    for (int i = 0; i < m; i++) {
        int a, b, w;//边 a 到边 b 的权值 w
        ifs >> a >> b >> w;
        addEdge(a, b, w, head, edge, ecnt);
        //无向图, 每次都需要反向加边
//      addEdge(b, a, w, head, edge, ecnt);

//      //调试用, 输出有向图每条边的情况
//      cout<<" 第"<<i<<" 条边:"
//      <<a<<" -> "<<edge[i].to<<" = "<<edge[i].w
//      <<"\t 此时 head["<<a<<"]="<<head[a]
//      <<"\t 以"<<a<<" 为起点";
//      if(edge[i].pre==-1)
//          cout<<" 没有上一条边";
//          else
//              cout<<" 的上一条边是第"<<edge[i].pre<<" 条边";
//      cout<<endl;

//      //调试用, 输出无向图每条边的情况
//      cout<<" 第"<<2*i<<" 条边:"
//      <<a<<" -> "<<edge[2*i].to<<" = "<<edge[2*i].w
//      <<"\t 此时 head["<<a<<"]="<<head[a]
//      <<"\t 以"<<a<<" 为起点";
//      if(edge[2*i].pre==-1)
//          cout<<" 没有上一条边";
//          else
//              cout<<" 的上一条边是第"<<edge[2*i].pre<<" 条边";
//      cout<<endl;
//
//      cout<<" 第"<<2*i+1<<" 条边:"
//      <<b<<" -> "<<edge[2*i+1].to<<" = "<<edge[2*i+1].w
//      <<"\t 此时 head["<<b<<"]="<<head[b]
//      <<"\t 以"<<b<<" 为起点";
//      if(edge[2*i+1].pre==-1)
//          cout<<" 没有上一条边";
//          else
//              cout<<" 的上一条边的是第"<<edge[2*i+1].pre<<" 条边";
//      cout<<endl;
    }
    ifs.close();
    //遍历输出, 有向图和无向图均适用
    for (int a = 1; a <= n; a++) {//起点 a
        cout << a;
        for (int b = head[a]; b != -1; b = edge[b].pre) {//终点 b
            cout << " -> " << edge[b].to;
        }
        cout << endl;
    }
    return 0;
}