# 线性表

标签：数据结构和算法

---

## 线性表
线性表是最简单和常用的一种数据结构，是有限个数据元素组成的序列。同一线性表中的数据元素必须具有相同的特性，也就是数据元素的类型需要一样。具体的抽象数据类型(ADT)表示如下：    
```
    ADT List {
        D: 
            // 每个数据元素
            [element];
        S: 
            // 每个数据元素的索引
            [elementIndex]
            
            // 表的长度
            [listSize]
        P:
            // 创建一个空表
            listInitialize(&l);
            
            // 销毁一个表
            listDestroy(&l);
            
            // 清空一个表
            listClear(&l);
            
            // 判断一个表是否为空
            listIsEmpty(l);
            
            // 获取表中元素的个数
            listSize(l);
            
            // 获取表中指定索引的元素
            listGet(l, i, &e);
            
            // 获取表中指定元素第一次出现的索引
            listFind(l, e);
            
            // 在表中指定索引插入元素
            listInsert(&l, i, e);
            
            // 在表中指定索引删除元素
            listRemove(&l, i, &e);
    } ADT List;
```

## 线性表的顺序表示
顺序表示就是用一组地址连续的存储单元依次存储线性表的数据元素。通常来说就是动态数组。

### 顺序表示的特征
> - 查找比较快，由于数据元素是连续存储的，因此查找只需要知道数据元素索引，根据地址偏移很快就能查找到；
> - 增删比较慢，由于在指定位置新增的时候，该位置以及以后的元素通通都要后移一位；删除也是同理。

### 部分代码实现
[完整代码](https://github.com/pengqiang-gs/algorithms/tree/master/chapter02/SequentialList)
```
// SequentialList.h [部分]

#ifndef ADT_SEQUENTIAL_LIST_H
#define ADT_SEQUENTIAL_LIST_H

// method: insert element into PositionType of sequential list.
// input : the instance of list, the PositionType of inserted element, the value of inserted element.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType listInsert(SequentialList* l, PositionType p, DataType e);

// method: remove the element from PositionType of sequential list.
// input : the instance of list, the PositionType of element, the value of removed element.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType listRemove(SequentialList* l, PositionType p, DataType* e);

#endif
```
```
// SequentialList.c[部分]

StatusType listInsert(SequentialList* l, PositionType p, DataType e)
{
	DataType* re = NULL;
	SizeType current_size = listSize(*l);
	PositionType index = p;
	
	if(p < 0 && p > (PositionType)current_size)
		return FAILED;
	
	if(current_size == l->_asize)
	{
		// realloc size.
		l->_asize += INCREASE_SIZE;
		re = (DataType*)realloc(l->_element, (l->_asize) * sizeof(DataType));
		if(re == NULL)
			return FAILED;
		
		l->_element = re;
	}
	
	// move element which is located in PositionType p to next PositionType.
	for(index = current_size - 1; index >= p; --index)
		l->_element[index+1] = l->_element[index];

	l->_element[p] = e;
	++l->_size;

	return SUCCESS;
}

StatusType listRemove(SequentialList* l, PositionType p, DataType* e)
{
	PositionType index = 0;
	SizeType current_size = listSize(*l);
	
	if(p < 0 || p >= current_size)
		return FAILED;
	
	// move element which is located in PositionType p to previous PositionType.
	for(index = p+1; index < current_size; ++index)
		l->_element[index-1] = l->_element[index];
	--l->_size;

	return SUCCESS;
}
```
## 线性表的链式表示
从上一小节示例代码可以看出，线性表的顺序存储结构不仅是逻辑关系数据元素之间相邻，物理存储上也采用连续存储，这种结构的最大弱点：在插入和删除数据元素的时候，需要移动大量的数据节点。因此线性表的另一种存储方法-链式存储应运而生。 

线性表的链式存储结构是用一组任意的存储单元存储线性表的数据元素，这些存储单元不要求是存储地址连续，但是每个存储元素除了存储本身的信息之外，还需要存储一个指示其后继数据元素的指针（称之为节点）。

### 单向链表特征
单向链表一般还会附设一个头节点（head），头节点的数据域可以不放任何信息，当然也可以放和链表有关系的其他的东西（比如链表的长度），头节点指针域如果为空，则该链表长度为`0`.    
链表由于数据元素的存储不是连续的，因此不能按照顺序存储的那样随机存取，只能从头指针出发，一路通过`next`才能找到，因此链式存储对于数据元素的访问效率很低。

### 单向链表部分实现
[完整代码](https://github.com/pengqiang-gs/algorithms/tree/master/chapter02/SinglyLinkedList)
```
// SinglyLinkedList.h [部分]

#ifndef ADT_SINGLY_LINKED_LIST_H
#define ADT_SINGLY_LINKED_LIST_H

// method: insert element into position of singly linked list.
// input : the instance of list, the position of inserted element, the value of inserted element.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType listInsert(SinglyLinkedList* l, PositionType p, DataType e);

// method: remobe the element from position of singly linked list.
// input : the instance of list, the position of element, the value of removed element.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType listRemove(SinglyLinkedList* l, PositionType p, DataType* e);

#endif
```
```
// SinglyLinkedList.c [部分]

StatusType listInsert(SinglyLinkedList* l, PositionType p, DataType e)
{
	PositionType pos = 0;
	Node* n_cur = l->_header;
	Node* n_new = NULL;

	// check the insertion boundary.
	if(p < 0 || p > listSize(*l))
		return FAILED;

	n_new = (Node*)malloc(sizeof(Node));
	if(n_new == NULL)
		return FAILED;

	n_new->_element = e;

	// look for the node which is located in position p-1
	for(pos = 0; pos < p; ++pos)
		n_cur = n_cur->_next;

	// insert new node
	n_new->_next = n_cur->_next;
	n_cur->_next = n_new;
	l->_size++;

	return SUCCESS;
}

StatusType listRemove(SinglyLinkedList* l, PositionType p, DataType* e)
{
	PositionType pos = 0;
	Node* n_cur = l->_header;
	Node* n_remove = NULL;

	// check the access boundary.
	if(p < 0 || p >= listSize(*l))
		return FAILED;

	// look for the node which is located in position p-1.
	for(pos = 0; pos < p - 1; ++pos)
		n_cur = n_cur->_next;

	n_remove = n_cur->_next;
	n_cur->_next = n_remove->_next;
	*e = n_remove->_element;
	free(n_remove);

	return SUCCESS;
}
```

### 双向链表特征
单向链表中，获取位置`pos`上的元素的时间复杂度是`O(n)`，获取下一个元素（直接`next`就可以获取）的时间复杂度是`O(1)`，获取上一个元素（需要从`header`出发再去遍历`pos-1`个节点）的时间复杂度是`O(n)`。鉴于以上的原因，**双向链表**产生了。双向链表同上面单向链表一样，也是以一个`header`的节点开头。

### 双向链表实现
[完整代码](https://github.com/pengqiang-gs/algorithms/tree/master/chapter02/DoubleLinkedList)
```
// DoubleLinkedList.h [部分]

#ifndef ADT_DOUBLE_LINKED_LIST_H
#define ADT_DOUBLE_LINKED_LIST_H

// method: insert element into position of double linked list.
// input : the instance of list, the position of inserted element, the value of inserted element.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType listInsert(DoubleLinkedList* l, PositionType p, DataType e);

// method: remove the element from position of double linked list.
// input : the instance of list, the position of element, the value of removed element.
// return: return SUCCESS if succeed, otherwise return FAILED.
StatusType listRemove(DoubleLinkedList* l, PositionType p, DataType* e);

#endif
```
```
// DoubleLinkedList.c [部分]

StatusType listInsert(DoubleLinkedList* l, PositionType p, DataType e)
{
	PositionType pos = 0;
	Node* n_cur = l->_header;
	Node* n_new = NULL;


	// check the insertion boundary
	if(p < 0 || p > listSize(*l))
		return FAILED;

	n_new = (Node*)malloc(sizeof(Node));
	if(n_new == NULL)
		return FAILED;

	n_new->_element = e;

	// looking for the node which is located in position p-1
	for(pos = 0; pos < p; ++pos)
		n_cur = n_cur->_next;

	n_new->_next = n_cur->_next;
	n_new->_previous = n_cur;
	if(n_cur->_next != NULL)
		n_cur->_next->_previous = n_new;
	n_cur->_next = n_new;
	++l->_size;

	return SUCCESS;
}

StatusType listRemove(DoubleLinkedList* l, PositionType p, DataType* e)
{
	PositionType pos = 0;
	Node* n_cur = l->_header;
	Node* n_remove = NULL;

	// check the access boundary
	if(p < 0 || p >= listSize(*l))
		return FAILED;

	// looking for the node which is located in position p-1
	for(pos = 0; pos < p; ++pos)
		n_cur = n_cur->_next;

	n_remove = n_cur->_next;
	*e = n_remove->_element;
	n_cur->_next = n_remove->_next;
	if(n_remove->_next != NULL)
		n_remove->_next->_previous = n_cur;
	free(n_remove);
	--l->_size;

	return SUCCESS;
}
```