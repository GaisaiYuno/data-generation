# 生成数据
## 用法

在数据生成器前面加上：

```cpp
#include "random.h"
#include "gen_xxx.h"
```

## random.h

### 函数

`rand_int()`：生成随机 `int` 范围内整数。

`random(l,r)`：生成 [l,r]​ 内整数。

## gen_string.h

### 类

`char_set`（字符集）：

​	`init()`：初始化。

​	`add_ch(c)`：增加字符 c。

​	`add_chs(l,r)`：增加从 l 到 r 的字符。

​	`add_upper_case()`：初始化为大写字母。

​	`add_lower_case()`：初始化为小写字母。

​	`add_numbers()`：初始化为数字。

​	`gen_char()`：从字符集里面随机抽取一个字符。

### 函数

`gen_rand_string(len,c)`：用字符集 c 生成长度为 len 的随机字符串。

`gen_palindrome(len,c)`：用字符集 c 生成长度为 len 的随机回文字符串。

`add_noise(s,c,cnt)`：用字符集 c 为 s 添加 cnt 个噪音，也就是随机 cnt 个位置，放上随机字符。

`repeat(pattern,cnt)`：将 pattern 这个字符串重复 cnt 次，生成新的字符串。

### 举例

```cpp
cout<<add_noise(repeat("poiop",2000),rnd,10); //生成一个由 poiop 重复 2000 次形成的字符串，添加 10 点噪音

char_set c;
c.init();
c.add_ch('a');
c.add_ch('b');
cout<<gen_rand_string(n,c); //生成一个随机的由 a,b 构成的长度为 n 的字符串
cout<<gen_palindrome(n,c); //生成一个随机的由 a,b 构成的长度为 n 的回文串

c.init();
c.add_lower_case();
cout<<gen_rand_string(n,c); //生成一个随机的由小写字母构成的长度为 n 的字符串
```

## gen_seq.h

### 类

`sequence`（序列）：

​	`init()`：初始化。

​	`add()`：添加元素。

​	`print(c,ed)`：输出，中间两个数用 c 隔开，最后输出 ed。c 默认为空格，ed 默认为换行。

### 函数

`gen_random_sequence(len,l,r)`：生成一个长度为 len，每个元素从 [l,r] 中选取的数列。

`gen_random_permutation(len)`.生成一个长度为len的排列

`repeat(pattern,cnt)`：将数列 pattern 重复 cnt 次。

`add_noise(seq,cnt,l,r)`：在数列 seq 中添加 cnt 个噪音，每个元素从 [l,r] 中选取。

`gen_query(m,l,r)`：生成 m 个左右边界在 [l,r] 之间的查询。

### 举例

```cpp
sequence s=gen_random_sequence(100000,0,1e9); //生成元素处在 [0,1e9] 之间的随机数列
s.print();
gen_query(100000,1,100000); //再随机生成几组查询
```

## gen_graph.h

### 类

`graph`（图）：
    注意图中的边默认是一个`std::pair<int,int>`

​	`init`：初始化。

​	`print()`：输出，不带边权。

​	`printw(l,r)`：输出带权边，权值在 [l,r] 之间。

​	`shuffle`：打乱边。

​	`add_edge(p)`：添加边 p。

 `add_edge(u,v)`: 添加边(u,v)

​	`check(p)`：检查边 p 是否存在。

### 函数

`random_tree(n)`：生成一棵 n 个节点的树。

`random_graph(n,m,is_connected,has_same_edge),has_self_loop)`：生成一张 n 个节点，m 条边的图。`is_connected`表示是否连通(看成无向图),`has_same_edge`表示是否有重边,`has_self_loop`表示是否有自环。另外还提供了宏`CONNECTED,NOT_CONNECTED,NO_SELF_LOOP,ALLOW_SELF_LOOP,NO_SAME_EDGE,ALLOW_SAME_EDGE`可以直接传入。

`random_dag(n,m,has_same_edge)`表示生成一张n个点m条边的有向无环图(DAG)

`random_edge(n)`：生成一条端点在 [1,n] 之间的边。

`chain(n)`：生成一条有 n 个节点的链。

`jhgraph(n,nd)`：生成一个 n 节点菊花图，中心节点为 nd。

### 举例

```cpp
graph g;
g=chain(n);
g.add_edge(make_pair(1,n));
g.print(); //生成一个环
g=random_graph(n,m,CONNECTED,NO_SAME_EDGE,NO_SELF_LOOP);
g.shuffle();
g.printw(0,1e9); //生成一张边权在 [0,1e9] 之间的图，并打乱输出
```

