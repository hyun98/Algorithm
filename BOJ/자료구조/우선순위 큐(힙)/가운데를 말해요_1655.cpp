#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, less<int> > maxheap;
priority_queue<int, vector<int>, greater<int> > minheap;
int N, center;

void working(int input){
    if(center <= input){
        if(minheap.size() == maxheap.size()) minheap.push(input);
        else if(minheap.size() > maxheap.size()){
            maxheap.push(center);
            if(input < minheap.top()) center = input;
            else{
                center = minheap.top();
                minheap.pop();
                minheap.push(input);
            }
        }
        else minheap.push(input);
    }
    else{
        if(minheap.size() == maxheap.size()){
            maxheap.push(input);
            minheap.push(center);
            center = maxheap.top();
            maxheap.pop();
        }
        else if(minheap.size() < maxheap.size()){
            minheap.push(center);
            if(input > maxheap.top()) center = input;
            else{
                minheap.push(center);
                center = maxheap.top();
                maxheap.pop();
                maxheap.push(input);
            }
        }
        else maxheap.push(input);
    }
}

void solve(){
    int input;
    cin >> N;
    cin >> center;
    cout << center << "\n";
    for(int i = 1; i < N; i++){
        cin >> input;
        working(input);
        cout << center << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    
    return 0;
}
