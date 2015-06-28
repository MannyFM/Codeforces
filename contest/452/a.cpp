
#include <bits/stdc++.h>

using namespace std;

string a[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

bool check(string s, int i)
{
	if (s.size() != a[i].size())
		return 0;
	for (int j = 0; j < (int)s.size(); j++)
	{
		if (s[j] == '.')
			continue;
		if (s[j] != a[i][j])
			return 0;
	}
	return 1;
}

int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	for (int i = 0; i < 8; i++)
		if (check(s, i))
		{
			cout << a[i];
			break;
		}	
}