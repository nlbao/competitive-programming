class Solution {
public:
    string s1, s2;
    unordered_map<int, bool> answers; // 0 - not yet, 1 = match, 2 = not match
    int p[3];

    int hash(int x1, int x2, int len) {
        return x1*p[0] + x2*p[1] + len*p[2];
    }

    bool solve(int x1, int x2, int len) {
        if (len < 1) return true;
        if (len == 1) return s1[x1] == s2[x2];
        int y1 = x1+len-1, y2 = x2+len-1;

        // heuristics
        int cnt[255] = {};
        for (int i = x1; i <= y1; ++i) ++cnt[s1[i]];
        for (int i = x2; i <= y2; ++i) --cnt[s2[i]];
        for (int i = 0; i < 255; ++i)
            if (cnt[i] != 0)
                return false;

        // check if this case is solved before
        int hashVal = hash(x1, x2, len);
        __typeof(answers.begin()) it = answers.find(hashVal);
        if (it != answers.end())
            return it->second;

        // calculate the answer by recursive
        bool ans = false;
        for (int m1 = x1; m1 < y1 && !ans; ++m1) {
            int lenLeft = m1-x1+1, lenRight = y1-m1;
            ans = solve(x1, x2, lenLeft) && solve(m1+1, y2-lenRight+1, lenRight);
            if (!ans)
                ans = solve(x1, y2-lenLeft+1, lenLeft) && solve(m1+1, x2, lenRight);
        }
        return answers[hashVal] = ans;
    }

    bool isScramble(string s1, string s2) {
        this->s1 = s1;
        this->s2 = s2;
        int n1 = s1.size(), n2 = s2.size();
        if (n1 != n2) return false;
        p[0] = 1;
        for (int i = 1; i < 3; ++i)
            p[i] = p[i-1] * n1;
        answers.clear();
        return solve(0, 0, n1);
    }
};
