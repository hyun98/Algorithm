#include <iostream>
#include <vector>

using namespace std;

vector<int> arr, temparr;

int N;
long long Inv = 0;

void counting_inversions(int st, int ed){
    if(st == ed) return;
    
    int mid = (st + ed)/2;
    
    counting_inversions(st, mid);
    counting_inversions(mid+1, ed);
    
    int lo = st;
    int hi = mid+1;
    long long temp_Inv = 0;
    int idx = 0;
    
    while(lo <= mid || hi <= ed){
        if(lo <= mid && (hi > ed || arr[lo] < arr[hi])){
            temparr[idx++] = arr[lo++];
        }
        else{
            temparr[idx++] = arr[hi++];
            temp_Inv += (mid - lo + 1);
        }
    }
    
    for(int i = st; i <= ed; i++){
        arr[i] = temparr[i - st];
    }
    Inv += temp_Inv;
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    arr.resize(N+1);
    temparr.resize(N+1);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    counting_inversions(0, N-1);
    
    cout << Inv;
    
    return 0;
}