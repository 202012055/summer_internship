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
	int n;cin>>n;
	int v[n];
	FOR(i,n)cin>>v[i];
	int p=1;
	int mn=INT_MIN;
	FOR(i,n){
		if(v[i])p*=v[i];
		if(v[i]<0)mn=max(mn,v[i]);
	}
	if(p<0){
		p/=mn;
	}
	cout<<p<<endl;

}

