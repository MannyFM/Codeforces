
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 12)
#define maxa 5050

int n, a[maxn];
int cnt[maxa];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i), cnt[a[i]]++;
	vector <int> ans;
	for (int i = 1; i < maxa; i++)
		if (cnt[i])
		{
			cnt[i]--;
			ans.push_back(i);
			
		}
	for (int i = maxa - 1; i > 0; i--)
		if (cnt[i])
		if (ans.empty() || ans.back() != i)
			ans.push_back(i);
	printf("%d\n", (int)(ans.size()));
	for (int i = 0; i < (int)(ans.size()); i++)
		printf("%d ", ans[i]);
}