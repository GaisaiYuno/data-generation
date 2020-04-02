#include <bits/stdc++.h>
#include "random.h"
#include "gen_graph.h" 
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
	srand(time(NULL));
	int n=10,m=30;
	graph g;
	g=chain(n);
	g.add_edge(make_pair(1,n));
	g.print(); //生成一个环
	g=random_graph(n,m);
	g.shuffle();
	g.printw(0,1e9); //生成一张边权在 [0,1e9] 之间的图，并打乱输出
	return 0;
}
