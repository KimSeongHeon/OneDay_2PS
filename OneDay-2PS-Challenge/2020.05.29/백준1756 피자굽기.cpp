/*2020/05/29 �ι�° ����
����14503 ���� ����(����)*/
//�ּ� radius�� ���Ͽ� �����ϴ� ���� �ٽ�
//�ּ� radius�� ���� ĭ�� ���̴� ���� �����ؾ���. �װ��� ã�� ��� �� ������ ã�Ƴ���
//O(n)�� Ǯ �� �ִ� ����
//���� ����, �ð� : 30��
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