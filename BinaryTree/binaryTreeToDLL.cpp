    Node * bToDLL(Node *root)
    {
        // your code here
        if(root==NULL) return NULL;
        
        if(root->left) {
             Node* left = root->left;
             bToDLL(root->left);
           
            while(left->right!=NULL) {
                left = left->right;
            }
            root->left=left;
            left->right = root;
        }
        
        if(root->right) {
             Node* right = root->right;
            bToDLL(root->right);
           
            while(right->left!=NULL) {
                right = right->left;
            }
            
            root->right = right;
            right->left = root;
        }
        Node* tmp = root;
        while(tmp->left!=NULL) {
            tmp=tmp->left;
        }
        return tmp;
        
    }