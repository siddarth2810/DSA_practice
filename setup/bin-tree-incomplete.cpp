#include<iostream>
#include<memory>

#include "lest.hpp"

using namespace std;


class BinaryTreeNode
{
	public: 
		int value_;
		BinaryTreeNode* left_;
		BinaryTreeNode* right_;

		BinaryTreeNode(int value):
		value_(value),
		left_(nullptr),
		right_(nullptr)
		{
		}

		~BinaryTreeNode()
		{
		delete left_;
		delete right_;
		}

		BinaryTreeNode* insertLeft(int value)
		{
			this->left_ = new BinaryTreeNode(value);
			return this->left_;
		}

		BinaryTreeNode* insertRight(int value)
		{
			this->right_ = new BinaryTreeNode(value);
			return this->right_;
		}
};

bool isBalanced (BinaryTreeNode* treeRoot){
}





















//tests


const lest::test tests[] {
	{ CASE("Full Tree"){
				   auto root = make_unique<BinaryTreeNode>(5);
				   root->insertLeft(8)->insertLeft(1);
				   root->insertRight(6)->insertRight(4);
				   root->left_->insertRight(2);
				   root->right_->insertLeft(3);
				   EXPECT(isBalanced(root.get()) == true);
			   }

	}

};


int main(int argc, char** argv){
	return lest::run(tests, argc, argv);
}
