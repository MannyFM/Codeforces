
#include <bits/stdc++.h>

using namespace std;

#define dig(i) ('0' <= i && i <= '9')
#define ch(i) ('A' <= i && i <= 'Z')

void s1(string s)
{
	int sz = (int)(s.size());
	int i = 1;
	int a = 0;
	while (dig(s[i]))
	{
		a = a * 10 + (int)(s[i] - '0');
		i++;
	}
	int b = 0;
	i++;
	while (i < sz && dig(s[i]))
	{
		b = b * 10 + (int)(s[i] - '0');
		i++;
	}
	string s1 = "";
	while(b)
	{
		b--;
		s1 = char(b % 26 + 'A') + s1;
		b /= 26;
	}
	cout << s1 << a << '\n';
}

void s2(string s)
{
	int sz = (int)(s.size());
	int i = 0;
	string s1 = "", s2 = "";
	while (ch(s[i]))
	{
		s1 += s[i];
		i++;
	}
	while(i < sz)
	{
		s2 += s[i];
		i++;
	}
	int a = 0;
	for (int i = 0; i < (int)(s1.size()); i++)
	{
		a = a * 26 + (int)(s1[i] - 'A' + 1);
	}
	cout << "R" << s2 << "C" << a << '\n';
}

int main()
{
	int n;
	string s;
	cin >> n;
	while(n--)
	{
		cin >> s;
		int i = 0;
		while (ch(s[i]))
			i++;
		while (i < (int)(s.size()) && dig(s[i]))
			i++;
		if (i == (int)s.size())
			s2(s);
		else
			s1(s);
	}
}