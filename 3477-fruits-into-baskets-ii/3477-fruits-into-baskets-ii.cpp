
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int j = 0;
        int output = 0;

        while (!fruits.empty() && !baskets.empty()) {
             if (j == baskets.size()) {
                fruits.erase(fruits.begin());
                output++;
                j = 0;
            }
            else if (fruits[0] <= baskets[j]) {
                fruits.erase(fruits.begin());
                baskets.erase(baskets.begin() + j);
                 j = 0;
            }
            else {
                j++;
                
            }
        }
        output += fruits.size();
        return output;
    }
};