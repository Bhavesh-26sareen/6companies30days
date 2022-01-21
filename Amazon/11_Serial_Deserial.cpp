
class Solution
{
public:
    // Function to serialize a tree and return a list containing nodes of tree.
    void helper(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            ans.push_back(int(NULL));
            return;
        }
        ans.push_back(root->data);
        helper(root->left, ans);
        helper(root->right, ans);
        return;
    }
    vector<int> serialize(Node *root)
    {
        // Your code here
        vector<int> ans;
        helper(root, ans);
        return ans;
    }

    // Function to deserialize a list and construct the tree.
    int idx = 0;
    Node *deSerialize(vector<int> &A)
    {
        if (A.size() - 1 < idx || A[idx] == NULL)
        {
            idx++;
            return NULL;
        }
        // Your code here
        Node *root = new Node(A[idx++]);
        root->left = deSerialize(A);
        root->right = deSerialize(A);
        return root;
    }
};

// { Driver Code Starts.
