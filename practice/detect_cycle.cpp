#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define F first
#define S second
#define PB push_back 
#define PF push_front 
#define FOR(i,e) for(ll i=0;i<(e);i++)
#define ALL(i) begin(i),end(i)
#define endl '\n'

#define MODBASE 1000000007
inline ll MWRAP(ll i,ll b=MODBASE){return i%b;}
ll MPOW(ll a,ll b,ll n=MODBASE){ ll x=1,y=a; while(b){ if(b%2)x=MWRAP(x*y,n); y=MWRAP(y*y,n); b>>=1; } return x; }
inline ll MINV(ll a,ll n=MODBASE){ return MPOW(a,n-2,n); }

//#define DEBUG
#ifdef DEBUG
void _debug_print(){} 
template <typename T,typename... Ts>void _debug_print(T t,Ts... ts){cerr<<t<<' ';_debug_print(ts...);} //multi arg
#	define D(args...) _debug_print(args)
#	define DN(args...) D(args),cerr<<'\n';
#else
#	define D(args...) 
#	define DN(args...) 
#endif

void solve();
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t=1;
	//cin>>t;
	FOR(i,t){
		DN("\e[7mTEST CASE:",i+1,"\e[0m");
		solve();
	}
	return 0;
}
bool dfs(int i,vector<int>*adj,int*state){
	state[i]=1;
	for(auto a:adj[i]){
		if(state[a]==1)return false;
		else if(state[a]==0){
			if(!dfs(a,adj,state))return false;
		}
	}
	state[i]=2;
	return true;
}
void solve(){
	int n;cin>>n;
	int e;cin>>e;
	vector<int> adj[n+1];
	int u,v;
	FOR(i,e){
		cin>>u>>v;
		adj[u].PB(v);
	}
	int state[n+1]{};
	for(int i=1;i<=n;i++){
		if(!state[i]){
			if(!dfs(i,adj,state)){cout<<"cycle present"<<endl;return;}
		}
	}
	cout<<"no cycle present"<<endl;
}

