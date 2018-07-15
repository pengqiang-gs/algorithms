# 栈和队列

标签： 数据结构和算法

---

栈和队列从数据结构层面来看，也是属于线性表，相较于前面的线性表，栈和队列的基本操作是线性表操作的子集，是属于限定性的数据结构。

## 栈
栈（Stack）是限定只在表的尾部进行插入和删除操作的线性表。因此，对于栈这种线性表来说，尾端（endpoint）具有特殊的含义，称为栈顶（top），线性表的表头端（headpoint）称为栈底（bottom）。比如
`S = (A1, A2, ..., An)`
这样的一个栈，`A1`就是栈底元素，`An`就是栈顶元素。

栈是一种后进先出`(LIFO, Last In First Out)`的数据结构，常常用来形容调度（比如车站的调度，函数的调用等）。用ADT模型表示：

    ADT stack{
        D: // 数据元素
        S: // 约定栈顶和栈底
        P：
            init_stack(&s);         // 构造一个空栈
            destroy_stack(&s);      // 销毁栈
            clear_stack(&s);        // 清空栈
            stack_empty(s);         // 是否是空栈
            stack_size(s);          // 栈中元素的个数
            stack_top(s, &e);       // 获取栈顶元素给e
            stack_pop(&s, &e);      // 栈顶弹出元素给e
            stack_push(&s, e);      // 栈顶压入元素e
    } ADT stack;
    
## 栈与递归
我们普通的函数的调用层次就用的栈数据结构，称为函数的调用栈。递归是一个直接调用自身，或者通过一系列的调用语句间接地调用自己的函数，称之为递归函数。递归函数有很广泛的应用，比如：

- 阶乘
```
int Fact(const int n)
{
    if (n <= 1)
        return 1;
    else
        return n * Fact(n-1);
}
```
- Fibonacci数列
```
int Fabonacci(const int n)
{
    if(n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return Fabonacci(n-1) + Fabonacci(n-2);
}
```
- Ackerman函数
```
int Ack(const int m, const int n)
{
    if(m == 0)
        return n+1;
    else if(n == 0)
        return Ack(m-1, 1);
    else
        return Ack(m-1, Ack(m, n-1));
}
```
- Hanoi塔
有x, y, z三根柱子，x柱子上有从小到大n个盘子，将x上的n个盘子移动到z柱子上，并且保持盘子的顺序不变，具体规则：
1. 每次只能移动一个盘子
2. 盘子可以落到x, y, z任意一根柱子上
3. z柱子上的盘子必须从小到大的顺序
```
void Hanoi(const int n, const char x, const char y, const char z)
{
    if(n == 1)
    {
        // 直接将x上的盘子移动到z上
        move(x, 1, z);
    }
    else
    {
        // 先将上面的n-1个移动到y上
        Hanoi(n-1, x, z, y);
        
        // 第N个移动到z上
        move(x, n, z);
        
        // y上的n-1个移动到z上
        Hanoi(n-1, y, x, z);
    }
}
```
## 队列
和栈相反，队列（Queue）是一种先进先出`(FIFO, First In First Out)`的线性表。队列只允许在表的一段进行插入，另一端进行删除元素。队列中，允许插入的一端称为队尾（back），允许删除的一端称为队头（front）。抽象数据类型定义：

    ADT Queue{
        D: // 数据对象
        S: // 数据关系
        P：
            init_queue(&q); // 构造一个空队列
            destroy_queu(&q); // 销毁队列
            clear_queue(&q); // 清空队列
            is_empty(q); // 判断是否为空
            queue_size(q); // 队列元素长度
            queue_head(q, &e); // 返回队头元素给e
            queue_push(&q, e); // 队尾插入元素e
            queue_pop(&q, &e); // 队头弹出元素e
    } ADT Queue;
    
**双端队列**（deque）是一种在队头和队尾两端都可以进行插入和删除的数据结构。这里不做详细描述。

和所有的线性表一样，队列也有顺序存储和链式存储两种实现方式。由于顺序存储的已知的插入/删除弊端（在头部插入/删除元素时，整个线性表其他元素均要后移/前移），队列的顺序存储的实现方式这里不再讨论。

## 练习
练习[代码](https://github.com/pengqiang-gs/algorithms/tree/master/chapter03)。
### 库实现
> - 栈的顺序存储实现 
> int_seq_stack
> - 栈的链式存储实现 
> int_link_stack
> - 队列的链式存储实现
> int_link_queue
### 应用实现
> 应用1：栈 -> 数制转换
> 应用2：栈 -> 括号匹配
> 应用3：队列 -> 排队


