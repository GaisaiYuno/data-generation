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
	sequence s=gen_random_sequence(n,0,1e9); //����Ԫ�ش��� [0,1e9] ֮����������
	s.print();
	gen_query(m,1,n); //��������ɼ����ѯ
	return 0;
}
