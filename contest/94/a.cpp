
#include <bits/stdc++.h>

using namespace std;

string a;
string s[10];
map <string, int> m;

int main()
{
	cin >> a;
	for (int i = 0; i < 10; i++)
	{
		cin >> s[i];
		m[s[i]] = i;
	}
	for (int i = 0; i < 8; i++)
	{
		string now = a.substr(i * 10, 10);
		printf("%d", m[now]);
	}
}