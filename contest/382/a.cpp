
#include <bits/stdc++.h>

using namespace std;

string s, a, b, c;

int main()
{
	cin >> s >> c;
	int i = s.find('|');
	a = s.substr(0, i);
	b = s.substr(i + 1, s.size() - i - 1);
//	cout << a << "^" << b << '\n';
	if (a.size() == b.size())
	{
		if (c.size() & 1)
		{
			puts("Impossible");
			return 0;
		}
		else
		{
			int k = c.size() / 2;
			cout << c.substr(0, k) << a << "|" << b << c.substr(k, c.size() - k);
			return 0;
		}
	}
	int sa = a.size(), sb = b.size(), sc = c.size();
//	printf("%d %d %d\n", sa, sb, sc);
	if (abs(sa - sb) > sc)
		{
			puts("Impossible");
			return 0;
		}
	i = 0;
	while (a.size() < b.size() && i < c.size())
	{
		a.push_back(c[i]);
		i++;
	}
	while (a.size() > b.size() && i < c.size())
	{
		b.push_back(c[i]);
		i++;
	}
	c = c.substr(i, c.size() - i);
	//cout << a << " " << b << " " << c << '\n';
	if (a.size() != b.size())
	{
		puts("Impossible");
		return 0;
	}
	if (c.size() & 1)
	{
		puts("Impossible");
		return 0;
	}
	else
	{
		int k = c.size() / 2;
		cout << c.substr(0, k) << a << "|" << b << c.substr(k, c.size() - k);
		return 0;
	}
}