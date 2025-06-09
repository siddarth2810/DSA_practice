#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// construct binary tree using the array
TreeNode *buildTree(const vector<int> &arr, int i) {
  if (i >= arr.size())
    return NULL;

  TreeNode *root = new TreeNode(arr[i]);
  root->left = buildTree(arr, 2 * i + 1);
  root->right = buildTree(arr, 2 * i + 2);

  return root;
}

// Utility to print the tree structure sideways
void printTree(TreeNode* root, int space = 0, int indent = 4) {
    if (!root) return;

    space += indent;

    // Print right subtree first (on top)
    printTree(root->right, space);

    // Print current node
    cout << string(space - indent, ' ') << root->val << "\n";

    // Print left subtree (on bottom)
    printTree(root->left, space);
}



// construct BST using the array
TreeNode *buildBST(TreeNode *root, int val) {
  if (!root)
    return new TreeNode(val);

  if (val < root->val)
    root->left = buildBST(root->left, val);
  else
    root->right = buildBST(root->right, val);

  return root;
}

int main() {
  vector<int> v = {5, 1, 2, 3, 4, 6, 7, 8, 9, 10};
  TreeNode *root = buildTree(v, 0);
  TreeNode *rootNode = NULL;

  for (int val : v) {
    rootNode = buildBST(rootNode, val);
  }
 // printTree(root);
  return 0;
}

