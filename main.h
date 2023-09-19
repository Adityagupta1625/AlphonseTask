#ifndef SOLUTION_H
#define SOLUTION_H

#include <string>
#include <queue>

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    char color;

    TreeNode();
};

class Solution
{
public:
    std::string solve(std::string input);

private:
    void preorder(TreeNode *root, std::string &ans);
    void leftBoundary(TreeNode *root, char &color);
    void rightBoundary(TreeNode *root, char &color);
    void leaves(TreeNode *root, char &color);
    TreeNode *makeTree(std::string input);
    std::string anticlockwise(TreeNode *root);
};

#endif // SOLUTION_H
