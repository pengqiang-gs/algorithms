#ifndef ADT_INT_LINK_STACK_H
#define ADT_INT_LINK_STACK_H

typedef int type;
typedef int status;

typedef struct node{
	type _element; 			// node data area.
	struct node* _next;		// node pointer area, point to next node.
	struct node* _previous;	// node pointer area, point to previous node.
}node;

typedef struct {
	node* _bottom; 		// stack bottom.
	node* _top; 		// stack top.
	int _size; 			// stack size.
}stack;

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


// method: initialize a link stack. 
// input : the address of stack instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
status init_stack(stack* s);

// method: destroy a link stack and free the element storage space.
// input : the address of stack instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
status destroy_stack(stack* s);

// method: clear the elements of link stack, the size of stack will be 0.
// input : the address of stack instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
status clear_stack(stack* s);

// method: check the link stack is empty or not.
// input : the stack object.
// return: return TRUE if the stack is empty, otherwise return FALSE.
int is_empty(stack s);

// method: obtain the element count of link stack.
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
