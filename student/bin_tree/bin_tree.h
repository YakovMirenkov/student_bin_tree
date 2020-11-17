#ifndef BIN_TREE_H
#define BIN_TREE_H

#include "bin_tree_node.h"

class bin_tree
{
private:
	bin_tree_node *root = nullptr;
	void add_node(bin_tree_node *new_node) const;
public:
	enum ERRORS
	{
		SUCCESS,
		OPEN_ERROR,
		READ_ERROR,
		ALLOC_ERROR
	};

	bin_tree_node *get_root() const { return root; };
	void rm();
	int read(const char *filename);
	void print(int depth);
	~bin_tree() { rm(); }
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

#endif// BIN_TREE_H
