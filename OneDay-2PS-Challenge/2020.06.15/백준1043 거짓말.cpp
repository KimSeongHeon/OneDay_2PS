#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<memory.h>
using namespace std;
bool visited[101];
set<int> adj[101];
set<int> truth;
void dfs(int n) {
	visited[n] = true;
	truth.insert(n);
	for (auto iter = adj[n].begin(); iter != adj[n].end(); iter++) {
		if (!visited[(*iter)]) dfs((*iter));
	}

}
int main() {
	vector<vector<int>> all;
	int n, m, k;
	cin >> n >> m;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int element;
		cin >> element;
		truth.insert(element);
	}
	for (int i = 0; i < m; i++) {
		vector<int> v;
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int element;
			cin >> element;
			v.push_back(element);
		}
		sort(v.begin(), v.end());
		all.push_back(v);
		for (int j = 0; j < v.size(); j++) {
			for (int k = 0; k < v.size(); k++) {
				if (j == k) continue;
				adj[v[j]].insert(v[k]);
			}
		}
	}
	for (auto iter = truth.begin(); iter != truth.end(); iter++) {
		memset(visited, false, sizeof(visited));
		dfs((*iter));
	}
	int cnt = 0;
	for (int i = 0; i < all.size(); i++) {
		for (int j = 0; j < all[i].size(); j++) {
			if (truth.find(all[i][j]) == truth.end()) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}