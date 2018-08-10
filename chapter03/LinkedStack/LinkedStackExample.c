// 
// 一个输入的字符串表达式中包含小括号，中括号，大括号
// (), [], {}, ([]), ({}), [{}], ({{[]}})这种都是匹配正确的
// (], {)]} 这中都是匹配不正确的
// 
// 写一个程序，验证输入的一串括号是否匹配。
// 输入非括号内容要求提示"输入错误"并且退出程序
// 

#include "LinkedStack.h"

#include <stdio.h>

int is_bracket_input(const char* src)
{
	int index = 0;

	for(index = 0; *(src+index) != '\0'; ++index)
	{
		if(*(src+index) != '(' && *(src+index) != ')' &&
		*(src+index) != '[' && *(src+index) != ']' &&
		*(src+index) != '{' && *(src+index) != '}')
			return 0;
	}

	return 1;
}

int bracket_match(const char* src)
{
	const char* pos = src;
	int ch;

	LinkedStack s;
	if(FAILED == stackInitialize(&s))
	{
		printf("init stack failed.\n");
		return -1;
	}

	while(*pos != '\0')
	{
		if(*pos == '(' || *pos == '[' || *pos == '{')
		{
			if(FAILED == stackPush(&s, *pos))
			{
				printf("stack push %c failed.\n", *pos);
				return -1;
			}
		}
		else if(*pos == ')' || *pos == ']' || *pos == '}')
		{
			if(FAILED == stackTop(s, &ch))
			{
				printf("stack top failed.\n");
				return -1;
			}

			if((*pos == ')' && ch == '(') ||
					(*pos == ']' && ch == '[') ||
					(*pos == '}' && ch == '{'))
			{
				if(FAILED == stackPop(&s, &ch))
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

	// not match while the stack is not empty!
	if(IS_FALSE == stackIsEmpty(s))
		return -1;

	if(FAILED == stackDestroy(&s))
	{
		printf("destroy stack failed.\n");
		return -1;
	}

	return 0;
}

int main(const int argc, const char* argv[])
{
	char input[256] = {0};

	while(1)
	{
		scanf("%s", input);
		if(0 == is_bracket_input(input))
		{
			printf("输入错误\n");
			return -1;
		}
		
		if(0 == bracket_match(input))
			printf("match!\n");
		else
			printf("not match!\n");
	}

	return 0;
}
