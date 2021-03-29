class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        queue<pair<int, int>> q;
        vector<bool> visited(n * n + 1, false);
        vector<int> d(n * n + 1, 0);
        int k = 1;
        bool p = false;
        for (int i = n - 1; i >= 0; i--)
        {
            if (!p)
            {
                for (int j = 0; j < n; j++)
                {
                    d[k++] = board[i][j];
                }
                p = true;
            }
            else
            {
                for (int j = n - 1; j >= 0; j--)
                {
                    d[k++] = board[i][j];
                }
                p = false;
            }
        }
        for (int i = 1; i <= n * n; i++)
        {
            cout << d[i] << " ";
        }
        q.push(make_pair(1, 0));
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            if (front.first == n * n)
                return front.second;
            for (int i = 1; i <= 6 && front.first + i <= n * n; i++)
            {
                if (d[front.first + i] == -1 && (!visited[front.first + i]))
                {
                    visited[front.first + i] = true;
                    q.push(make_pair(front.first + i, front.second + 1));
                }
                else if (d[front.first + i] != -1 && !visited[d[front.first + i]])
                {
                    visited[d[front.first + i]] = true;
                    q.push(make_pair(d[front.first + i], front.second + 1));
                }
            }
        }
        return -1;
    }
};