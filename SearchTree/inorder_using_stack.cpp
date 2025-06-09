#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  TreeNode *left;
  TreeNode *right;
  int val;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *createSampleTree() {
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(1);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  return root;
}

void inoder_using_stack(TreeNode *root) {
  vector<TreeNode *> st;

  while (!st.empty() || root != NULL) {
    if (root != NULL) {
      st.push_back(root);
      root = root->left;
    } else {
      root = st.back();
      cout << "before popping: ";
      for (auto it : st) {
        cout << it->val << " ";
      }
      cout << endl;
      st.pop_back();
      cout << "after popping: ";
      for (auto it : st) {
        cout << it->val << " ";
      }
      cout << endl;
      root = root->right;
    }
  }
}

int main() {
  TreeNode *root = createSampleTree();
  inoder_using_stack(root);
  return 0;
}

