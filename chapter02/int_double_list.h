#ifndef ADT_INT_SINGLE_LIST_H
#define ADT_INT_SINGLE_LIST_H

typedef int type;
typedef int position;
typedef int status;

typedef struct node{
	type _element; 			// element node base address.
	struct node* _next;		// pointer to next node.
	struct node* _previous;	// pointer to previous node.
}node;

typedef struct {
	int _size;				// size
	node* _header;			// header
}list;

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

#ifndef NOT_FOUND
#define NOT_FOUND -1
#endif

// method: initialize a single list. 
// input : the address of list instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
status init_list(list* l);

// method: destroy a single list and free the element storage space.
// input : the address of list instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
status destroy_list(list* l);

// method: clear the elements of single list, the size of list will be 0.
// input : the address of list instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
status clear_list(list* l);

// method: check the single list is empty or not.
// input : the list object.
// return: return TRUE if the list is empty, otherwise return FALSE.
int list_empty(list l);

// method: obtain the element count of single list.
// input : the list object.
// return: the element count of list.
int list_length(list l);

// method: obtain the element as e, which located in postion p of single list.
// input : the list object, the position of element, the element will be returned.
// return: return SUCCESS if succeed, otherwise return FAILED.
status list_get(list l, position p, type* e);

// method: locate the element position.
// input : the list object, the element value.
// return: return the position of element in list if succeed, otherwise return NOT_FOUND.
position list_locate(list l, type e);

// method: insert element into position of single list.
// input : the instance of list, the position of inserted element, the value of inserted element.
// return: return SUCCESS if succeed, otherwise return FAILED.
status list_insert(list* l, position p, type e);

// method: remobe the element from position of single list.
// input : the instance of list, the position of element, the value of removed element.
// return: return SUCCESS if succeed, otherwise return FAILED.
status list_remove(list* l, position p, type* e);

#endif