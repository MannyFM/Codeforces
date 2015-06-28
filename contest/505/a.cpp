
#include <bits/stdc++.h>

using namespace std;

bool check(string s)
{
	for (int i = 0; i < (int)(s.size()) / 2; i++)
		if (s[i] != s[(int)(s.size() - 1 - i)])
			return 0;
	return 1;
}

string add(string s, int pos, char a)
{
	string aa = s.substr(0, pos);
	aa += a;
	aa += s.substr(pos, (int)(s.size()) - pos);
	return aa;
}

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i <= (int)(s.size()); i++)
	for (char z = 'a'; z <= 'z'; z++)
	{
		string a = add(s, i, z);
		if (check(a))
		{
			cout << a;
			return 0;
		}
	}
	puts("NA");
}