#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    char color;

    TreeNode()
    {
        this->color = 'G';
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
TreeNode *makeTree(string input)
    {

        if(input.size()==0) return NULL;

        queue<TreeNode *> q;
        TreeNode *root = new TreeNode();
        q.push(root);
        int i = 1;

        while (i < input.size() && !q.empty())
        {

            TreeNode *temp = q.front();
            q.pop();

            if (i < input.size())
            {
                if (input[i] != 'N')
                {
                    temp->left = new TreeNode();
                    q.push(temp->left);
                }
                i++;
            }

            if (i < input.size())
            {
                if (input[i] != 'N')
                {
                    temp->right = new TreeNode();
                    q.push(temp->right);
                }
                i++;
            }
        }

        return root;
    }

    void leftBoundary(TreeNode *root, char& color)
    {
        if (!root) return;

        if(root->left){
            root->color=color;
            color=(color=='B'?'R':'B');
            leftBoundary(root->left,color);
        }
        else if(root->right){
            root->color=color;
            color=(color=='B'?'R':'B');
            leftBoundary(root->right,color);
        }
    }

    void rightBoundary(TreeNode *root, char& color)
    {
        if (!root) return;
        
        if(root->right){
            rightBoundary(root->right,color);
            root->color=color;
            color=(color=='B'?'R':'B');
        }

        else if(root->left){
            rightBoundary(root->left,color);
            root->color=color;
            color=(color=='B'?'R':'B');
        }
    }

    void leaves(TreeNode *root, char& color)
    {
        if (!root) return;
        
        leaves(root->left, color);

        
        if (!root->left && !root->right){
            root->color = color;
            color=(color=='B'?'R':'B');
        }

        leaves(root->right, color);
    }

    void preorder(TreeNode *root,string& ans)
    {
        if (!root)
            return;

        ans=ans+root->color+" ";
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    string anticlockwise(TreeNode *root)
    {
        if (!root) return "";

        char color = 'B';
        root->color = color;
        color='R';

        leftBoundary(root->left,color);
        leaves(root->left, color);
        leaves(root->right, color);
        rightBoundary(root->right, color);

        string s;
        preorder(root,s);
        return s;
    }
public:
    string solve(string input){
        TreeNode *root = makeTree(input);

        return anticlockwise(root);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    ifstream file;
    ofstream out;
    out.open("output.txt");

    streambuf* coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    file.open("input.txt");

    string line;

    while(getline(file,line)){
        if(line.empty()) break;

        line.erase(remove(line.begin(), line.end(), ' '), line.end());

        Solution sol;

        cout<<sol.solve(line)<<endl;
    }

    file.close();


    return 0;
}