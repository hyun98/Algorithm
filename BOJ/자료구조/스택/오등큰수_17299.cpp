#include <iostream>
#include <stack>
#include <cstring>

#define pii pair<int, int>
using namespace std;

int N, NGE[1000001], arr[1000001], counting[1000001];
stack<pii> stk;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        counting[arr[i]]++;
    }
    
    memset(NGE, -1, sizeof(NGE));
    
    int arrnow, countingnow;
    pii stktop;
    
    for(int i = 1; i <= N; i++){
        if(stk.empty()) stk.push({counting[arr[i]], i});
        else{
            arrnow = arr[i];
            countingnow = counting[arr[i]];
            stktop = stk.top();
            while(stktop.first < counting[arr[i]]){
                NGE[stktop.second] = arr[i];
                stk.pop();
                if(!stk.empty()) stktop = stk.top();
                else break;
            }
            
            stk.push({counting[arr[i]], i});
        }
    }
    
    for(int i = 1; i <= N; i++){
        cout << NGE[i] << " ";
    }
    
    return 0;
}
