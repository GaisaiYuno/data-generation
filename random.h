#include <cstdlib> //һ���Ӱ�bit���ȥ���������� 
int rand_int(){
	return rand()|(rand()<<15);
}
long long rand_long_long(){
	long long x=rand_int(); 
	return x|(x<<32ll); 
}
int random(int l,int r){
	return rand_int()%(r-l+1);
}
long long random(long long l,long long r){
	return rand_long_long()%(r-l+1);
}

