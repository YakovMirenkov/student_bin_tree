#ifndef TREE_NODE_H
#define TREE_NODE_H

#include "../student.h"

class tree_node: public student
{
private:
	tree_node *left = nullptr;
	tree_node *right = nullptr;
public:
	tree_node *get_left() const { return left; }
	tree_node *get_right() const { return right; }
	tree_node() = default;
	tree_node(const char *name, int value): student(name, value) { left = nullptr; right = nullptr; }
	tree_node(const tree_node &x): student(x) { left = nullptr; right = nullptr; }
	tree_node(tree_node &&x): student(static_cast<student &&>(x))
	{
		left = x.left;
		x.left = nullptr;
		right = x.right;
		x.right = nullptr;
	}
	~tree_node() { left = nullptr; right = nullptr; }
	friend class tree;
	friend class list2_width;
};

#endif// TREE_NODE_H
