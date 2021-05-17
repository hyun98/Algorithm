#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define NUM 10
using namespace std;

int char_to_int(const char c){
    return c-'0';
}

struct trie{
    bool is_in = false, is_end = false;
    trie *child[NUM] = {NULL, };
};

bool check = false;
void Insert(string &str, trie *root){
    if(str.size() == 0){
        if(root->is_in){
            check = true;
        }
        root->is_in = true;
        root->is_end = true;
        return;
    }
    if(root->is_end){
        check = true;
        return;
    }
    root->is_in = true;
    int n = char_to_int(str[0]);
    if(root->child[n] == NULL) root->child[n] = new trie;
    str.erase(str.begin());
    Insert(str, root->child[n]);
}

void input(){
    string phone_n;
    int n;
    trie *root;
    root = new trie;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> phone_n;
        Insert(phone_n, root);
    }
    if(check) cout << "NO\n";
    else cout << "YES\n";
    check = false;
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int test_case;
    cin >> test_case;
    while(test_case--){
        input();
    }
    return 0;
}
