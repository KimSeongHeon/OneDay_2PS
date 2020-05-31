/*2020/05/31 첫번째 문제
백준1753 최단경로(그래프 탐색)*/
//그래프 탐색(다익스트라, 플루이드 워셜 ,벨만 포드)
//이 문제는 노드가 20000개이기 때문에 다익스트라로 풀어야 시간초과가 나지 않음
//시작점 받고 탐색하고 업데이트 해주면 됨.
// 주의해야 할점은 갱신될 때에만 Queue에 넣어줌
//시도 횟수 : 1번, 구현 시간: 20분
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int V, E, start;
int dist[20001];
vector<pair<int, int>> graph[20001];
struct cmp {
	bool operator()(pair<int,int> a,pair<int,int> b) {
		if (a.second == b.second) return a.first > b.first;
		return a.second > b.second;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
void dijkstra(int start) {
	fill(dist, dist + 20001, 1e9);
	q.push({ start ,0});
	dist[start] = 0;
	while (!q.empty()) {
		int x = q.top().first;
		int weight = q.top().second;
		q.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			int next_x = graph[x][i].first;
			int next_weight = graph[x][i].second;
			if (dist[next_x] > weight + next_weight) {//작아지는 경우 갱신,dist 업데이트
				q.push({ next_x,weight + next_weight });
				dist[next_x] = weight + next_weight;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> V >> E;
	cin >> start;
	for (int i = 0; i < E; i++) {
		int begin, end, weight;
		cin >> begin >> end >> weight;
		graph[begin].push_back({ end,weight });
	}
	dijkstra(start);
	for (int i = 1; i <= V; i++) {
		if (dist[i] == 1e9) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}
	return 0;
}