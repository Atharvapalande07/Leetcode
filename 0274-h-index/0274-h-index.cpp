class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==1)
        {
            if(citations[0]==0)
            return 0;
            else
            return 1;
        }
        sort(citations.begin(),citations.end());
        int h=1;
        for(int i=citations.size()-1;i>=0;i--)
        {
            if(citations[i]>=h)
               h++;
            else 
            break;
        }
        return h-1;
    }
};