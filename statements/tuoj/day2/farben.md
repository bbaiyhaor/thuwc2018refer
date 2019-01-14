


**时间限制：** 1.0 秒 


**空间限制：** 512 MB

**相关文件：** 题目目录




## 题目描述

法本公司曾经是世界最大的化工企业，他们生产的染料颜色非常丰富，有清华紫，心灵黄，原谅绿，会议蓝，高级黑，北大红，相簿白等。

现在B君有一个由$n$个区域组成的环，B君要用$m$种颜色来染这$n$个区域。

B君不希望在这$n$个区域中存在连续$m$个区域恰好出现所有$m$个颜色。换句话说，对于任意连续$m$个区域，都不能恰好出现所有$m$个颜色。

如果两个方案通过旋转可以变得一模一样，那么我们认为他们是本质相同的；

但是如果两个方案需要通过翻转才能变得一模一样，我们不认为他们是本质相同的。

比如如果$n=4, m = 4$；

我们认为$1, 2, 3, 4$和$3, 4, 1, 2$是本质相同的方案；

我们认为$1, 2, 3, 4$和$4, 3, 2, 1$是本质不同的方案；

我们认为$1, 2, 1, 2$和$2, 1, 2, 1$是本质相同的方案；

B君希望知道满足条件，本质不同的方案数，输出答案对$1000000007$取模。

## 输入格式

从标准输入读入数据。

输入一行包含两个整数$n, m$。

其中$n$表示环的长度，$m$表示颜色数。

## 输出格式

输出到标准输出。

输出一行一个整数，表示答案对$1000000007$取模的结果。






## 样例1输入

```plain
6 3

```



## 样例1输出

```plain
44

```







## 样例2输入

```plain
120 6

```



## 样例2输出

```plain
615888898

```


## 子任务

* 对于 $100\%$ 的测试点， $1 \leq n \leq 1000000000, 2 \leq m \leq 7$。

 
	


<table class="table table-bordered"><thead><tr><th rowspan="1">数据编号</th><th rowspan="1">$n$</th><th rowspan="1">$m$</th></tr></thead><tbody><tr><td rowspan="1">1</td><td rowspan="2">$1 \leq n \leq 10$</td><td rowspan="1">$m = 3$</td></tr><tr><td rowspan="1">2</td><td rowspan="1">$m = 4$</td></tr><tr><td rowspan="1">3</td><td rowspan="6">$1 \leq n \leq 10^{5}$, $n$是质数</td><td rowspan="1">$m = 2$</td></tr><tr><td rowspan="1">4</td><td rowspan="1">$m = 3$</td></tr><tr><td rowspan="1">5</td><td rowspan="1">$m = 4$</td></tr><tr><td rowspan="1">6</td><td rowspan="1">$m = 5$</td></tr><tr><td rowspan="1">7</td><td rowspan="1">$m = 6$</td></tr><tr><td rowspan="1">8</td><td rowspan="1">$m = 7$</td></tr><tr><td rowspan="1">9</td><td rowspan="6">$1 \leq n \leq 10^{9}$, $n$是质数</td><td rowspan="1">$m = 2$</td></tr><tr><td rowspan="1">10</td><td rowspan="1">$m = 3$</td></tr><tr><td rowspan="1">11</td><td rowspan="1">$m = 4$</td></tr><tr><td rowspan="1">12</td><td rowspan="1">$m = 5$</td></tr><tr><td rowspan="1">13</td><td rowspan="1">$m = 6$</td></tr><tr><td rowspan="1">14</td><td rowspan="1">$m = 7$</td></tr><tr><td rowspan="1">15</td><td rowspan="5">$1 \leq n \leq 10^{9}$</td><td rowspan="1">$m = 2$</td></tr><tr><td rowspan="1">16</td><td rowspan="1">$m = 3$</td></tr><tr><td rowspan="1">17</td><td rowspan="1">$m = 4$</td></tr><tr><td rowspan="1">18</td><td rowspan="1">$m = 5$</td></tr><tr><td rowspan="1">19</td><td rowspan="1">$m = 6$</td></tr><tr><td rowspan="1">20</td><td rowspan="1">$n = 635,643,090$</td><td rowspan="1">$m = 7$</td></tr></tbody></table> 