
#include <bits/stdc++.h>

using namespace std;

string a;
int j = -1;

int main()
{
	cin >> a;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '0')
		{
			j = i;
			break;
		}
	}
	if (j == -1)
		cout << a.substr(0, a.size() - 1);
	else
		cout << a.substr(0, j) << a.substr(j + 1, a.size() - j);
}