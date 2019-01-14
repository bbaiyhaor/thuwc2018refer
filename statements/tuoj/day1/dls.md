


**时间限制：** 5.0 秒 


**空间限制：** 512 MB

**相关文件：** 题目目录




## 题目描述

杜老师可是要打$+\infty$年$World~Final$的男人，虽然规则不允许，但是可以改啊！

但是今年$WF$跟$THUSC$的时间这么近，所以他造了一个$idea$就扔下不管了……

给定$L,R$，求从$L$到$R$的这$R-L+1$个数中能选出多少个不同的子集，满足子集中所有的数的乘积是一个完全平方数。特别地，空集也算一种选法，定义其乘积为$1$。

由于杜老师忙于跟陈老师和鏼老师一起打$ACM$竞赛，所以，你能帮帮杜老师写写标算吗？

## 输入格式

从标准输入读入数据。

每个测试点包含多组测试数据。

输入第一行包含一个正整数 $T(1\le T\le 100)$，表示测试数据组数。

接下来$T$行，第$i+1$行两个正整数$L_i,R_i$表示第 $i$ 组测试数据的 $L,R$ ，保证$1\le L_i\le R_i\le 10^{7}$。

## 输出格式

输出到标准输出。

输出$T​$行，每行一个非负整数，表示一共可以选出多少个满足条件的子集，答案对$998244353​$取模。






## 样例1输入

```plain
3
1 8
12 24
1 1000000

```



## 样例1输出

```plain
16
16
947158782

```
## 样例2

见题目目录下的 *2.in* 与 *2.ans*。

## 样例解释

对于 $L=1,R=8$，对应的$16$种选法为：

1. 空集
2. 4 
3. 3 6 8 
4. 3 4 6 8 
5. 2 8 
6. 2 4 8 
7. 2 3 6 
8. 2 3 4 6 
9. 1 
10. 1 4 
11. 1 3 6 8 
12. 1 3 4 6 8 
13. 1 2 8 
14. 1 2 4 8 
15. 1 2 3 6 
16. 1 2 3 4 6 

## 子任务

 
	


<table class="table table-bordered"><thead><tr><th rowspan="1">测试点</th><th rowspan="1">$R_i$</th><th rowspan="1">$T$</th><th rowspan="1">$\sum_{i=1}^T R_i-L_i+1$</th><th rowspan="1">特殊约束</th></tr></thead><tbody><tr><td rowspan="1">1,2</td><td rowspan="1">$\le 30$</td><td rowspan="8">$\le 10$</td><td rowspan="5">$\le 10^{3}$</td><td rowspan="1">无特殊约束</td></tr><tr><td rowspan="1">3</td><td rowspan="2">$\le 10^{2}$</td><td rowspan="1">保证答案不超过$5 \times 10^{6}$</td></tr><tr><td rowspan="1">4</td><td rowspan="1">无特殊约束</td></tr><tr><td rowspan="1">5,6</td><td rowspan="3">$\le 10^{3}$</td><td rowspan="1">$R_i-L_i\le 22$</td></tr><tr><td rowspan="1">7,8</td><td rowspan="1">保证答案不超过$2 \times 10^{6}$</td></tr><tr><td rowspan="1">9,10</td><td rowspan="1">$\le 5,000$</td><td rowspan="1">无特殊约束</td></tr><tr><td rowspan="1">11,12</td><td rowspan="2">$\le 10^{6}$</td><td rowspan="3">$\le 10^{7}$</td><td rowspan="1">$R_i-L_i\ge 999,990$</td></tr><tr><td rowspan="1">13,14</td><td rowspan="7">无特殊约束</td></tr><tr><td rowspan="1">15</td><td rowspan="6">$\le 10^{7}$</td><td rowspan="6">$\le 100$</td></tr><tr><td rowspan="1">16</td><td rowspan="1">$\le 2 \times 10^{7}$</td></tr><tr><td rowspan="1">17</td><td rowspan="1">$\le 3 \times 10^{7}$</td></tr><tr><td rowspan="1">18</td><td rowspan="1">$\le 4 \times 10^{7}$</td></tr><tr><td rowspan="1">19</td><td rowspan="1">$\le 5 \times 10^{7}$</td></tr><tr><td rowspan="1">20</td><td rowspan="1">$\le 6 \times 10^{7}$</td></tr></tbody></table> 