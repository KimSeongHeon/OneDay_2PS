/*2020/05/30 �ι�° ����
����1918 ��Ȧ(����)*/
//������ Ȱ���� ���� Ǯ��
//������ �켱������ ���� ��µǴ� ������ �ٲ�
//���� �������� ���̵��� �켱������ ���� �����ڰ� ���� ����� �ǵ��� �Ѵٴ� ����
//�ǿ����ڴ� ��� ���ڿ��� append�ϰ� �����ڵ��� stack�� �̿��Ͽ� ������
//stack���� �켱������ ���� ��ȣ�� ���ö����� ��� ���ڿ��� append����
// '(' ���� ���� ������ �־��ְ�, ')'�� ������ '('�� ���ö����� pop�ϸ鼭 ��� ���ڿ��� �߰�����.
// �ݺ����� �� ������ stack�� �������� �̴� ���ʴ�� ���ڿ��� �߰�������
// �õ�Ƚ�� 1��, ���� ����..
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
int main() {
	string str;
	string answer = "";
	cin >> str;
	stack<char> s;
	for (int i = 0; i < str.length(); i++) {
		switch (str[i]) {
		case '+':
		case '-':
			while (!s.empty() && s.top() != '(') {
				answer += s.top();
				s.pop();
			}
			s.push(str[i]);
			break;
		case '*':
		case '/':
			while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				answer += s.top();
				s.pop();
			}
			s.push(str[i]);
			break;
		case '(':
			s.push(str[i]);
			break;
		case ')':
			while (!s.empty() && s.top() != '(') {
				answer += s.top();
				s.pop();
			}
			s.pop();
			break;
		default :
			answer = answer + str[i];
			break;
		}
	}
	while (!s.empty()) {
		answer += s.top();
		s.pop();
	}
	cout << answer;
	return 0;

}