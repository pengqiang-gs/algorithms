//
// 将任意的非负十进制数转换成八进制并且打印出来。
// 
// 输入：十进制数(输入负数退出)
// 输出：八进制数
// 
#include "SequentialStack.h"

#include <stdio.h>

int main(const int argc, const char* argv[])
{
	int input = 0;
	
	while(1)
	{
		printf("请输入一个非负数【输入负数退出】:");
		scanf("%d", &input);
		
		if(input < 0)
			break;
		
		SequentialStack s;
		if(FAILED == stackInitialize(&s))
		{
			printf("init stack failed.\n");
			return -1;
		}
		
		while(input)
		{
			if(FAILED == stackPush(&s, input % 8))
			{
				printf("stack push failed.\n");
				return -1;
			}
			
			input /= 8;
		}
		
		while(!stackIsEmpty(s))
		{
			if(FAILED == stackPop(&s, &input))
			{
				printf("stack pop failed.\n");
				return -1;
			}
			
			printf("%d", input);
		}
		
		if(FAILED == stackDestroy(&s))
		{
			printf("destroy list failed.\n");
			return -1;
		}
		
		printf("\n\n");
	}
	
	return 0;
}