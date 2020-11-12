#include <cstdlib>
#include "tree.h"
int diff_depths_node(tree_node *node, int &max_diff);

int tree::max_diff_depths() const
{
	int max_diff = -1;

	diff_depths_node(root, max_diff);

	return max_diff;
}

int diff_depths_node(tree_node *node, int &max_diff)
{
	int depth_left, depth_right;

	if( node==nullptr )
		return -1;

	depth_left = diff_depths_node(node->get_left(), max_diff);
	depth_right = diff_depths_node(node->get_right(), max_diff);

	if( depth_left>=0 && depth_right>=0 )
	{
		int diff = abs(depth_left - depth_right);

		if( diff>max_diff )
			max_diff = diff;
	}

	if( depth_left>depth_right )
		return 1 + depth_left;
	return 1 + depth_right;
}
