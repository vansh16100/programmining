#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class disjoint_set{
    class node{
        public:
        int data;
        int rank;
        node* parent;
        node(int data){
            this->data=data;
            rank=0;
        }
    };
    map<int,node*> mp;
    public:
    disjoint_set(int n){
        for(int i=0;i<n;i++){
            mp[i]=new node(i);
            mp[i]->parent=mp[i];
        }
    }
    void Union(int d1,int d2){
        node* parent1=find_set(mp[d1]);
        node* parent2=find_set(mp[d2]);
        
        if(parent1==parent2)
          return;
        if(parent1->rank>=parent2->rank){
            if(parent1->rank==parent2->rank)
              parent1->rank=parent1->rank+1;
            parent2->parent=parent1;
        }
        else parent1->parent=parent2;
    }
    
    int find_set(int d){
        node* f=find_set(mp[d]);
        return f->data;
    }
    node* find_set(node* n){
        if(n->parent==n)
          return n;
        n->parent=find_set(n->parent);
    return n->parent;
    }
};
class edge{
    public:
    int src,dest,wt;
    edge(int wt,int src,int dest){
        this->src=src;
        this->dest=dest;
        this->wt=wt;
    }
    egde(){}
};
class Graph{
public:
   vector<edge> edge_list;
   void addEdge(int wt,int src,int des){
    edge e(wt,src,des);
    edge_list.push_back(e);
   } 
};
int myCompare(edge e1,edge e2){
    return e1.wt < e2.wt;
}
int spanningTree(int V, Graph g) {
       
      sort((g.edge_list).begin(),(g.edge_list).end(),myCompare);
      vector<pair<int,int>> v;
      disjoint_set d(V);
      int weight=0;
      for(int i=0;i<g.edge_list.size();i++){

          if(d.find_set(g.edge_list[i].src)!=d.find_set( g.edge_list[i].dest )){
             {weight+=g.edge_list[i].wt;
              d.Union(g.edge_list[i].src, g.edge_list[i].dest );
              v.push_back(make_pair(g.edge_list[i].src, g.edge_list[i].dest));
             }
      }
    }
    for(auto it:v) {
      cout<<setw(4)<<it.first<<" "<<setw(8)<<it.second<<"\n";
    }

     return weight;
}

int main(){
  Graph g;
// g.addEdge(1,7,6);
// g.addEdge(2,8,2);
// g.addEdge(2,6,5);
// g.addEdge(4,0,1);
// g.addEdge(4,2,5);
// g.addEdge(6,8,6);
// g.addEdge(7,2,3);
// g.addEdge(7,7,8);
// g.addEdge(8,0,7);
// g.addEdge(8,1,2);
// g.addEdge(9,3,4);
// g.addEdge(10,5,4);
// g.addEdge(11,1,7);
// g.addEdge(14,3,5);
int v,e;
cin>>v>>e;
int w,s,d;
cout<<"vertices = "<<v<<"\n";
cout<<"edges = "<<e<<"\n";
cout<<setw(6)<<"source "<<setw(10)<<"destination"<<endl;
for(int i=0;i<e;i++){
  cin>>w>>s>>d;
  g.addEdge(w,s,d);
}
  cout<<spanningTree(v,g);
  return 0;
}
