/*2020/06/02 ù��° ����
����1303 �������(DP)*/
//DP �ƴϰ��� ����� ���� ������ ���Ƽ� Ǯ ���� ����
//ó���� ������ �߸����� 10�̸����� �˰� ������ ������ 10������ ��ȯ�Ͽ� Ǯ�� �õ�
//10�� �ֱ⋚���� 10������ �ϸ� �ȵ�.
//7���� �迭�� ����Ͽ� Ǯ����
#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;
int n;
vector<int> v;
long long cache[11][11][11][11][11][7][7];
long long cal(int one, int two, int three, int four, int five, int before, int bbefore){
	if (one == 0 && two == 0 && three == 0 && four == 0 && five == 0) {
		return 1;
	}
	if (one < 0 || two < 0 || three < 0 || four < 0 || five < 0) {
		return 0;
	}
	long long &ret = cache[one][two][three][four][five][before][bbefore];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	if (one >= 1 && before != 1 && bbefore != 1) {
		ret += cal(one - 1, two, three, four, five, 1, before);
	}

	if (two >= 1 && before != 2 && bbefore != 2) {
		ret += cal(one, two - 1, three, four, five, 2, before);
	}

	if (three >= 1 && before != 3 && bbefore != 3) {
		ret += cal(one, two, three - 1, four, five, 3, before);
	}

	if (four >= 1 && before != 4 && bbefore != 4) {
		ret += cal(one, two, three, four - 1, five, 4, before);
	}

	if (five >= 1 && before != 5 && bbefore != 5) {
		ret += cal(one, two, three, four, five - 1, 5, before);
	}
	return ret;
}

int main(){
	memset(cache, -1, sizeof(cache));
	cin >> n;
	int element;
	for (int i = 0; i < n; i++) {
		cin >> element;
		v.push_back(element);
	}
	for (int i = n; i < 5; i++) {
		v.push_back(0);
	}
	cout << cal(v[0], v[1], v[2], v[3], v[4], -1, -1) << endl;
	return 0;
}