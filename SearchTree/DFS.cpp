#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int dfs(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int left = dfs(root->left);
    int right = dfs(root->right);
    cout << root->val << " " << left << " " << right << endl;
    return max(left, right) + 1;
    // so this recursively caluclates the length, when reaches the last node, it
    // returns 0 and adds 1 to the max of left and right
  }
};
int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  Solution().dfs(root);
  return 0;
}

