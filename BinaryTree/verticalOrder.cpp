vector<int> verticalOrder(Node *root)
    {
        //Your code here
        
        map<int , vector<int>> order;
        queue<pair<Node*,int>> Q;
        Q.push({root,0});
        while(!Q.empty()) {
            pair<Node*,int> front = Q.front();
            Q.pop();
            order[front.second].push_back(front.first->data);
            if(front.first->left) {
                Q.push({front.first->left,front.second-1});
            }
            if(front.first->right) {
                Q.push({front.first->right,front.second+1});
            }
        }
        
        vector<int> v;
        for(auto it:order) {
            for(auto i:it.second) {
                v.push_back(i);
            }
        }
        return v;
    }