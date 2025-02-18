// Leetcode 208
#include <string>
#include <vector>

struct TrieNode
{
    TrieNode() : isEnd(false), children(26, nullptr)
    {
    }
    ~TrieNode()
    {
        for (auto child : children)
        {
            if (child)
            {
                delete child;
            }
        }
    }
    std::vector<TrieNode *> children;
    bool isEnd;
};

class Trie
{
  public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(std::string word)
    {
        auto curr = root;
        for (auto c : word)
        {
            if (curr->children[c - 'a'] == nullptr)
            {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isEnd = true;
    }

    bool search(std::string word)
    {
        auto curr = root;
        for (auto c : word)
        {
            if (curr->children[c - 'a'] == nullptr)
            {
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return curr->isEnd;
    }

    bool startsWith(std::string prefix)
    {
        auto curr = root;
        for (auto c : prefix)
        {
            if (curr->children[c - 'a'] == nullptr)
            {
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return true;
    }

  private:
    TrieNode *root;
};