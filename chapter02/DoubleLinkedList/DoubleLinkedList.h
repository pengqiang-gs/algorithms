#ifndef ADT_DOUBLE_LINKED_LIST_H
#define ADT_DOUBLE_LINKED_LIST_H

typedef int DataType;
typedef int PositionType;
typedef int StatusType;
typedef int SizeType;

// declare the element node information of linked list.
typedef struct Node{
	// the element data of linked list.
	DataType _element;

	// the pointer of next node of linked list.
	struct Node* _next;

	// the pointer of previous node of linked list.
	struct Node* _previous;
}Node;

// declare the information of linked list.
typedef struct {
	// the header node of linked list.
	Node* _header;

	// the size of linked list.
	SizeType _size;
}DoubleLinkedList;


// declare other constant that will be used in singly linked list definition.
static const StatusType IS_TRUE = 1;
static const StatusType IS_FALSE = 0;
static const StatusType SUCCESS = 0;
static const StatusType FAILED = -1;
static const PositionType NOT_FOUND = -1;

// method: initialize a double linked list. 
// input : the address of list instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType listInitialize(DoubleLinkedList* l);

// method: destroy a double linked list and free the element storage space.
// input : the address of list instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType listDestroy(DoubleLinkedList* l);

// method: clear the elements of double linked list, the size of list will be 0.
// input : the address of list instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType listClear(DoubleLinkedList* l);

// method: check the double linked list is empty or not.
// input : the list object.
// return: return TRUE if the list is empty, otherwise return FALSE.
StatusType listIsEmpty(DoubleLinkedList l);

// method: obtain the element count of double linked list.
// input : the list object.
// return: the element count of list.
SizeType listSize(DoubleLinkedList l);

// method: obtain the element as e, which located in postion p of double linked list.
// input : the list object, the position of element, the element will be returned.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType listGet(DoubleLinkedList l, PositionType p, DataType* e);

// method: find the position which the element first appeared in double linked list.
// input : the list object, the element value.
// return: return the position of element in list if succeed, otherwise return NOT_FOUND.
PositionType listFind(DoubleLinkedList l, DataType e);

// method: insert element into position of double linked list.
// input : the instance of list, the position of inserted element, the value of inserted element.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType listInsert(DoubleLinkedList* l, PositionType p, DataType e);

// method: remove the element from position of double linked list.
// input : the instance of list, the position of element, the value of removed element.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType listRemove(DoubleLinkedList* l, PositionType p, DataType* e);

#endif