#include "bin_tree.h"
int max_depth_node(bin_tree_node *node);

int bin_tree::max_depth() const
{
	return max_depth_node(root);
}

int max_depth_node(bin_tree_node *node)
{
	int depth_left, depth_right;

	if( node==nullptr )
		return -1;

	depth_left = max_depth_node(node->get_left());
	depth_right = max_depth_node(node->get_right());

	if( depth_left>depth_right )
		return 1 + depth_left;
	return 1 + depth_right;
}
