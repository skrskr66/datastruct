#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//递归方法完成
class Solution {
  public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
      vector<int> result;
      if(root)
      {
        PushNode(root,result);
      }
      return result;
    }
  private:
    void PushNode(TreeNode* root,vector<int> &result)
    {
      if(root)
      {
        PushNode(root->left,result);
        result.push_back(root->val);
        PushNode(root->right,result);
      }
    }
};
//迭代完成
class Solution2 {
  public:
    vector<int> inorderTraversal(TreeNode* root)
    {
      vector<int> result;
      TreeNode* tmp = root;
      stack<TreeNode*> tree;
      while(tmp || !tree.empty())
      {
        if(tmp)
        {
          tree.push(tmp);
          tmp = tmp->left;
        }
        else
        {
          tmp = tree.top();
          tree.pop();
          result.push_back(tmp->val);
          tmp = tmp->right;
        }
      }
      return result;
    }
};
int main()
{
  return 0;
}
