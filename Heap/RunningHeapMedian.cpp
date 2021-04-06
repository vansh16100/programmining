
// complexity O(nlogn)


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class maxHeap
{
public:
    vector<int> heapMax;
    void maxHeapifyBottomUp(int pos)
    {
        while (pos > 0)
        {
            int parent = (pos - 1) / 2;
            if (heapMax[parent] < heapMax[pos])
            {
                swap(heapMax[parent], heapMax[pos]);
            }
            pos = parent;
        }
    }
    void maxHeapify(int pos)
    {
        int left = 2 * pos + 1;
        int right = 2 * pos + 2;
        int max = pos;

        if (left < heapMax.size() && heapMax[max] < heapMax[left])
            max = left;
        if (right < heapMax.size() && heapMax[max] < heapMax[right])
            max = right;

        if (max != pos)
        {
            swap(heapMax[pos], heapMax[max]);
            maxHeapify(max);
        }
    }
    int getMax()
    {
        return heapMax[0];
    }
    int extractMax()
    {
        int p = heapMax[0];
        swap(heapMax[0], heapMax[heapMax.size() - 1]);
        heapMax.pop_back();
        maxHeapify(0);
        return p;
    }
};
class minHeap
{
public:
    vector<int> heapMin;
    void minHeapifyBottomUp(int pos)
    {
        while (pos > 0)
        {
            int parent = (pos - 1) / 2;
            if (heapMin[parent] > heapMin[pos])
            {
                swap(heapMin[parent], heapMin[pos]);
            }
            pos = parent;
        }
    }

    void minHeapify(int pos)
    {
        int left = 2 * pos + 1;
        int right = 2 * pos + 2;
        int min = pos;

        if (left < heapMin.size() && heapMin[min] > heapMin[left])
            min = left;
        if (right < heapMin.size() && heapMin[min] > heapMin[right])
            min = right;

        if (min != pos)
        {
            swap(heapMin[pos], heapMin[min]);
            minHeapify(min);
        }
    }
    int getMin()
    {
        return heapMin[0];
    }
    int extractMin()
    {
        int p = heapMin[0];
        swap(heapMin[0], heapMin[heapMin.size() - 1]);
        heapMin.pop_back();
        minHeapify(0);
        //cout<<"b"<<heapMin[0]<<"b";
        return p;
    }
};
class Solution
{
    maxHeap heapMax;
    minHeap heapMin;

public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if (heapMin.heapMin.size() == 0 || heapMax.heapMax.size() == 0)
        {
            heapMax.heapMax.push_back(x);
            heapMax.maxHeapifyBottomUp(heapMax.heapMax.size() - 1);
        }
        else if (x <= heapMax.getMax())
        {
            heapMax.heapMax.push_back(x);
            heapMax.maxHeapifyBottomUp(heapMax.heapMax.size() - 1);
        }
        else
        {

            heapMin.heapMin.push_back(x);
            heapMin.minHeapifyBottomUp(heapMin.heapMin.size() - 1);

            // for(auto it: heapMin.heapMin) cout<<it<<" ";cout<<"k";
        }
        balanceHeaps();
    }

    //Function to balance heaps.
    void balanceHeaps()
    {
        // auto &greaterHeap = heapMin.heapMin.size() > heapMax.heapMax.size() ? heapMin : heapMax;
        // auto &smallerHeap = heapMin.heapMin.size() <= heapMax.heapMax.size() ? heapMin : heapMax;
        bool isMaxGreater = false;
        isMaxGreater = heapMin.heapMin.size() > heapMax.heapMax.size() ? false : true;
        int bsize = isMaxGreater ? heapMax.heapMax.size() : heapMin.heapMin.size();
        int ssize = isMaxGreater ? heapMin.heapMin.size() : heapMax.heapMax.size();
        if (bsize - ssize >= 2)
        {
            //cout<<"p";
            if (isMaxGreater)
            {
                heapMin.heapMin.push_back(heapMax.extractMax());
                heapMin.minHeapifyBottomUp(heapMin.heapMin.size() - 1);
            }
            else
            {
                heapMax.heapMax.push_back(heapMin.extractMin());
                heapMax.maxHeapifyBottomUp(heapMax.heapMax.size() - 1);
            }
        }
    }

    //Function to return Median.
    double getMedian()
    {

        if (heapMin.heapMin.size() > heapMax.heapMax.size())
            return double(heapMin.getMin());
        else if (heapMin.heapMin.size() < heapMax.heapMax.size())
            return double(heapMax.getMax());
        else
        {
            return double(heapMin.getMin() + heapMax.getMax()) / 2.0;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x;
            ob.insertHeap(x);
            cout << floor(ob.getMedian()) << endl;
        }
    }
    return 0;
} 