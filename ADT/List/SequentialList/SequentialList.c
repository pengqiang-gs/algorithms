#include "SequentialList.h"

// include for memory management functions, such as malloc, realloc, free.
#include <stdlib.h>

StatusType listInitialize(SequentialList* l)
{
	l->_asize = INITIAL_SIZE;
	l->_element = (DataType*)malloc(l->_asize * sizeof(DataType));
	if(l->_element == NULL)
		return FAILED;
	
	l->_size = 0;
	return SUCCESS;
}

StatusType listDestroy(SequentialList* l)
{
	if(l->_element != NULL)
	{
		free(l->_element);
		l->_element = NULL;
		l->_size = 0;
		l->_asize = 0;
	}
	
	return SUCCESS;
}

StatusType listClear(SequentialList* l)
{
	l->_size = 0;
	
	return SUCCESS;
}

StatusType listIsEmpty(SequentialList l)
{
	if(l._size == 0)
		return IS_TRUE;
	else
		return IS_FALSE;
}

SizeType listSize(SequentialList l)
{
	return l._size;
}

StatusType listGet(SequentialList l, PositionType p, DataType* e)
{
	if(p < 0 || p >= listSize(l))
	{
		*e = NOT_FOUND;
		return FAILED;
	}
	else
		*e = l._element[p];
	
	return SUCCESS;
}

PositionType listFind(SequentialList l, DataType e)
{
	PositionType i = 0;
	for(i = 0; i < listSize(l); ++i)
	{
		if(e == l._element[i])
			return i;
	}
	
	return NOT_FOUND;
}

StatusType listInsert(SequentialList* l, PositionType p, DataType e)
{
	DataType* re = NULL;
	SizeType current_size = listSize(*l);
	PositionType index = p;
	
	if(p < 0 && p > (PositionType)current_size)
		return FAILED;
	
	if(current_size == l->_asize)
	{
		// realloc size.
		l->_asize += INCREASE_SIZE;
		re = (DataType*)realloc(l->_element, (l->_asize) * sizeof(DataType));
		if(re == NULL)
			return FAILED;
		
		l->_element = re;
	}
	
	// move element which is located in PositionType p to next PositionType.
	for(index = current_size - 1; index >= p; --index)
		l->_element[index+1] = l->_element[index];

	l->_element[p] = e;
	++l->_size;

	return SUCCESS;
}

StatusType listRemove(SequentialList* l, PositionType p, DataType* e)
{
	PositionType index = 0;
	SizeType current_size = listSize(*l);
	
	if(p < 0 || p >= current_size)
		return FAILED;
	
	// move element which is located in PositionType p to previous PositionType.
	for(index = p+1; index < current_size; ++index)
		l->_element[index-1] = l->_element[index];
	--l->_size;

	return SUCCESS;
}