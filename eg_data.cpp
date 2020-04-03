#include <bits/stdc++.h>
#include "random.h"
#include "gen_seq.h" 
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
	int n=100,m=100;
	srand(time(NULL));
	sequence s=gen_random_sequence(n,0,1e9); //生成元素处在 [0,1e9] 之间的随机数列
	s.print();
	gen_query(m,1,n); //再随机生成几组查询
	return 0;
}
