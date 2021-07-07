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

int dfs(int i,int p,int*color,vector<int> *adj){
	DN("dfs",p,i);
	if(color[i]==1){
		DN("contact");
		color[i]=2;
		return 1;
	}
	for(auto a:adj[i])D(a);DN();
	color[i]=1;
	int l=0;
	for(auto a:adj[i]){
		DN("check",i,a);
		if(a==p || color[a]==2)continue;
		int t=dfs(a,i,color,adj);
		if(t){
			if(color[i]==2){
				t--;
				color[i]=1;
			}
		}else{
			cout<<i<<a<<endl;
		}
		l+=t;
	}
	color[i]=2;
	return l;
}
void solve(){
	int v,e;
	int m,n;
	cin>>v>>e;
	vector<int> adj[v];
	FOR(i,e){
		cin>>m>>n;
		adj[m].PB(n);
		adj[n].PB(m);
	}
	int color[v]{};
	FOR(i,v){
		if(!color[i])dfs(i,-1,color,adj);
	}
}

