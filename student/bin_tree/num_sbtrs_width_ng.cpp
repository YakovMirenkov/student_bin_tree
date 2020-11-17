#include "bin_tree.h"
#include "list2_width.h"
#include "width_node.h"
int num_sbtrs_width_ng_node(bin_tree_node *node, int max);

// Число поддеревьев, ширина которых не больше max
int bin_tree::num_sbtrs_width_ng(int max) const
{
	return num_sbtrs_width_ng_node(root, max);
}

int num_sbtrs_width_ng_node(bin_tree_node *node, int max)
{
	int res = 1, depth, curr_width;
	list2_width lst{node};

	if( node==nullptr || max<=0 )
		return 0;

	for( depth = 1; lst.get_head()!=nullptr; depth++ )
	{
		if( lst.next_depth()!=list2_width::SUCCESS )
		{
			while( (curr_width = width_node(node, depth))!=0 )
			{
				if( curr_width>max )
					return num_sbtrs_width_ng_node(node->get_left(), max) + num_sbtrs_width_ng_node(node->get_right(), max);
				else
					res += curr_width;
				depth++;
			}
			return res;
		}
		if( lst.get_width()>max )
			return num_sbtrs_width_ng_node(node->get_left(), max) + num_sbtrs_width_ng_node(node->get_right(), max);
		else
			res += lst.get_width();
	}

	return res;
}
