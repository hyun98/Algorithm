#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int N, M, x
vector<int> card;
vector<pair<int, int>> to_find;
void solve(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x;
        card.push_back(x);
    }
    cin >>M;
    for(int i = 0; i < M; i++){
        cin >> x;
        to_find.push_back(make_pair(x, i));
    }
    sort(card.begin(), card.end());
    sort(to_find.begin(), to_find.end());
    int an = 0, bn = 0;
    while(true){


    }

}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

    return 0;
}









#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,temp;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> m;
	vector<pair<int, int>> b(m);
	int check[500001] = { 0, };
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		b[i] = make_pair(temp, i);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int an = 0, bn = 0;
	while (true)
	{
		if (a[an] == b[bn].first)
		{
			check[b[bn].second] = check[b[bn].second] + 1;
			an = an + 1;
		}
		else if (a[an] > b[bn].first)
		{
			bn = bn + 1;
		}
		else if (a[an] < b[bn].first)
		{
			an = an + 1;
		}
		if (bn == m || an == n)
		{
			break;
		}
	}
	for (int i = 0; i < m-1; i++)
	{
		if (b[i].first == b[i + 1].first)
		{
			check[b[i + 1].second] = check[b[i].second];
		}
	}
	for (int i = 0; i < m; i++)
	{
		cout << check[i] << ' ';
	}
}
