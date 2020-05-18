class Solution {
public:
    int countSmaller(vector<int> &a, double val) {
        int n = a.size();
        int l = 0, r = n-1, pos = -1;
        while (l <= r) {
            int mid = (l+r)>>1;
            if (a[mid] < val) pos = mid, l = mid+1;
            else r = mid-1;
        }
        return pos+1;
    }

    int countBigger(vector<int> &a, double val) {
        int n = a.size();
        int l = 0, r = n-1, pos = n;
        while (l <= r) {
            int mid = (l+r)>>1;
            if (a[mid] > val) pos = mid, r = mid-1;
            else l = mid+1;
        }
        return n-pos;
    }

    int countEqual(vector<int> &a, double val) {
        return (int)a.size() - countSmaller(a, val) - countBigger(a, val);
    }

    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int nA = a.size(), nB = b.size();
        if (nA+nB == 1) return nA ? a[0] : b[0];
        int half = (nA+nB)/2;
        if ((nA+nB)&1) ++half;

        // find the smallest number that >= at least haft elements
        double left = -1;
        double l = INT_MIN, r = INT_MAX;
        for (int i = 0; i < 100; ++i) {
            double mid = (l+r)/2;
            int cntSmaller = countSmaller(a, mid) + countSmaller(b, mid);
            int cntEqual = countEqual(a, mid) + countEqual(b, mid);
            int cnt = cntSmaller + cntEqual;
            if (cnt < half) l = mid;
            else left = mid, r = mid;
        }

        // find the biggest number that <= at least haft elements
        double right = -1;
        l = INT_MIN, r = INT_MAX;
        for (int i = 0; i < 100; ++i) {
            double mid = (l+r)/2;
            int cntBigger = countBigger(a, mid) + countBigger(b, mid);
            int cntEqual = countEqual(a, mid) + countEqual(b, mid);
            int cnt = cntBigger + cntEqual;
            if (cnt < half) r = mid;
            else right = mid, l = mid;
        }

        // calculate the answer
        return (left+right)/2.0;
    }
};
