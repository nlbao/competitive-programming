class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        root = new Node();
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string s) {
        pNode p = root;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int x = s[i];
            if (!p->next[x]) p->next[x] = new Node(0, p);
            p = p->next[x];
            ++(p->cnt);
        }
        ++(p->value);
        updateMaxMin(p);
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string s) {
        if (!containsKey(s)) return;
        pNode p = root;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int x = s[i];
            p = p->next[x];
            --(p->cnt);
        }
        --(p->value);
        updateMaxMin(p);
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        string ans = "";
        if (isEmpty()) return ans;
        pNode p = root;
        while (p && p->value != p->maxVal) {
            for (int x = 0; x < 255; ++x)
                if (p->next[x] && p->next[x]->maxVal == p->maxVal) {
                    ans.push_back(char(x));
                    p = p->next[x];
                }
        }
        return ans;
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        string ans = "";
        if (isEmpty()) return ans;
        pNode p = root;
        while (p && p->value != p->minVal) {
            for (int x = 0; x < 255; ++x)
                if (p->next[x] && p->next[x]->minVal == p->minVal) {
                    ans.push_back(char(x));
                    p = p->next[x];
                }
        }
        return ans;
    }

private:
    static const int oo = 1e9;

    // Trie
    struct Node {
        int value, cnt, maxVal, minVal;
        Node *next[255];
        Node *parent;

        Node(int val = 0, Node *p = NULL) {
            value = maxVal = val;
            minVal = val > 0 ? val : oo;
            cnt = 0;
            parent = p;
            for (int i = 0; i < 255; ++i)
                next[i] = NULL;
        }
    };
    typedef Node* pNode;

    // variables
    pNode root;

    // methods
    void updateMaxMin(pNode p) {
        while (p) {
            p->maxVal = p->value;
            p->minVal = p->value > 0 ? p->value : oo;
            for (int x = 0; x < 255; ++x)
                if (p->next[x]) {
                    p->maxVal = max(p->maxVal, p->next[x]->maxVal);
                    p->minVal = min(p->minVal, p->next[x]->minVal);
                }
            p = p->parent;
        }
    }

    bool containsKey(const string &s) {
        pNode p = root;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int x = s[i];
            if (!p->next[x]) return false;
            p = p->next[x];
        }
        return true;
    }

    bool isEmpty() {
        for (int x = 0; x < 255; ++x)
            if (root->next[x])
                return false;
        return true;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */