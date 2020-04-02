#include <bits/stdc++.h>
#include "random.h"
#include "gen_string.h" 
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main(){
	int n=100;
	
	char_set rnd,c;
	rnd.init();
	rnd.add_lower_case();
	
	cout<<add_noise(repeat("poiop",n/5),rnd,10)<<endl; //生成一个由 poiop 重复 2000 次形成的字符串，添加 10 点噪音

	c.init();
	c.add_ch('a');
	c.add_ch('b');
	cout<<gen_rand_string(n,c)<<endl; //生成一个随机的由 a,b 构成的长度为 n 的字符串
	cout<<gen_palindrome(n,c)<<endl; //生成一个随机的由 a,b 构成的长度为 n 的回文串
	
	c.init();
	c.add_lower_case();
	cout<<gen_rand_string(n,c)<<endl; //生成一个随机的由小写字母构成的长度为 n 的字符串
	
	return 0;
}
