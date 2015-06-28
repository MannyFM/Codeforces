
#include <bits/stdc++.h>

using namespace std;

int n;
string a;

int main()
{
	scanf("%d", &n);
	cin >> a;
	int i = 0;
	while (i < n && a[i] == '1')
	{
		i++;
	}
	printf("%d", i + (i != n));
}