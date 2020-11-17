#include "bin_tree.h"
#include "width_node.h"

int bin_tree::num_nodes_depth(int depth) const
{
	return width_node(root, depth);
}
