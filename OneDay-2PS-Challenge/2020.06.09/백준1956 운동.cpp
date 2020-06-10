/*2020/06/10 ù��° ����
����1956 �(�÷��̵� ���� �˰���)*/
//�������� �־��� ���� ����.
//��尡 400��, �ð����⵵�� O(v^3)�̱� ������ 600�� ������ �����
//�÷��̵�� ��� ������ �Ÿ��� ���� ��, ���� �������� ���ư��� ���� �ִ��� ��� ��带 ���鼭 üũ��
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