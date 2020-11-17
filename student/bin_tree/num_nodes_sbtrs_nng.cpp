#include "bin_tree.h"
int num_nodes_sbtrs_nng_node(bin_tree_node *node, int max, int &res);

// Число узлов поддеревьев, т.ч. кол-во узлов не больше max
int bin_tree::num_nodes_sbtrs_nng(int max) const
{
	int res = 0;

	num_nodes_sbtrs_nng_node(root, max, res);

	return res;
}

int num_nodes_sbtrs_nng_node(bin_tree_node *node, int max, int &res)
{
	int num;

	if( node==nullptr )
		return 0;

	num = num_nodes_sbtrs_nng_node(node->get_left(), max, res) + num_nodes_sbtrs_nng_node(node->get_right(), max, res);

	if( num<max )
	{
		num++;
		res += num;
	}

	return num;
}
