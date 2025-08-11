class Solution {
public:
    unordered_map<string, bool> hash;
    Solution(){
        vector<string> s = {"011237","0122579","012356789","0124",
        "0134449", "0145678","01466788","0248","0368888","0469",
        "1","112234778","11266777","122446","125","128","1289","13468",
        "16","2","224588","23","23334455","234455668","23678",
        "256","35566","4","46","8"};
        for(int i = 0; i < s.size(); ++i){
            hash[s[i]] = true;
        }
    }
    string extract(int& n){
        string s;
        while(n != 0){
            int temp = n % 10;
            n = n / 10;
            s += to_string(temp);
        }
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string s = extract(n);
        sort(s.begin(), s.end(), [](char& a, char& b){return a < b;});
        return hash.contains(s) == true? true: false;
    }
};