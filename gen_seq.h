#include "random.h"
struct sequence{
	std::vector<int>S;
	void print(char c=' ',char ed='\n'){
		//默认格式：1 2 3 换行
		for (int i=0;i<S.size();++i){
			printf("%d\n",S[i]);
			putchar(c);
		}
		putchar(ed);
	}
	void add(int x){
		S.push_back(x);
	}
	void init(){
		S.clear();
	}
};
sequence gen_random_sequence(int len,int l,int r){
	sequence ans;
	ans.init();
	for (int i=1;i<=len;++i){
		ans.add(random(l,r));
	}
	return ans;
}
sequence repeat(sequence pattern,int cnt){
	sequence ans;
	ans.init();
	for (int i=1;i<=cnt;++i){
		for (int j=0;j<pattern.S.size();++j){
			ans.add(pattern.S[j]);
		}
	}
	return ans;
}
sequence add_noise(sequence seq,int cnt,int l,int r){
	for (int i=1;i<=cnt;++i){
		seq.S[random(0,seq.S.size()-1)]=random(l,r);
	}
	return seq;
}
void gen_query(int m,int l,int r){
	for (int i=1;i<=m;++i){
		int Left=random(l,r);
		int Right=random(l,r);
		if (Left>Right) printf("%d %d\n",Left,Right);
	}
} 
