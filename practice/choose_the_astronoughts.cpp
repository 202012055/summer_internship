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
int *p,*s;
int f(int i){
	if(p[i]!=i){
		p[i]=f(p[i]);
	}
	return p[i];
}
void u(int i,int j){
	int ip=f(i);
	int jp=f(j);
	if(ip!=jp){
		if(s[ip]>s[jp]){
			s[ip]+=s[jp];
			p[jp]=ip;
		}else{
			s[jp]+=s[ip];
			p[ip]=jp;
		}
	}
}
void solve(){
	int v,e;
	cin>>v>>e;
	p=new int[v];
	s=new int[v];
	FOR(i,v){p[i]=i;s[i]=1;}
	FOR(i,e){
		int m,n;cin>>m>>n;
		u(m,n);
	}
	vector<int> cnts;
	FOR(i,v){
		if(p[i]==i)cnts.PB(s[i]);
	}
	ll ans=0;
	int t=cnts.size();
	for(int i=t-2;i>=0;i--){
		ans+=cnts[i]*cnts[i+1];
		cnts[i]+=cnts[i+1];
	}
	cout<<ans<<endl;
}

