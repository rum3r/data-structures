#include<bits/stdc++.h>
using namespace std;
/*
    build/insert/search -> O(M) where M is max length of key
    memory -> O(N * alphabet_size * M) 
*/

struct Node {
    Node* children[26];
    bool isEnd;
    Node() {
        this->isEnd = false;
        for (int i = 0; i < 26; ++i) {
            this->children[i] = NULL;
        }
    }
};

void insert(Node* root, string key) {
    Node* tmp = root;
    if(!tmp)
        tmp = new Node();

    for (int i = 0; i < key.length(); ++i) {
        int ind = key[i] - 'a'; 
        if(!tmp->children[ind]) {
            tmp->children[ind] = new Node();
        }
        tmp = tmp->children[ind];
    }
    tmp->isEnd = true;
}
bool search(Node* root, string key) {
    Node* tmp = root;
    for (int i = 0; i < key.length(); ++i) {
        int ind = key[i] - 'a'; 
        if(!tmp->children[ind]) 
            return false;
        tmp = tmp->children[ind];
    }
    return tmp->isEnd;
}

int main() {
    Node* root = new Node();
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };

    for (int i = 0; i < 8; ++i) {
        insert(root, keys[i]);
    }

    search(root, "the")? cout << "Yes\n" :
                         cout << "No\n";
    search(root, "these")? cout << "Yes\n" :
                           cout << "No\n";
    return 0;
}