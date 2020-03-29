#include <bits/stdc++.h>
int RandInt(){
	return rand()|(rand()<<15);
}
int Rand(int l,int r){
	return RandInt()%(r-l+1);
}
struct char_set{
	std::vector<int>ch;
	char_set(){
		ch.clear();
	}
	void init(){
		ch.clear();
	}
	void add_ch(char c){
		ch.push_back(c);
	}
	void add_upper_case(){
		init();
		for (int i=0;i<26;++i){
			ch.push_back(i+'A');
		}
	}
	void add_lower_case(){
		init();
		for (int i=0;i<26;++i){
			ch.push_back(i+'a');
		}
	}
	char gen_char(){
		return ch[Rand(0,ch.size()-1)];
	}
};
std::string gen_rand_string(int len,char_set c){
	//生成长度为len的随机字符串
	std::string s="";
	for (int i=1;i<=len;++i){
		s+=c.gen_char();
	}
	return s;
}
std::string gen_palindrome(int len,char_set c){
	//生成长度为len的回文串
	std::string s="";
	int r=len/2;
	std::string s1=gen_rand_string(r,c);
	s+=s1;
	if (len&1) s+=c.gen_char();
	reverse(s1.begin(),s1.end());
	s+=s1;
	return s;
}
std::string add_noise(std::string s,char_set c,int cnt){
	for (int i=1;i<=cnt;++i){
		s[Rand(0,s.size()-1)]=c.gen_char();
	}
	return s;
}
std::string repeat(std::string pattern,int cnt){
	std::string s="";
	for (int i=1;i<=cnt;++i){
		s+=pattern;
	}
	return s;
}