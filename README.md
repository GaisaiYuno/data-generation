# string data generation
### 用法

在数据生成器前面加上 `#include "gen_string.h"`

### 类

char_set（字符集）：

​	init：初始化。

​	add_ch(c)：增加字符 c。

​	add_upper_case()：初始化为大写字母。

​	add_lower_case()：初始化为小写字母。

​	gen_char()：从字符集里面随机抽取一个字符。

### 函数

RandInt：生成随机 `int` 范围内整数。

Rand：生成 [l,r]​ 内整数。

gen_rand_string(len,c)：用字符集 c 生成长度为 len 的随机字符串。

gen_palindrome(len,c)：用字符集 c 生成长度为 len 的随机回文字符串。

add_noise(s,c,cnt)：用字符集 c 为 s 添加 cnt 个噪音，也就是随机 cnt 个位置，放上随机字符。

repeat(pattern,cnt)：将 pattern 这个字符串重复 cnt 次，生成新的字符串。