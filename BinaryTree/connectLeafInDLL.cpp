void preorder(Node *root, Node *parent, Node **pre)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        if (parent && parent->left == root)
            parent->left = NULL;
        else if (parent)
            parent->right = NULL;
        if ((*pre) == NULL)
            root->left = NULL;
        else
        {
            (*pre)->right = root;
            root->left = (*pre);
        }
        (*pre) = root;
        return;
    }
    preorder(root->left, root, pre);
    preorder(root->right, root, pre);
}
Node *convertToDLL(Node *root)
{
    // add code here.
    Node *pre, *parent;
    pre = parent = NULL;
    preorder(root, parent, &pre);
    while (pre->left != NULL)
    {
        pre = pre->left;
    }
    return pre;
}