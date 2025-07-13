class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
if (words.empty()) return res;
int wordLen = words[0].length(), wordCount = words.size(), totalLen = wordLen * wordCount;
unordered_map<string, int> wordMap;
for (auto& w : words) ++wordMap[w];

  for (int i = 0; i <= (int)s.length() - totalLen; ++i) {
unordered_map<string, int> seen;
 int j = 0;
 for (; j < wordCount; ++j) {
    string sub = s.substr(i + j * wordLen, wordLen);
   if (++seen[sub] > wordMap[sub]) break;
        }
   if (j == wordCount) res.push_back(i);
  }
  return res;
    }
};