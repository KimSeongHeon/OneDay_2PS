#include<iostream>
#include<string>
#include<algorithm>
#include<memory.h>
using namespace std;
int cache[1001][1001];
string str1, str2;
int calculate(int x1, int x2){
	if (x1 < 0 || x2 < 0 || x1>str1.length() || x2>str2.length()) return 0;
	if (cache[x1][x2] != -1) return cache[x1][x2];
	if (str1[x1] == str2[x2]) cache[x1][x2] = calculate(x1 - 1, x2 - 1) + 1;
	else cache[x1][x2] = max(calculate(x1 - 1, x2), calculate(x1, x2 - 1));
	return cache[x1][x2];
}
int main(){
	memset(cache, -1, sizeof(cache));
	cin >> str1 >> str2;
	cout << calculate(str1.size() - 1, str2.size() - 1);
}