#include <bits/stdc++.h>
using namespace std;
template<typename T>
class node{
		public:
		T key;
		int wt;
	};
template<typename T>
class binary_heap{
	public:
	int Size;
	int cap;
	vector<node<T>> v;
    map<T,int> position;
	public:
	binary_heap(int n){
		cap=n;
		Size=0;
	}
	void update_map(T n1,T n2,int pos1,int pos2){
		position[n1]=pos1;
		position[n2]=pos2;
	}
	void heapify(int i){
		int l=2*i+1;
		int r=2*i+2;
		int mini=i;
		if(l<Size&&v[l].wt<v[mini].wt)
		  mini=l;
		if(r<Size&&v[r].wt<v[mini].wt)
		  mini=r;
		 if(mini!=i)
		 {swap(v[i],v[mini]);
		   update_map(v[i].key,v[mini].key,i,mini);
		  heapify(mini);
		 }
	}
	
   void add_ele(T j,int a){
   	node<T> n;
   	n.key=j;
   	n.wt=a;
   	v.push_back(n);
   	int i=Size;
   	position[n.key]=i;
   	Size++;
   	while(i>0){
   		if(v[i].wt<v[(i-1)/2].wt)
   		  swap(v[i],v[(i-1)/2] );
   		  update_map(v[i].key,v[(i-1)/2].key,i,(i-1)/2);
   		i=(i-1)/2;
   	}
   }
   node<T> extract_min(){
   	node<T> n=v[0];
   	position.erase(v[0].key);
   	position[v[Size-1].key]=0;
   	swap(v[0],v[Size-1]);
   	 
   	Size--;
   	v.pop_back();
   	heapify(0);
   	return n;
   }
   void decrease_key(T data,int weight){
   	int pos=position[data];
   	int i=pos;
   	v[i].wt=weight;
   	while(i>0){
   			if(v[i].wt<v[(i-1)/2].wt)
   		  swap(v[i],v[(i-1)/2]);
   		  update_map(v[i].key,v[(i-1)/2].key,i,(i-1)/2);
   		i=(i-1)/2;
   	}
   }
   void print(){
   	for(int i=0;i<v.size();i++){
   		cout<<v[i].wt<<" "<<v[i].key<<endl;;
   	}
   }
   int find_key(T key){
   	if(position.find(key)==position.end())
   	  return -1;
   	  return position[key];
   }
   node<T> access_node(int pos){
   	return v[pos];
   }
};
class Graph{
	int v;
	map<int,list<pair<int,int>>> graph;
	public:
	Graph(int v){		this->v=v;
	}
	void addEdge(int u,int v,int w){
		graph[u].push_back(make_pair(v,w));
		graph[v].push_back(make_pair(u,w));
	}
	void print(){
		for(auto adj:graph){
			for(auto adjj:adj.second)
			  cout<<adjj.second<<" "<<adj.first<<" "<<adjj.first<<endl;
		}
		cout<<endl;
	}
	void prims(int root){
		map<pair<int,int>,int> ans;
		map<int,int> parent;
		binary_heap<int> heap(100);
		for(auto it:graph){
			if(it.first!=root)
			heap.add_ele(it.first,INT_MAX);
		}
		heap.add_ele(root,0);
        //cout<<endl;
		parent[root]=root;
		 while(heap.v.size()>0){
		node<int> n=heap.extract_min();
		ans[make_pair(n.key,parent[n.key])]=n.wt;
		 	for(auto adj:graph[n.key]){
		 			int pos=heap.find_key(adj.first);
				if(pos!=-1){
				node<int> n1=heap.access_node(pos);
					if(adj.second<n1.wt){
						heap.decrease_key(adj.first,adj.second);
				       parent[adj.first]=n.key;
					}
				}
		 	}      
		 }
		 for(auto it: ans){
		 cout<<it.first.first<<" "<<it.first.second<<" "<<it.second<<endl;
		 }
	}
};
int main() {

     Graph g(9);

	g.addEdge(7,6,1);
	g.addEdge(8,2,2);
	g.addEdge(6,5,2);
	g.addEdge(0,1,4);
	g.addEdge(2,5,4);
	g.addEdge(8,6,6);
	g.addEdge(2,3,7);
	g.addEdge(7,8,7);
	g.addEdge(0,7,8);
	g.addEdge(1,2,8);
	g.addEdge(3,4,9);
	g.addEdge(5,4,10);
	g.addEdge(1,7,11);
	g.addEdge(3,5,14);
	g.prims(0);
	return 0;
}
