//Radhe Radhe
#include<bits/stdc++.h>
//#include<boost/multiprecision/cpp_int.hpp>
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
const int N = 10001;
//const int N = (2 * (1e5)) + 2;
 
int dp[105][100005];
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    
    int t = 1;
    //cin >> t;
    while (t--) {
        int N, W;
        cin >> N >> W;
        vector<int> w(N), v(N);
        for (int i = 0; i < N; i++) {
            cin >> w[i] >> v[i];
        }
 
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= W; j++) {
                if (i == 0) { if (j >= w[i]) dp[i][j] = v[i];}
                else if (j - w[i] >= 0) dp[i][j] = max(v[i] + dp[i - 1][j - w[i]], dp[i - 1][j]);
                else dp[i][j] = dp[i - 1][j];
            }
        }
 
        cout << dp[N - 1][W] << endl;
    }
    return 0;
 
}
