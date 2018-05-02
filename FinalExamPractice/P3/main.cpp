#include <iostream>
#include "tree.h"
using namespace std;

// Naming convention is to describe the path of the tree
// H - head
// L - left
// R - right 

double max(double a, double b, double c)
{
	double m = 0;
	if (a > m) m = a;
	if (b > m) m = b;
	if (c > m) m = c;
	return m;
}


double tree_max(TreeNode * tree)
{
	if (tree==NULL) return 0.0;
	return max(tree->get_value(), tree_max(tree->get_left()), tree_max(tree->get_right()));
}

int main()
{
	TreeNode * HLLR = new TreeNode(NULL,NULL, 5.92);
	TreeNode * HLR = new TreeNode(NULL,NULL, 4.5);
	TreeNode * HRRR = new TreeNode(NULL,NULL,0.5);
	TreeNode * HRRL = new TreeNode(NULL,NULL,13.5);
	TreeNode * HRR = new TreeNode(HRRL,HRRR, 7.6);
	TreeNode * HR = new TreeNode(NULL, HRR,89.0);
	TreeNode * HLL = new TreeNode(NULL,HLLR, 45.8);
	TreeNode * HL = new TreeNode(HLL,HLR, 23.1);
	TreeNode * H = new TreeNode(HL,HR,56.8);
	TreeNode * root = H;
	cout << tree_max(root) << endl;
}
