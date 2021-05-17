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
    bool is_end = false;
    trie *child[NUM] = {NULL, };
};


bool check = false;
void Insert(string &str, trie *root){
    if(root->is_end){
        cout << "NO\n";
        check = true;
        return;
    }
    if(str.size() == 0){
        root->is_end = true;
        return;
    }
    else{
        int n = char_to_int(str[0]);
        if(root->child[n] == NULL) root->child[n] = new trie;
        str.erase(str.begin());
        Insert(str, root->child[n]);
    }
}

bool Compare(string a, string b){
    if(a.length() == b.length()) return a < b;
    else return a.length() < b.length();
}

void input(){
    vector<string> phone_list;
    string phone_n;
    int n;
    trie *root;
    root = new trie;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> phone_n;
        phone_list.push_back(phone_n);
    }

    sort(phone_list.begin(), phone_list.end(), Compare);
    for(int i = 0; i < phone_list.size(); i++){
        Insert(phone_list[i], root);
        if(check){
            check = false;
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int test_case;
    cin >> test_case;
    for(int i = 0; i < test_case; i++){
        input();
    }
    return 0;
}
