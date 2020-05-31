/*2020/05/31 ù��° ����
����1753 �ִܰ��(�׷��� Ž��)*/
//�׷��� Ž��(���ͽ�Ʈ��, �÷��̵� ���� ,���� ����)
//�� ������ ��尡 20000���̱� ������ ���ͽ�Ʈ��� Ǯ��� �ð��ʰ��� ���� ����
//������ �ް� Ž���ϰ� ������Ʈ ���ָ� ��.
// �����ؾ� ������ ���ŵ� ������ Queue�� �־���
//�õ� Ƚ�� : 1��, ���� �ð�: 20��
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
			if (dist[next_x] > weight + next_weight) {//�۾����� ��� ����,dist ������Ʈ
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