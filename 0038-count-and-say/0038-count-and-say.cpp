class Solution {
public:
    string rle(const string& s) {
        string res;
        char c = s[0];
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (c == s[i]) {
                count++;
            }

            else {
                res += to_string(count);
                res += c;
                c = s[i];
                count = 1;
            }
        }
        res += to_string(count);
        res += c;
        return res;
    }

    string countAndSay(int n) {
        string result = "1";
        for (int i = 1; i < n; i++) {
            result = rle(result);
        }
        return result;
    }
};