#include <cstdio>
#include "tree.h"
void rm_node(tree_node *node);
void print_node(tree_node *node, int depth);

void rm_node(tree_node *node)
{
	tree_node *tmp;

	while( node!=nullptr )
	{
		rm_node(node->get_left());
		tmp = node->get_right();
		delete node;
		node = tmp;
	}
}

void tree::rm()
{
	rm_node(root);
	root = nullptr;
}


void tree::add_node(tree_node *new_node) const
{
	tree_node *tmp = root;

	while( true )
	{
		if( *tmp>*new_node )
		{
			if( tmp->left==nullptr )
			{
				tmp->left = new_node;
				return;
			} else
				tmp = tmp->left;
		} else
		{
			if( tmp->right==nullptr )
			{
				tmp->right = new_node;
				return;
			} else
				tmp = tmp->right;
		}
	}
}

int tree::read(const char *filename)
{
	FILE *in;
	int res;
	tree_node *new_node;

	rm();
	if( (root = new tree_node)==nullptr )
		return ALLOC_ERROR;
	if( !(in = fopen(filename, "r")) )
	{
		delete root;
		root = nullptr;
		return OPEN_ERROR;
	}

	if( (res = root->read(in))!=student::SUCCESS )
	{
		fclose(in);
		rm();
		switch( res )
		{
		case student::EOF_ERROR:
			return SUCCESS;
		case student::ALLOC_ERROR:
			return ALLOC_ERROR;
		default:
			return READ_ERROR;
		}

	}

	if( (new_node = new tree_node)==nullptr )
	{
		fclose(in);
		rm();
		return ALLOC_ERROR;
	}
	while( (res = new_node->read(in))==student::SUCCESS )
	{
		add_node(new_node);
		if( (new_node = new tree_node)==nullptr )
		{
			fclose(in);
			rm();
			return ALLOC_ERROR;
		}
	}
	delete new_node;

	fclose(in);
	if( res==student::EOF_ERROR )
		return SUCCESS;
	rm();
	switch( res )
	{
	case student::ALLOC_ERROR:
		return ALLOC_ERROR;
	default:
		return READ_ERROR;
	}
}


static int depth_print = 0;

void print_node(tree_node *node, int depth)
{
	int i;

	while( node!=nullptr && depth<=depth_print )
	{
		for( i = 0; i<2*depth; i++ )
			printf(" ");
		node->print();

		print_node(node->get_left(), depth + 1);

		node = node->get_right();
		depth++;
	}
}

void tree::print(int depth)
{
	depth_print = depth;

	print_node(root, 0);
}
