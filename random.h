
#ifndef _MHYRANDOM_H//��ֹͷ�ļ��ظ�����,������_RANDOM_H�ƺ����ͻ 
#define _MHYRANDOM_H

#include <cstdlib>
 //һ���Ӱ�bit���ȥ���������� 
int rand_int() {
	return rand()|(rand()<<15);
}
long long rand_long_long() {
	long long x=rand_int();
	long long y=rand_int(); //��������� 
	return x|(y<<32ll);
}
int random(int l,int r) {
	return l+rand_int()%(r-l+1);
}
long long random(long long l,long long r) {
	return l+rand_long_long()%(r-l+1);
}

#endif
