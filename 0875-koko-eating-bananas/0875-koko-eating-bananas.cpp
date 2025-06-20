#define ll long long
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        ll start = 1, end = 1000000000,ans = 1000000000;
        while(start <= end){
            ll mid = (end + start)/2, totalMoves = 0;

            for(auto x:piles)
                totalMoves += (x/mid) + ((x%mid)!=0?1:0);
            
            if(totalMoves <= h){
                end = mid-1;
                ans = mid;
            } else
                start = mid+1;
        }
        return ans;
    }
};