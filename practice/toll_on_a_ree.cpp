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

int n,c,m;
ll mn;
vector<int> *adj;
int *poll;
int *people;
ll *agg;
ll ptot;
int dfs_agg(int i,int p){
	ll mini=0;
	for(auto a:adj[i]){
		if(a!=p){
			mini+=dfs_agg(a,i);
			agg[i]+=agg[a];
		}
	}
	mini+=agg[i]*poll[i];
	agg[i]+=people[i];
	return mini;
}
void dfs_check(int i,int p,int cost){
	if(mn>cost)mn=cost;
	for(auto a:adj[i]){
		if(a!=p){
			dfs_check(a,i,cost-(agg[a]*poll[i])+((ptot-agg[a])*poll[a]));
		}
	}
}

void solve(){
	cin>>n>>c>>m;
	adj=new vector<int>[n+1];
	poll=new int[n+1];
	people=new int[n+1];
	agg=new ll[n+1];
	FOR(i,n-1){
		int p,q;
		cin>>p>>q;
		adj[p].PB(q);
		adj[q].PB(p);
	}
	int t;
	FOR(i,c){
		cin>>t;
		poll[t]++;
	}
	FOR(i,m){
		cin>>t;
		people[t]++;
	}
	mn=dfs_agg(1,-1);
	ptot=agg[1];
	dfs_check(1,-1,mn);
	cout<<mn<<endl;

}

