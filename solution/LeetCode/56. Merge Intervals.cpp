/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    inline static bool cmp(const Interval &a, const Interval &b) {
        if (a.start != b.start) return a.start < b.start;
        return a.end < b.end;
    }

    inline bool isEmpty(const Interval &a) {
        return a.start > a.end;
    }

    inline bool isIntersect(const Interval &a, const Interval &b) {
        return !isEmpty(Interval(max(a.start, b.start), min(a.end, b.end)));
    }

    inline Interval merge(const Interval &a, const Interval &b) {
        return Interval(min(a.start, b.start), max(a.end, b.end));
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n < 2) return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> ans;
        for (int i = 0; i < n; ) {
            Interval x = intervals[i];
            while (i<n && isIntersect(x, intervals[i])) {
                x = merge(x, intervals[i]);
                ++i;
            }
            ans.push_back(x);
        }
        return ans;
    }
};