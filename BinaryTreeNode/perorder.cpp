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
    vector<int> preorderTraversal(TreeNode* root) 
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
        result.push_back(root->val);
        PushNode(root->left,result);
        PushNode(root->right,result);
      }
    }
};
//迭代完成
class Solution2 {
  public:
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> result;

      if(root == NULL)
      {
        return result;
      }

      stack<TreeNode*> stacktree;
      TreeNode* tmp;
      stacktree.push(root);
      while(!stacktree.empty())
      {
        tmp = stacktree.top();
        result.push_back(tmp->val);
        stacktree.pop();

        if(tmp->right != NULL)
        {
          stacktree.push(tmp->right);
        }
        if(tmp->left != NULL)
        {
          stacktree.push(tmp->left);
        }
      }
      return result;
    }
};
int main()
{
  return 0;
}
