Node *dfs(Node *root, unordered_map<Node *, Node *> &clone)
{
    if (root == NULL)
        return NULL;

    if (clone.find(root) == clone.end())
        clone[root] = new Node(root->data);
    if (root->random != NULL && clone.find(root->random) == clone.end())
        clone[root->random] = new Node(root->random->data);
    if (root->random != NULL)
        clone[root]->random = clone[root->random];

    clone[root]->left = dfs(root->left, clone);
    clone[root]->right = dfs(root->right, clone);
    return clone[root];
}
class Solution
{
public:
    /* The function should clone the passed tree and return 
       root of the cloned tree */
    Node *cloneTree(Node *tree)
    {
        //Your code here
        if (tree == NULL)
            return NULL;
        unordered_map<Node *, Node *> cloneNode;
        cloneNode[tree] = new Node(tree->data);
        return dfs(tree, cloneNode);
    }