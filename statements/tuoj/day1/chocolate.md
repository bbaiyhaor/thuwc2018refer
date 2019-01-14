


**时间限制：** 5.0 秒 


**空间限制：** 512 MB

**相关文件：** 题目目录




## 题目描述

​“人生就像一盒巧克力，你永远不知道吃到的下一块是什么味道。”

​	明明收到了一大块巧克力，里面有若干小块，排成$n$行$m$列。每一小块都有自己特别的图案$c_{i,j}$，它们有的是海星，有的是贝壳，有的是海螺......其中还有一些因为挤压，已经分辨不出是什么图案了。明明给每一小块巧克力标上了一个美味值$a_{i,j}$ ( $0\leq a_{i,j} \leq10^6$ )，这个值越大，表示这一小块巧克力越美味。

​正当明明咽了咽口水，准备享用美味时，舟舟神奇地出现了。看到舟舟恳求的目光，明明决定从中选出一些小块与舟舟一同分享。

​舟舟希望这些被选出的巧克力是连通的（两块巧克力连通当且仅当他们有公共边），而且这些巧克力要包含至少$k$ ( $1\leq k\leq 5$ )种。而那些被挤压过的巧克力则是不能被选中的。

​	明明想满足舟舟的愿望，但他又有点“抠”，想将美味尽可能多地留给自己。所以明明希望选出的巧克力块数能够尽可能地少。如果在选出的块数最少的前提下，美味值的中位数（我们定义$n$个数的中位数为第$\left \lfloor \frac{n+1}{2}\right\rfloor$小的数）能够达到最小就更好了。

​	你能帮帮明明吗？

## 输入格式

从标准输入读入数据。

​	每个测试点包含多组测试数据。

​	输入第一行包含一个正整数 $T$ ($1\leq T \leq 5$)，表示测试数据组数。

​	对于每组测试数据：

​	输入第一行包含三个正整数$n,m$和$k$；

​	接下来$n$行，每行$m$个整数，表示每小块的图案$c_{i,j}$。若$c_{i,j}=-1$表示这一小块受到过挤压，不能被选中；

​	接下来$n$行，每行$m$个整数，表示每个小块的美味值$a_{i,j}$。

## 输出格式

输出到标准输出。

​	输出共包括$T$行，每行包含两个整数，用空格隔开，即最少的块数和最小的美味值中位数。

​	若对于某组测试数据，不存在任意一种合法的选取方案，请在对应行输出两个$-1$。







## 样例输入

```plain
1
5 4 5
3 4 3 4
5 5 -1 5
-1 4 5 5
5 5 4 2
1 -1 2 4
1 3 1 1
3 2 3 3
4 4 4 5
8 9 9 5
7 2 6 3
```



## 样例输出

```plain
9 5
```


## 子任务

 
	


<table class="table table-bordered"><thead><tr><th rowspan="1">测试点编号</th><th rowspan="1">$n,m$的限制</th><th rowspan="1">$c_{i,j}$的限制</th><th rowspan="1">部分分说明</th></tr></thead><tbody><tr><td rowspan="1">1</td><td rowspan="1">$n = 1, 1\leq m \leq 233$</td><td rowspan="6">$c_{i,j} = -1$或$1\leq c_{i,j} \leq n \times m$</td><td rowspan="10">若输出的最少块数均正确，但最小中位数存在错误，选手可以获得该测试点$80\%$的分数。</td></tr><tr><td rowspan="1">2</td><td rowspan="1">$1\leq n\times m \le 20$</td></tr><tr><td rowspan="1">3</td><td rowspan="2">$n = 2, m = 15$</td></tr><tr><td rowspan="1">4</td></tr><tr><td rowspan="1">5</td><td rowspan="2">$1\leq n\times m \leq 30$</td></tr><tr><td rowspan="1">6</td></tr><tr><td rowspan="1">7</td><td rowspan="3">$1 \leq n\times m \leq 50$</td><td rowspan="6">$c_{i,j} = -1$或$1\leq c_{i,j} \leq 8$</td></tr><tr><td rowspan="1">8</td></tr><tr><td rowspan="1">9</td></tr><tr><td rowspan="1">10</td><td rowspan="11">$ 1 \leq n\times m \leq 233$</td></tr><tr><td rowspan="1">11</td><td rowspan="10">若输出的最少块数均正确，但最小中位数存在错误，选手可以获得该测试点$60\%$的分数。</td></tr><tr><td rowspan="1">12</td></tr><tr><td rowspan="1">13</td><td rowspan="3">$c_{i,j} = -1$或$1\leq c_{i,j} \leq 14$</td></tr><tr><td rowspan="1">14</td></tr><tr><td rowspan="1">15</td></tr><tr><td rowspan="1">16</td><td rowspan="5">$c_{i,j} = -1$或$1\leq c_{i,j} \leq n \times m$</td></tr><tr><td rowspan="1">17</td></tr><tr><td rowspan="1">18</td></tr><tr><td rowspan="1">19</td></tr><tr><td rowspan="1">20</td></tr></tbody></table> 