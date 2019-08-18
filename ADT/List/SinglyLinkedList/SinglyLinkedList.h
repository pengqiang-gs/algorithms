#ifndef ADT_SINGLY_LINKED_LIST_H
#define ADT_SINGLY_LINKED_LIST_H

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
}Node;

// declare the information of linked list.
typedef struct {
	// the header node of linked list.
	Node* _header;

	// the size of linked list.
	SizeType _size;
}SinglyLinkedList;

// declare other constant that will be used in singly linked list definition.
static const StatusType IS_TRUE = 1;
static const StatusType IS_FALSE = 0;
static const StatusType SUCCESS = 0;
static const StatusType FAILED = -1;
static const PositionType NOT_FOUND = -1;

// method: initialize a singly linked list. 
// input : the address of list instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType listInitialize(SinglyLinkedList* l);

// method: destroy a singly linked list and free the element storage space.
// input : the address of list instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType listDestroy(SinglyLinkedList* l);

// method: clear the elements of singly linked list, the size of list will be 0.
// input : the address of list instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType listClear(SinglyLinkedList* l);

// method: check the singly linked list is empty or not.
// input : the list object.
// return: return TRUE if the list is empty, otherwise return FALSE.
StatusType listIsEmpty(SinglyLinkedList l);

// method: obtain the element count of singly linked list.
// input : the list object.
// return: the element count of list.
SizeType listSize(SinglyLinkedList l);

// method: obtain the element as e, which located in postion p of singly linked list.
// input : the list object, the position of element, the element will be returned.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType listGet(SinglyLinkedList l, PositionType p, DataType* e);

// method: find the position which the element first appeared in singly linked list.
// input : the list object, the element value.
// return: return the position of element in list if succeed, otherwise return NOT_FOUND.
PositionType listFind(SinglyLinkedList l, DataType e);

// method: insert element into position of singly linked list.
// input : the instance of list, the position of inserted element, the value of inserted element.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType listInsert(SinglyLinkedList* l, PositionType p, DataType e);

// method: remobe the element from position of singly linked list.
// input : the instance of list, the position of element, the value of removed element.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType listRemove(SinglyLinkedList* l, PositionType p, DataType* e);

#endif