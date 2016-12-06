class Solution {
public:
    int findKth(vector<int> &a, int la, int ra, vector<int> &b, int lb, int rb, int k) {
        if (la > ra) return b[lb+k-1];
        if (lb > rb) return a[la+k-1];
        int ma = (la+ra)>>1, mb = (lb+rb)>>1;
        int lenLeftA = ma-la+1, lenLeftB = mb-lb+1;
        if (k < lenLeftA + lenLeftB) {
            if (a[ma] <= b[mb]) return findKth(a, la, ra, b, lb, mb-1, k);
            else return findKth(a, la, ma-1, b, lb, rb, k);
        }
        else {
            if (a[ma] <= b[mb]) return findKth(a, ma+1, ra, b, lb, rb, k - lenLeftA);
            else return findKth(a, la, ra, b, mb+1, rb, k - lenLeftB);
        }
    }

    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int nA = a.size(), nB = b.size();
        if (nA+nB == 1) return nA ? a[0] : b[0];
        int midLeft = (nA+nB+1) / 2;
        int midRight = ((nA+nB)&1) ? midLeft : midLeft + 1;
        double l = findKth(a, 0, nA-1, b, 0, nB-1, midLeft);
        double r = findKth(a, 0, nA-1, b, 0, nB-1, midRight);
        return (l+r)/2.0;
    }
};
