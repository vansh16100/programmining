#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;
template <typename T>
class Graph
{
private:
    int v;
    vector<T> vertices;
   

public:
    map<T, list<T>> graph;
    Graph(int v, vector<T> vertex)
    {
        this->v = v;
        list<T> l;
        for (int i = 0; i < vertex.size(); i++)
        {
            vertices.push_back(vertex[i]);
            graph[vertex[i]]=l;
        }

    }

    void addEdge(T u, T v)
    {
        graph[u].push_back(v);
    }

    void printGraph()
    {
        for (auto it : graph)
        {
            cout << it.first << "->";
            for (auto child : it.second)
            {
                cout << child << " ";
            }
            cout << endl;
        }
    }
};

void topo(Graph<int> *g)
{
    map<int, list<int>> graph = g->graph;
    //cout<<graph[1].size()<<endl;
    int n = graph.size();
    vector<int> indegree(graph.size() + 1, 0);
    for (auto i : graph)
    {
        for (auto it : i.second)
            indegree[it]++;
    }
    vector<int> v;
    vector<int> time(graph.size() + 1, 1);
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        v.push_back(front);
        for (auto it : graph[front])
        {
            indegree[it]--;
            time[it] = max(time[it], time[front] + 1);
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    for (int i = 1; i < time.size(); i++)
    {
        cout << time[i] << " ";
    }
}
void solve() {
    int v, e;
    cin >> v >> e;
    vector<int> ve(v);
    for (int i = 0; i < v; i++)
    {
        cin >> ve[i];
    }
    Graph<int> g(v, ve);

    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g.addEdge(x, y);
    }
    topo(&g);
    //g.printGraph();
}
int main()
{
#ifndef true
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}