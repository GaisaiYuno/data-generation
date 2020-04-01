#include "random.h"
struct graph{
	std::vector<std::pair<int,int> > E;
	std::set<std::pair<int,int> >S;
	void print(){
		for (int i=0;i<E.size();++i){
			printf("%d %d\n",E[i].first,E[i].second);
		}
		puts("");
	}
	void printw(int l,int r){//´ø±ßÈ¨
		for (int i=0;i<E.size();++i){
			printf("%d %d %d\n",E[i].first,E[i].second,random(l,r));
		}
		puts("");
	}
	void init(){
		E.clear();
		S.clear();
	}
	void add_edge(pair<int,int>p){
		E.push_back(p);
		if (p.first>p.second) swap(p.first,p.second);
		S.insert(p);
	}
	void check(pair<int,int>p){
		if (p.first>p.second) swap(p.first,p.second);
		if (S.count(p)) return false;
		else return true;
	}
	void shuffle(){
		random_shuffle(E.begin(),E.end());
	}
};
pair<int,int>random_edge(int n){
	int u=random(1,n),v=random(1,n);
	while (u==v) v=random(1,n);
	return make_pair(u,v);
}
graph random_tree(int n){
	graph g;
	for (int i=2;i<=n;++i){
		g.E.push_back(make_pair(random(1,i-1),i));
	}
	return g;
}
graph chain(int n){
	graph g;
	for (int i=2;i<=n;++i){
		g.E.push_back(make_pair(i-1,i));
	}
	return g;
}
graph jhgraph(int n,int nd){
	graph g;
	for (int i=1;i<=n;++i){
		if (i!=nd) g.E.push_back(make_pair(i,nd));
	}
	return g;
}
graph random_graph(int n,int m){
	if (m<=n-1){
		cerr<<"Error."<<endl;
		return 0;
	}
	graph g=random_tree(n);
	for (int i=1;i<=m-n+1;++i){
		pair<int,int>e=random_edge(n);
		while (!check(e)) e=random_edge(n);
		g.add_edge(e);
	}
	return g;
}
