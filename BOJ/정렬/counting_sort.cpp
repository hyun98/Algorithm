#include <iostream>
using namespace std;

int counting[10001] = {0, }, n, k;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &k);
        counting[k]++;
    }
    for(int i = 1; i <= 10000; i++){
        for(int j = 0; j < counting[i]; j++){
            printf("%d\n", i);
        }
    }
    return 0;
}
