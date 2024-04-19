void leftTraversal(TreeNode<int> *root, vector<int> &ans) {
    if (!root || (!root->left && !root->right)) // If root is null or a leaf node
        return;

    ans.push_back(root->data);

    if (root->left)
        leftTraversal(root->left, ans);
    else
        leftTraversal(root->right, ans);
}

void rightTraversal(TreeNode<int> *root, vector<int> &temp) {
    if (!root || (!root->left && !root->right)) // If root is null or a leaf node
        return;

    temp.push_back(root -> data);

    if (root->right)
        rightTraversal(root->right, temp);
    else
        rightTraversal(root->left, temp);
}

void leafTraversal(TreeNode<int> *root, vector<int> &ans) {
    if (!root)
        return;

    if (!root->left && !root->right) // If root is a leaf node
        ans.push_back(root->data);

    leafTraversal(root->left, ans);
    leafTraversal(root->right, ans);
}

vector<int> traverseBoundary(TreeNode<int> *root) {
    vector<int> ans;
    vector<int> temp;

    if (!root)
        return ans;

    ans.push_back(root->data); // Include the root

    leftTraversal(root->left, ans); // Traverse left boundary
    leafTraversal(root, ans);       // Traverse leaf nodes
    rightTraversal(root->right, temp); // Traverse right boundary

    // Pop elements from the stack and push them into the result vector
    for (int i = temp.size() -1 ; i >= 0 ; i-- )
    {
        ans.push_back(temp[i]) ;
    }
    return ans;
}
