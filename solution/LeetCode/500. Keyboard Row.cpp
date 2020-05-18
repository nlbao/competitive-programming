class Solution {
public:
    string row0 = "qwertyuiop";
    string row1 = "asdfghjkl";
    string row2 = "zxcvbnm";

    bool inString(char x, const string &s) {
        for (int i = 0; i < s.length(); ++i)
            if (s[i] == x) return true;
        return false;
    }

    int getRow(char x) {
        x = tolower(x);
        return inString(x, row0) ? 0 : inString(x, row1) ? 1 : 2;
    }

    bool inSameRow(const string &s) {
        int row = -1;
        for (int i = 0; i < s.length(); ++i) {
            int r = getRow(s[i]);
            if (row < 0) row = r;
            else if (row != r) return false;
        }
        return true;
    }

    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            if (inSameRow(words[i]))
                ans.push_back(words[i]);
        }
        return ans;
    }
};