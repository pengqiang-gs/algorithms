#include "SinglyLinkedList.h"

#include <stdio.h>

int main(const int argc, const char* argv[])
{
	SinglyLinkedList l;
	PositionType index = 0;
	DataType element = 0;
	
	printf("testing singly linked list start...\n");
	if(FAILED == listInitialize(&l))
	{
		printf("initialize singly linked list error.\n");
		return -1;
	}
	
	printf("initialize singly linked list success, insert a element valued 10.\n");
	if(FAILED == listInsert(&l, 0, 10))
	{
		printf("insert a element valued 10 failed!\n");
		return -1;
	}
	
	printf("insert into singly linked list success, current list size: %d\n", listSize(l));
	printf("insert a element valued 20 into current singly linked list.\n");
	if(FAILED == listInsert(&l, 1, 20))
	{
		printf("insert a element valued 20 failed.\n");
		return -1;
	}

	printf("print all elements in current singly linked list.\n");
	for(index = 0; index < listSize(l); ++index)
	{
		if(FAILED == listGet(l, index, &element))
		{
			printf("get element located in position %d failed.\n", index);
			return -1;
		}

		printf("%d  ", element);
	}

	printf("\nremove element in current singly linked list at position 1.\n");
	if(FAILED == listRemove(&l, 1, &element))
	{
		printf("remove element at position 1 failed.\n");
		return -1;
	}

	printf("remove element [%d] success, current singly linked list is [%s] empty!\n", 
		element, listIsEmpty(l) == IS_TRUE ? "" : "not");
	if(listIsEmpty(l) == IS_FALSE)
	{
		if(FAILED == listDestroy(&l))
		{
			printf("destroy current singly linked list failed.\n");
			return -1;
		}

		printf("destroy current singly linked list success.\n");	
	}

	printf("testing int single list end.\n");
	return 0;
}