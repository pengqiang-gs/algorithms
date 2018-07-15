#include "int_link_queue.h"

#include <stdlib.h>

status init_queue(queue* q)
{
	q->_front = (node*)malloc(sizeof(node));
	if(q->_front == NULL)
		return FAILED;
	
	q->_end = q->_front;
	q->_size = 0;
	
	return SUCCESS;
}

status destroy_queue(queue* q)
{
	node* n_cur = q->_front;
	node* next = NULL;
	
	while(n_cur != NULL)
	{
		next = n_cur->_next;
		free(n_cur);
		n_cur = next;
	}
	
	q->_front = NULL;
	q->_end = NULL;
	return SUCCESS;
}

status clear_queue(queue* q)
{
	node* n_cur = q->_front->_next;
	node* next = NULL;
	
	while(n_cur != NULL)
	{
		next = n_cur->_next;
		free(n_cur);
		n_cur = next;
	}
	
	q->_front->_next = NULL;
	q->_end = q->_front;
	q->_size = 0;
	
	return SUCCESS;
}

int is_empty(queue q)
{
	if(q._size > 0)
		return FALSE;
	else
		return TRUE;
}

int queue_size(queue q)
{
	return q._size;
}

status queue_head(queue q, type* e)
{
	if(is_empty(q))
	{
		e = NULL;
		return FAILED;
	}
	
	*e = q._front->_next->_element;
	return SUCCESS;
}

status queue_pop(queue* q, type* e)
{
	node* n_cur = NULL;

	if(is_empty(*q))
	{
		e = NULL;
		return FAILED;
	}
	
	*e = q->_front->_next->_element;
	n_cur = q->_front->_next;
	q->_front->_next = n_cur->_next;
	free(n_cur);
	n_cur = NULL;
	--(q->_size);
	return SUCCESS;
}

status queue_push(queue* q, type e)
{
	node* end = NULL;
	node* n_new = (node*)malloc(sizeof(node));
	if(n_new == NULL)
		return FAILED;

	q->_end->_next = n_new;
	n_new->_element = e;
	n_new->_next = NULL;
	q->_end = n_new;
	++(q->_size);
	
	return SUCCESS;
}
