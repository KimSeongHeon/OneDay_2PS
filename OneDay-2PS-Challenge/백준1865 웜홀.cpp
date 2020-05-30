/*2020/05/30 첫번째 문제
백준1865 웜홀(그래프 탐색)*/
//그래프 탐색(다익스트라, 플루이드 워셜 ,벨만 포드)
//이 문제는 음수인 weight를 가지기 떄문에 벨만 포드로 풀어야 함.
//벨만 포드 알고리즘에서 음의 사이클이 생길 경우가 문제에서 찾는 조건임을 생각할 것
//루프를 V-1번 돌면서 모든 정점의 인접한 노드를 다 방문하여 업데이트 함.
//V-1번 돌았을 때, 모든 거리는 업데이트 되어야 하는데, 그럼에도 불구하고 계속 업데이트를 시도한다 => 음의 사이클이다.
//음의 사이클 : 돌면 돌수록 계속 작아짐(-무한대)
//시도 횟수 : 1번, 벨만 포드 알고리즘 참고
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
	for (int i = 0; i < N; i++) { // N-1 번 루프
		for (int j = 1; j <= N; j++) { //모든 정점에 대해서
			//N-1번 루프에 걸쳐 각 정점이 i+1 정점을 가져오는 최단 경로 갱신
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
void dfs(int start) {//콤포넌트의 개수 구하기
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