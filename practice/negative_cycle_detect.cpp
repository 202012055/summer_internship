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
	vector<vector<int>>edges;
	int u,v,W;
	FOR(i,e){
		cin>>u>>v>>W;
		edges.push_back(vector<int>{u,v,W});
	}
	int w[n];
	    for(int i=0;i<n;i++){w[i]=INT_MAX;}
	    w[0]=0;
	    for(int i=1;i<n;i++){
	        for(auto &e:edges){
	            if(w[e[0]]!=INT_MAX && w[e[1]]>w[e[0]]+e[2]){
	                w[e[1]]=w[e[0]]+e[2];
	            }
	        }
	    }
	    for(auto &e:edges){
	        if(w[e[1]]>w[e[0]]+e[2]){
			cout<<1<<endl;return;
	        }
	    }
	    cout<<0<<endl;

}

