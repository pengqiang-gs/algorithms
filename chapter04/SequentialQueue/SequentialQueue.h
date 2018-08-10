#ifndef ADT_SEQUENTIAL_QUEUE_H
#define ADT_SEQUENTIAL_QUEUE_H

typedef int DataType;
typedef int StatusType;
typedef int SizeType;

// declare the sequential queue structure.
typedef struct {
    // the array elements of sequential queue.
    DataType* _element;

    // the sequential queue size.
    SizeType _size;

    // the alloc space size.
    SizeType _asize;
}SequentialQueue;

// constants will be used in definition.
static const SizeType INITIALIZE_SIZE = 10;
static const SizeType INCREASE_SIZE = 10;
static const StatusType IS_TRUE = 1;
static const StatusType IS_FALSE = 0;
static const StatusType SUCCESS = 0;
static const StatusType FAILED = -1;

///////////////////////////////////////////////////////////////
// declare the operation of sequential queue.
///////////////////////////////////////////////////////////////

// method: initialize a sequential queue.
// input : the address of sequential queue.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType queueInitialize(SequentialQueue* q);

// method: destroy a sequential queue.
// input : the address of sequential queue.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType queueDestroy(SequentialQueue* q);

// method: clear a sequential queue.
// input : the address of sequential queue.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType queueClear(SequentialQueue* q);

// method: check the sequential queue is empty or not.
// input : the instance of sequential queue.
// return: return IS_TRUE if empty, otherwise return IS_FALSE.
StatusType queueIsEmpty(SequentialQueue q);

// method: obtain the size of sequential queue.
// input : the instance of sequential queue.
// return: the specific size of sequential queue.
SizeType queueSize(SequentialQueue q);

// method: obtain the first element of sequential queue.
// input : the instance of sequential queue, the address of value which will be assigned.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType queueFront(SequentialQueue q, DataType* e);

// method: insert a element into tail of sequential queue.
// input : the address of sequential queue, the instance of value which will be inserted.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType enqueue(SequentialQueue* q, DataType e);

// method: delete a element from header of sequential queue.
// input : the address of sequential queue, the address of value(deleted).
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType dequeue(SequentialQueue* q, DataType* e);

#endif