#include "int_link_queue.h"

#include <stdio.h>

int main(const int argc, const char* argv[])
{
	queue q;
	type e;
	
	printf("stand in line start....\n");
	if(FAILED == init_queue(&q))
	{
		printf("init queue failed.\n");
		return -1;
	}
	
	printf("element 1 enter queue.\n");
	if(FAILED == queue_push(&q, 1))
	{
		printf("push 1 into queue failed.\n");
		return -1;
	}
	
	printf("element 2 enter queue.\n");
	if(FAILED == queue_push(&q, 2))
	{
		printf("push 2 into queue failed.\n");
		return -1;
	}
	
	printf("obtain the queue head element.\n");
	if(FAILED == queue_pop(&q, &e))
	{
		printf("obtain the queue head element failed.\n");
		return -1;
	}
	
	printf("current queue head element is %d\n", e);
	if(FAILED == destroy_queue(&q))
	{
		printf("destroy queue failed.\n");
		return -1;
	}
	
	printf("stand in line success.\n");
	return 0;
}