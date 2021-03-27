
// contains only function//

void topsort_util(map<char, list<char>> graph, char root, stack<char> &s, map<char, bool> &visited)
{
    visited[root] = true;
    for (auto it : graph[root])
    {
        if (!visited[it])
        {
            visited[it] = true;
            topsort_util(graph, it, s, visited);
        }
    }
    s.push(root);
}
stack<char> topological_sort(map<char, list<char>> graph)
{
    stack<char> s;
    map<char, bool> visited;
    for (auto it : graph)
    {
        visited[it.first] = false;
    }
    //   cout<<visited['c'];
    for (auto it : graph)
    {
        if (!visited[it.first])
        {
            for (auto i : it.second)
            {
                if (!visited[i])
                {
                    topsort_util(graph, i, s, visited);
                }
            }
            s.push(it.first);
            visited[it.first] = true;
        }
    }
    return s;
}