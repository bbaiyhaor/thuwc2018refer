{{ self.title() }}

## 题目描述

{{ render(json.dumps('<del>中二病患者</del>'), 'md') }}{{ render(json.dumps('\\sout{中二病患者}'), 'tex') }} 大魔法师小L 制作了 $n$ 个魔力水晶球，每个水晶球有水、火、土三个属性的能量值。小L把这 $n$ 个水晶球在地上从前向后排成一行，然后开始今天的魔法表演。

我们用 $A_i$, $B_i$, $C_i$ 分别表示从前向后第 $i$ 个水晶球（下标从 $1$ 开始）的水、火、土的能量值。

小L计划施展 $m$ 次魔法。每次，他会选择一个区间 $[l, r]$，然后施展以下 $3$ 大类、 $7$ 种魔法之一：

1. 魔力激发：令区间里每个水晶球中**特定属性**的能量爆发，从而使另一个**特定属性**的能量增强。具体来说，有以下三种可能的表现形式：

   * 火元素激发水元素能量：令 $A_i = A_i + B_i$。
   * 土元素激发火元素能量：令 $B_i = B_i + C_i$。
   * 水元素激发土元素能量：令 $C_i = C_i + A_i$。

   **需要注意的是，增强一种属性的能量并不会改变另一种属性的能量，例如 $A_i = A_i + B_i$ 并不会使 $B_i$ 增加或减少。**

2. 魔力增强：小L挥舞法杖，消耗自身 $v$ 点法力值，来改变区间里每个水晶球的**特定属性**的能量。具体来说，有以下三种可能的表现形式：

   * 火元素能量定值增强：令 $A_i = A_i + v$。
   * 水元素能量翻倍增强：令 $B_i=B_i \cdot v$。
   * 土元素能量吸收融合：令 $C_i = v$。

3. 魔力释放：小L将区间里所有水晶球的能量聚集在一起，融合成一个新的水晶球，然后送给场外观众。生成的水晶球每种属性的能量值 = 区间内所有水晶球对应能量值的代数和。**需要注意的是，魔力释放的过程不会真正改变区间内水晶球的能量**。

值得一提的是，小L制造和融合的水晶球的原材料都是定制版的OI工厂水晶，所以这些水晶球有一个能量阈值 $998244353​$。当水晶球中某种属性的能量值大于等于这个阈值时，能量值会自动对阈值取模，从而避免水晶球爆炸。

小W 为小L（唯一的）观众，围观了整个表演，并且收到了小L在表演中融合的每个水晶球。小W 想知道，这些水晶球蕴涵的三种属性的能量值分别是多少。

## 输入格式

{{ self.input_file() }}

我们将题目描述中的 $7$ 种魔法，从上到下依次标号为 $1$ ~ $7$。如下表所示：

{{ render("table('data')") }}

输入的第一行包含一个整数 $n$ $(1\le n\le {{ tools.hn(prob.args.n) }})$，表示水晶球个数。

接下来 $n$ 行，每行空格隔开的 $3$ 个整数，其中第 $i$ 行的三个数依次表示 $A_i, B_i, C_i$。

接下来一行包含一个整数 $m$ $(1\le m\le {{ tools.hn(prob.args.n) }})$，表示施展魔法的次数。

接下来 $m$ 行，每行 3 或 4 个数，格式为 `opt l r (v)`。其中 opt 表示魔法的编号，$l, r$ 表示施展魔法的区间 （保证有 $l \le r$）。特别地，如果施展 4 ~ 6 号魔法（魔力增强），则还有一个整数 $v$ ，表示小 L 消耗的法力值。

## 输出格式

{{ self.output_file() }}

对每个 7 号魔法（魔力释放），输出一行、空格隔开的 3 个整数 `a b c`，分别表示此次融合得到的水晶球的水、火、土元素能量值。

{% set vars = {} -%}
{% do vars.__setitem__('sample_id', 1) -%}
{{ self.sample_text() }}

{{ self.title_sample_description() }}

以下展示每次施展魔法后，两个水晶球内的能量：

```
(2, 3, 3) (6, 6, 6)
(5, 3, 3) (12, 6, 6)
(8, 3, 3) (15, 6, 6)
(8, 3, 3) (15, 6, 6)
```

{% do vars.__setitem__('sample_id', 2) -%}
{{ self.sample_file() }}

## 子任务

100% 的数据，$n,m\le {{tools.hn(prob.args.n)}}$, $0\le A_i,B_i,C_i,v<{{ tools.hn(prob.args.a) }}$。

1. 10% 的数据，$n\times m\le 10^7$。
2. 另外 10% 的数据，每次魔法的区间均为 $[1,n]$
3. 另外 10% 的数据，每次非询问魔法的影响区间均为 $[1,n]$，所有修改在询问之前
4. 另外 10% 的数据，$opt\in\{4,5,6,7\}$
5. 另外 15% 的数据，$opt\in\{1,2,7\}$
6. 另外 15% 的数据，$opt\in\{1,2,3,5,7\}$
7. 另外 15% 的数据，$n,m\le 10^5$
8. 其他数据，无特殊约定。

**提示：请注意本题的空间限制，妥善处理你的程序的内存消耗。**