#include "int_single_list.h"

#include <stdlib.h>

status init_list(list* l)
{	
	l->_header = (node*)malloc(sizeof(node));
	l->_header->_element = 0;
	l->_header->_next = NULL;
	l->_size = 0;

	return SUCCESS;
}

status destroy_list(list* l)
{
	node* n_cur = l->_header;
	node* n_next = NULL;

	while(n_cur != NULL)
	{
		n_next = n_cur->_next;
		free(n_cur);
		n_cur = n_next;
	}

	return SUCCESS;
}

status clear_list(list* l)
{
	node* n_cur = l->_header->_next;
	node* n_next = NULL;

	while(n_cur != NULL)
	{
		n_next = n_cur->_next;
		free(n_cur);
		n_cur = n_next;
	}

	// reset head node
	l->_header->_next = NULL;
	l->_header->_element = 0;
	l->_size = 0;

	return SUCCESS;
}

int list_empty(list l)
{
	if(l._size == 0)
		return TRUE;
	else
		return FALSE;
}

int list_length(list l)
{
	return l._size;
}

status list_get(list l, position p, type* e)
{
	node* n_cur = NULL;
	position pos = 0;

	if(p > 0 && p < list_length(l))
	{
		n_cur = l._header->_next;
		while(n_cur != NULL)
		{
			pos++;
			if(pos == p)
			{
				*e = n_cur->_element;
				return SUCCESS;
			}

			n_cur = n_cur->_next;
		}
	}

	return FAILED;
}

position locate_list(list l, type e)
{
	position pos = 0;
	node* n_cur = l._header->_next;

	while(n_cur != NULL)
	{
		if(n_cur->_element == e)
			return pos;
		pos++;
	}

	return NOT_FOUND;
}

status list_insert(list* l, position p, type e)
{
	position pos = 0;
	node* n_cur = l->_header->_next;
	node* n_new = NULL;

	n_new = (node*)malloc(sizeof(node));
	if(n_new == NULL)
		return FAILED;

	n_new->_element = e;
	if(0 == list_length(*l) && p == 0)
	{
		// insert first node
		l->_header->_next = n_new;
		n_new->_next = NULL;
	}
	else
	{
		// look for the node whose position is p-1
		while(n_cur != NULL && pos < p - 1)
		{
			n_cur = n_cur->_next;
			pos++;
		}

		n_new->_next = n_cur->_next;
		n_cur->_next = n_new;
	}
	l->_size++;

	return SUCCESS;
}

status list_remove(list* l, position p, type* e)
{
	position pos = 0;
	node* n_cur = l->_header->_next;
	node* n_remove = NULL;

	// look for the node whose position is p-1
	while(n_cur != NULL && pos < p - 1)
	{
		n_cur = n_cur->_next;
		pos++;
	}

	if(n_cur == NULL || pos > p - 1)
		return FAILED;

	n_remove = n_cur->_next;
	n_cur->_next = n_remove->_next;
	*e = n_remove->_element;
	free(n_remove);

	return SUCCESS;
}
