# 队列

标签： 数据结构和算法

---

## 队列
和栈相反，队列（Queue）是一种先进先出`(FIFO, First In First Out)`的线性表。队列只允许在表的一段进行插入，另一端进行删除元素。队列中，允许插入的一端称为队尾（back），允许删除的一端称为队头（front）。抽象数据类型定义：
```
    ADT Queue{
        D:
            // 队列元素
            [element];
        S:
            // 队列长度
            [size]
        P：
            // 初始化一个空队列
            queueInitialize(&q);
            
            // 销毁队列
            queueDestroy(&q);
            
            // 清空队列
            queueClear(&q);
            
            // 判断队列是否为空
            queueIsEmpty(q);
            
            // 获取队列长度
            queueSize(q);
            
            // 获取队列的第一个元素
            queueFront(q, &e);
            
            // 进队
            enqueue(&q, e);
            
            // 出队
            dequeue(&q, &e);
    } ADT Queue;
``` 

## 双端队列
**双端队列**（deque）是一种在队头和队尾两端都可以进行插入和删除的数据结构。这里不做详细描述。

## 队列实现
和所有的线性表一样，队列也有顺序存储和链式存储两种实现方式。顺序存储的已知的插入/删除弊端（在头部插入/删除元素时，整个线性表其他元素均要后移/前移），同样在队列中也存在，入队只是在队尾插入，出队只是在队头删除（类比现实生活中的排队情况，如果队头出队了，所有人都向对头方向移动一个人的位置）。

### 队列顺序存储实现
查看[完整代码](https://github.com/pengqiang-gs/algorithms/tree/master/chapter04/SequentialQueue)。
```
// SequentialQueue.h [部分]

#ifndef ADT_SEQUENTIAL_QUEUE_H
#define ADT_SEQUENTIAL_QUEUE_H
// declare the sequential queue structure.
typedef struct {
    // the array elements of sequential queue.
    DataType* _element;

    // the sequential queue size.
    SizeType _size;

    // the alloc space size.
    SizeType _asize;
}SequentialQueue;

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
```
```
// SequentialQueue.c [部分]


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
```
```
// 测试实例
//
// 模拟打印机的作业
// 
#include "SequentialQueue.h"

#include <stdio.h>

int main(const int argc, const char* argv[])
{
    SequentialQueue q;
    DataType e;

    printf("print the files which numbered [5, 3, 7] start...\n");
    printf("initialize printer...\n");
    if(FAILED == queueInitialize(&q))
    {
        printf("printer initialize failed. break!\n");
        return -1;
    }

    printf("initialize printer success, add task numbered 5.\n");
    if(FAILED == enqueue(&q, 5))
    {
        printf("add task numbered 5 failed. break!\n");
        return -1;
    }

    printf("add task numbered 5 success, current working task: %d\n", queueSize(q));
    printf("add task numbered 3.\n");
    if(FAILED == enqueue(&q, 3))
    {
        printf("add task numbered 3 failed, break!\n");
        return -1;
    }

    printf("add task numbered 3 success, current working task: %d\n", queueSize(q));
    printf("remove task numbered 5 because it is completed.\n");
    if(FAILED == dequeue(&q, &e))
    {
        printf("remove task numberd 5 failed. break!\n");
        return -1;
    }

    printf("remove task numbered 5 success, current working task: %d\n", queueSize(q));
    printf("add task numbered 7.\n");
    if(FAILED == enqueue(&q, 7))
    {
        printf("add task numbered 7 failed. break!\n");
        return -1;
    }

    printf("add task numbered 7 success, current working task: %d\n", queueSize(q));
    printf("wait...\n");
    if(FAILED == queueClear(&q))
    {
        printf("printer clear task failed. break!\n");
        return -1;
    }

    printf("current working task: %d, all task has been completed.\n", queueSize(q));
    printf("print numbered files finish.\n");

    if(FAILED == queueDestroy(&q))
    {
        printf("destroy print queue failed.\n");
        return -1;
    }

    return 0;
}
```
```
// 测试实例输出结果：

print the files which numbered [5, 3, 7] start...
initialize printer...
initialize printer success, add task numbered 5.
add task numbered 5 success, current working task: 1
add task numbered 3.
add task numbered 3 success, current working task: 2
remove task numbered 5 because it is completed.
remove task numbered 5 success, current working task: 1
add task numbered 7.
add task numbered 7 success, current working task: 2
wait...
current working task: 0, all task has been completed.
print numbered files finish.
```

### 队列链式存储实现
查看[完整代码](https://github.com/pengqiang-gs/algorithms/tree/master/chapter04/LinkedQueue)。

```
// LinkedQueue.h [部分]

#ifndef ADT_LINKED_QUEUE_H
#define ADT_LINKED_QUEUE_H

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
```
```
// LinkedQueue.c [部分]


StatusType queueFront(LinkedQueue q, DataType* e)
{
	if(e == NULL || queueIsEmpty(q))
	{
		e = NULL;
		return FAILED;
	}
	
	*e = q._front->_next->_element;

	return SUCCESS;
}

StatusType enqueue(LinkedQueue* q, DataType e)
{
	Node* tail = NULL;

	if(q == NULL || q->_front == NULL)
		return FAILED;

	tail = (Node*)malloc(sizeof(Node));
	if(tail == NULL)
		return FAILED;

	tail->_element = e;
	tail->_next = q->_tail->_next;
	q->_tail->_next = tail;
	++(q->_size);
	
	return SUCCESS;
}

StatusType dequeue(LinkedQueue* q, DataType* e)
{
	Node* front = NULL;

	if(q == NULL || q->_front == NULL || queueIsEmpty(*q))
		return FAILED;
	
	front = q->_front->_next;
	*e = front->_element;
	q->_front->_next = front->_next;
	free(front);
	front = NULL;
	--q->_size;

	return SUCCESS;
}

```
```
// 测试案例同上
//
// 输出结果同上
```