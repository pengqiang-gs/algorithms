#include "SequentialQueue.h"

#include <stdlib.h>

StatusType queueInitialize(SequentialQueue *q)
{
    if (q == NULL)
        return FAILED;

    q->_asize = INITIALIZE_SIZE;
    q->_element = (DataType *)malloc(q->_asize * sizeof(DataType));
    q->_size = 0;

    return SUCCESS;
}

StatusType queueDestroy(SequentialQueue *q)
{
    if (q == NULL || q->_element == NULL)
        return FAILED;

    free(q->_element);
    q->_element = NULL;

    q->_size = 0;
    q->_asize = 0;

    return SUCCESS;
}

StatusType queueClear(SequentialQueue *q)
{
    if (q == NULL || q->_element == NULL)
        return FAILED;

    q->_size = 0;
    q->_asize = 0;

    return SUCCESS;
}

StatusType queueIsEmpty(SequentialQueue q)
{
    if(q._size > 0)
        return IS_FALSE;
    else
        return IS_TRUE;
}

SizeType queueSize(SequentialQueue q)
{
    return q._size;
}

StatusType queueFront(SequentialQueue q, DataType* e)
{
    if(IS_TRUE == queueIsEmpty(q))
    {
        e = NULL;
        return FAILED;
    }

    *e = *(q._element);

    return SUCCESS;
}

StatusType enqueue(SequentialQueue* q, DataType e)
{
    DataType* re = NULL;

    if(q == NULL || q->_element == NULL)
        return FAILED;

    if(q->_size >= q->_asize)
    {
        // realloc space 
        q->_asize += INCREASE_SIZE;
        re = (DataType*)realloc(q->_element, q->_asize * sizeof(DataType));
        q->_element = re;
    }

    q->_element[q->_size] = e;
    ++q->_size;

    return SUCCESS;
}

StatusType dequeue(SequentialQueue* q, DataType* e)
{
    SizeType index = 0;

    if(q == NULL || q->_element == NULL || queueIsEmpty(*q))
        return FAILED;

    *e = q->_element[0];
    for(index = 0; index < q->_size - 1; ++index)
        q->_element[index] = q->_element[index+1];
    --q->_size;

    return SUCCESS;
}