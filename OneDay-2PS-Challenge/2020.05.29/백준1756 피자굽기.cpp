/*2020/05/29 두번째 문제
백준14503 피자 굽기(구현)*/
//최소 radius를 구하여 저장하는 것이 핵심
//최소 radius의 다음 칸에 쌓이는 것을 생각해야함. 그것을 찾고 계속 그 위에서 찾아나감
//O(n)에 풀 수 있는 문제
//답지 참고, 시간 : 30분
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int main() {
	int depth, n;
	vector<int> oven;
	vector<int> minRadius;
	vector<int> pizza;
	cin >> depth >> n;
	int pre = 1987654321;
	for (int i = 0; i < depth; i++) {
		int elm;
		cin >> elm;
		oven.push_back(elm);
		minRadius.push_back(pre = min(pre,elm));
	}
	for (int i = 0; i < n; i++) {
		int elm;
		cin >> elm;
		pizza.push_back(elm);
	}
	int pizza_cnt = 0;
	int answer = -1;
	for (int i = depth - 1; i >= 0; i--) {
		if (pizza_cnt == n) {
			cout << answer + 1 << endl;
			return 0;
		}
		if (minRadius[i] >= pizza[pizza_cnt]) {
			answer = i;
			pizza_cnt++;
		}
	}
	cout << 0;
	return 0;
}