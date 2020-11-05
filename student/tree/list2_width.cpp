#include "list2_width.h"

void list2_width::rm()
{
	list2_width_node *tmp;

	while( head!=nullptr )
	{
		tmp = head->next;
		delete head;
		head = tmp;
	}
	width = 0;
}

list2_width::list2_width(tree_node *new_x)
{
	rm();

	if( new_x==nullptr )
		return;

	head = new list2_width_node;
	head->x = new_x;
	head->prev = nullptr;
	head->next = nullptr;
	width = 1;
}

int list2_width::next_depth()
{
	list2_width_node *curr, *tmp;

	if( head!=nullptr )
	{
		while( head->x->left==nullptr && head->x->right==nullptr )
		{
			tmp = head->next;
			delete head;
			head = tmp;
			width--;
			if( head==nullptr )
				return SUCCESS;
			head->prev = nullptr;
		}
		curr = head;
		if( curr->x->left==nullptr )
		{
			curr->x = curr->x->right;
		} else
		{
			if( curr->x->right==nullptr )
			{
				curr->x = curr->x->left;
			} else
			{
				tmp = curr->next;
				if( (curr->next = new list2_width_node)==nullptr )
				{
					rm();
					return ALLOC_ERROR;
				}
				curr->next->prev = curr;
				if( tmp!=nullptr )
					tmp->prev = curr->next;
				curr->next->next = tmp;
				curr->next->x = curr->x->right;
				curr->x = curr->x->left;
				curr = curr->next;
				width++;
			}
		}

		while( (curr = curr->next)!=nullptr )
		{
			if( curr->x->left==nullptr && curr->x->right==nullptr )
			{
				curr->prev->next = curr->next;
				if( curr->next!=nullptr )
					curr->next->prev = curr->prev;
				tmp = curr->prev;
				delete curr;
				curr = tmp;
				width--;
				continue;
			}
			if( curr->x->left==nullptr )
			{
				curr->x = curr->x->right;
				continue;
			}
			if( curr->x->right==nullptr )
			{
				curr->x = curr->x->left;
				continue;
			}
			tmp = curr->next;
			if( (curr->next = new list2_width_node)==nullptr )
			{
				rm();
				return ALLOC_ERROR;
			}
			curr->next->prev = curr;
			if( tmp!=nullptr )
				tmp->prev = curr->next;
			curr->next->next = tmp;
			curr->next->x = curr->x->right;
			curr->x = curr->x->left;
			curr = curr->next;
			width++;
		}
	}

	return SUCCESS;
}

void list2_width::print(int length) const
{
	int i;
	list2_width_node *tmp;

	if( head==nullptr || length<=0 )
		return;

	head->x->print();

	tmp = head;
	for( i = 1; i<length && (tmp = tmp->next); i++ )
		tmp->x->print();
}
