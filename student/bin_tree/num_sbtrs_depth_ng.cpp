#include "bin_tree.h"
int num_sbtrs_depth_ng_node(bin_tree_node *node, int max, int &res);

// Число поддеревьев, глубина которых не больше max
int bin_tree::num_sbtrs_depth_ng(int max) const
{
	int res = 0;

	num_sbtrs_depth_ng_node(root, max, res);

	return res;
}

int num_sbtrs_depth_ng_node(bin_tree_node *node, int max, int &res)
{
	int depth_left, depth_right;

	if( node==nullptr )
		return -1;

	depth_left = num_sbtrs_depth_ng_node(node->get_left(), max, res);
	depth_right = num_sbtrs_depth_ng_node(node->get_right(), max, res);

	if( depth_left>depth_right )
	{
		if( depth_left<max )
			res++;
		return 1 + depth_left;
	}
	if( depth_right<max )
		res++;
	return 1 + depth_right;
}
