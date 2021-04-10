bool isFoldableUtil(Node *x, Node *y)
{
    if ((!x) && (!y))
        return true;
    if ((!x) || (!y))
        return false;

    return isFoldableUtil(x->left, y->right) && isFoldableUtil(x->right, y->left);
}
bool IsFoldable(Node *root)
{
    // Your code goes here
    if (root == NULL)
        return true;
    return isFoldableUtil(root->left, root->right);
}