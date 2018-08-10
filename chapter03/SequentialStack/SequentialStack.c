#include "SequentialStack.h"

#include <stdlib.h>

StatusType stackInitialize(SequentialStack* s)
{
	s->_asize = INITIAL_SIZE;
	s->_bottom = (DataType*)malloc(s->_asize * sizeof(DataType));
	if(s->_bottom == NULL)
		return FAILED;
	
	s->_top = s->_bottom;
	s->_size = 0;
	
	return SUCCESS;
}

StatusType stackDestroy(SequentialStack* s)
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

StatusType stackClear(SequentialStack* s)
{
	if(s == NULL || s->_bottom == NULL)
		return FAILED;
	
	s->_size = 0;
	return SUCCESS;
}

StatusType stackIsEmpty(SequentialStack s)
{
	if(s._size > 0)
		return IS_FALSE;
	else
		return IS_TRUE;
}

SizeType stackSize(SequentialStack s)
{
	return s._size;
}

StatusType stackTop(SequentialStack s, DataType* e)
{
	if(stackIsEmpty(s))
	{
		e = NULL;
		return FAILED;
	}
	
	*e = *(s._top-1);
	return SUCCESS;
}

StatusType stackPop(SequentialStack* s, DataType* e)
{
	if(FAILED == stackTop(*s, e))
	{
		e = NULL;
		return FAILED;
	}
	
	--(s->_top);
	--(s->_size);
	return SUCCESS;
}

StatusType stackPush(SequentialStack* s, DataType e)
{
	DataType* re = NULL;

	if(s->_size >= s->_asize)
	{
		s->_asize += INCREASE_SIZE;
		re = (DataType*)realloc(s->_bottom, s->_asize * sizeof(DataType));
		if(s->_bottom == NULL)
			return FAILED;
		
		s->_bottom = re;
		s->_top = s->_bottom + s->_size;
	}
	
	*(s->_top) = e;
	++(s->_top);
	++(s->_size);

	return SUCCESS;
}