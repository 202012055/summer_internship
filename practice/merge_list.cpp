#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define F first
#define S second
#define FOR(i,e) for(int i=0;i<(e);i++)
#define ALL(i) begin(i),end(i)
#define endl '\n'
#define MOD(x) (x)%1000000007

//#define DEBUG
#ifdef DEBUG
void _debug_print(){} 
void _debug_print(char c){ cerr<<c; if(c!='\n')cerr<<' '; }
template <typename T,typename... Ts>void _debug_print(T t,Ts... ts){cerr<<t<<' ';_debug_print(ts...);} //multi arg
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
		D("\e[7mTEST CASE:",i+1,"\e[0m",endl);
		solve();
	}
	return 0;
}

void solve(){
	int n,m;
	cin>>n>>m;
	int a[n+1][m+1];
	FOR(i,n+1)a[i][0]=1;
	FOR(i,m+1)a[0][i]=1;
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			a[i][j]=MOD(a[i-1][j]+a[i][j-1]);
		}
	}
	cout<<a[n][m]<<endl;

}

