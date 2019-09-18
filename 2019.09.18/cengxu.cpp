#include <iostream>
#include <vector>

using namespace std;
struct TreeNode
{
  char val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(char x) :val(x), left(NULL), right(NULL){}
};


void insert(TreeNode *p, vector<char>& temp, int t){
  int length = temp.size();
  if (t >= length)return;
  p->val = temp[t];
  if ((2 * (t + 1)) <= length){
    if (temp[2 * (t + 1) - 1] != '#'){
      TreeNode *l;
      l = (TreeNode*)malloc(sizeof(TreeNode));
      l->left = NULL;
      l->right = NULL;
      p->left = l;
      insert(p->left, temp, 2 * (t + 1) - 1);
    }
    if ((2 * (t + 1) + 1) <= length){
      if (temp[2 * (t + 1)] != '#'){
        TreeNode *r;
        r = (TreeNode*)malloc(sizeof(TreeNode));
        r->left = NULL;
        r->right = NULL;
        p->right = r;
        insert(p->right, temp, 2 * (t + 1));
      }
    }
  }
}

TreeNode* createFromArray(vector<char>& temp){
  TreeNode *p;
  p = (TreeNode*)malloc(sizeof(TreeNode));
  p->left = NULL;
  p->right = NULL;
  insert(p, temp, 0);
  return p;

}

int main()
{
  int num;
  cin >> num;
  vector<char> result(num, 0);
  for (int i = 0; i < num; i++)
  {
    cin >> result[i];
  }
  TreeNode* root = createFromArray(result);
  return 0;
}
