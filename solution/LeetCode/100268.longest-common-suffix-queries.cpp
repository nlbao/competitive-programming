struct Node
{
    Node *nexts[26];
    int lcs_idx; // longest common suffix index.

    Node()
    {
        for (int i = 0; i < 26; ++i)
            nexts[i] = NULL;
        lcs_idx = -1;
    }

    Node *getOrCreateNext(int x)
    {
        if (nexts[x] == NULL)
        {
            nexts[x] = new Node();
        }
        return nexts[x];
    }
};

typedef Node *pNode;

class Solution
{
private:
public:
    vector<int> stringIndices(vector<string> &wordsContainer, vector<string> &wordsQuery)
    {
        // build Trie
        pNode root = new Node();
        int minWordLenIdx = 0;
        for (int i = 0; i < wordsContainer.size(); ++i)
        {
            pNode p = root;
            string &word = wordsContainer[i];
            int crrWordLen = word.length();
            if (crrWordLen < wordsContainer[minWordLenIdx].length())
            {
                minWordLenIdx = i;
            }
            for (int k = crrWordLen - 1; k >= 0; --k)
            {
                int x = word[k] - 'a';
                pNode nextNode = p->getOrCreateNext(x);
                int lcs_idx = nextNode->lcs_idx;
                if (lcs_idx == -1 || (wordsContainer[lcs_idx].length() > crrWordLen))
                {
                    nextNode->lcs_idx = i;
                }
                p = nextNode;
            }
        }

        // search
        vector<int> ans;
        for (int i = 0; i < wordsQuery.size(); ++i)
        {
            pNode p = root;
            string &word = wordsQuery[i];
            int lcs_idx = -1;
            for (int k = word.length() - 1; k >= 0; --k)
            {
                int x = word[k] - 'a';
                pNode nextNode = p->nexts[x];
                if (nextNode == NULL)
                    break;
                if (nextNode->lcs_idx > -1)
                {
                    lcs_idx = nextNode->lcs_idx;
                }
                p = nextNode;
            }
            if (lcs_idx == -1)
            { // common suffix is empty, then take the shortest word.
                lcs_idx = minWordLenIdx;
            }
            ans.push_back(lcs_idx);
        }
        return ans;
    }
};