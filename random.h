#include <bits/stdc++.h>
int rand_int(){
	return rand()|(rand()<<15);
}
int random(int l,int r){
	return rand_int()%(r-l+1);
}
