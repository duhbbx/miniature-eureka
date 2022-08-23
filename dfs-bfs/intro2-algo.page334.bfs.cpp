
#include <iostream>                // �������
#include <vector>                // �ɱ䳤������
#include <unordered_map>        // hashmap
#include <stack>                // ջ
#include <string>                // �ַ���
#include <queue>                // ����
#include <climits>

using namespace std;



/// <summary>
/// ��������е�����
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="t"></param>
template<typename T>
void print(T t) {



    for (typename T::const_iterator it = t.begin(); it != t.end() - 1; ++it) {
        cout << *it << ", ";
    }

    cout << *(t.end() - 1) << endl;
}



////////////////////////////////////////////////////////////////////////////////
/// �����OJ����




#define N_INFINITY (INT_MIN/2)


class Solution {



private:

    enum Color {
        WHITE,
        GRAY,
        BLACK
    };

    class V {
    public:
        Color color;             // ��ɫ
        int distanceFromSrc;     // ������ʼ��ĳ���
        V* precursor;            // ǰ���ڵ�
        int index;               // ����
        string name;             // �ڵ��ǩ
    };

    vector<string>* m_vertex;
    vector<vector<int>>* m_adjacent_matrix;
    unordered_map<string, int>* m_name2index;
    unordered_map<int, string>* m_index2name;

    int m_vertex_num;

public:
    Solution() {

        m_vertex = new vector<string>({ "r", "s", "t", "u", "v", "w", "x", "y" });

        m_name2index = new unordered_map<string, int>;
        m_index2name = new unordered_map<int, string>;

        m_name2index->emplace("r", 0);
        m_name2index->emplace("s", 1);
        m_name2index->emplace("t", 2);
        m_name2index->emplace("u", 3);
        m_name2index->emplace("v", 4);
        m_name2index->emplace("w", 5);
        m_name2index->emplace("x", 6);
        m_name2index->emplace("y", 7);

        m_index2name->emplace(0, "r");
        m_index2name->emplace(1, "s");
        m_index2name->emplace(2, "t");
        m_index2name->emplace(3, "u");
        m_index2name->emplace(4, "v");
        m_index2name->emplace(5, "w");
        m_index2name->emplace(6, "x");
        m_index2name->emplace(7, "y");




        m_vertex_num = m_vertex->size();
        // �����ڽӾ���
        m_adjacent_matrix = new vector<vector<int>>(m_vertex_num, vector<int>(m_vertex_num));


        doSetEdge();
    }


    void bfs(const string& s) {

    }

private:
    void setEdge(const string& a, const string b) {
        (*m_adjacent_matrix)[(*m_name2index)[a]][(*m_name2index)[b]] = 1;
        (*m_adjacent_matrix)[(*m_name2index)[b]][(*m_name2index)[a]] = 1;
    }

    void doSetEdge() {
        setEdge("r", "s");
        setEdge("r", "v");
        setEdge("s", "w");
        setEdge("t", "w");
        setEdge("w", "x");
        setEdge("t", "x");
        setEdge("t", "u");
        setEdge("x", "y");
        setEdge("u", "y");
    }

    
};






////////////////////////////////////////////////////////////////////////////////












int main() {


    Solution s;

    /*print<vector<int>>({ 1, 2, 3, 4 });*/

    return 0;
}