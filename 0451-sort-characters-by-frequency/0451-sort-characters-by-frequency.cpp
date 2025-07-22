class Solution {
public:
    typedef pair<char,int> P;

    string frequencySort(string s) {
        vector<P> vec(123);  // To store frequency for ASCII characters

        for (char &ch : s) {
            vec[ch].first = ch;     // Ensure character is stored
            vec[ch].second++;       // Increment frequency
        }

        // Sort in descending order of frequency
        auto lambda = [&](P &p1 , P &p2){
            return p1.second > p2.second;
        };
        sort(vec.begin(), vec.end(), lambda);

        string result = "";

        for (int i = 0; i < 123; i++) {
            if (vec[i].second > 0) {
                result += string(vec[i].second, vec[i].first);
            }
        }

        return result;
    }
};
