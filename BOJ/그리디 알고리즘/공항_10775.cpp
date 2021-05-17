#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int G, P, dock[100001];
int union_set[100001];

int find_top(int a){
    if(union_set[a] == a){
        return a;
    }
    return union_set[a] = find_top(union_set[a]);
}

bool make_union(int a){
    int top = find_top(a);
    if(union_set[top] == 0) return false;
    else{
        union_set[top]--;
        return true;
    }
}

void process(){
    cin >> G >> P;
    
    for(int i = 0; i <= G; i++){
        union_set[i] = i;
    }
    
    for(int i = 1; i <= P; i++){
        cin >> dock[i];
    }
    
    int cnt = 0;
    for(int i = 1; i <= P; i++){
        if(make_union(dock[i])){
            cnt++;
        }
        else break;
    }
    cout << cnt;
}

int main(){
    process();
    
    return 0;
}