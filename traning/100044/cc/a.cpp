#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fname ""

typedef long long LL;
      
LL n, c, all, m, M, z, l, r, b, R, ans;

int main() {
	#ifdef LOCAL
		freopen(fname".in", "r", stdin);
		freopen(fname".out", "w", stdout);
	#endif

	cin >> n;
	while(cin >> n) {
		ans = 0;
		cin >> m >> z >> l >> r >> b;
		if (m == 1)
		{
			cout << min(n, z + l + r + b) << "\n";
			continue;
		}
		
		if (m % 2 == 0)
		{
			LL buf = n;
			R = min(buf, l);
			l -= R;
			buf -= R;
			ans += R;
			
			R = min(buf, r);
			r -= R;
			buf -= R;
			ans += R;
			
			R = min(buf, z);
			z -= R;
			buf -= R;
			ans += R;
			
			if (buf)
			{
				cout << ans + min(m / 2 * n, b) << "\n";
				continue;
			}
			else
				m--;
		}
		if (m == 1)
		{
			cout << min(n, z + l + r + b) + ans << "\n";
			continue;
		}
		
		R = min(min(l / (m - 1), b), n);
		ans += R * m;
		n -= R;
		l -= R * (m - 1);
		b -= R;

		R = min(min(r / (m - 1), b), n);
		ans += R * m;
		n -= R;
		r -= R * (m - 1);
		b -= R;

		R = min(n, l / m);
		ans += R * m;
		l -= R * m;
		n -= R;
		
		R = min(n, r / m);
		r -= R * m;
		ans += R * m;
		n -= R;

		if (!n)
		{
			cout << ans << "\n";
			continue;
		}
		n--;
		M = m;
		M -= l;
		l = 0;
		if (b)
		{
			b--;
			M--;
		}

		c = min(M, r);
		M -= c;
		r -= c;
		ans += m - M;
		
		c = min(M / 2, b);
		M -= c;
		b -= c;
		ans += c;

		c = min(M, z);
		M -= c;
		z -= c;
		ans += c;
		
		if (!n)
		{
			cout << ans << "\n";
			continue;
		}
		
		n--;
		M = m;
		M -= r;
		r = 0;
		ans += m - M;
		
		c = min((M + 1) / 2, b);
		M -= c;
		b -= c;
		ans += c;

		c = min(M, z);
		M -= c;
		z -= c;
		ans += c;
		

		all = n * m;
		c = min((m + 1) / 2 * n, b);
		all -= c;
		b -= c;
		ans += c;
		c = min(all, z);
		all -= c;
		ans += c;
		z -= c;

		cout << ans << "\n";
	}
	return 0;
}
