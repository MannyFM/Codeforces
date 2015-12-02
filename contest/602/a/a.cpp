
#include <bits/stdc++.h>

#ifdef _WIN32
    #define I64 "%I64d"
#else
    #define I64 "%lld"
#endif

using namespace std;

typedef long long ll;

ll f(vector <int> v, int base)
{
	ll res = 0;
	for (int x : v)
		res = res * base + x;
	return res;
}

vector <int> v;
int n, b;
ll x, y;

int main()
{
	scanf("%d%d", &n, &b);
	v.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	x = f(v, b);
	scanf("%d%d", &n, &b);
	v.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	y = f(v, b);
	if (x == y)
		printf("=");
	else
		printf("%c", x < y ? '<' : '>');
}