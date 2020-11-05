#include "tree.h"
#include "list2_width.h"
int width_node(int desired_depth, tree_node *node, int curr_depth);

int tree::max_width() const
{
	int max = 1, depth, curr_width;
	list2_width lst{root};

	if( root==nullptr )
		return 0;

	for( depth = 1; lst.head!=nullptr; depth++ )
	{
		if( lst.next_depth()!=list2_width::SUCCESS )
		{
			while( (curr_width = width_node(depth, root, 0))!=0 )
			{
				if( curr_width>max )
					max = curr_width;
				depth++;
			}
			break;
		}
		if( lst.width>max )
			max = lst.width;
	}

	return max;
}

int width_node(int desired_depth, tree_node *node, int curr_depth)
{
	int res = 0;

	while( node!=nullptr )
	{
		if( curr_depth==desired_depth )
		{
			res++;
			break;
		}
		res += width_node(desired_depth, node->get_left(), curr_depth + 1);
		node = node->get_right();
		curr_depth++;
	}

	return res;
}
