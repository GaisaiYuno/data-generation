#include <cstdlib>
void Execute(string x){
    cerr<<"Execute "<<x<<endl;
    system(x.c_str());
}
void make_data(string std,string name){
	string in_file=name+".in";
    string out_file=name+".out";
    double st=clock();
    Execute(std_name+".exe<"+in_file+">"+out_file);
    double ed=clock();
    printf("Used time %.3lf\n\n",(ed-st)/CLOCKS_PER_SEC);
}
