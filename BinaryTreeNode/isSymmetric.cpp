//给定一个二叉树，判断是否是镜像对称的
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
//递归解法
class Solution {
  public:
    TreeNode *t;
    bool isSymmetric(TreeNode* root) {
      return ismirror(root,root);
    }
    bool ismirror(TreeNode* p,TreeNode* q)
    {
      if(!p && !q)
        return true;
      if(!p || !q)
        return false;
      if(p->val == q->val)
        return ismirror(p->left,q->right) && ismirror(p->right,q->left);
      return false;
    }
};
//迭代思想
class Solution1 {
public:
bool isSymmetric(TreeNode* root) {
  vector<int> a;
  vector<int> b;
  if(!root)
    return true;
  a = perorder_l(root);
  b = perorder_r(root);
  return a== b;
}
vector<int> perorder_l(TreeNode* q)
{
  vector<int> result;
  stack<TreeNode*> s;
  TreeNode* temp;
  s.push(q);
  while(!s.empty())
  {
    temp = s.top();
    result.push_back(temp->val);
    s.pop();
    if(temp->right != NULL)
    {
      s.push(temp->right);
    }
    else
    {
      result.push_back(0);
    }
    if(temp->left != NULL)
    {
      s.push(temp->left);
    }
  }
  return result;
}
vector<int> perorder_r(TreeNode* q)
{
  vector<int> result;
  stack<TreeNode*> s;
  TreeNode* temp;
  s.push(q);
  while(!s.empty())
  {
    temp = s.top();
    result.push_back(temp->val);
    s.pop();
    if(temp->left != NULL)
    {
      s.push(temp->left);
    }
    else
    {
      result.push_back(0);
    }
    if(temp->right != NULL)
    {
      s.push(temp->right);
    }
  }
  return result;
}
};
