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
	void add_chs(char l,char r){
		for (char i=l;i<=r;++i){
			ch.push_back(i);
		}
	}
	void add_upper_case(){
		add_chs('A','Z');
	}
	void add_lower_case(){
		add_chs('a','z');
	}
	void add_numbers(){
		add_chs('0','9');
	}
	char gen_char(){
		return ch[random(0,ch.size()-1)];
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
	//添加cnt个噪音 
	for (int i=1;i<=cnt;++i){
		s[random(0,s.size()-1)]=c.gen_char();
	}
	return s;
}
std::string repeat(std::string pattern,int cnt){
	//重复cnt次 
	std::string s="";
	for (int i=1;i<=cnt;++i){
		s+=pattern;
	}
	return s;
}
