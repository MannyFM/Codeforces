
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 7)
#define inf (int)(1e9 + 7)
#define pb push_back
#define ll long long
#define f first
#define s second
#define mp make_pair
//           0  1  2  3  4  5  6  7  8  9
int a[10] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};

int main()
{
	int n;
	cin >> n;
	int x = n / 10;
	int y = n % 10;
	cout << a[x] * a[y];
}