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
        int n;
        cin >> n;
        int  a[n];
        int pref[n + 1];
        pref[0] = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pref[i + 1] = pref[i] + a[i];
        }

        int dp[n][n];
        memset(dp, 0x3f, sizeof(dp));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 0;
        }

        for (int l = 2; l <= n; l++) {
            for (int i = 0; i < n - l + 1; i++) {
                int j = i + l - 1;
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], (dp[i][k] + dp[k + 1][j]) + (pref[k + 1] - pref[i] + pref[j + 1] - pref[k + 1]));
                }
            }
        }

        cout << dp[0][n - 1] << endl;
    }
    return 0;

}

