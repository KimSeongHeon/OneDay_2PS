/*2020/06/02 두번째 문제
백준5549 행성탐사(구현)*/
//시간초과 안나게 구현하는 것이 핵심
//입력 받을 때마다 이전의 값들을 활용하여 J,O,i의 개수를 세야함
//그리고 그 값을 이용하여 수학적으로 계산하면 답을 구할 수 있음.
#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct area {
	int jungle;
	int ocean;
	int ice;
};
area map[1001][1001];
area row;
area col[1001];
area all;
void cal(int x, int y,char character) {
	map[x][y] = map[x - 1][y - 1];
	map[x][y].jungle += row.jungle;
	map[x][y].ocean += row.ocean;
	map[x][y].ice += row.ice;
	map[x][y].jungle += col[y].jungle;
	map[x][y].ocean += col[y].ocean;
	map[x][y].ice += col[y].ice;
	if (character == 'J') {
		map[x][y].jungle++;
		row.jungle++;
		col[y].jungle++;
		all.jungle++;
	}
	else if (character == 'O') {
		map[x][y].ocean++;
		row.ocean++;
		col[y].ocean++;
		all.ocean++;
	}
	else if (character == 'I') {
		map[x][y].ice++;
		row.ice++;
		col[y].ice++;
		all.ice++;
	}
	//cout << map[x][y].jungle << map[x][y].ocean << map[x][y].ice << endl;
}
area width(int x1, int y1, int x2, int y2) {
	area all = map[x2][y2];
	area sub1 = map[x2][y1 - 1];
	area sub2 = map[x1 - 1][y2];
	area coincide = map[x1 - 1][y1 - 1];
	area ret = { 0,0,0 };
	ret.jungle = all.jungle - sub1.jungle - sub2.jungle + coincide.jungle;
	ret.ocean = all.ocean - sub1.ocean - sub2.ocean + coincide.ocean;
	ret.ice = all.ice - sub1.ice - sub2.ice + coincide.ice;
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m,k;
	cin >> n >> m >> k;
	//for (int i = 0; i <= n; i++) map[i][0] = { 0,0,0 };
	//for (int j = 0; j <= n; j++) map[0][j] = { 0,0,0 };
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		row = {0,0,0};
		for (int j = 1; j <= m; j++) {
			cal(i, j, s[j-1]);
		}
	}
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		area answer = width(x1, y1, x2, y2);
		cout << answer.jungle << " " << answer.ocean << " " << answer.ice << "\n";
	}
	return 0;
}