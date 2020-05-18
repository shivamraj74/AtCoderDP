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

int dp[3010][3030];
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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = n - 1; i >= 0; i--)
            for (int j = i; j < n; j++)
                if (i == j)
                    dp[i][j] = a[i];
                else
                    dp[i][j] = max((a[i] - dp[i + 1][j]), (a[j] - dp[i][j - 1]));
        cout << dp[0][n - 1] << endl;
    }
    return 0;

}

