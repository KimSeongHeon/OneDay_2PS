/*2020/05/30 ù��° ����
����1865 ��Ȧ(�׷��� Ž��)*/
//�׷��� Ž��(���ͽ�Ʈ��, �÷��̵� ���� ,���� ����)
//�� ������ ������ weight�� ������ ������ ���� ����� Ǯ��� ��.
//���� ���� �˰��򿡼� ���� ����Ŭ�� ���� ��찡 �������� ã�� �������� ������ ��
//������ V-1�� ���鼭 ��� ������ ������ ��带 �� �湮�Ͽ� ������Ʈ ��.
//V-1�� ������ ��, ��� �Ÿ��� ������Ʈ �Ǿ�� �ϴµ�, �׷����� �ұ��ϰ� ��� ������Ʈ�� �õ��Ѵ� => ���� ����Ŭ�̴�.
//���� ����Ŭ : ���� ������ ��� �۾���(-���Ѵ�)
//�õ� Ƚ�� : 1��, ���� ���� �˰��� ����
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;
vector<pair<int, int>> road[501];
int dist[501];
bool visited[501];
int N, M, W;
bool belman_ford(int start) {
	fill(dist, dist + 501, 1e9);
	dist[start] = 0;
	for (int i = 0; i < N; i++) { // N-1 �� ����
		for (int j = 1; j <= N; j++) { //��� ������ ���ؼ�
			//N-1�� ������ ���� �� ������ i+1 ������ �������� �ִ� ��� ����
			for (int k = 0; k < road[j].size(); k++) {
				int next = road[j][k].first , d = road[j][k].second;
				if (dist[j] != 1e9 && dist[next] > dist[j] + d) {
					dist[next] = dist[j] + d;
					if (i == N - 1) return true;
				}
			}
		}
	}
	return false;
}
void dfs(int start) {//������Ʈ�� ���� ���ϱ�
	visited[start] = true;
	for (int i = 0; i < road[start].size(); i++) {
		int next = road[start][i].first;
		if (!visited[next]) dfs(next);
	}
}
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		memset(road, 0, sizeof(road));
		memset(visited, false, sizeof(visited));
		cin >> N >> M >> W;
		for (int j = 0; j < M; j++) {
			int S, E, T;
			cin >> S >> E >> T;
			road[S].push_back({E,T});
			road[E].push_back({S,T});
		}
		for (int k = 0; k < W; k++) {
			int S, E, T;
			cin >> S >> E >> T;
			road[S].push_back({E,-1*T});
		}
		vector<int> start;
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				start.push_back(i);
				dfs(i);
			}
		}
		bool ans = false;
		for (int i = 0; i < start.size(); i++) {
			if (belman_ford(start[i])) {
				ans = true;
				break;
			}
		}
		if (ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}