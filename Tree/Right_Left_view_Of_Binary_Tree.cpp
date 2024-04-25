/* Brute Force Approach */
//  Optimal Approach is Downsisde

    void recursionLeft(Node* root, int level, vector<int>& res){
        // Check if the current node is NULL
        if(root == NULL){
            return;
        }
        
        // Check if the size of the result vector
        // is equal to the current level
        if(res.size() == level){
            // If equal, add the value of the
            // current node to the result vector
            res.push_back(root->data);
        }
        
        // Recursively call the function for the
        // left child with an increased level
        recursionLeft(root->left, level + 1, res);
        
        // Recursively call the function for the
        // right child with an increased level
        recursionLeft(root->right, level + 1, res);
    }
    
    // Recursive function to traverse the
    // binary tree and populate the right-side view
    void recursionRight(Node* root, int level, vector<int> &res){
        // Check if the current node is NULL
        if(root == NULL){
            return;
        }
        
        // Check if the size of the result vector
        // is equal to the current level
        if(res.size() == level){
            // If equal, add the value of the
            // current node to the result vector
            res.push_back(root->data);
            
            // Recursively call the function for the
            // right child with an increased level
            recursionRight(root->right, level + 1, res);
            
            // Recursively call the function for the
            // left child with an increased level
            recursionRight(root->left, level + 1, res);
        }
    }
