#include "bin_tree.h"
int num_one_descendant_node(bin_tree_node *node);

int bin_tree::num_one_descendant() const
{
	return num_one_descendant_node(root);
}

int num_one_descendant_node(bin_tree_node *node)
{
	int num = 0;
	bin_tree_node *tmp;

	while( node!=nullptr )
	{
		if( node->get_left()==nullptr && (tmp = node->get_right())!=nullptr && tmp->get_left()==nullptr && tmp->get_right()==nullptr )
			return num + 1;
		if( node->get_right()==nullptr && (tmp = node->get_left())!=nullptr && tmp->get_right()==nullptr && tmp->get_left()==nullptr )
			return num + 1;

		num += num_one_descendant_node(node->get_left());
		node = node->get_right();
	}

	return num;
}
