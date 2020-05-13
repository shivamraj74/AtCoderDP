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
 
 
 
int dp[3][100005];
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    
    int t = 1;
    //cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> a(N), b(N), c(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i] >> b[i] >> c[i];
        }
 
        dp[0][0] = a[0];
        dp[1][0] = b[0];
        dp[2][0] = c[0];
        for (int i = 1; i < N; i++) {
            dp[0][i] = a[i] + max(dp[1][i - 1], dp[2][i - 1]);
            dp[1][i] = b[i] + max(dp[0][i - 1], dp[2][i - 1]);
            dp[2][i] = c[i] + max(dp[0][i - 1], dp[1][i - 1]);
        }
        cout << max(max(dp[0][N - 1], dp[1][N - 1]), dp[2][N - 1]) << endl;
 
    }
    return 0;
 
}
