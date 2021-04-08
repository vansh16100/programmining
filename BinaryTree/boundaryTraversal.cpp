void inorderLeaf(Node *root, vector<int> &v)
{

    if (root == NULL)
        return;

    inorderLeaf(root->left, v);
    if (root->left == NULL && root->right == NULL)
    {
        v.push_back(root->data);
    }
    inorderLeaf(root->right, v);
}
void leftBoundary(Node *root, vector<int> &v)
{
    Node *curr = root->left;
    while (curr && (curr->left || curr->right))
    {
        v.push_back(curr->data);

        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}
stack<int> rightBoundary(Node *root)
{
    stack<int> s;
    Node *curr = root->right;
    while (curr && (curr->left || curr->right))
    {
        s.push(curr->data);

        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    return s;
}
vector<int> printBoundary(Node *root)
{
    //Your code here
    vector<int> v;
    if (root == NULL)
        return {};
    v.push_back(root->data);

    leftBoundary(root, v);
    stack<int> s = rightBoundary(root);

    inorderLeaf(root, v);
    while (!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    return v;
}