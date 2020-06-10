/*2020/06/10 ù��° ����
����10282 ��ŷ(���ͽ�Ʈ�� �˰���)*/
//������(dependency) = �ᱹ �׷��� ����
//�׷��� ���迡�� ���ο� ���� �̵����� �����ϸ� ����
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct cmp {
	bool operator()(pair<int, int> &a, pair<int, int> &b) {
		return a.second > b.second;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n, d, c;
		cin >> n >> d >> c;
		vector<pair<int, int>> adj[10001];
		int dist[10001];
		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			adj[b].push_back({a,s});
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
		fill(dist, dist + n + 1, 1e9);
		q.push({ c,0 });
		dist[c] = 0;
		while (!q.empty()) {
			int x = q.top().first;
			int weight = q.top().second;
			q.pop();
			for (int i = 0; i < adj[x].size(); i++) {
				int next = adj[x][i].first;
				int next_weight = adj[x][i].second;
				if (dist[next] > weight + next_weight) {
					q.push({next,weight + next_weight });
					dist[next] = weight + next_weight;
				}
			}
		}
		int cnt = 0;
		int sum = -1;
		for (int i = 1; i <= n; i++) {
			if (dist[i] != 1e9) {
				cnt++;
				sum = max(sum, dist[i]);
			}
		}
		cout << cnt << " " << sum << "\n";
	}
	return 0;
}