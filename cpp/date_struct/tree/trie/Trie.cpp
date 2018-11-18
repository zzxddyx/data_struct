#include<iostream>
#include <vector>
#include <string>

using namespace std;

struct Node
{
    bool isWorld;
    Node *next[26];

    Node()
    {
        isWorld = false;
        for (int i = 0; i < 2 6; ++i)
        {
            next[i] = NULL;
        }
    }
};


class Trie
{
    public:
        Trie()
        {
            root = NULL;
        }

    public:
        void Insert(string str)
        {
            if (!root)
            {
                root = new Node();
            }

            Node *head = root;
            for (int i = 0; i < str.length(); ++i)
            {
                int num = str[i] - 'a';
                if (head->next[num] == NULL)
                {
                    head->next[num] = new Node();
                }
                head = head->next[num];
            }
            head->isWorld = true;
        }

    private:
        Node *root;
};
