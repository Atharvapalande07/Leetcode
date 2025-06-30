class Solution {
public:

    bool allZeros(vector<int> & counter){
        for(int i=0 ; i<counter.size() ; i++){
            if(counter[i] != 0){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        vector<int> counter(26 , 0);

        for(int i=0 ; i<p.length() ; i++){
            char ch = p[i];
            counter[ch - 'a']++;

        }

        int i=0 , j=0;
        vector<int> result;
        int k =p.length();

        while(j <n ){

            counter[s[j]-'a']--;
            if(j-i+1 == k){
                if(allZeros(counter)){
                    result.push_back(i);
                }
                counter[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return result;
    }
};