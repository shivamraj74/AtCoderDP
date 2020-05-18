//Radhe Radhe
#include<bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
//#include<boost/math/common_factor.hpp>
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 
//using namespace __gnu_pbds; 
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
 
int N;
 
long double dp[305][305][305];
 
long double rec(int i, int j, int k) {
    if (i == 0 && j == 0 && k == 0) return dp[0][0][0];
    if (dp[i][j][k] != 0) return dp[i][j][k];
 
    long double res = 0.0;
    if (i > 0)res += rec(i - 1, j, k) * i;
    if (j > 0)res += rec(i + 1, j - 1, k) * j;
    if (k > 0)res += rec(i, j + 1, k - 1) * k;
 
    res += (long double) N;
    res /= (long double) (i + j + k);
    dp[i][j][k] = res;
    return res;
 
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--) {
        cin >> N;
        int one = 0, two = 0, three = 0;
        for (int i = 0; i < N; i++) {
            int x; cin >> x;
            if (x == 1) one++;
            else if (x == 2) two++;
            else three++;
        }
        memset(dp, 0, sizeof(dp));
 
        long double ans = rec(one, two, three);
        cout << setprecision(20) << ans << endl;
 
    }
    return 0;
 
}
