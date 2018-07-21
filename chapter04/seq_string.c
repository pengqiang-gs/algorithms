#include "seq_string.h"

#include <stdlib.h>

status init_string(string* s, const char* src)
{
	length l = 0, l_alloc = string_init_size;
	char* src_temp = src;
	char* s_temp = NULL;
	
	// 获取初始字符串的长度
	while(*(src_temp++)) != '\0')
		l++;
	
	// 获取string应该初始化的长度
	while(l_alloc <= l)
		l_alloc += string_increase_size;
	
	// 初始化string
	s->_data = (char*)malloc(l_alloc*sizeof(char));
	if(s->_data == NULL)
		return FAILED;
	
	s->_size = 0;
	src_temp = src;
	s_temp = s->_data; // 保持首地址
	while(*(src_temp) != '\0')
	{
		*(s_temp++) = *(src_temp++);
		s->_size++;
	}
	s_temp[s->_size] = '\0';
	
	return SUCCESS;
}

status destroy_string(string* s)
{
	if(s->_data != NULL)
	{
		free(s->_data);
		s->data = NULL;
		s->_size = 0;
	}
	
	return SUCCESS;
}

status clear_string(string* s)
{
	memset(s->_data, 0, s->_size);
	s->_size = 0;
	return SUCCESS;
}

status copy_string(string* t, string s)
{
	if(t->_data != NULL)
		destroy_string(t);
	
	return init_string(t, s->_data);
}

int is_empty(string s)
{
	if(s->_size > 0)
		return TRUE;
	else
		return FALSE;
}

int string_compare(string t, string s)
{
	int result = 0;
	int t_size = string_size(t), s_size = string_size(s), pos = 0;
	
	for(pos = 0; pos < t_size && pos < s_size; ++pos)
	{
		if(t->_data[pos] > s->_data[pos])
			result = 1;
		else if(t->_data[pos] == s->_data[pos])
			result = 0;
		else
			result = -1;
	}
	
	if(result == 0)
	{
		t_size -= pos;
		s_size -= pos;
		if(t_size > 0)
			result = 1;
		else if(s_size > 0)
			result = -1;
		else
			result = 0;
	}
	
	return result;
}

int string_size(string s)
{
	return s->_size;
}

status string_concat(string* t, string s1, string s2)
{
	length ls = string_size(s1) + string_size(s2), lt = string_init_size;
	char* t_temp = NULL;
	char* s1_temp = s1->_data;
	char* s2_temp = s2->_data;
	
	if(t->_data != NULL)
	{
		if(FAILED == destroy_string(t))
			return FAILED;
	}
	
	while(lt <= ls)
		lt += string_increase_size;
	
	t->_data = (char*)malloc(lt * sizeof(char));
	if(t->_data == NULL)
		return FAILED;
	
	t_temp = t->_data;  // 保存首指针
	t->_size = 0;
	while(*s1_temp != '\0')
	{
		*(t_temp++) = *(s1_temp++);
		t->_size++;
	}
	
	while(*s2_temp != '\0')
	{
		*(t_temp++) = *(s2_temp++);
		t->_size++;
	}
	
	*t_temp = '\0';
	return SUCCESS;
}

status string_sub(string* t, string s, position p, length l)
{
	length lt = string_init_size, p_temp = 0;
	char* t_temp = NULL;
	
	
	if(t->_data != NULL)
	{
		if(FAILED == destroy_string(t))
			return FAILED;
	}
	
	if(p > string_size(s))
		return FAILED;
	
	while(lt <= l)
		lt += string_increase_size;
	
	t->_data = (char*)malloc(lt * sizeof(char));
	if(t->_data == NULL)
		return FAILED;
	
	t->_size = 0;
	t_temp = t->_data;
	while(*(s->_data+p+p_temp) != '\0')
	{
		*(t_temp++) = *(s->_data+p+p_temp++);
		t->_size++;
		
		if(t->_size >= l)
			break;
	}
	*t_temp = '\0';
	
	return SUCCESS;
}

position string_find(string s, string t, position p)
{
#if defined(MATCH_MODE_1)
	// 传统的逐位匹配方法，最坏情况复杂度是O(m*n)
	// m是源字符串s的长度，n是目标字符串t的长度
	int t_size = string_size(t), s_size = string_size(s);
	int l_sub = s_size - p - t_size;
	position s_pos = p, t_pos = 0;
	
	// 如果位置之后的子串已经长度不满足则直接返回
	if(l_sub < 0)
		return NOT_FOUND;
	
	while(s_pos < s_size && t_pos < t_size)
	{
		if(s._data[s_pos] == t._data[t_pos])
		{
			// 比较后继字符
			s_pos++;
			t_pos++;
		}
		else
		{
			// 回退pos到原来比较的下一位，目前已经进行了t_pos次比较
			s_pos = s_pos - t_pos + 1；
			t_pos = 0；
		}
	}

	if(t_pos >= t_size)
	{
		// 说明已经找到匹配的值了，回退pos到原来比较的值，目前已经进行了t_size次比较
		return s_pos - t_size;
	}

	return NOT_FOUND;
#elif defined(MATCH_MODE_2)
	// 克努特-莫里斯-普拉特（KMP）匹配方法，时间复杂度O(m+n)
	// 在每一趟匹配过程中出现字符不等时，不需要像mode_1一样回溯指针，而是目标串已经匹配的部分向右滑动
	// 相当于每次匹配不成功需要回溯时，只需要回溯对应的next值就可以了，具体next值的算法另外给出
#endif
}

status string_replace(string* s, string t, string v)
{
	// TODO:
	return SUCCESS;
}

status string_insert(string* s, position p, string t)
{
	// TODO:
	return SUCCESS;
}

status string_delete(string* s, position p, length l)
{
	// TODO:
	return SUCCESS;
}

void kmp_next(string s, int* next)
{
	// 此方法从字符串的模式匹配查找而来，同时next的取值只和匹配查找的模式串有关系，和源字符串无关。
	// 此算法比较复杂，以后再行补充
}