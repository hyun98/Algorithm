#include <iostream>
#include <cstring>

typedef long long ll;
using namespace std;

int N, R, G, B;

ll cache[11][60][60][60];
int fact[11];

int getFacto(int n){
    if(n == 0 || n == 1) return 1;
    if(fact[n]) return fact[n];
    return fact[n] = n * getFacto(n-1);
}

int numCase(int facto, int r, int g, int b){
    return facto / getFacto(r) / getFacto(g) / getFacto(b);
}

ll dfs(int lv, int r, int g, int b){
    if(lv > N) return 1;
    
    ll &ret = cache[lv][r][g][b];
    if(ret != -1) return ret;
    
    ret = 0;
    
    // 1가지 색 사용
    if(R - r >= lv) ret += dfs(lv+1, r+lv, g, b);
    if(G - g >= lv) ret += dfs(lv+1, r, g+lv, b);
    if(B - b >= lv) ret += dfs(lv+1, r, g, b+lv);
    
    // 2가지 색 사용
    if(lv % 2 == 0){
        if(R - r >= lv/2 && G - g >= lv/2){
            ret += (numCase(getFacto(lv), lv/2, lv/2, 0) * dfs(lv+1, r+lv/2, g+lv/2, b));
        }
        if(B - b >= lv/2 && G - g >= lv/2) {
            ret += (numCase(getFacto(lv), 0, lv/2, lv/2) * dfs(lv+1, r, g+lv/2, b+lv/2));
        }
        if(R - r >= lv/2 && B - b >= lv/2){
            ret += (numCase(getFacto(lv), lv/2, 0, lv/2) * dfs(lv+1, r+lv/2, g, b+lv/2));
        }
    }
    
    // 3가지 색 사용
    if(lv % 3 == 0 && R - r >= lv/3 && G - g >= lv/3 && B - b >= lv/3){
        ret += (numCase(getFacto(lv), lv/3, lv/3, lv/3) * dfs(lv+1, r+lv/3, g+lv/3, b+lv/3));
    }
    
    return ret;
}

int main(){
    cin >> N >> R >> G >> B;
    memset(cache, -1, sizeof(cache));
    cout << dfs(1, 0, 0, 0);
    
    return 0;
}
