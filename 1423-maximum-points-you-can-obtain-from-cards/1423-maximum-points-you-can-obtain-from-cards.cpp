class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int left = 0;
        int right =k-1;

        if(n < k){
            return 0;
        }
        
        int windowsum=0;

        for(int i=0 ; i<k ; i++){
            windowsum+=cardPoints[i];
        }
        int maxans=windowsum;

        for(int i =1 ; i<=k ; i++){
            windowsum=windowsum-cardPoints[k-i];
            windowsum=windowsum+cardPoints[n-i];
            maxans=max(maxans,windowsum);
        }
        return maxans;

        
    }
};