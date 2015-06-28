
#include <bits/stdc++.h>

using namespace std;

#define eps 1e-8
#define inf int(1e9) + 7
#define maxn int(5e5) + 12

int n, a[maxn], sum[maxn];
string s;
double ans;

int main()
{
	cin >> s;
	n = int(s.size());
	for (int i = 0; i < n; i++)
		a[i + 1] = s[i] == 'I' || s[i] == 'E' || s[i] == 'A' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y';
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	/*
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	puts("");
	*/
	for (int len = 0; len < n; len++)
	{
		for (int st = 1; st + len <= n; st++)
		{
			ans += (sum[st + len] - sum[st - 1]) / (len + 1.0);
//			printf("%d %d %0.6f", st, st + len);
		}	
	}
	printf("%0.6f", ans);
}