#ifndef TREE_H
#define TREE_H

#include "tree_node.h"

class tree
{
private:
	tree_node *root = nullptr;
	void add_node(tree_node *new_node) const;
public:
	enum ERRORS
	{
		SUCCESS,
		OPEN_ERROR,
		READ_ERROR,
		ALLOC_ERROR
	};

	tree_node *get_root() const { return root; };
	void rm();
	int read(const char *filename);
	void print(int depth);
	~tree() { rm(); }
	int num_ends() const;
	int max_depth() const;
	int max_width() const;
	int max_diff_depths() const;
	int num_one_descendant() const;
	int num_sbtrs_nng(int max) const;
	int num_nodes_sbtrs_nng(int max) const;
	int num_sbtrs_depth_ng(int max) const;
	int num_sbtrs_width_ng(int max) const;
	int num_nodes_depth(int depth) const;
};

#endif// TREE_H
