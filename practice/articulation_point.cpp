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

int *d=nullptr;
vector<int> *adj=nullptr;

void solve();
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t=1;
	cin>>t;
	FOR(i,t){
		DN("\e[7mTEST CASE:",i+1,"\e[0m");
		solve();
	}
	return 0;
}

int curr;
int dfs(int i,int p){
	DN(p,i);
	bool yes{};
	if(d[i]!=-1)return d[i];
	int low=curr++;
	d[i]=low;
	int cnt=0;
	for(auto a:adj[i]){
		if(a!=p){
			if(d[a]==-1)cnt++;
			low=min(low,dfs(a,i));
			if(p==-1){
				if(cnt>1)yes=1;
			}else{
				if(cnt>0&&low>=d[i])yes=1;
			}
				}
			}
	if(yes)cout<<i<<endl;
	return low;
}
void solve(){
	int v,e;
	cin>>v>>e;
	delete [] d;
	delete [] adj;
	d=new int[v];
	FOR(i,v)d[i]=-1;
	adj=new vector<int>[v];
	int m,n;
	FOR(i,e){
		cin>>m>>n;
		adj[m].PB(n);
		adj[n].PB(m);
	}
	curr=0;
	FOR(i,v){
		if(d[i]==-1){
			dfs(i,-1);
		}
	}
}

