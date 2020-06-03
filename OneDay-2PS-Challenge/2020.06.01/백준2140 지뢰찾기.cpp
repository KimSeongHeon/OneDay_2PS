/*2020/06/01 첫번째 문제
백준2140 지뢰찾기(완전탐색?)*/
//8방향으로 하여 지뢰를 놓을 수 있는 공간이면 8 방향의 숫자를 하나씩 제거해주면 됨.
//map의 모든 면을 보고 이 과정을 수행해 나감.
//시도 횟수 : 1번, 구현 시간: 20분
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int dx[8] = { 0,0,1,1,1,-1,-1,-1};
int dy[8] = { 1,-1,0,1,-1,0,1,-1 };
int main() {
	int n;
	int ans = 0;
	char map[101][101];
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			map[i][j] = str[j];
		}
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (map[x][y] == '#') {
				bool check = false;
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
						if ((map[nx][ny] >= '1' && map[nx][ny] <= '9')||map[nx][ny] == '#' || map[nx][ny] == '*') {
						}
						else check = true;
					}
				}
				if (!check) {
					map[x][y] = '*';
					for (int i = 0; i < 8; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (map[nx][ny] != '#' && map[nx][ny] != '*') map[nx][ny]--;
					}
				}	
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '*') ans++;
		}
	}
	cout << ans;
	return 0;
}