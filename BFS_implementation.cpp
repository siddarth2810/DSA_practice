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
void printTree(TreeNode *root, int space = 0, int indent = 4) {
  if (!root)
    return;

  space += indent;

  // Print right subtree first (on top)
  printTree(root->right, space);
  // Print current node
  cout << string(space - indent, ' ') << root->val << "\n";
  printTree(root->left, space);
}

vector<int> BFSTraversal(TreeNode *root) {
  vector<int> res;
  if (root == NULL)
    return {};

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
      TreeNode *curr = q.front();
      q.pop();
      res.push_back(curr->val);

      if (curr->left != NULL)
        q.push(curr->left);
      if (curr->right != NULL)
        q.push(curr->right);
  }
  return res; 
}

int main() {
  vector<int> v = {5, 1, 2, 3, 4, 6, 7, 8, 9, 10};
  TreeNode *root = buildTree(v, 0);
  vector<int> bfs = BFSTraversal(root);
  printTree(root);

  cout << endl;
  for(auto it: bfs){
	  cout << it << " ";
  }

  return 0;
}

