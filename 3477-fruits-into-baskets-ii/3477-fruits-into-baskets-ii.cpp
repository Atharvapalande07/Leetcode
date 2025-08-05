class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count=0;
        
        for(int num : fruits){
            for(int j=0 ; j<baskets.size() ; j++){
                if(baskets[j] >= num){
                    baskets[j]=0;
                    count++;
                    break;
                }
            }
        }
        return fruits.size()- count;
        
    }
};