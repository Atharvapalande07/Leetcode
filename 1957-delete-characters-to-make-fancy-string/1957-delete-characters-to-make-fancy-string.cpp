class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();

        string result="";
        result+=s[0];
        int count =1;

        for (int i = 1; i < n; i++) {
            if (s[i - 1] == s[i]) {
                count++;
            } else {
                count = 1;
            }
            if (count < 3) {
                result += s[i];
            }
        }
        return result;
    }
};