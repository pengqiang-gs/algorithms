#include "SinglyLinkedList.h"

#include <stdlib.h>

StatusType listInitialize(SinglyLinkedList* l)
{	
	l->_header = (Node*)malloc(sizeof(Node));
	l->_header->_element = 0;
	l->_header->_next = NULL;
	l->_size = 0;

	return SUCCESS;
}

StatusType listDestroy(SinglyLinkedList* l)
{
	Node* n_cur = l->_header;
	Node* n_next = NULL;

	while(n_cur != NULL)
	{
		n_next = n_cur->_next;
		free(n_cur);
		n_cur = n_next;
	}

	return SUCCESS;
}

StatusType listClear(SinglyLinkedList* l)
{
	Node* n_cur = l->_header->_next;
	Node* n_next = NULL;

	while(n_cur != NULL)
	{
		n_next = n_cur->_next;
		free(n_cur);
		n_cur = n_next;
	}

	// reset head node
	l->_header->_next = NULL;
	l->_header->_element = 0;
	l->_size = 0;

	return SUCCESS;
}

StatusType listIsEmpty(SinglyLinkedList l)
{
	if(l._size == 0)
		return IS_TRUE;
	else
		return IS_FALSE;
}

SizeType listSize(SinglyLinkedList l)
{
	return l._size;
}

StatusType listGet(SinglyLinkedList l, PositionType p, DataType* e)
{
	Node* n_cur = l._header;
	PositionType pos = 0;

	// check the access boundary.
	if(p < 0 || p >= listSize(l))
		return FAILED;

	for(pos = 0; pos <= p; ++pos)
		n_cur = n_cur->_next;

	*e = n_cur->_element;

	return SUCCESS;
}

PositionType listFind(SinglyLinkedList l, DataType e)
{
	PositionType pos = 0;
	Node* n_cur = l._header->_next;

	while(n_cur != NULL)
	{
		if(n_cur->_element == e)
			return pos;
		pos++;
	}

	return NOT_FOUND;
}

StatusType listInsert(SinglyLinkedList* l, PositionType p, DataType e)
{
	PositionType pos = 0;
	Node* n_cur = l->_header;
	Node* n_new = NULL;

	// check the insertion boundary.
	if(p < 0 || p > listSize(*l))
		return FAILED;

	n_new = (Node*)malloc(sizeof(Node));
	if(n_new == NULL)
		return FAILED;

	n_new->_element = e;

	// look for the node which is located in position p-1
	for(pos = 0; pos < p; ++pos)
		n_cur = n_cur->_next;

	// insert new node
	n_new->_next = n_cur->_next;
	n_cur->_next = n_new;
	l->_size++;

	return SUCCESS;
}

StatusType listRemove(SinglyLinkedList* l, PositionType p, DataType* e)
{
	PositionType pos = 0;
	Node* n_cur = l->_header;
	Node* n_remove = NULL;

	// check the access boundary.
	if(p < 0 || p >= listSize(*l))
		return FAILED;

	// look for the node which is located in position p-1.
	for(pos = 0; pos < p; ++pos)
		n_cur = n_cur->_next;

	n_remove = n_cur->_next;
	n_cur->_next = n_remove->_next;
	*e = n_remove->_element;
	free(n_remove);

	return SUCCESS;
}
