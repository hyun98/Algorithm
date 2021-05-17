#include<bits/stdc++.h>

using namespace std;
int N, payStart, payEnd, ans = 0, now;
vector<int> vdata;
stack<int> sidx;
int main() {

	cin >> N;
	vdata.resize(N+2, 0);

	for (int i = 1; i <= N; i++){
        cin >> vdata[i];
    }
    
	sidx.push(0);
	for (int i = 1; i <= N+1; i++) {
		if(vdata[sidx.top()] >= vdata[i]){
            while (!sidx.empty() && vdata[sidx.top()] >= vdata[i]) {
                int maxPay = vdata[sidx.top()];
                sidx.pop();
                if(!sidx.empty()){
                    cout << i-1-sidx.top() << endl;
                    ans = max(ans, (i-1 - sidx.top()) * maxPay);
                }
            }
        }
		sidx.push(i);
	}
	
	cout << ans;

	return 0;
}