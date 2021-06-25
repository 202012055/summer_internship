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

int *w;
void solve(){
	int v,e;
	cin>>v>>e;
	int s,d;
	vector<Pi> adj[v];
	FOR(i,e){
		int m,n;
		cin>>m>>n;
		adj[m].EB(n,0);
		adj[n].EB(m,1);
	}
	cin>>s>>d;
	w=new int[v];
	bool done[v]{};
	FOR(i,v)w[i]=INT_MAX;
	priority_queue<Pi,vector<Pi>,greater<Pi>> q;
	w[s]=0;
	q.emplace(w[s],s);
	while(q.size()){
		auto p=q.top();
		DN(p.S,p.F);
		if(p.S==d){cout<<p.F<<endl;return;}
		q.pop();
		if(!done[p.S]){
			done[p.S]=1;
			for(auto a:adj[p.S]){
				if(w[a.F]>w[p.S]+a.S){
					w[a.F]=w[p.S]+a.S;
					q.emplace(w[a.F],a.F);
				}
			}
		}
	}
	return;
}

