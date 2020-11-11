#include "width_node.h"

int width_node(int desired_depth, tree_node *node)
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
		res += width_node(desired_depth, node->get_left());
		node = node->get_right();
	}

	return res;
}
