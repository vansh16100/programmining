void kFarDown(Node *root, int k, vector<int> &kFar)
{
    if (root == NULL)
        return;

    if (k == 0)
    {
        kFar.push_back(root->data);
        return;
    }

    kFarDown(root->left, k - 1, kFar);
    kFarDown(root->right, k - 1, kFar);
}
int kFarNode(Node *root, int target, int k, vector<int> &kFar)
{
    if (root == NULL)
        return -1;

    if (root->data == target)
    {
        kFarDown(root, k, kFar);
        return 0;
    }

    int distFromLeft = kFarNode(root->left, target, k, kFar);

    if (distFromLeft != -1)
    {
        if (distFromLeft + 1 == k)
        {
            kFar.push_back(root->data);
            return -1;
        }

        kFarDown(root->right, k - distFromLeft - 2, kFar);

        return distFromLeft + 1;
    }

    int distFromRight = kFarNode(root->right, target, k, kFar);
    if (distFromRight != -1)
    {
        if (distFromRight + 1 == k)
        {
            kFar.push_back(root->data);
            return -1;
        }

        kFarDown(root->left, k - distFromRight - 2, kFar);
        return distFromRight + 1;
    }

    return -1;
}
class Solution
{
private:
public:
    vector<int> KDistanceNodes(Node *root, int target, int k)
    {
        // return the sorted vector of all nodes at k dist
        vector<int> kFar;
        kFarNode(root, target, k, kFar);
        sort(kFar.begin(), kFar.end());
        return kFar;
    }
};