{{ self.title() }}

## {{ _('Description') }}

杜老师可是要打$+\infty$年$World~Final$的男人，虽然规则不允许，但是可以改啊！

但是今年$WF$跟$THUSC$的时间这么近，所以他造了一个$idea$就扔下不管了……

给定$L,R$，求从$L$到$R$的这$R-L+1$个数中能选出多少个不同的子集，满足子集中所有的数的乘积是一个完全平方数。特别地，空集也算一种选法，定义其乘积为$1$。

由于杜老师忙于跟陈老师和鏼老师一起打$ACM$竞赛，所以，你能帮帮杜老师写写标算吗？

## {{ _('Input Format') }}

{{ self.input_file() }}

每个测试点包含多组测试数据。

输入第一行包含一个正整数 $T(1\le T\le {{prob.args['T']}})$，表示测试数据组数。

接下来$T$行，第$i+1$行两个正整数$L_i,R_i$表示第 $i$ 组测试数据的 $L,R$ ，保证$1\le L_i\le R_i\le {{tools.hn( prob.args['M'] )}}$。

## {{ _('Output Format') }}

{{ self.output_file() }}

输出$T​$行，每行一个非负整数，表示一共可以选出多少个满足条件的子集，答案对${{prob.args['P']}}​$取模。

{% set vars = {} -%}
{%- do vars.__setitem__('sample_id', 1) -%}
{{ self.sample_text() }}

{%- do vars.__setitem__('sample_id', 2) -%}
{{ self.sample_file() }}

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

## {{ _('Subtasks') }}

{{ render("table('data')") }}