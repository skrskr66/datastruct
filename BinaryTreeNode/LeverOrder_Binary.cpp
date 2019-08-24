#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<int> res;
      vector<vector<int>> result;
      if(root == NULL)
      {
        return result;
      }
      queue<TreeNode*> q;
      TreeNode *temp;
      q.push(root);
      while(!q.empty())
      {
        int num = q.size();
        for(int i = 0;i < num;i++)
        {
          temp = q.front();
          res.push_back(temp->val);
          q.pop();
          if(temp->left != NULL)
          {
            q.push(temp->left);
          }
          if(temp->right != NULL)
          {
            q.push(temp->right);
          }
        }
        result.push_back(res);
        res.clear();
      }
      return result;
    }
};
