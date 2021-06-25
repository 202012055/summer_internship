#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define F first
#define S second
#define FOR(i,e) for(int i=0;i<(e);i++)
#define endl '\n'

#define DEBUG
#ifdef DEBUG
template <typename T> void _debug_print(T t){ cerr<<t; } //single arg
template <typename T,typename... Ts>void _debug_print(T t,Ts... ts){cerr<<t<<" ";_debug_print(ts...);} //multi arg
#	define D(args...) _debug_print(args)
#else
#	define D(args...) 0
#endif

void solve();
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	FOR(i,t){
		D("TEST:",i+1,endl);
		solve();
	}
	return 0;
}

void solve(){
	int n,V;
	cin>>n>>V;
	int c[n];
	FOR(i,n)cin>>c[i];
	int v[n+1][V+1];
	FOR(i,V+1)v[0][i]=INT_MAX;
	FOR(i,n+1)v[i][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=V;j++){
			int a=j>=c[i-1]?v[i][j-c[i-1]]:INT_MAX;
			int b=v[i-1][j];
			if(a==INT_MAX)a--;
			v[i][j]=min(a+1,b);
			D(v[i][j]==INT_MAX?-1:v[i][j]," ");

		}
		D(endl);
	}

}

