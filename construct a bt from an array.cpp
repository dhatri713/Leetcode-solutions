struct node* level_order(vector<int> vec, node* root, int i, int n){
        if (i < n){
            if (i != 0){
                struct node* temp = newNode(vec[i]);
                root = temp;
            }
            
            // left child
            root->left = level_order(vec, root->left, 2*i + 1, n);
            
            // right child
            root->right = level_order(vec, root->right, 2*i + 2, n);
        }
        return root;
    }
    
    void create_tree(node* root0, vector<int> &vec){
        //Your code goes here
        root0 = level_order(vec, root0, 0, vec.size());
        
    }
