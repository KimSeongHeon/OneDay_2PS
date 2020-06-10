/*2020/06/04 두번째 분제
백준14938 서강그라운드*/
//다익스트라같음
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
struct cmp {
	bool operator()(pair<int, int> &a, pair<int, int> &b) {
		if (a.second == b.second) a.first > b.first;
		return a.second > b.second;
	}
};
int main() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
	int n, m, r,element;
	vector<int> item;
	vector<pair<int,int>> adj[100];
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		cin >> element;
		item.push_back(element);
	}
	for (int i = 0; i < r; i++) {
		int start, dest,weight;
		cin >> start >> dest >> weight;
		adj[start].push_back({ dest,weight });
		adj[dest].push_back({ start,weight });
	}
	int answer = -1;
	for (int i = 0; i < item.size(); i++) {
		int dist[101];
		fill(dist, dist + 101, INT_MAX);
		q.push({ i,0 });
		dist[i] = 0;
		while (!q.empty()) {
			pair<int, int> temp = q.top(); q.pop();
			int here = temp.first;
			int weight = temp.second;
			for (int j = 0; j < adj[here].size(); j++) {
				int next_x = adj[here][j].first;
				int next_cost = adj[here][j].second;
				if (dist[next_x] > dist[here] + next_cost) {
					dist[next_x] = dist[here] + next_cost;
					q.push({ next_x,next_cost});
				}
			}
		}
		answer = max(answer,)
	}
	cout << answer;

}