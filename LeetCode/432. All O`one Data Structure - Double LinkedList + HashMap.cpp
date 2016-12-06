class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        firstBucket = lastBucket = new Node(0);
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string s) {
        __typeof(bucketOf.begin()) it = bucketOf.find(s);
        pNode p = (it == bucketOf.end()) ? firstBucket : it->second;
        p->keys.erase(s);
        int val = p->val;
        if (p->right && p->right->val == val+1)
            p->right->keys.insert(s);
        else {
            pNode q = new Node(val+1);
            insertNode(p, q, p->right);
            q->keys.insert(s);
        }
        bucketOf[s] = p->right;
        if (p->right->val > lastBucket->val)
            lastBucket = p->right;
        if (p->keys.empty()) removeNode(p);
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string s) {
        __typeof(bucketOf.begin()) it = bucketOf.find(s);
        pNode p = (it == bucketOf.end()) ? firstBucket : it->second;
        if (p->val == 0) return;
        p->keys.erase(s);
        int val = p->val;
        if (p->left && p->left->val == val-1)
            p->left->keys.insert(s);
        else {
            pNode q = new Node(val-1);
            insertNode(p->left, q, p);
            q->keys.insert(s);
        }
        bucketOf[s] = p->left;
        if (lastBucket->keys.empty())
            lastBucket = p->left;
        if (p->keys.empty()) removeNode(p);
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (lastBucket == firstBucket) return "";
        return *(lastBucket->keys.begin());
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (!firstBucket->right) return "";
        return *(firstBucket->right->keys.begin());
    }

private:
    // value list
    struct Node {
        int val;
        unordered_set<string> keys;
        Node *left, *right;
        Node(int val = -1) {
            this->val = val;
            left = right = NULL;
        }
    };
    typedef Node* pNode;

    pNode firstBucket, lastBucket;
    unordered_map<string, pNode> bucketOf;


    void insertNode(pNode a, pNode x, pNode b) {
        if (a) a->right = x, x->left = a;
        if (b) b->left = x, x->right = b;
    }

    void removeNode(pNode p) {
        if (!p) return;
        if (p->val == 0) return;
        if (p == lastBucket)
            lastBucket = p->right ? p->right : p->left;
        if (p->right) p->right->left = p->left;
        if (p->left) p->left->right = p->right;
        delete p;
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