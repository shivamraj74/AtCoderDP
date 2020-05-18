//Radhe Radhe
#include<bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//using namespace boost::multiprecision;
//#include<boost/math/common_factor.hpp>
#include <ext/numeric>
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define array(a,n) int a[n]; for(int i=0;i<n;i++) cin>>a[i];
#define loop(i,a,b,x) for(int i=a;i<b;i+=x)
const int MOD = 1000000007;

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int dp[n + 2][k + 2];
        for (int j = 0; j <= k; j++)
        {
            dp[1][j] = (j > a[1]) ? 0 : 1;
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                if (j == 0)
                    dp[i][j] = dp[i - 1][j];
                else {
                    if (j - a[i] - 1 >= 0)
                        dp[i][j] = (MOD + dp[i][j - 1] % MOD + dp[i - 1][j] % MOD - dp[i - 1][j - 1 - a[i]] % MOD) % MOD;
                    else
                        dp[i][j] = (dp[i][j - 1] % MOD + dp[i - 1][j] % MOD) % MOD;
                }
            }
        }
        cout << dp[n][k] % MOD << endl;
    }
    return 0;

}

