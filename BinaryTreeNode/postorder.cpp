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
        PushNode(root->right,result);
        result.push_back(root->val);
      }
    }
};
//迭代完成
//这是一个正常后续遍历过程，按照最后一次访问节点加入数组中
class Solution2 {
  public:
    vector<int> inorderTraversal(TreeNode* root)
    {
      vector<int> result;
      TreeNode *tmp = root;
      TreeNode *ret = NULL;
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
          if(tmp->right == NULL || tmp->right == ret)
          {
            result.push_back(tmp->val);
            ret = tmp;
            tree.pop();
            tmp = NULL;
          }
          else 
          {
            tmp = tmp->right;
          }
        }
      }
      return result;
    }
};
//这是一个取巧的方法，先按照根-右-左的方式，然后将结果逆序就是左-右-根
class Solution3 {
  public:
    vector<int> postorderTraversal(TreeNode* root) {
      vector<int> result;
      if(root == NULL)
      {
        return result;
      }
      stack<TreeNode*> tree;
      TreeNode *tmp;
      tree.push(root);
      while(!tree.empty())
      {
        tmp = tree.top();
        result.push_back(tmp->val);
        tree.pop();
        if(tmp->left != NULL)
        {
          tree.push(tmp->left);
        }
        if(tmp->right != NULL)
        {
          tree.push(tmp->right);
        }
      }
      reverse(result.begin(),result.end());
      return result;
    }
};

int main()
{
  return 0;
}
