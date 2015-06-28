
#include <bits/stdc++.h>

using namespace std;

map <string, int> d;
string s;
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (d.find(s) == d.end())
			d[s]++,puts("OK");
		else
		{
			cout << s << d[s] << '\n';
			d[s]++;
		}
	}
}