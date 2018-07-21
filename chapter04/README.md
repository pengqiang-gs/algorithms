# 串

标签： 数据结构和算法

---

计算机上的非数值处理的对象基本上就是字符串数据。在汇编和语言的编译环境中，源程序以及目标程序都是字符串数据。但是现今的计算机的硬件结构主要是反映数值计算的需要的，因此在处理字符串数据时比处理整数和浮点数要复杂得多。

## 串类型
串（string）是由0个或者多个字符组成的有限的序列：
    ```str = "abcdfeded"```
其中`str`是串的名称，引号中的是串的数据，`0`个字符的串称为空串。由一个或者多个字符组成的串是**空格串**，不是空串。串的抽象数据类型定义如下：

    ADT string{
        D: // 数据是字符
        S: // 每个字符属于串
        P: // 串的操作
            init_string(&s, chars); // 用一系列字符初始化串
            copy_string(&t, s); // 将串s拷贝给串t
            is_empty(s); //判断串是否为空
            compare(t, s); // 比较两个串的大小，如果t>s返回TRUE
            string_size(s); // 返回串的长度
            clear_string(&s); // 将串清空
            string_concat(&t, s1, s2); // 合并s1，s2两个串到t
            sub_string(&t, s, p, l); // 将串s的p开始的l的长度的字串给t
            string_find(s, t, p); //s中在位置pos之后查找子串t，查找到返回找到的首字符位置，没查到p就为0
            string_replace(&s, t, v); // 用串v将s中的t串替换
            string_insert(&s, p, t); // 串s中在位置p插入字串t
            string_delete(&s, p, l); // 串s中从位置p开始删除l的长度的子串
            destroy_string(&s); // 销毁串
    } ADT string;

## 串的实现
### 定长顺序存储实现
用一组连续地址的存储单元存储字符串，预先定义足够的长度来存储串，超过预定义长度的部分将发生截断。
```
#define max_string_size 255
typedef unsigned char string[max_string_size+1];
```
由于这种做法很不灵活，对于超过`max_string_size`的部分会发生截断，因此这地方不再讨论。

### 顺序存储实现
利用动态分配堆空间的方式，以一组地址连续的存储单元存放串值的字符序列，同时也约定串长度作为存储结构的一部分。
```
typedef struct {
    char* _content; // 存放串的内容
    int _size; // 存放串的长度
}string;
```
基于以上的实现具体细节，请参考[代码](https://github.com/pengqiang-gs/algorithms/tree/master/chapter03/)。

### 链式存储实现
和之前的线性表的存储结构类似，串的存储方式也可以使用链式。**教程中说的采用链块的方式这里不推荐使用，尤其是定位子串以及替换子串时性能很低下，同时也很不建议采用串的链式存储实现，因为串就是字符的集合，占用的存储本来就少，如果采用了链式存储，则大大增加了存储开销**。
```
// 定义链式的节点node
typedef struct node{
    char _ch;
    struct node* _next;
}node;

// 定义string
typedef struct {
    node* _data;
    int _size;
}string;
```
基于以上的实现，其实可以根据之前线性表的链式存储实现一样，只是链式节点`node`中的`type`由原来的`int`换成`char`即可，同时实现上述ADT结构中的关于串的一些特殊的接口。具体实现请参考[代码](https://github.com/pengqiang-gs/algorithms/tree/master/chapter03/)。

## 练习
### 库实现
- seq_string
> 顺序存储实现串ADT

