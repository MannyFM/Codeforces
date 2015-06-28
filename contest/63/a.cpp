
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair

vector <pair<pair<int, int>,string>> v;
string a, b;
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		int prior;
		if (b == "rat")
			prior = 1;
		if (b ==  "woman")
			prior = 2;
		if (b == "child")
			prior = 2;
		if (b == "man")
			prior = 3;
		if (b == "captain")
			prior = 4;
		v.push_back(mp(mp(prior, i), a));
	}
	sort(begin(v), end(v));
	for (int i = 0; i < n; i++)
		cout << v[i].second << '\n';
}