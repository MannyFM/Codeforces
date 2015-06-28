
#include <bits/stdc++.h>

using namespace std;

int a[30], b[30];
string s, t;

int main()
{
	cin >> s >> t;
	for (int i = 0; i < (int)(s.size()); i++)
	{
		a[s[i] - 'a']++;
	}
	for (int i = 0; i < (int)(t.size()); i++)
	{
		b[t[i] - 'a']++;
	}
	bool need_automaton = 0, need_array = 0;
	for (int i = 0; i < 26; i++)
	{
		if (a[i] < b[i])
		{
			puts("need tree");
			return 0;
		}
		if (a[i] > b[i])
			need_automaton = 1;
	}
	if (!need_automaton)
	{
		puts("array");
		return 0;
	}
	int l = 0, ok = 1;
	for (int i = 0; i < (int)(t.size()); i++)
	{
		while (l < (int)(s.size()) && s[l] != t[i])
			l++;
		if (l == (int)(s.size()))
		{
			ok = 0;
			break;
		}
		l++;
	}
	need_array = !ok;
	if (!need_array)
	{
		puts("automaton");
		return 0;
	}
	puts("both");
}