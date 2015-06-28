
#include <bits/stdc++.h>

using namespace std;

#define inf (int)(1e9 + 7)
#define maxn (int)(1e5 + 12)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair <int, int>
#define ll long long

int n;
string s, ans;

void ch(string s)
{
	string a = "";
	for (int i = 0; i < n; i++)
	{
		a = s.substr(i, n - i) + s.substr(0, i);
		if (a < ans)
			ans = a;
	}
}

int main()
{
	string s;
	cin >> n >> s;
	string a;
	ans = s;
	for (int i = 0; i < 10; i++)
	{
		a = "";
		for (int j = 0; j < n; j++)
			a.pb((s[j] + i) % 10 + '0');
		ch(a);
	}
	cout << ans;
}