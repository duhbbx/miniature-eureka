
#include <iostream>				// 输入输出
#include <vector>				// 可变长度数组
#include <unordered_map>		// hashmap
#include <stack>				// 栈
#include <string>				// 字符串
#include <queue>                // 队列

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
/// 这里放OJ的类


class Solution {
public:
    int maxLevelSum(TreeNode* root) {

        if (root == nullptr) {  // 如果树为空的话直接返回 0
            return 0;
        }

        queue<TreeNode*> q;

        q.push(root);

        vector<int> level = { 1,0 };
        int curr_level = 0;


        int sum = root->val;    // 给第一层赋值
        int sum_level = 0;

        int loop_sum = 0;       // 循环中进行求和的临时变量

        while (!q.empty()) {

            level[curr_level] -= 1; // 每次弹出都从这里减去一个元素数量
            TreeNode* node = q.front();
            q.pop();

            loop_sum += node->val;  // 求和

            if (node->left) {       // 左子节点入栈
                q.push(node->left);
                level[curr_level + 1]++;
            }

            if (node->right) {      // 右子节点入栈
                q.push(node->right);
                level[curr_level + 1]++;
            }

            if (level[curr_level] == 0) {   // 到了换层的时候了

                if (loop_sum > sum) {
                    sum = loop_sum;
                    sum_level = curr_level;
                }

                curr_level++;
                level.push_back(0);
                loop_sum = 0;   // 这里忘记了要清零了, 之前把这个放在了上一个if中555
            }
        }

        return sum_level + 1;   // 题目中的层是从 1 开始的
    }
};



////////////////////////////////////////////////////////////////////////////////







/// <summary>
/// 输出容器中的内容
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