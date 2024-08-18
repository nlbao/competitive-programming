// https://leetcode.com/problems/minimize-or-of-remaining-elements-using-operations/
// status: WA

// WA test cases: 
//      [37,6,46,32,23]     k = 3

// OK test cases:
//      [39,11]     k = 1

class Solution {
// private:
    // // return false if exists at least 1-bit of x that is not in target
    // bool isBitwiseLessThan(int x, int target) {
    //     return ((x|target) == target);
    // }

    // bool solutionExists(vector<int>& nums, int k, int target) {
    //     // we will partition consecutive items in nums into multiple "good" and "bad" segments.
    //     // + good: isBitwiseLessThan(each elements in group) == true
    //     // + base: isBitwiseLessThan(AND of elements in group) == false
    //     // --> observation: in the result array, there are no two groups of the same type that are next to each other.
    //     // --> Then we just need to check if the number of "bad" group is <= k
    //     int n = nums.size();
    //     int goodCount = 0, badCount = 0;
    //     int prevValue = nums[0];
    //     bool isGoodGroup = isBitwiseLessThan(prevValue, target);
    //     if (isGoodGroup) ++goodCount;
    //     else ++badCount;
    //     // bool accepted = isBitwiseLessThan(prevValue, target);
    //     for (int i = 1; i < n && k >= 0; ++i) {
    //         int x = nums[i];
    //         bool newValueIsGood = isBitwiseLessThan(x, target);
    //         if (newValueIsGood) {
    //             if (isGoodGroup) { }
    //             else {
    //                 isGoodGroup = true;
    //                 ++goodCount;
    //             }
    //             prevValue = x;
    //         }
    //         else {
    //             if (isGoodGroup) {
    //                 isGoodGroup = false;
    //                 ++badCount;
    //                 prevValue = x;
    //             }
    //             else {
    //                 --k;    // merge 2 bad values into one
    //                 prevValue &= x;
    //                 cout << "   merge: " << "prevValue and " << x << " into " << prevValue << " target = " << target << endl;
    //                 if (isBitwiseLessThan(prevValue, target)) {
    //                     cout << "           . is good group now." << endl;
    //                     isGoodGroup = true;
    //                     --badCount;
    //                     ++goodCount;
                        
    //                 }
    //             }
    //         }


    //         // if (accepted) {
    //         //     if (newValueIsGood) {
    //         //         // case 1: accepted & x is good => do nothing, x is the new prevValue
    //         //         prevValue = x;
    //         //     }
    //         //     else {
    //         //         --k; // case 2: accepted & x is NOT good => merge (previous value, x) into a new accepted value
    //         //         prevValue &= x;
    //         //     }
    //         // }
    //         // else {
    //         //     if (newValueIsGood) {
    //         //         --k; // case 3: !accepted & x is good ==> merge (previous value, x) into a new accepted value
    //         //         prevValue &= x;
    //         //         accepted = true;
    //         //     }
    //         //     else {
    //         //         --k; // case 4: !accepted & x is NOT good ==> merge (previous value, x) into a new !accepted value
    //         //         prevValue &= x;
    //         //     }
    //         // }
    //         // accepted = isBitwiseLessThan(prevValue, target);
    //     }
    //     // return accepted && (k >= 0);
    //     // if (badCount > 0 && goodCount == 0) return isBitwiseLessThan(prevValue, target);
    //     return badCount <= k;
    // }

public:
    int minOrAfterOperations(vector<int>& nums, int k) {
        // Iterate bit positions from the highest (29) to 0:
        // With each bit position, check if we can elimitate all 1, with t operations, where m < k.
        // If yes, mark the items in nums that need to be operated, then set k -= t.
        // If no, do nothing and moves on to the lower bits.
        int n = nums.size();
        vector<bool> marked(n, false);
        for (int h = 29; h >= 0; --h) {
            int bitValue = 1<<h;
            int operationsNeeded = 0;
            for (int i = 0; i < n; ++i) {
                if (marked[i]) continue; // it will be merged with some other items, ignore.
                if (bitValue & nums[i]) ++operationsNeeded;
            }
            if (operationsNeeded > k || operationsNeeded == n) {
                // ans |= bitValue;
                continue; // too much operations needed, just let this bit be 1 and move on.
            }
            k -= operationsNeeded;
            for (int i = 0; i < n; ++i) {
                if (!marked[i] && (bitValue & nums[i])) {
                    marked[i] = true;  // this nums[i] will be merged with some other bit
                }
            }
        }
        // now, perform the operations to get the answer.
        for (int i = 0; i < n; ++i) {
            cout << marked[i] << " ";
        }
        cout << endl;
        int ans = 0, preValue = nums[0];
        bool preMarked = marked[0];
        for (int i = 1; i < n; ++i) {
            int x = nums[i];
            if (marked[i]) {
                if (preMarked) preValue &= x;  // merge preValue and nums[i]
                else {
                    preValue &= x;
                    // preMarked = false;
                }
            }
            else {
                if (preMarked) {
                    preValue &= x;
                    preMarked = false;   // change status
                }
                else {
                    // both good, so the result can OR preValue 
                    ans |= preValue;
                    preValue = x;
                }
            }
            
        }
        ans |= preValue;
        return ans;
    }
};