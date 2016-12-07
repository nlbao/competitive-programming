class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(NULL));
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool ans = positionsOfValue[val].empty();
        values.push_back(val);
        positionsOfValue[val].insert(values.size()-1);
        return ans;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (positionsOfValue[val].empty())
            return false;
        int pos = *positionsOfValue[val].begin(), last = values.size()-1;
        removeAt(pos);
        if (last > pos) {
            removeAt(last);
            values[pos] = values[last];
            positionsOfValue[values[pos]].insert(pos);
        }
        values.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        int n = values.size();
        return n ? values[rand() % (values.size())] : -1;
    }

private:
    unordered_map<int, unordered_set<int> > positionsOfValue;
    vector<int> values;

    void removeAt(int pos) {
        int val = values[pos];
        positionsOfValue[val].erase(pos);
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */