#include <iostream>
#include <cstring>
using namespace std;

int Cownum[11];
int cowcount;
int N;

int main(){
    cin >> N;
    memset(Cownum, -1, sizeof(Cownum));
    int u, v;
    for(int i = 0; i < N; i++){
        cin >> u >> v;
        if(Cownum[u] == -1) Cownum[u] = v;
        else if(Cownum[u] != v){
            Cownum[u] = v;
            cowcount++;
        }
    }
    cout << cowcount;
    return 0;
}
