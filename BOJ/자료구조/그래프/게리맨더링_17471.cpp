#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n;
int popul[11];
bool isConnect[11][11];
const int INF = 987654321;
int best = INF;
bool visited[1000];
void BFS(vector<int>& picked, vector<bool>& c)
{
	queue<int> q;
	q.push(picked[0]);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < picked.size(); ++i)
		{
			int nx = picked[i];
			if (isConnect[x][nx] && !c[nx]) {
				c[nx] = true;
				q.push(nx);
			}
		}
	}
}
void solve(int cnt,int begin, vector<int>& picked, vector<int>& cand)
{
	if (picked.size() == cnt) {

		// 나머지
		vector<int> temp;

		for (int i = 0; i < cand.size(); ++i)
		{
			int x = cand[i];
			bool check = true;
			for (int j = 0; j < picked.size(); ++j) {
				if (x == picked[j]) {
					check = false;
					break;
				}
			}
			if (!check) continue;
			temp.push_back(x);
		}

		//picked 배열 연결 확인
		vector<bool> c(11);
		BFS(picked, c);
		bool check1 = true;
		if (picked.size() != 1) {
			for (int i = 0; i < picked.size(); ++i)
			{
				if (!c[picked[i]]) {
					check1 = false;
					break;
				}
			}
		}
		// 나머지 배열 연결 확인
		c = vector<bool>(11);
		BFS(temp, c);
		bool check2 = true;
		if (temp.size() != 1) {
			for (int i = 0; i < temp.size(); ++i)
			{
				if (!c[temp[i]]) {
					check2 = false;
					break;
				}
			}
		}
		// 조건을 만족한다면 차를 구한다.
		if (check1 && check2) {
			int s1 = 0, s2 = 0;
			for (int i = 0; i < picked.size(); ++i) {
				s1 += popul[picked[i]];
			}
			for (int i = 0; i < temp.size(); ++i) {
				s2 += popul[temp[i]];
			}
			best = min(best, abs(s1 - s2));
		}
		return;
	}
	for (int i = begin+1; i < cand.size(); ++i)
	{
		int x = cand[i];

		picked.push_back(cand[i]);
		solve(cnt,i, picked, cand);
		picked.pop_back();
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> popul[i];
	}

	for (int i = 1; i <= n; ++i)
	{
		int num;
		cin >> num;
		for (int j = 0; j < num; ++j)
		{
			int next;
			cin >> next;
			isConnect[i][next] = true;
			isConnect[next][i] = true;
		}
	}
	vector<int> cand;
	for (int i = 1; i <= n; ++i)
		cand.push_back(i);
	for (int i = 1; i < n; ++i)
	{
		vector<int> picked;
		solve(i,-1, picked, cand);
	}

	if (best == INF) {
		cout << -1 << "\n";
		return 0;
	}
	cout << best << "\n";
	return 0;
}
