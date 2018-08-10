#ifndef ADT_SEQUENTIAL_STACK_H
#define ADT_SEQUENTIAL_STACK_H

typedef int DataType;
typedef int StatusType;
typedef int SizeType;

// declare stack information. 
typedef struct {
	// stack bottom.
	DataType* _bottom;

	// stack top.
	DataType* _top;

	// stack size.
	int _size;

	// allocated stack size.
	int _asize;
}SequentialStack;

static const int INITIAL_SIZE = 10;
static const int INCREASE_SIZE = 10;
static const int IS_TRUE = 1;
static const int IS_FALSE = 0;
static const int SUCCESS = 0;
static const int FAILED = -1;

// method: initialize a sequential stack. 
// input : the address of stack instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType stackInitialize(SequentialStack* s);

// method: destroy a sequential stack and free the element storage space.
// input : the address of stack instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType stackDestroy(SequentialStack* s);

// method: clear the elements of sequential stack, the size of stack will be 0.
// input : the address of stack instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType stackClear(SequentialStack* s);

// method: check the sequential stack is empty or not.
// input : the stack object.
// return: return TRUE if the stack is empty, otherwise return FALSE.
StatusType stackIsEmpty(SequentialStack s);

// method: obtain the element count of sequential stack.
// input : the stack object.
// return: the element count of stack.
SizeType stackSize(SequentialStack s);

// method: obtain the element of stack top.
// input : the stack object, the address of element.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType stackTop(SequentialStack s, DataType* e);

// method: pop the element of stack top.
// input : the address of stack instance, the address of element.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType stackPop(SequentialStack* s, DataType* e);

// method: push the element into stack top.
// input : the address of stack instance, element.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType stackPush(SequentialStack* s, DataType e);

#endif
