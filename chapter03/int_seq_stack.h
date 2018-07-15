#ifndef ADT_INT_SEQ_STACK_H
#define ADT_INT_SEQ_STACK_H

typedef int type;
typedef int status;

typedef struct {
	type* _bottom; 		// stack bottom.
	type* _top; 		// stack top.
	int _size; 			// stack size.
	int _asize;			// allocated stack size.
}stack;

#define stack_init_size      10
#define stack_increase_size  10


#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef SUCCESS
#define SUCCESS 0
#endif

#ifndef FAILED
#define FAILED -1
#endif


// method: initialize a sequential stack. 
// input : the address of stack instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
status init_stack(stack* s);

// method: destroy a sequential stack and free the element storage space.
// input : the address of stack instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
status destroy_stack(stack* s);

// method: clear the elements of sequential stack, the size of stack will be 0.
// input : the address of stack instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
status clear_stack(stack* s);

// method: check the sequential stack is empty or not.
// input : the stack object.
// return: return TRUE if the stack is empty, otherwise return FALSE.
int is_empty(stack s);

// method: obtain the element count of sequential stack.
// input : the stack object.
// return: the element count of stack.
int stack_size(stack s);

// method: obtain the element of stack top and assign it to e.
// input : the stack object, the address of element.
// return: return SUCCESS if succeed, otherwise return FAILED.
status stack_top(stack s, type* e);

// method: pop the element of stack top and assign it to e.
// input : the address of stack instance, the address of element.
// return: return SUCCESS if succeed, otherwise return FAILED.
status stack_pop(stack* s, type* e);

// method: push the element e into stack top.
// input : the address of stack instance, element.
// return: return SUCCESS if succeed, otherwise return FAILED.
status stack_push(stack* s, type e);

#endif
