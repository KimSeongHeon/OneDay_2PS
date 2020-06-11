/*2020/06/10 두번째 문제풀이
백준18119 단어 암기(비트마스킹)*/
//O(NM)즉 5억도 통과됨을 기억
// 비트마스킹으로 내가 알고있는 단어를 표기 후 적절한 연산을 통하여 계산
// set을 이용하여 처음 생각을 하였으나 서로 비교하는 과정에서 아마 문제가 발생할 듯 싶음
// 이 문제에서 비트마스킹이 가장 적절한 풀이 방법임!
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<memory.h>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	int cur = (1 << 27) - 1;
	unsigned int table[10000];
	memset(table, 0, sizeof(table));
	vector<string> v;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			table[i] |= 1 << (str[j] - 'a');
		}
	}
	for (int i = 0; i < m; i++) {
		int cnt = 0;
		int o; 
		char x;
		cin >> o >> x;
		if (o == 1) cur &= ~(1 << (x - 'a'));
		else if (o == 2) cur |= (1 << (x - 'a'));
		for (int i = 0; i < n; i++) {
			if ((table[i] & cur) == table[i]) cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}