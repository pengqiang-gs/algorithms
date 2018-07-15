#include "int_double_list.h"

#include <stdio.h>

int main(const int argc, const char* argv[])
{
	list l;
	
	printf("testing int single list start...\n");
	printf("create a int single list.\n");
	if(FAILED == init_list(&l))
	{
		printf("create list error.\n");
		return -1;
	}
	
	printf("create success, insert a element 10.\n");
	if(FAILED == list_insert(&l, 0, 10))
	{
		printf("insert a element 10 failed!\n");
		return -1;
	}
	
	printf("insert success, current list size: %d\n", list_length(l));
	printf("destroy list.\n");
	if(FAILED == destroy_list(&l))
	{
		printf("destroy list failed.\n");
		return -1;
	}
	printf("destroy list success.\n");
	
	printf("testing int single list end.\n");
	return 0;
}