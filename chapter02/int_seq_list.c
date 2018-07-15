#include "int_seq_list.h"

#include <stdlib.h>

status init_list(list* l)
{
	l->_element = (type*)malloc(INIT_SIZE * sizeof(type));
	if(l->_element == NULL)
		return FAILED;
	
	l->_size = 0;
	l->_asize = INIT_SIZE;
	return SUCCESS;
}

status destroy_list(list* l)
{
	if(l->_element)
	{
		free(l->_element);
		l->_element = NULL;
		l->_size = 0;
		l->_asize = 0;
	}
	
	return SUCCESS;
}

status clear_list(list* l)
{
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
	if(p < 0 || p >= list_length(l))
	{
		e = NULL;
		return FAILED;
	}
	else
		e = &l._element[p];
	
	return SUCCESS;
}

position locate_list(list l, type e)
{
	position i = 0;
	for(i = 0; i < list_length(l); ++i)
	{
		if(e == l._element[i])
			return i;
	}
	
	return NOT_FOUND;
}

status list_insert(list* l, position p, type e)
{
	type* re = NULL;
	type* m = NULL;
	type* n = NULL;
	
	if(p < 0 && p > l->_size)
		return FAILED;
	
	if(l->_size >= l->_asize)
	{
		// realloc size
		re = (type*)realloc(l->_element, (l->_asize + INCREASE_SIZE) * sizeof(type));
		if(re == NULL)
			return FAILED;
		
		l->_element = re;
		l->_asize += INCREASE_SIZE;
	}
	
	// move afterwards p to next position
	m = &(l->_element[p]);   // p is insertion position
	for(n = &(l->_element[l->_size-1]); n >= m; --n)
		*(n+1) = *n;
	
	*m = e;
	++l->_size;
	return SUCCESS;
}

status list_remove(list* l, position p, type* e)
{
	type* m = NULL;
	position n = 0;
	
	if(p < 0 || p > l->_size)
		return FAILED;
	
	m = &(l->_element[p]);
	*e = *m;
	for(n = p+1; n < l->_size; ++n)
		l->_element[n-1] = l->_element[n];
	--l->_size;
	return SUCCESS;
}