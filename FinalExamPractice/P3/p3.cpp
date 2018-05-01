
double max(double a, double b, double c)
{
	double m = 0;
	if (a > m) m = a;
	if (b > m) m = b;
	if (c > m) m = c;
	return m;
}


double tree_max(treeNode * tree)
{
	if (tree==NULL) return 0.0;
	return max(tree->get_value, tree_max(tree->get_left()), tree_max(get_right()));
}