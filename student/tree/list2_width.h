#ifndef LIST2_WIDTH_H
#define LIST2_WIDTH_H

#include "list2_width_node.h"
#include "tree_node.h"

class list2_width
{
private:
	list2_width_node *head = nullptr;
	int width = 0;
public:
	enum ERRORS
	{
		SUCCESS,
		ALLOC_ERROR
	};

	list2_width_node *get_head() const { return head; }
	int get_width() const { return width; }
	void rm();
	list2_width() = default;
	list2_width(tree_node *x);
	~list2_width() { rm(); }
	int next_depth();
	void print(int length) const;
	friend class tree;
};

#endif// LIST2_WIDTH_H
