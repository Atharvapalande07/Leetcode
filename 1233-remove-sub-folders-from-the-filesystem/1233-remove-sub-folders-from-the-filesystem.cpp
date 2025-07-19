class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();

        sort(folder.begin(), folder.end());
        string root = folder[0];
        vector<string> ans;
        ans.push_back(root);
        for(int i= 1;i<n;i++)
        {
            int k = root.size();
            if(folder[i].substr(0,k) == root && folder[i][k] == '/')
            {
                continue;
            }
            else
            {
                ans.push_back(folder[i]);
                root = folder[i];
            }
        }
        return ans;
    }
};