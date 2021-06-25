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
vector<int>*adj;
int *col;
bool dfs(int i,int p,int c){
	DN(p,i,c);
	col[i]=c;
	c=(c==2?1:2);
	for(auto a:adj[i]){
		if(a!=p){
			if(col[a]){
				if(col[a]!=c)return false;
			}else{
				if(!dfs(a,i,c)){
					return false;
				}
			}
		}
	}
	return true;
}
void solve(){
	int v,e;
	cin>>v>>e;
	adj=new vector<int>[v+1];
	col=new int[v+1];
	FOR(i,e){
		int m,n;
		cin>>m>>n;
		adj[m].PB(n);
		adj[n].PB(m);
	}
	FOR(i,v)col[i+1]=0;
	FOR(i,v){
		if(!col[i+1]){
			if(!dfs(i+1,-1,1)){
				cout<<"NO"<<endl;
				return;
			}
		}
	}
	cout<<"YES"<<endl;

}

