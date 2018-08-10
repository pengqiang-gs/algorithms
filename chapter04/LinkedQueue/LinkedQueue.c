#include "LinkedQueue.h"

#include <stdlib.h>

StatusType queueInitialize(LinkedQueue* q)
{
	if(q == NULL)
		return FAILED;

	q->_front = (Node*)malloc(sizeof(Node));
	if(q->_front == NULL)
		return FAILED;
	
	q->_front->_element = 0;
	q->_front->_next = NULL;
	q->_tail = q->_front;
	q->_size = 0;
	
	return SUCCESS;
}

StatusType queueDestroy(LinkedQueue* q)
{
	Node* cur = q->_front;
	Node* next = NULL;
	
	if(q == NULL || q->_front == NULL)
		return FAILED;

	while(cur != NULL)
	{
		next = cur->_next;
		free(cur);
		cur = next;
	}
	
	q->_front = NULL;
	q->_tail = NULL;

	return SUCCESS;
}

StatusType queueClear(LinkedQueue* q)
{
	Node* cur = q->_front->_next;
	Node* next = NULL;
	
	while(cur != NULL)
	{
		next = cur->_next;
		free(cur);
		cur = next;
	}
	
	q->_front->_next = NULL;
	q->_tail = q->_front;
	q->_size = 0;
	
	return SUCCESS;
}

StatusType queueIsEmpty(LinkedQueue q)
{
	if(q._size > 0)
		return IS_FALSE;
	else
		return IS_TRUE;
}

SizeType queueSize(LinkedQueue q)
{
	return q._size;
}

StatusType queueFront(LinkedQueue q, DataType* e)
{
	if(e == NULL || queueIsEmpty(q))
	{
		e = NULL;
		return FAILED;
	}
	
	*e = q._front->_next->_element;

	return SUCCESS;
}

StatusType enqueue(LinkedQueue* q, DataType e)
{
	Node* tail = NULL;

	if(q == NULL || q->_front == NULL)
		return FAILED;

	tail = (Node*)malloc(sizeof(Node));
	if(tail == NULL)
		return FAILED;

	tail->_element = e;
	tail->_next = q->_tail->_next;
	q->_tail->_next = tail;
	++(q->_size);
	
	return SUCCESS;
}

StatusType dequeue(LinkedQueue* q, DataType* e)
{
	Node* front = NULL;

	if(q == NULL || q->_front == NULL || queueIsEmpty(*q))
		return FAILED;
	
	front = q->_front->_next;
	*e = front->_element;
	q->_front->_next = front->_next;
	free(front);
	front = NULL;
	--q->_size;

	return SUCCESS;
}
