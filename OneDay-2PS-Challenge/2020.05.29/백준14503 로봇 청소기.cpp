/*2020/05/29 첫번째 문제
백준14503 로봇 청소기(시뮬레이션)*/
//문제의 조건대로 코딩하면 됨
//map 밖의 부분을 예외처리하기 위하여 1~row/1~col 까지를 범위로 잡고 나머지 부분을 1의 벽으로 채운것이 포인트
//시도 횟수 : 1번 , 걸린 시간 : 30분
#include<iostream>
#include<memory.h>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
int row, col;
int map[52][52];
int visited[52][52];
pair<int, int> back(int x,int y,int direction) {
	if (direction == 0) return { x+1,y };
	else if (direction == 1) return { x,y - 1 };
	else if (direction == 2) return { x - 1,y };
	else if (direction == 3) return { x,y + 1 };
}
pair<int, int> rotation(int x, int y, int direction) {
	if (direction == 0) return { x,y - 1 };
	else if (direction == 1) return {x-1,y};
	else if (direction == 2) return {x,y+1};
	else if (direction == 3) return { x + 1,y };
}
int rotate_dir(int direction) {
	if (direction == 0) return 3;
	else if (direction == 1) return 0;
	else if (direction == 2) return 1;
	else if (direction == 3) return 2;
}
int ret_ans() {
	int cnt = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (visited[i][j] == 1) cnt++;
		}
	}
	return cnt;
}
int main() {
	memset(visited, 0, sizeof(visited));
	int x, y, direction;
	cin >> row >> col;
	cin >> x >> y >> direction;
	for (int i = 0; i <= col+1; i++) {
		map[0][i] = 1;
		map[row + 1][i] = 1;
	}
	for (int i = 0; i <= row + 1; i++) {
		map[i][0] = 1;
		map[i][col + 1] = 1;
	}
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> map[i][j];
		}
	}
	x = x + 1; y = y + 1;
	while (1) {
		visited[x][y] = 1;
		bool finish = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!(visited[nx][ny] || map[nx][ny] == 1)) {
				finish = false;
				break;
			}
		}
		pair<int, int> tmp = back(x, y, direction);
		if (finish && map[tmp.first][tmp.second] == 1) {
			cout << ret_ans();
			return 0;
		}
		else if (finish) {
			x = tmp.first;
			y = tmp.second;
			continue;
		}
		else {
			pair<int, int> next = rotation(x, y, direction);
			int nx = next.first; int ny = next.second;
			if (visited[nx][ny] == 0 && map[nx][ny] == 0) {
				direction = rotate_dir(direction);
				x = nx; y = ny;
			}
			else {
				direction = rotate_dir(direction);
			}
		}
	}
}