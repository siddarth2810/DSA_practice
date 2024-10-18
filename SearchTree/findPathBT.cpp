#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
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
  bool findPath(TreeNode *root, int value, vector<int> &path) {
    if (!root) {
      return false; // base case: root is null
    }
    path.push_back(root->val);
    if (root->val == value) {
      return true;
    }
    if (findPath(root->left, value, path) ||
        findPath(root->right, value, path)) {
      return true;
    }
    path.pop_back();
    return false;
  }
};

// Function to create a sample binary tree
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

// Function to delete the binary tree
void deleteTree(TreeNode *root) {
  if (root == nullptr)
    return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

void printPath(vector<int> path) {
  for (auto &it : path) {
    cout << it << " ";
  }
  cout << endl;
}

int main() {
  Solution solution;
  TreeNode *root = createSampleTree();
  vector<int> left;
  vector<int> right;
  solution.findPath(root, 3, left);
  solution.findPath(root, 6, right);
  printPath(left);
  printPath(right);

  for (int i = left.size() - 1; i > 0; i--) {
    cout << left[i] << " ";
  }

  for (int i = 0; i < right.size(); i++) {
    cout << right[i] << " ";
  }

  return 0;
}
