Node *mergeKLists(Node *arr[], int K)
{
    // Your code here
    priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<pair<int, Node *>>> Q;
    for (int i = 0; i < K; i++)
    {
        if (arr[i] != NULL)
        {
            Q.push(make_pair(arr[i]->data, arr[i]));
        }
    }
    Node *head = new Node(-1);

    Node *tmp;
    tmp = head;

    while (!Q.empty())
    {
        pair<int, Node *> top = Q.top();
        Q.pop();

        head->next = top.second;

        if ((top.second)->next != NULL)
        {
            Q.push(make_pair((top.second)->next->data, (top.second)->next));
        }
        head = head->next;
        head->next = NULL;
    }

    return tmp->next;
}