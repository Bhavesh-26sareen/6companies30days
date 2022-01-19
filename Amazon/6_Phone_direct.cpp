// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Node
{
public:
    Node *links[26];
    bool flag = false;
    bool containskey(char ch)
    {

        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *temp)
    {
        links[ch - 'a'] = temp;
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containskey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->links[word[i] - 'a'];
        }
        node->flag = true;
    }
    void searchhelper(Node *temp, string pre, vector<string> &vs)
    {
        // cout << pre << endl;
        if (temp->flag == true)
        {
            // cout << pre << endl;
            vs.push_back(pre);
        }
        for (char i = 'a'; i <= 'z'; i++)
        {
            Node *nxt_node = temp->links[i - 'a'];
            if (nxt_node != NULL)
            {
                // cout << i << endl;
                searchhelper(nxt_node, pre + (char)i, vs);
            }
        }
    }
    vector<vector<string>> search(string prefix)
    {
        Node *node = root;
        string pre = "";
        vector<vector<string>> ans;
        int i;
        for (i = 0; i < prefix.length(); i++)
        {
            pre += (char)prefix[i];
            char lch = prefix[i];
            // cout << lch << endl;
            if (node->containskey(lch) == false)
            {
                // cout << lch << endl;
                break;
            }
            // cout << "Pre ::" << pre << endl;
            vector<string> vs;
            searchhelper(node->links[lch - 'a'], pre, vs);
            ans.push_back(vs);
            node = node->links[lch - 'a'];
        }
        for (; i < prefix.length(); i++)
            ans.push_back({"0"});

        return ans;
    }
};
class Solution
{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code
        Trie T;
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            // cout << contact[i] << endl;
            T.insert(contact[i]);
        }
        // cout << "ho " << endl;
        ans = T.search(s);
        // cout << "ho1 " << endl;

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string contact[n], s;
        for (int i = 0; i < n; i++)
            cin >> contact[i];
        cin >> s;

        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for (int i = 0; i < s.size(); i++)
        {
            for (auto u : ans[i])
                cout << u << " ";
            cout << "\n";
        }
    }
    return 0;
} // } Driver Code Ends
  /*
  1
  3
  geeikistest geeksforgeeks geeksfortest
  geeips
  */