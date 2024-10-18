class Solution {
private:
  bool dfs(TreeNode *root, TreeNode *&lastLeaf, TreeNode *target) {
    if (!root)
      return true;

    if (!root->left && !root->right) {
      if (lastLeaf) {
        // Compare current leaf with the corresponding leaf in the other tree
        if (lastLeaf->val != root->val)
          return false;
        lastLeaf = nullptr;
      } else {
        lastLeaf = root;
      }

      // Check if we've processed all leaves in both trees
      return lastLeaf != target;
    }

    if (!dfs(root->left, lastLeaf, target))
      return false;
    return dfs(root->right, lastLeaf, target);
  }

public:
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    TreeNode *lastLeaf = nullptr;

    // First DFS to process root1 and store the last leaf
    if (!dfs(root1, lastLeaf, root2))
      return false;

    // Second DFS to compare root2 leaves with root1 leaves
    if (!dfs(root2, lastLeaf, root2))
      return false;

    // If lastLeaf is null, all leaves matched; otherwise, trees have different
    // number of leaves
    return lastLeaf == nullptr;
  }
};
