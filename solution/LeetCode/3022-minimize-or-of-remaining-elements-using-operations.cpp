// https://leetcode.com/problems/minimize-or-of-remaining-elements-using-operations/
// status: WA

class Solution {
private:
    // return false if exists at least 1-bit of x that is not in target
    bool isBitwiseLessThan(int x, int target) {
        return ((x|target) == target);
    }

    bool solutionExists(vector<int>& nums, int k, int target) {
        // we will partition consecutive items in nums into multiple "good" and "bad" segments.
        // + good: isBitwiseLessThan(each elements in group) == true
        // + base: isBitwiseLessThan(AND of elements in group) == false
        // --> observation: in the result array, there are no two groups of the same type that are next to each other.
        // --> Then we just need to check if the number of "bad" group is <= k
        int n = nums.size();
        int goodCount = 0, badCount = 0;
        int prevValue = nums[0];
        bool isGoodGroup = isBitwiseLessThan(prevValue, target);
        if (isGoodGroup) ++goodCount;
        else ++badCount;
        // bool accepted = isBitwiseLessThan(prevValue, target);
        for (int i = 1; i < n && k >= 0; ++i) {
            int x = nums[i];
            bool newValueIsGood = isBitwiseLessThan(x, target);
            if (newValueIsGood) {
                if (isGoodGroup) { }
                else {
                    isGoodGroup = true;
                    ++goodCount;
                }
                prevValue = x;
            }
            else {
                if (isGoodGroup) {
                    isGoodGroup = false;
                    ++badCount;
                    prevValue = x;
                }
                else {
                    --k;    // merge 2 bad values into one
                    prevValue &= x;
                    cout << "   merge: " << "prevValue and " << x << " into " << prevValue << " target = " << target << endl;
                    if (isBitwiseLessThan(prevValue, target)) {
                        cout << "           . is good group now." << endl;
                        isGoodGroup = true;
                        --badCount;
                        ++goodCount;
                        
                    }
                }
            }


            // if (accepted) {
            //     if (newValueIsGood) {
            //         // case 1: accepted & x is good => do nothing, x is the new prevValue
            //         prevValue = x;
            //     }
            //     else {
            //         --k; // case 2: accepted & x is NOT good => merge (previous value, x) into a new accepted value
            //         prevValue &= x;
            //     }
            // }
            // else {
            //     if (newValueIsGood) {
            //         --k; // case 3: !accepted & x is good ==> merge (previous value, x) into a new accepted value
            //         prevValue &= x;
            //         accepted = true;
            //     }
            //     else {
            //         --k; // case 4: !accepted & x is NOT good ==> merge (previous value, x) into a new !accepted value
            //         prevValue &= x;
            //     }
            // }
            // accepted = isBitwiseLessThan(prevValue, target);
        }
        // return accepted && (k >= 0);
        // if (badCount > 0 && goodCount == 0) return isBitwiseLessThan(prevValue, target);
        return badCount <= k;
    }

public:
    int minOrAfterOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        for (int i = 0; i < n; ++i) {
            r |= nums[i];
        }
        int ans = r;
        while (l <= r) {
            int mid = (l+r)>>1;
            bool tmp = solutionExists(nums, k, mid);
            cout << "mid : " << mid << " result = " << tmp << endl;
            if (tmp) {
            // if (solutionExists(nums, k, mid)) {
                ans = mid;
                // cout << "mid ok : " << mid << endl;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};