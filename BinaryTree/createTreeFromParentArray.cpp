Node *createTree(unordered_map<int, vector<int>> &ump, int root)
{
    Node *node = new Node(root);
    if (ump.find(root) == ump.end())
        return node;
    vector<int> v = ump[root];
    node->left = createTree(ump, v[0]);
    if (v.size() > 1)
        node->right = createTree(ump, v[1]);
    return node;
}

Node *createTree(int parent[], int N)
{
    // Your code here
    unordered_map<int, vector<int>> ump;
    int root;
    for (int i = 0; i < N; i++)
    {
        if (parent[i] == -1)
            root = i;
        else
            ump[parent[i]].push_back(i);
    }
    return createTree(ump, root);
}