//
//  백준5052 - 전화번호 목록.cpp
//  OneDay2PS
//
//  Created by 김성헌 on 2020/09/11.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define ALPHABETS 10

int char_to_index(char c) {
    return c - '0';
}
struct Trie {
    bool is_terminal; // this represents end of string
    Trie *children[ALPHABETS];
    // Constructor
    Trie() : is_terminal(false) {
        memset(children, 0, sizeof(children));
    }
    // Delete all children
    ~Trie() {
        for (int i = 0; i < ALPHABETS; ++i) {
            if (children[i])
                delete children[i];
        }
    }
    void insert(const char * key) {
        if (*key == '\0') {
            is_terminal = true;
        }
        else {
            int index = char_to_index(*key);
            if (children[index] == 0) {
                children[index] = new Trie();
            }
            children[index]->insert(key + 1);
        }
    }

    Trie* find(const char * key) {
        if (*key == 0) {
            return this;
        }
        int index = char_to_index(*key);
        if (children[index] == 0) {
            return NULL;
        }
        return children[index]->find(key + 1);
    }
};

bool cmp(string &str1,string &str2){
    return str1.size() > str2.size();
}

int main(){
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int n;
        cin >> n;
        Trie *root = new Trie();
        vector<string> v;
        bool check = false;
        for(int i=0;i<n;i++){
            string str;
            cin >> str;
            v.push_back(str);
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<v.size();i++){
            if(root->find(v[i].c_str())){
                check = true;
                break;
            }
            else root->insert(v[i].c_str());
        }
        if(check) cout << "NO" << endl;
        else cout <<"YES" << endl;
        root->~Trie();
    }
    return 0;
}
