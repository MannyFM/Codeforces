
#include <bits/stdc++.h>

using namespace std;

#define eps 1e-8
#define inf int(1e9) + 7
#define maxn int(5e5) + 12
#define ll long long
#define ull unsigned ll
#define ld double

int n, a[maxn];
ull pre[maxn], suf[maxn], sum[maxn];
string s;
ld ans;

ld get(int l, int r)
{
	return ld(sum[r] - sum[l - 1]);
}

int main()
{
	cin >> s;
	n = int(s.size());
	for (int i = 0; i < n; i++)
		a[i + 1] = s[i] == 'I' || s[i] == 'E' || s[i] == 'A' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y';
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + a[i] * i;
	for (int i = 1; i <= n; i++)
		suf[i] = suf[i - 1] + a[n - i + 1] * i;
	for (int len = 1; len <= n; len++)
	{
		if (len == n)
		{
			ld d = sum[n] / (n + .0);
			printf("%I64u %d %0.7f\n", sum[n], n, d);
			ans += d;
			continue;
		}
		ull now = pre[len - 1] + suf[len - 1];
		ld d = now / (len + .0);
		printf("%d %0.7f %0.7f %0.7f\n", len, d, get(len, n - len + 1), d + get(len, n - len + 1));
		d += get(len, n - len + 1);
		ans += d;
	}
	
	for (int i = 1; i <= n; i++)
		printf("%d %I64u %I64u\n", a[i], pre[i], suf[i]);
	puts("");
	
	printf("%0.7f", ans);
}