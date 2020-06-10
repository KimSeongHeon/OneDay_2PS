/*2020/06/10 첫번쨰 문제
백준9370 미확인 도착지*/
//단순 경로 저장하여 경로 있는지 판별 => 문제점 단 한가지 경로 밖에 찾지 않기 떄문에 문제 발생
// 다익스트라를 두번돌리며 문제를 해결
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<pair<int, int>> adj[2010];
int dist_s[2010];
int dist_g[2010];
int dist_h[2010];
struct cmp {
	bool operator()(pair<int, int> &a, pair<int, int> &b) {
		return a.first > b.first;
	}
};
bool gre(int &a,int &b) {
	return a < b;
}
void dijkstra(int start,int dist[2001]) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
	q.push({ start,0 });
	dist[start] = 0;
	while (!q.empty()) {
		int here = q.top().first;
		int weight = q.top().second;
		q.pop();
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int next_weight = adj[here][i].second;
			if (dist[there] > weight + next_weight) {
				q.push({ there,weight + next_weight });
				dist[there] = weight + next_weight;
			}
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n, m, cand,s,g,h;
		for (int i = 0; i < 2010; i++) {
			adj[i].clear();
			dist_s[i] = 1e10;
			dist_g[i] = 1e10;
			dist_h[i] = 1e10;
		}
		vector<int> dest_cand;
		cin >> n >> m >> cand;
		cin >> s >> g >> h;
		for (int i = 0; i < m; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			adj[a].push_back({ b,d });
			adj[b].push_back({ a,d });
		}
		for (int i = 0; i < cand; i++) {
			int dest;
			cin >> dest;
			dest_cand.push_back(dest);
		}
		dijkstra(s, dist_s);
		dijkstra(g, dist_g);
		dijkstra(h, dist_h);
		sort(dest_cand.begin(), dest_cand.end(), gre);
		for (int i = 0; i < dest_cand.size(); i++) {
			int x = dest_cand[i];
			if (dist_s[x] == dist_s[g] + dist_g[h] + dist_h[x]) cout << x << " ";
			else if (dist_s[x] == dist_s[h] + dist_h[g] + dist_g[x]) cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}