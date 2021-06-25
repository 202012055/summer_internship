#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pi;
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
typedef vector<ll> Vll;

#define F first
#define S second
#define PB push_back 
#define EB emplace_back 
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

void solve(){
	int n,m,k,q;
	cin>>n>>m>>k>>q;
	int u,v,w;
	vector<Pi> adj[n+1];
	FOR(i,m){
		cin>>u>>v>>w;
		adj[u].EB(v,w);
		adj[v].EB(u,w);
	}
	ll dis[n+1];
	FOR(i,n)dis[i+1]=LLONG_MAX;
	FOR(i,k){
		int t;cin>>t;
		adj[0].EB(t,0);
	}
	set<Pi> heap;
	heap.insert(make_pair(0,0));
	while(heap.size()){
		auto t=*(heap.begin());
		heap.erase(heap.begin());
		for(auto a:adj[t.S]){
			if(dis[a.F]==LLONG_MAX){
				dis[a.F]=t.F+a.S;
				heap.emplace(dis[a.F],a.F);
			}else if(dis[a.F]>a.S+t.F){
				heap.erase(heap.find(make_pair(dis[a.F],a.F)));
				dis[a.F]=t.F+a.S;
				heap.emplace(dis[a.F],a.F);
			}
		}

	}
	FOR(i,q){
		int t;cin>>t;
		cout<<dis[t]<<endl;
	}

}

