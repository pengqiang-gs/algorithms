#include "SequentialList.h"

#include <stdio.h>

int main(const int argc, const char* argv[])
{
	SequentialList l;
	PositionType index = 0;
	DataType element;
	StatusType empty = IS_FALSE;

	printf("testing sequential list start...\n");

	// initialize sequential list.
	if(FAILED == listInitialize(&l))
	{
		printf("initialize sequential list error.\n");
		return -1;
	}
	
	// insert a element valued 10, into current sequential list.
	printf("initialize sequential list success, insert a element valued 10.\n");
	if(FAILED == listInsert(&l, 0, 10))
	{
		printf("insert a element 10 into current sequential list failed!\n");
		return -1;
	}
	
	// get current sequential list size
	printf("insert success, current list size: %d\n", listSize(l));

	// insert a element valued 20, into current sequential list.
	printf("insert a element valued 20 into current sequential list.\n");
	if(FAILED == listInsert(&l, 1, 20))
	{
		printf("insert a element valued 20 into current sequential list failed.\n");
		return -1;
	}

	// print current sequential list.
	printf("print elements in current sequential list.\n");
	for(index = 0; index < listSize(l); ++index)
	{
		if(FAILED == listGet(l, index, &element))
		{
			printf("get element which located in position %d failed.\n", index);
			return -1;
		}

		printf("%d  ", element);
	}
	
	// check the current sequential list is empty or not, if not, destroy it.
	printf("\ncurrent sequential list is [%s] empty!\n", listIsEmpty(l) == IS_TRUE ? "" : "not");
	if(listIsEmpty(l) == IS_FALSE)
	{
		if(FAILED == listDestroy(&l))
		{
			printf("destroy current sequential list failed.\n");
			return -1;
		}

		printf("destroy current sequential list success.\n");
	}
	
	printf("testing sequential list end.\n");
	return 0;
}