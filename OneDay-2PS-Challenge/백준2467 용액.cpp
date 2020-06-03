/*2020/06/02 �ι�° ����
����2467 ���(����Ž��)
//ó���� n�� 10000���� ���� n^2(���� Ž��)���� ����
//10���̶�� ���� ���ݰ� ���� Ž������ �絵��
//positive num �� negative num�� ����
//�̸� ������
//lower_boundȰ���Ͽ� �־��� ���� ����� ���� ã��
// ������ ���� ���� ���� �� �� �����Ƿ� lower_bound�� �� ���� ���� �Բ� ��
// ���� 2��, ��� 2���� ���� �� ���� �����Ƿ� �̷� ��쵵 ���(����0,1����, ��� 0,1��°�� ��)
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