#include"random.h"
#include"gen_graph.h"
#include"gen_seq.h"
#include"gen_string.h"
#include<ctime>
using namespace std;
int main(){
	srand(time(NULL));
	random_graph(5,6,CONNECT,ALLOW_SAME_EDGE,NO_SELF_LOOP).print();
}
