#include "bin_tree.h"
#include "list2_width.h"
#include "width_node.h"

int bin_tree::max_width() const
{
	int max = 1, depth, curr_width;
	list2_width lst{root};

	if( root==nullptr )
		return 0;

	for( depth = 1; lst.head!=nullptr; depth++ )
	{
		if( lst.next_depth()!=list2_width::SUCCESS )
		{
			while( (curr_width = width_node(root, depth))!=0 )
			{
				if( curr_width>max )
					max = curr_width;
				depth++;
			}
			return max;
		}
		if( lst.width>max )
			max = lst.width;
	}

	return max;
}
