class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &s)
    {
        // code here
        unordered_map<string, vector<int>> umap;
        for (int i = 0; i < s.size(); i++)
        {
            string temp = s[i];
            sort(temp.begin(), temp.end());
            umap[temp].push_back(i);
        }
        vector<vector<string>> ans;
        for (auto mp : umap)
        {
            vector<string> a;
            for (auto i : mp.second)
            {
                a.push_back(s[i]);
            }
            ans.push_back(a);
        }
        return ans;
    }
};