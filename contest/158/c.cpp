
#include <bits/stdc++.h>

using namespace std;

string a, b;
string ans[10000];
int n, sz;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a == "pwd")
		{
			for (int j = 0; j < sz; j++)
				cout << '/' << ans[j];
			cout << "/\n";
			
		}
		else
		{
			cin >> b;
			int i = 0;
			if (b[0] == '/')
			{
				sz = 0;
				i++;
			}
			while (i < b.size())
			{
				string now = "";
				while (i < b.size() && b[i] != '/')
					now += b[i], i++;
				if (now == "..")
					sz--;
				else
					ans[sz++] = now;
				i++;
			}
		}
	}
}