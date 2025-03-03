
#include <stdlib.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> res;
        if(root ==  nullptr){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int levelSize = q.size();
            for(int i=0; i<levelSize; i++){
            TreeNode *curr = q.front();
            q.pop();
            if(curr->left != NULL) q.push(curr->left);
            if(curr->right !=NULL ) q.push(curr->right); 
            level.push_back(curr->val);
            }
        res.push_back(level);
        }
        //print res
        return {};
    }

};
