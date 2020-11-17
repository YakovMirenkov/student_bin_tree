#include "bin_tree.h"
int num_sbtrs_nng_node(bin_tree_node *node, int max);

// Число поддеревьев, кол-во узлов которых не больше max
int bin_tree::num_sbtrs_nng(int max) const
{
	return num_sbtrs_nng_node(root, max);
}

int num_sbtrs_nng_node(bin_tree_node *node, int max)
{
	int res;

	if( node==nullptr )
		return 0;

	res = num_sbtrs_nng_node(node->get_left(), max) + num_sbtrs_nng_node(node->get_right(), max);

	if( res<max )
		res++;

	return res;
}
