# 开头总想写些什么

------

标签：数据结构和算法

## 为过去的时间埋单
曾经有多少美好且充足的去学习数据结构和算法的时间放在我的面前，我没有珍惜，直到一直失去的现在才追悔莫及。如果上天再给我一次重新学习数据结构和算法的机会的话，我想说我要争分夺秒的好好学，踏踏实实的学习好基础，为过去的时间好好埋单。

## 记录将要学习的征途

> - chapter01 绪论和概念
> - chapter02 线性表
> - chapter03 栈和队列
> - chapter04 串
> - chapter05 数组和广义表
> - chapter06 树和二叉树
> - chapter07 图
> - chapter08 动态存储管理
> - chapter09 查找
> - chapter10 内部排序
> - chapter11 外部排序
> - chapter12 文件

## 一些基本的数学公式
### 关于Github中无法展示数学Latex公式
Chrome浏览器安装`Github with MathJax`
安装后无法启用请打开开发者模式。

### 指数
- $X^AX^B = X^{A+B}$
- $\frac{X^A}{X^B} = X^{A-B}$
- $(X^A)^B = X^{AB}$
- $X^N + X^N = 2X^N \not= X^{2N}$
- $2^N + 2^N = 2 \times 2^N = 2^{N+1}$

### 对数
- $log_AB = \frac{log_CB}{log_cA}; C > 0$
- $logAB = logA + logB$
- $log \frac{A}{B} = logA - logB$
- $logA^B = BlogA$
- $logX < X; X > 0$
- $log$这里都是以$2$为底数的对数，也就是$log1 = 0， log2 = 1$

### 级数
- $\sum_{i=0}^{N}A^i = \frac{A^{N+1}-1}{A-1}$，如果$0 < A < 1$, 那么$i \to \infty, A^i \to 0$，上面的公式也就变成$\sum_{i=0}^{\infty}A^i = \frac{1}{1-A}$
- $\sum_{i=0}^{N}i = \frac{N(N+1)}{2} \to \frac{N^2}{2}$
- $\sum_{i=0}^{N}i^2 = \frac{N(N+1)(2N+1)}{6} \to \frac{N^3}{3}$
- $\sum_{i=0}^{N}i^k \to \frac{N^{k+1}}{|k+1|}$
- 欧拉常数：$\sum_{i=0}^{N}{\frac{1}{i}} \to log_eN$
- $\sum_{i=0}^{N}f(N) = Nf(N)$
- $\sum_{i=n_0}^{N}f(i) = \sum_{i=1}^{N}f(i) - \sum_{i=1}^{n_0-1}f(i)$

## 证明方法
### 归纳法
- 证明基准（$N=1$）情况下命题成立
- 假设有限值（$N=k$）情况下命题也成立
- 证明下一值（$N=k+1$）情况下命题也成立
- 命题得证

### 反证法
- 假设当前命题不成立
- 然后证明当前命题的一个已知的性质不成立
- 证明假设是伪命题
- 命题得证