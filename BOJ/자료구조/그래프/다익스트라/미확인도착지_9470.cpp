#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
 
vector<pair<int, int>>graph[2004];
bool check[2004];
int endp[104];  // 목적지 후보들
int stoa[2004]; // 시작점부터 도착점까지 직행 최단 거리를 저장하고 있는 배열
int gtoa[2004]; // g부터 다른 모든 점까지의 최단거리
int htoa[2004]; // h부터 다른 모든 점까지의 최단거리
 
void dijkstra(int s, int dis[]) {
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, s));
    while (!pq.empty()) {
        int now = pq.top().second;
        int wei = pq.top().first;
        pq.pop();
        if (check[now] == true) continue;
        check[now] = true;
        if (dis[now] < wei) continue;
        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;
            int w = graph[now][i].second;
            if (dis[now] + w < dis[next]) {
                dis[next] = dis[now] + w;
                pq.push(pii(dis[next], next));
            }
        }
    }
}
 
// 초기화 작업 꼭 해줘야 함!!!!!
void init() {
    // graph, check, stoa, gtoa, htoa
    memset(graph, 0, sizeof(graph));
    memset(check, false, sizeof(check));
    memset(stoa, 127, sizeof(stoa));
    memset(gtoa, 127, sizeof(gtoa));
    memset(htoa, 127, sizeof(htoa));
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t, n, m, k, s, g, h, a, b, d, x, gtoh;
    cin >> t;
    while (t--) {
        init();
        int INF = stoa[0];
        cin >> n >> m >> k;
        cin >> s >> g >> h;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> d;
            // 입력받을때 gtoh 미리 가지고 있기
            if ((a == g && b == h) || (a == h && b == g)) gtoh = d;
            // 양방향 간선임!
            graph[a].push_back(pii(b, d));
            graph[b].push_back(pii(a, d));
        }
        for (int i = 0; i < k; i++) {
            cin >> x;
            endp[i] = x;
        }

        dijkstra(s, stoa); // 시작점부터 다른 모든 지점까지의 최단거리 구하기
        memset(check, false, sizeof(check));
        dijkstra(g, gtoa); // g 부터 다른 모든 지점까지의 최단거리 구하기
        memset(check, false, sizeof(check));
        dijkstra(h, htoa); // h 부터 다른 모든 지점까지의 최단거리 구하기

        // 모든 도착지점들이 조건을 만족하는지 판단
        vector<int>ans;
        for (int i = 0; i < k; i++) {
            int node = endp[i];
            int temp;
            if (stoa[g] < stoa[h]) { // s-g가 s-h 보다 짧다면(최단)
                if (htoa[node] == INF) continue; // 경로가 존재하지 않는다면 불가!
                temp = stoa[g] + gtoh + htoa[node];
            }
            else {
                if (gtoa[node] == INF) continue;
                temp = stoa[h] + gtoh + gtoa[node];
            }
            if (temp <= stoa[node]) ans.push_back(node);
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}