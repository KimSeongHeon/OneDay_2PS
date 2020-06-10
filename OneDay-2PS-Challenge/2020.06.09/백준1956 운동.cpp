/*2020/06/10 첫번째 문제
백준1956 운동(플로이드 워셜 알고리즘)*/
//시작점이 주어져 있지 않음.
//노드가 400개, 시간복잡도가 O(v^3)이기 떄문에 600만 정도로 충분함
//플로이드로 모든 지점의 거리를 구한 후, 시작 지점으로 돌아가는 것이 있는지 모든 노드를 돌면서 체크함
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int adj[401][401];
int main() {
	int v, e;
	cin >> v >> e;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) adj[i][j] = 1e9;
	}
	for (int i = 0; i < e; i++) {
		int start, dest, weight;
		cin >> start >> dest >> weight;
		adj[start][dest] = weight;
	}
	for (int i = 0; i < v; i++) adj[i][i] = 0;
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
	int ans = 1e9;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (adj[j][i] != 1e9 && i != j) ans = min(ans, adj[i][j] + adj[j][i]);
		}
	}
	if (ans != 1e9) cout << ans;
	else cout << -1;
	return 0;
}