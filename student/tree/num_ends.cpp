#include "tree.h"
int num_ends_node(tree_node *node);

int tree::num_ends() const
{
	return num_ends_node(root);
}

int num_ends_node(tree_node *node)
{
	int num = 0;

	while( node!=nullptr )
	{
		if( node->get_left()==nullptr && node->get_right()==nullptr )
			return num + 1;
		num += num_ends_node(node->get_left());
		node = node->get_right();
	}

	return num;
}
