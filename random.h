
#ifndef _MHYRANDOM_H //防止头文件重复包含,名字用_RANDOM_H似乎会冲突 
#define _MHYRANDOM_H

#include <cstdlib>
//一下子把bit搞进去不怕重名吗
int rand_int() {
	return rand()|(rand()<<15);
}
long long rand_long_long() {
	long long x=rand_int();
	long long y=rand_int(); //这样才随机
	return x|(y<<32ll);
}
int random(int l,int r) {
	return l+rand_int()%(r-l+1);
}
long long random(long long l,long long r) {
	return l+rand_long_long()%(r-l+1);
}

#endif
