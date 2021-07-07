#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define F first
#define S second
#define FOR(i,e) for(int i=0;i<(e);i++)
#define ALL(i) begin(i),end(i)
#define endl '\n'

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
	//cin>>t;
	FOR(i,t){
		D("\e[7mTEST CASE:",i+1,"\e[0m",endl);
		solve();
	}
	return 0;
}

void solve(){
	int n;cin>>n;
	ll q[n];
	FOR(i,n)cin>>q[i];
	int m=*max_element(q,q+n);
	ll t[m+1][m+1]{};
	t[0][0]=1;
	for(int i=1;i<=m;i++){
		t[i][0]=1;
		for(int j=1;j<=i;j++){
			t[i][j]=(t[i-1][j-1]+t[i-1][j])%1000000000;
		}
	}
	FOR(i,n){
		int k=q[i];
		for(int j=0;j<=k;j++){
			cout<<t[k][j]<<' ';
		}
		cout<<endl;
	}


}

