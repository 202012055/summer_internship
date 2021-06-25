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
vector<int> *adj;
auto h=[](const pair<int,int>& p){return p.F^p.S;}; 
unordered_set<pair<int,int>,decltype(h)> cache(10000,h);
vector<int> st;
void dfs(int i,int j){
	st.PB(i);
	for(auto s:st){
		cache.emplace(s,i);
	}
	for(auto o:adj[i]){
		if(o!=j)dfs(o,i);
	}
	st.pop_back();
}
void solve(){
	int n;
	cin>>n;
	adj=new vector<int>[n+1];
	FOR(i,n-1){
		int f,t;
		cin>>f>>t;
		adj[f].PB(t);
		adj[t].PB(f);
	}
	dfs(1,-1);
	int q;cin>>q;
	FOR(i,q){
		int d,a,b;
		cin>>d>>a>>b;
		if(d)swap(a,b);
		if(cache.count(make_pair(a,b)))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

