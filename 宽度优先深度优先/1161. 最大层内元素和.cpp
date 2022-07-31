
#include <iostream>				// �������
#include <vector>				// �ɱ䳤������
#include <unordered_map>		// hashmap
#include <stack>				// ջ
#include <string>				// �ַ���
#include <queue>                // ����

using namespace std;




struct TreeNode {
    int val;

    TreeNode *left;
    
    TreeNode *right;
    
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    
    TreeNode(int x, TreeNode *left, TreeNode *right) : 
        val(x), left(left), right(right) {}
};





////////////////////////////////////////////////////////////////////////////////
/// �����OJ����


class Solution {
public:
    int maxLevelSum(TreeNode* root) {

        
        if (root == nullptr) {  // �����Ϊ�յĻ�ֱ�ӷ��� 0
            return 0;
        }

        queue<TreeNode*> q;

        q.push(root);

        vector<int> level = { 1,0 };
        int curr_level = 0;

        int sum = root->val;
        int sum_level = 0;

        int loop_sum = 0;

        while (!q.empty()) {

            level[curr_level] -= 1; // ÿ�ε������������ȥһ��Ԫ������
            TreeNode* node = q.front();
            q.pop();

            loop_sum += node->val;  // ���

            if (node->left) {       // ���ӽڵ���ջ
                q.push(node->left);
                level[curr_level + 1]++;
            }

            if (node->right) {      // ���ӽڵ���ջ
                q.push(node->right);
                level[curr_level + 1]++;
            }

            if (level[curr_level] == 0) {   // ���˻����ʱ����

                if (loop_sum > sum) {
                    sum = loop_sum;
                    sum_level = curr_level;
                    loop_sum = 0;   // ����������Ҫ������
                }

                curr_level++;
                level.push_back(0);
            }
        }

        return sum_level + 1;   // ��Ŀ�еĲ��Ǵ� 1 ��ʼ��
    }
};



////////////////////////////////////////////////////////////////////////////////







/// <summary>
/// ��������е�����
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="t"></param>
template<typename T>
void print(T t) {
	for (typename T::const_iterator it = t.begin(); it != t.end(); ++it) {
		cout << *it << endl;
	}
}



int main() {


	print<vector<int>>({ 1, 2, 3, 4 });





	return 0;
}