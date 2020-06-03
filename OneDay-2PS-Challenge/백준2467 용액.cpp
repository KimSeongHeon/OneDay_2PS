/*2020/06/02 두번째 문제
백준2467 용액(이진탐색)
//처음에 n을 10000으로 보고 n^2(완전 탐색)으로 구현
//10만이라는 것을 깨닫고 이진 탐색으로 재도전
//positive num 과 negative num을 구분
//이를 정렬함
//lower_bound활용하여 주어진 값과 비슷한 값을 찾음
// 나보다 작은 값도 답이 될 수 있으므로 lower_bound와 그 이전 값도 함꼐 비교
// 음수 2개, 양수 2개가 답이 될 수도 있으므로 이런 경우도 고려(음수0,1번쨰, 양수 0,1번째와 비교)
*/
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<climits>
#include<memory.h>
using namespace std;
bool cmp(int &a, int &b) {
	return a > b;
}
int main() {
	int n, element;
	int cand = INT_MAX;
	pair<int, int> ans;
	vector<int> positive;
	vector<int> negative;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> element;
		if(element>=0) positive.push_back(element);
		else negative.push_back(element);
	}
	sort(positive.begin(), positive.end());
	sort(negative.begin(), negative.end(),cmp);
	for (int i = 0; i < negative.size(); i++) negative[i] = -1 * negative[i];
	for (int i = 0; i < positive.size(); i++) {
		int index = lower_bound(negative.begin(), negative.end(), positive[i]) - negative.begin();
		if (negative.size() != 0) {
			if (cand > abs(positive[i] - negative[index])) {
				cand = abs(positive[i] - negative[index]);
				ans = { -negative[index] , positive[i] };
			}
			if (index != 0) {
				if (cand > abs(positive[i] - negative[index - 1])) {
					cand = abs(positive[i] - negative[index - 1]);
					ans = { -1 * negative[index - 1] , positive[i] };
				}
			}
		}
	}
	if (positive.size() >= 2) {
		if (positive[0] + positive[1] < cand) {
			cand = positive[0] + positive[1];
			ans = { positive[0],positive[1] };
		}
	}
	if (negative.size() >= 2) {
		if (abs(-negative[0] - negative[1]) < cand) {
			cand = abs(-negative[0] - negative[1]);
			ans = { -negative[1],-negative[0] };
		}
	}
	cout << ans.first << " " <<ans.second << endl;
	return 0;
}