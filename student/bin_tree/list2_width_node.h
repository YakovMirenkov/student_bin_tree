#ifndef LIST2_WIDTH_NODE_H
#define LIST2_WIDTH_NODE_H

#include "bin_tree_node.h"

class list2_width_node
{
private:
	bin_tree_node *x = nullptr;
	list2_width_node *prev = nullptr;
	list2_width_node *next = nullptr;
public:
	list2_width_node() = default;
	~list2_width_node() { x = nullptr; prev = nullptr; next = nullptr; }
	friend class list2_width;
	friend class bin_tree;
};

#endif// LIST2_WIDTH_NODE_H
