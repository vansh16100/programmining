int subTree(Node *root, int &k, int X)
{
    if (root == NULL)
        return 0;
    int sumLeft = subTree(root->left, k, X);
    int sumRight = subTree(root->right, k, X);
    if (sumLeft + sumRight + root->data == X)
        k++;
    return sumLeft + sumRight + root->data;
}
int countSubtreesWithSumX(Node *root, int X)
{
    int sum = 0;
    subTree(root, sum, X);
    return sum;
}
