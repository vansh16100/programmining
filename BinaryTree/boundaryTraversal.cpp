// O(n)
// using inorder and stack

void inorder(Node *root, vector<int> &v)
{

    if (root == NULL)
        return;

    inorder(root->left, v);
    if (root->left == NULL && root->right == NULL)
    {
        v.push_back(root->data);
    }
    inorder(root->right, v);
}

vector<int> printBoundary(Node *root)
{
    //Your code here
    Node *curr = root;
    vector<int> v;
    if (root == NULL)
        return {};
    v.push_back(root->data);

    curr = root->root->left;

    while (curr && (curr->left || curr->right))
    {
        v.push_back(curr->data);

        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
    stack<int> s;
    curr = root->right;
    while (curr && (curr->left || curr->right))
    {
        s.push(curr->data);

        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    inorder(root, v);
    while (!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    return v;
}