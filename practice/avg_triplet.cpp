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
	int n;
	cin>>n;
	ll t,tot=0;
	int r[3]{};
	FOR(i,3*n){
		cin>>t;
		tot+=t;
		r[t%3]++;
	}
	DN(r[0],r[1],r[2]);
	if(tot%3){
		tot/=3;
		tot++;
	}else{
		tot/=3;
	}
	DN(tot);
	r[0]%=3;
	r[1]%=3;
	r[2]%=3;
	DN(r[0],r[1],r[2]);
	int mn=*min_element(ALL(r));
	r[0]-=mn;
	r[1]-=mn;
	r[2]-=mn;
	DN(r[0],r[1],r[2]);
	tot-=(r[0]+r[1]+r[2])/3;
	cout<<tot<<endl;

}

