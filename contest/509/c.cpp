
#include <bits/stdc++.h>

using namespace std;

#define maxn 325
#define maxb (maxn + 8) / 9
#define ll unsigned long long

int last = 1;
string ss, a[maxn];
int n, b[maxn];

string change(string s, int i)
{
	if (i >= int(s.size()) || i < 0)
		return "--1";
	string ans = "";
	ans += '1';
	for (int k = 1; k < i; k++)	
		ans += s[k];
	ans += char(s[i] - 1);
	for (int k = i + 1; k < int(s.size()); k++)
		ans += s[k];
	return ans;
}

bool lower(string a, string b)
{
	if (int(a.size()) != int(b.size()))
		return int(a.size()) < int(b.size());
	for (int i = 0; i < int(a.size()); i++)
		if (a[i] != b[i])
			return a[i] < b[i];
	return 0;
}

string calc(int x)
{
	//printf("%d:\n", x);
	int old = x;
	string s = "";
	if (x < 10)
	{
		s = char(x + '0');
		if (lower(ss, s))
			return s;
	}
	int t = 0;
	while (t < 400)
	{
		s = "";
		int pos_last = -1;
		for (int i = 0; i < last; i++)
		{
			int add = min(x, 9);
			x -= add;
			if (add != 0)
				pos_last = last - i - 1;
			//printf("%d ", add);
			s = char(add + '0') + s;
		}
		//cout << '\n' << s << " " << pos_last << " ";
		if (s[0] == '0')
		{
			s = change(s, pos_last);
		}
		//cout << s << "\n\n";
		if (lower(ss, s) && x == 0)
			return s;
		last++;
		t++;
		x = old;
	}
	return "-1";
}

int main()
{
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", b + i);
	ss = "";
	for (int i = 0; i < n; i++)
	{
		string now = calc(b[i]);
		//puts("");
		a[i] = now;
		last = int(now.size());
		ss = now;
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << '\n';
}
/*
int main()
{
	string s;
	cin >> s;
	int pos = -1;
	for (int i = 0; i < int(s.size()); i++)
		if (s[i] != '0')
		{
			pos = i;
			break;
		}
	s = change(s, pos);
	cout << s << '\n' << pos;
}
*/