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
	
	cout<<add_noise(repeat("poiop",n/5),rnd,10)<<endl; //����һ���� poiop �ظ� 2000 ���γɵ��ַ�������� 10 ������

	c.init();
	c.add_ch('a');
	c.add_ch('b');
	cout<<gen_rand_string(n,c)<<endl; //����һ��������� a,b ���ɵĳ���Ϊ n ���ַ���
	cout<<gen_palindrome(n,c)<<endl; //����һ��������� a,b ���ɵĳ���Ϊ n �Ļ��Ĵ�
	
	c.init();
	c.add_lower_case();
	cout<<gen_rand_string(n,c)<<endl; //����һ���������Сд��ĸ���ɵĳ���Ϊ n ���ַ���
	
	return 0;
}
