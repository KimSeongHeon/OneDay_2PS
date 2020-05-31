/*2020/05/30 두번째 문제
백준1918 웜홀(스택)*/
//스택을 활용한 문제 풀이
//연산자 우선순위에 따라 출력되는 순서가 바뀜
//가장 기초적인 아이디어는 우선순위가 높은 연산자가 먼저 출력이 되도록 한다는 것임
//피연산자는 결과 문자열에 append하고 연산자들은 stack을 이용하여 봐야함
//stack에서 우선순위가 낮은 기호가 나올때까지 결과 문자열에 append해줌
// '(' 같은 경우는 무조건 넣어주고, ')'가 나오면 '('가 나올때까지 pop하면서 결과 문자열에 추가해줌.
// 반복문이 다 돌고나서 stack이 남았으면 이는 차례대로 문자열에 추가시켜줌
// 시도횟수 1번, 답지 참고..
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