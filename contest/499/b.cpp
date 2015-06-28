
#include <bits/stdc++.h>

using namespace std;

map <string, string> d;
string s, input;
int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		cin >> s >> input;
		d[s] = input;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if ((int)d[input].size() < (int)input.size())
			cout << d[input] << " ";
		else
			cout << input << " ";
	}
}