
#include <bits/stdc++.h>

using namespace std;

string s;
int a, b, n;

int main()
{
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++)
	{
		if ('a' <= s[i] && s[i] <= 'z')
			a++;
		else
			b++;
	}
	if (a >= b)
	{
		for (int i = 0; i < n; i++)
			cout << char(('a' <= s[i] && s[i] <= 'z') ? s[i] : s[i] - 'A' + 'a');
	}
	else
		for (int i = 0; i < n; i++)
			cout << char(('a' <= s[i] && s[i] <= 'z') ? s[i] - 'a' + 'A' : s[i]);
}