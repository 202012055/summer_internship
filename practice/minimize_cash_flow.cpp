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
	//cin>>t;
	FOR(i,t){
		D("TEST:",i+1,endl);
		solve();
	}
	return 0;
}

void solve(){
	int n;cin>>n;
	int v[n][n];
	FOR(i,n)FOR(j,n)cin>>v[i][j];
	FOR(i,n){
		D(i,endl);
		int f=0,t=0;
		while(f<n && t<n){
			D(f,t,endl);
			if(f==i){f++;continue;}
			if(t==i){t++;continue;}
			if(v[f][i]<v[i][t]){
				v[i][t]-=v[f][i];
				v[f][t]+=v[f][i];
				v[f][i]=0;
				f++;
			}else{
				v[f][i]-=v[i][t];
				v[f][t]+=v[i][t];
				v[i][t]=0;
				t++;
			}
		}	
	}
	FOR(i,n)v[i][i]=0;
	int sm=0;
	FOR(i,n){
		FOR(j,n){
		D(v[i][j]," ");
		sm+=v[i][j];
		}
		D(endl);
	}
	cout<<sm<<endl;

}

