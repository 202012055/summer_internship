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

void solve(){
	int n,e;
	cin>>n>>e;
	typedef tuple<int,int,int> triple;
	priority_queue<triple,vector<triple>,greater<triple>> q;
	int w,s,d;
	vector<pair<int,int>> adj[n];
	FOR(i,e){
		cin>>w>>s>>d;
		adj[s].emplace_back(d,w);
		adj[d].emplace_back(s,w);
	}
	bool dn[n]{};
	dn[0]=1;
	for(auto t:adj[0]){
		q.push(make_tuple(t.S,t.F,0));
	}
	int ans=0;
	while(q.size()){
		tie(w,s,d)=q.top();
		q.pop();
		if(!dn[s] ||!dn[d]){
			DN(w,s,d);
			ans+=w;
			int ne=dn[s]?d:s;
			dn[ne]=1;
			for(auto t:adj[ne]){
				int tmp=t.F;
				if(!dn[tmp])q.push(make_tuple(t.S,t.F,ne));
			}

		}
	}
	cout<<ans<<endl;



}

