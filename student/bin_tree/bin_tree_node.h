#ifndef BIN_TREE_NODE_H
#define BIN_TREE_NODE_H

#include "../student.h"

class bin_tree_node: public student
{
private:
	bin_tree_node *left = nullptr;
	bin_tree_node *right = nullptr;
public:
	bin_tree_node *get_left() const { return left; }
	bin_tree_node *get_right() const { return right; }
	bin_tree_node() = default;
	bin_tree_node(const char *name, int value): student(name, value) { left = nullptr; right = nullptr; }
	bin_tree_node(const bin_tree_node &x): student(x) { left = nullptr; right = nullptr; }
	bin_tree_node(bin_tree_node &&x): student(static_cast<student &&>(x))
	{
		left = x.left;
		x.left = nullptr;
		right = x.right;
		x.right = nullptr;
	}
	~bin_tree_node() { left = nullptr; right = nullptr; }
	friend class bin_tree;
	friend class list2_width;
};

#endif// BIN_TREE_NODE_H
