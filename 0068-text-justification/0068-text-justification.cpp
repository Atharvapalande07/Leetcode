class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int left = 0, right = 0, currLength = -1;

        while (right < words.size()) {
            currLength += words[right].size() + 1;

            if (currLength > maxWidth) {
                currLength -= words[right].size() + (right - left);
                string line;

                // Only one word
                if (right - left == 1) {
                    line = words[left] + string(maxWidth - currLength, ' ');
                } else {
                    int totalSpaces = maxWidth - currLength;
                    int gaps = right - left - 1;
                    int space = totalSpaces / gaps;
                    int extra = totalSpaces % gaps;

                    for (int i = left; i < right; ++i) {
                        line += words[i];
                        if (i != right - 1) {
                            line += string(space + (extra-- > 0 ? 1 : 0), ' ');
                        }
                    }
                }

                res.push_back(line);
                left = right;
                currLength = -1;
            } else {
                right++;
            }
        }

        // Handle last line (left-justified)
        string lastLine;
        for (int i = left; i < right; ++i) {
            lastLine += words[i];
            if (i != right - 1) lastLine += ' ';
        }
        lastLine += string(maxWidth - lastLine.size(), ' ');
        res.push_back(lastLine);

        return res;
    }
};