//
// Created by duhbb on 2022/9/9.
//

#ifndef LEETCODE_TREENODE_H
#define LEETCODE_TREENODE_H



/**
 * Definition for a binary tree node.*/

struct TreeNode {

    int val;

    TreeNode *left;

    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};





#endif //LEETCODE_TREENODE_H
