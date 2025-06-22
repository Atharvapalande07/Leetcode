class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token = "";
        string result = "";

        while (ss >> token) {
            result = token + " " + result;
        }

        // Remove trailing space if present
        if (!result.empty()) {
            result.pop_back();  // remove the extra space at the end
        }

        return result;
    }
};
