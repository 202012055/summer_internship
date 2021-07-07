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
	cin>>t;
	FOR(i,t){
		DN("\e[7mTEST CASE:",i+1,"\e[0m");
		solve();
	}
	return 0;
}

void solve(){
	ll n,k;
	cin>>n>>k;
	ll v[n+2],s[n+2],e[n+2];
	FOR(i,n)cin>>v[i+1];
	v[0]=v[n+1]=LLONG_MAX;
	stack<ll>st;
	st.push(0);
	for(int i=1;i<=n;i++){
		while(v[st.top()]<v[i])st.pop();
		s[i]=st.top();
		D(s[i]);
		st.push(i);
	}
	DN();
	while(st.size())st.pop();
	st.push(n+1);
	for(int i=n;i>0;i--){
		while(v[st.top()]<v[i])st.pop();
		e[i]=st.top();
		D(e[i]);
		st.push(i);
	}
	DN();
	ll ans=0;
	for(ll i=1;i<=n;i++){
		if(v[i]<=k)continue;
		ll t=(e[i]-i)*(i-s[i]);
		ans+=t;
	}
	cout<<ans<<endl;



}

