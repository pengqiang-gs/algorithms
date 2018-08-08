#ifndef ADT_SEQUENTIAL_LIST_H
#define ADT_SEQUENTIAL_LIST_H

// declare data type of sequential list element.
typedef int DataType;

// declare PositionType type of sequential list element.
typedef int PositionType;

// declare return type of sequential list operation.
typedef int StatusType;

// declare size type of sequential list.
typedef int SizeType;

// declare type of sequential list.
typedef struct {
	// element node base address.
	DataType* _element;

	// element count of sequential list.
	SizeType _size;

	// capacity of alloc
	SizeType _asize;
}SequentialList;

// declare other constant that will be used in sequential list definition.
static const SizeType INITIAL_SIZE = 10;
static const SizeType INCREASE_SIZE = 10;
static const StatusType IS_TRUE = 1;
static const StatusType IS_FALSE = 0;
static const StatusType SUCCESS = 0;
static const StatusType FAILED = -1;
static const PositionType NOT_FOUND = -1;

//////////////////////////////////////////////////////////////////////////
// declare all operation of sequential list.
/////////////////////////////////////////////////////////////////////////

// method: initialize a sequential list. 
// input : the address of list instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType listInitialize(SequentialList* l);

// method: destroy a sequential list and release resources.
// input : the address of list instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType listDestroy(SequentialList* l);

// method: clear the elements of sequential list, the size of list will be 0.
// input : the address of list instance.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType listClear(SequentialList* l);

// method: check the sequential list is empty or not.
// input : the list object.
// return: return IS_TRUE if the list is empty, otherwise return IS_FALSE.
StatusType listIsEmpty(SequentialList l);

// method: obtain the element count of sequential list.
// input : the list object.
// return: the element count of list.
SizeType listSize(SequentialList l);

// method: obtain the element as e, which located in postion p of sequential list.
// input : the list object, the PositionType of element, the element will be returned.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType listGet(SequentialList l, PositionType p, DataType* e);

// method: find the PositionType where the element first appeared.
// input : the list object, the element value.
// return: return the PositionType of element in list if succeed, otherwise return NOT_FOUND.
PositionType listFind(SequentialList l, DataType e);

// method: insert element into PositionType of sequential list.
// input : the instance of list, the PositionType of inserted element, the value of inserted element.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType listInsert(SequentialList* l, PositionType p, DataType e);

// method: remove the element from PositionType of sequential list.
// input : the instance of list, the PositionType of element, the value of removed element.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType listRemove(SequentialList* l, PositionType p, DataType* e);

#endif