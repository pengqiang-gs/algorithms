#include "LinkedStack.h"

#include <stdlib.h>

StatusType stackInitialize(LinkedStack* s)
{
	s->_bottom = (Node*)malloc(sizeof(Node));
	if(s->_bottom == NULL)
		return FAILED;
	
	s->_bottom->_next = NULL;
	s->_bottom->_previous = NULL;
	s->_top = s->_bottom;
	s->_size = 0;
	
	return SUCCESS;
}

StatusType stackDestroy(LinkedStack* s)
{
	Node* n_cur = NULL;
	Node* n_next = NULL;
	
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

StatusType stackClear(LinkedStack* s)
{
	Node* n_cur = NULL;
	Node* n_next = NULL;
	
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

StatusType stackIsEmpty(LinkedStack s)
{
	if(s._size > 0)
		return IS_FALSE;
	else
		return IS_TRUE;
}

SizeType stackSize(LinkedStack s)
{
	return s._size;
}

StatusType stackTop(LinkedStack s, DataType* e)
{
	if(stackIsEmpty(s))
	{
		e = NULL;
		return FAILED;
	}
	
	*e = s._top->_element;

	return SUCCESS;
}

StatusType stackPop(LinkedStack* s, DataType* e)
{
	Node* n_cur = NULL;
	
	// stack top to e
	if(FAILED == stackTop(*s, e))
	{
		e = NULL;
		return FAILED;
	}
	
	n_cur = s->_top;
	s->_top = s->_top->_previous;
	s->_top->_next = NULL;
	--(s->_size);
	free(n_cur);

	return SUCCESS;
}

StatusType stackPush(LinkedStack* s, DataType e)
{
	Node* n_new = (Node*)malloc(sizeof(Node));
	if(n_new == NULL)
		return FAILED;
	
	n_new->_element = e;
	n_new->_next = s->_top->_next;
	n_new->_previous = s->_top;
	s->_top->_next = n_new;
	s->_top = n_new;
	++(s->_size);
	
	return SUCCESS;
}