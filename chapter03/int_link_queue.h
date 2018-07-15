#ifndef ADT_INT_LINK_QUEUE_H
#define ADT_INT_LINK_QUEUE_H

typedef int type;
typedef int status;

typedef struct node{
	type _element; 			// node data area.
	struct node* _next;		// node pointer area, point to next node.
}node;

typedef struct {
	node* _front; 		// queue bottom.
	node* _end; 		// queue top.
	int _size; 			// queue size.
}queue;


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


// method: initialize a link queue. 
// input : the address of queue instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
status init_queue(queue* q);

// method: destroy a link queue and free the element storage space.
// input : the address of queue instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
status destroy_queue(queue* q);

// method: clear the elements of link queue, the size of queue will be 0.
// input : the address of queue instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
status clear_queue(queue* q);

// method: check the link queue is empty or not.
// input : the queue object.
// return: return TRUE if the queue is empty, otherwise return FALSE.
int is_empty(queue q);

// method: obtain the element count of link queue.
// input : the queue object.
// return: the element count of queue.
int queue_size(queue q);

// method: obtain the element of queue top and assign it to e.
// input : the queue object, the address of element.
// return: return SUCCESS if succeed, otherwise return FAILED.
status queue_head(queue q, type* e);

// method: pop the element of queue top and assign it to e.
// input : the address of queue instance, the address of element.
// return: return SUCCESS if succeed, otherwise return FAILED.
status queue_pop(queue* q, type* e);

// method: push the element e into queue top.
// input : the address of queue instance, element.
// return: return SUCCESS if succeed, otherwise return FAILED.
status queue_push(queue* q, type e);

#endif
