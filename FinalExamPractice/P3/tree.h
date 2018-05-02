#ifndef __TREE_NODE__
#define __TREE_NODE__

class TreeNode;

class TreeNode {
	public:
		TreeNode(TreeNode *l_child, TreeNode* r_child, double v);
		double get_value();
		TreeNode * get_left();
		TreeNode * get_right();

	protected: 
		double val; // value stored in this node
		TreeNode *left; // pointer to left child, NULL if none
		TreeNode *right; // pointer to right child, NULL if none

};

#endif