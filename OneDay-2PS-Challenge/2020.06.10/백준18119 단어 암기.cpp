/*2020/06/10 �ι�° ����Ǯ��
����18119 �ܾ� �ϱ�(��Ʈ����ŷ)*/
//O(NM)�� 5�ﵵ ������� ���
// ��Ʈ����ŷ���� ���� �˰��ִ� �ܾ ǥ�� �� ������ ������ ���Ͽ� ���
// set�� �̿��Ͽ� ó�� ������ �Ͽ����� ���� ���ϴ� �������� �Ƹ� ������ �߻��� �� ����
// �� �������� ��Ʈ����ŷ�� ���� ������ Ǯ�� �����!
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