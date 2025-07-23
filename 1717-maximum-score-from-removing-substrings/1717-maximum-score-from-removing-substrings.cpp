

class Solution {
public:
    int solve(string &s, char a, char b, int val) {
        stack<char> st;
        int pts = 0;
        for (char c : s) {
            if (!st.empty() && st.top() == a && c == b) {
                st.pop();
                pts += val;
            } else {
                st.push(c);
            }
        }
        s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return pts;
    }

    int maximumGain(string s, int x, int y) {
        int res = 0;
        if (x > y) {
            res += solve(s, 'a', 'b', x);
            res += solve(s, 'b', 'a', y);
        } else {
            res += solve(s, 'b', 'a', y);
            res += solve(s, 'a', 'b', x);
        }
        return res;
    }
};