//O(n)
vector<int> diagonal(node *root)
{
    vector<int> v;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *curr = q.front();
        q.pop();
        // v.push_back(curr->data);
        while (curr != NULL)
        {
            if (curr->left)
            {
                q.push(curr->left);
               
            }
            v.push_back(curr->data);
            curr = curr->right;
        }
    }
    return v;
}
//o/p      

//1 2 3 5 778  98 98

//////
////
//        the following solution prints a diagonal;

void diagonal(node *root)
{
    // your code here
    vector<int> v;
    queue<node *> q1, q2;
    q1.push(root);

    while (!q1.empty() || !q2.empty())
    {
        bool b = false;
        while (!q1.empty())
        {
            node *curr = q1.front();
            q1.pop();
            // v.push_back(curr->data);
            while (curr != NULL)
            {
                if (curr->left)
                {
                    q2.push(curr->left);
                }

                cout << (curr->data) << " ";
                curr = curr->right;
            }
        }
        cout << endl;
        while (!q2.empty())
        {
            node *curr = q2.front();
            q2.pop();
            // v.push_back(curr->data);
            while (curr != NULL)
            {
                if (curr->left)
                {
                    q1.push(curr->left);
                }
                cout << (curr->data) << " ";
                curr = curr->right;
            }
        }
        cout << endl;
    }
    // return v;
}
// o/p
1 3 7
2 5 11 6
4 9 10
8