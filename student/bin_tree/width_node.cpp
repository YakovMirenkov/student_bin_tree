#include "width_node.h"

int width_node(bin_tree_node *node, int desired_depth)
{
	int res = 0;

	while( node!=nullptr )
	{
		if( desired_depth==0 )
		{
			res++;
			break;
		}
		desired_depth--;
		res += width_node(node->get_left(), desired_depth);
		node = node->get_right();
	}

	return res;
}
