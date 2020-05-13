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
//const int N = 10001;
const int N=1e5+10;
//const int N = (2 * (1e5)) + 2;
 
 
 
vector<int> edges[N];
bool visited[N];
int d[N];
 
void dfs(int i)
{
    visited[i]=1;
    d[i]=-1;
    for(int v : edges[i])
    {
        if(!visited[v]) 
            dfs(v);
 
        d[i]=max(d[i],d[v]);
    }
    d[i]++;
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
        int n, m;
        cin >> n >> m;
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            edges[a].push_back(b);
        }
 
        int answer = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
                dfs(i);
 
            answer = max(answer, d[i]);
        }
        cout << answer << endl;
    }
    return 0;
 
}
