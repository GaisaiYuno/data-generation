#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') {
        x=(x*10)+(ch-'0');
        ch=getchar();
    }
    return x*f;
}
void Execute(string x){
    cerr<<"Execute "<<x<<endl;
    system(x.c_str());
}
int main(){
    cout<<"l and r?";
    int l=read(),r=read();
    
    cout<<"data name?";
    string name;
    cin>>name;
    
	cout<<"std name?";
    string std_name;
    cin>>std_name;
    
    for (int i=l;i<=r;++i){
        string num=to_string(i);
        string in_file=name+num+".in";
        string out_file=name+num+".out";
        double st=clock();
        Execute(std_name+".exe<"+in_file+">"+out_file);
        double ed=clock();
        printf("Used time %.3lf\n\n",(ed-st)/CLOCKS_PER_SEC);
    }
}
