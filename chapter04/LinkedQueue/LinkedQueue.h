#ifndef ADT_LINKED_QUEUE_H
#define ADT_LINKED_QUEUE_H

typedef int DataType;
typedef int StatusType;
typedef int SizeType;

// declare linked queue node structure.
typedef struct Node{
	// element data of linked queue.
	DataType _element;

	// pointer that point to next node of linked queue.
	struct Node* _next;
}Node;

// declate linked queue structure.
typedef struct {
	// header of linked queue.
	Node* _front;

	// tail of linked queue.
	Node* _tail;
	
	// size of linked queue.
	SizeType _size;
}LinkedQueue;

// constant will be used in definition of linked queue.
static const StatusType IS_TRUE = 1;
static const StatusType IS_FALSE = 0;
static const StatusType SUCCESS = 0;
static const StatusType FAILED = -1;

////////////////////////////////////////////////////////////
// operation declaration of linked queue.
///////////////////////////////////////////////////////////

// method: initialize a link queue. 
// input : the address of linked queue.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType queueInitialize(LinkedQueue* q);

// method: destroy a link queue and free the element storage space.
// input : the address of linked queue.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType queueDestroy(LinkedQueue* q);

// method: clear the elements of linked queue.
// input : the address of linked queue.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType queueClear(LinkedQueue* q);

// method: check the linked queue is empty or not.
// input : the instance of linked queue.
// return: return TRUE if the queue is empty, otherwise return FALSE.
StatusType queueIsEmpty(LinkedQueue q);

// method: obtain the size of linked queue.
// input : the instance of linked queue.
// return: the size of linked queue.
SizeType queueSize(LinkedQueue q);

// method: obtain the first element of linked queue and assign it to e.
// input : the instance of linked queue, the address of value.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType queueFront(LinkedQueue q, DataType* e);

// method: insert a element into tail of linked queue.
// input : the address of linked queue, the instance of value which will be inserted.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType enqueue(LinkedQueue* q, DataType e);

// method: delete a element from header of linked queue.
// input : the address of linked queue, the address of value(deleted).
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType dequeue(LinkedQueue* q, DataType* e);

#endif
