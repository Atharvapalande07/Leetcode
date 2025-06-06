class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_candies = 0;

        if (!candies.empty()) {
            max_candies = *std::max_element(candies.begin(), candies.end());
        }
        std::vector<bool> result;
        result.reserve(candies.size());

        for (int i = 0; i < candies.size(); ++i) {
            int candies_with_extra = candies[i] + extraCandies;

            if (candies_with_extra >= max_candies) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }

        return result;
    }
};