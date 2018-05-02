#include <iostream>
#include "tree.h"

TreeNode::TreeNode(TreeNode *l_child, TreeNode * r_child, double v)
{
	left = l_child;
	right = r_child;
	val = v;
}

double TreeNode::get_value()
{
	return val;
}

TreeNode* TreeNode::get_left()
{
	return left;
}

TreeNode * TreeNode::get_right()
{
	return right;
}