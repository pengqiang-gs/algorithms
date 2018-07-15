#include "int_link_stack.h"

#include <stdlib.h>

status init_stack(stack* s)
{
	s->_bottom = (node*)malloc(sizeof(node));
	if(s->_bottom == NULL)
		return FAILED;
	
	s->_bottom->_next = NULL;
	s->_bottom->_previous = NULL;
	
	s->_top = s->_bottom;
	s->_size = 0;
	
	return SUCCESS;
}

status destroy_stack(stack* s)
{
	node* n_cur = NULL;
	node* n_next = NULL;
	
	if(s == NULL || s->_bottom == NULL)
		return FAILED;
	
	n_cur = s->_bottom;
	while(n_cur != NULL)
	{
		n_next = n_cur->_next;
		free(n_cur);
		n_cur = n_next;
	}
	
	s->_bottom = NULL;
	s->_top = NULL;
	s->_size = 0;
	return SUCCESS;
}

status clear_stack(stack* s)
{
	node* n_cur = NULL;
	node* n_next = NULL;
	
	if(s == NULL || s->_bottom == NULL)
		return FAILED;
	
	n_cur = s->_bottom->_next;
	while(n_cur != NULL)
	{
		n_next = n_cur->_next;
		free(n_cur);
		n_cur = n_next;
	}
	
	s->_top = s->_bottom;
	s->_size = 0;
	return SUCCESS;
}

int is_empty(stack s)
{
	if(s._size > 0)
		return FALSE;
	else
		return TRUE;
}

int stack_size(stack s)
{
	return s._size;
}

status stack_top(stack s, type* e)
{
	if(is_empty(s))
	{
		e = NULL;
		return FAILED;
	}
	
	*e = s._top->_element;
	return SUCCESS;
}

status stack_pop(stack* s, type* e)
{
	node* n_cur = NULL;
	
	if(is_empty(*s))
	{
		e = NULL;
		return FAILED;
	}
	
	n_cur = s->_top;
	*e = s->_top->_element;
	s->_top = s->_top->_previous;
	s->_top->_next = NULL;
	--(s->_size);
	free(n_cur);
	n_cur = NULL;
	return SUCCESS;
}

status stack_push(stack* s, type e)
{
	node* n_new = (node*)malloc(sizeof(node));
	if(n_new == NULL)
		return FAILED;
	
	n_new->_element = e;
	s->_top->_next = n_new;
	n_new->_previous = s->_top;
	n_new->_next = NULL;
	s->_top = n_new;
	++(s->_size);
	
	return SUCCESS;
}