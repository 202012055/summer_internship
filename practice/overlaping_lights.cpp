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
	int n,p;
	cin>>n>>p;
	vector<pair<int,int>> l;
	int c,r;
	FOR(i,n){
		cin>>c>>r;
		l.emplace_back(c-r,min(p,c+r));
	}
	sort(ALL(l));
	FOR(i,n){DN(l[i].F,l[i].S);}
	int mn=0;
	int x,y;
	x=y=-1;
	ll ans=0;
	FOR(i,n){
		int p=max(l[i].F,mn);
		int q=l[i].S;
		DN(mn,x,y,p,q);
		if(mn>q)continue;
		if(y<p){
			mn=p;
			x=p;
			y=q;
		}else{
			ans+=min(y,q)-max(x,p)+1;
			x=y+1;
			y=max(y,q);
			mn=x;
		}

	}
	cout<<ans<<endl;


}

