/*2020/06/02 첫번째 문제
백준1303 비즈공예(DP)*/
//DP 아니고서는 경우의 수가 굉장히 많아서 풀 수가 없음
//처음에 문제를 잘못보고 10미만인줄 알고 각각의 개수를 10진수로 변환하여 풀기 시도
//10이 있기떄문에 10진수로 하면 안됨.
//7차원 배열을 사용하여 풀었음
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