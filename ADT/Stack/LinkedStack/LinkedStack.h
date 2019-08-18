#ifndef ADT_LINKED_STACK_H
#define ADT_LINKED_STACK_H

typedef int DataType;
typedef int StatusType;
typedef int SizeType;

typedef struct Node{
	// node data
	DataType _element;

	// pointer which point to next node
	struct Node* _next;

	// pointer which point to previous node
	struct Node* _previous;
}Node;

typedef struct {
	// stack bottom
	Node* _bottom;

	// stack top
	Node* _top;

	// stack size
	SizeType _size;
}LinkedStack;

static const int IS_TRUE = 1;
static const int IS_FALSE = 0;
static const int SUCCESS = 0;
static const int FAILED = -1;

// method: initialize a linked stack. 
// input : the address of stack instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType stackInitialize(LinkedStack* s);

// method: destroy a linked stack and free the element storage space.
// input : the address of stack instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType stackDestroy(LinkedStack* s);

// method: clear the elements of linked stack, the size of stack will be 0.
// input : the address of stack instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType stackClear(LinkedStack* s);

// method: check the linked stack is empty or not.
// input : the stack object.
// return: return TRUE if the stack is empty, otherwise return FALSE.
StatusType stackIsEmpty(LinkedStack s);

// method: obtain the element count of linked stack.
// input : the stack object.
// return: the element count of stack.
SizeType stackSize(LinkedStack s);

// method: obtain the element of stack top.
// input : the stack object, the address of element.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType stackTop(LinkedStack s, DataType* e);

// method: pop the element of stack top.
// input : the address of stack instance, the address of element.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType stackPop(LinkedStack* s, DataType* e);

// method: push the element into stack top.
// input : the address of stack instance, element.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType stackPush(LinkedStack* s, DataType e);

#endif
