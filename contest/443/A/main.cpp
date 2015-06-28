
#include <bits/stdc++.h>

using namespace std;

set <char> c;
string s;

int main()
{
	getline(cin, s);
	for (int i = 1; i + 1 < (int)(s.length()); i++)
		if (s[i] != ',' && s[i] != ' ')
			c.insert(s[i]);
	cout << c.size();
}