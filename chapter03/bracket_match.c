// 
// 一个输入的字符串表达式中包含小括号，中括号，大括号
// (), [], {}, ([]), ({}), [{}], ({{[]}})这种都是匹配正确的
// (], {)]} 这中都是匹配不正确的
// 
// 写一个程序，验证输入的一串括号是否匹配。
// 

#include "int_link_stack.h"

#include <string.h>
#include <stdio.h>

int bracket_match(const char* src)
{
	const char* pos = src;
	int ch;

	stack s;
	if(FAILED == init_stack(&s))
	{
		printf("init stack failed.\n");
		return -1;
	}

	while(*pos != '\0')
	{
		if(*pos == '(' || *pos == '[' || *pos == '{')
		{
			if(FAILED == stack_push(&s, *pos))
			{
				printf("stack push %c failed.\n", *pos);
				return -1;
			}
		}
		else if(*pos == ')' || *pos == ']' || *pos == '}')
		{
			if(FAILED == stack_top(s, &ch))
			{
				printf("stack top failed.\n");
				return -1;
			}

			if((*pos == ')' && ch == '(') ||
					(*pos == ']' && ch == '[') ||
					(*pos == '}' && ch == '{'))
			{
				if(FAILED == stack_pop(&s, &ch))
				{
					printf("stack pop failed.\n");
					return -1;
				}
			}
		}
		else
			return -1;

		++pos;
	}

	if(FAILED == destroy_stack(&s))
	{
		printf("destroy stack failed.\n");
		return -1;
	}

	return 0;
}

int main(const int argc, const char* argv[])
{
	char input[256] = {0};

	while(scanf("%s", input) > 0)
	{
		if(0 == bracket_match(input))
			printf("match!\n");
		else
			printf("not match!\n");
	}

	return 0;
}
