#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007ll
#define endl "\n"
using namespace std::chrono;

class Trie;

class Node
{
private:
    unordered_map<char, Node *> character;
    bool endofword;
    friend class Trie;

public:
    Node()
    {
        endofword = false;
    }
};

class Trie
{
private:
    Node *head;
    bool have_children(Node *curr) //Returns true if the curr node has any children
    {
        for (auto itr : curr->character)
        {
            if (itr.second != NULL)
            {
                return true;
            }
        }
        return false;
    }
    Node* remove_int(Node *curr, string s, int index)
    {
        if (curr == NULL)
        {
            return NULL;
        }
        if (index == s.size())
        {
            curr->endofword = false;
            if (have_children(curr) == false)
            {
                delete (curr);
                curr = NULL;
            }
            return curr;
        }
        curr->character[s[index]] = remove_int(curr->character[s[index]], s, index + 1);
        if (have_children(curr) == false && curr->endofword == false)
        {
            delete (curr);
            curr = NULL;
        }
        return curr;
    }

public:
    Trie()
    {
        head = new Node();
    }
    void insert(string s)
    {
        Node *curr = head;
        for (char x : s)
        {
            if (curr->character.find(x) == curr->character.end())
            {
                curr->character[x] = new Node();
            }
            curr = curr->character[x];
        }
        curr->endofword = true;
    }
    bool search(string s)
    {
        if (head == NULL)
        {
            return false;
        }
        Node *curr = head;
        for (char x : s)
        {
            curr = curr->character[x];
            if (curr == NULL)
            {
                return false;
            }
        }
        return curr->endofword;
    }
    bool remove(string s)
    {
        if (search(s))
        {
            remove_int(head, s, 0);
            return true;
        }
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Trie t;
    vector<string> keys = {"the", "a", "there",
                           "answer", "any", "by",
                           "bye", "their", "hero", "heroplane"};
    for(int x=0;x<keys.size();x++)
    {
        t.insert(keys[x]);
    }
    cout<<t.search("the")<<endl;
    cout<<t.search("these")<<endl;
    cout<<t.remove("hero")<<endl;
    cout<<t.remove("hero")<<endl;
    cout<<t.search("heroplane")<<endl;
    return 0;
}