#include "int_seq_stack.h"

#include <stdlib.h>

status init_stack(stack* s)
{
	s->_bottom = (type*)malloc(stack_init_size * sizeof(type));
	if(s->_bottom == NULL)
		return FAILED;
	
	s->_top = s->_bottom;
	s->_size = 0;
	s->_asize = stack_init_size;
	
	return SUCCESS;
}

status destroy_stack(stack* s)
{
	if(s == NULL || s->_bottom == NULL)
		return FAILED;
	
	free(s->_bottom);
	s->_bottom = NULL;
	s->_top = NULL;
	s->_size = 0;
	s->_asize = 0;
	return SUCCESS;
}

status clear_stack(stack* s)
{
	if(s == NULL || s->_bottom == NULL)
		return FAILED;
	
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
	
	*e = *(s._top-1);
	return SUCCESS;
}

status stack_pop(stack* s, type* e)
{
	if(is_empty(*s))
	{
		e = NULL;
		return FAILED;
	}
	
	--(s->_top);
	--(s->_size);
	*e = *(s->_top);
	return SUCCESS;
}

status stack_push(stack* s, type e)
{
	if(s->_size >= s->_asize)
	{
		s->_bottom = (type*)realloc(s->_bottom, 
			(stack_increase_size + s->_asize) * sizeof(type));
		if(s->_bottom == NULL)
			return FAILED;
		
		s->_top = s->_bottom + s->_size;
		s->_asize += stack_increase_size;
	}
	
	*(s->_top) = e;
	++(s->_top);
	++(s->_size);
	return SUCCESS;
}