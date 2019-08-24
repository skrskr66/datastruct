#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node {
  public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val, vector<Node*> _children) {
      val = _val;
      children = _children;
    }
};
class Solution {
  public:
    vector<vector<int>> levelOrder(Node* root) {
      vector<int> res;
      vector<vector<int>> result;
      if(root == NULL)
      {
        return result;
      }
      queue<Node*> q;
      Node *temp;
      q.push(root);
      while(!q.empty())
      {
        int num = q.size();
        for(int i = 0;i < num;i++)
        {
          temp = q.front();
          res.push_back(temp->val);
          q.pop();
          if(temp->children.size() != 0)
          {
            for(size_t i = 0;i < temp->children.size();i++)
            {
              q.push(temp->children[i]);
            }
          }
        }
        result.push_back(res);
        res.clear();
      }
      return result;
    }
};
