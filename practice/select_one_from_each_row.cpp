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
	ll n,m;
	cin>>n>>m;
	ll a[2][m];
	ll *c=a[0];
	ll *o=a[1];
	ll z,t1,t2;
	FOR(i,m){
		cin>>o[i];
	}
	for(ll i=2;i<=n;i++){
	t1=LLONG_MAX;t2=LLONG_MAX;
		FOR(j,m){
			if(o[j]<t2){
				if(o[j]<t1){
					t2=t1;
					t1=o[j];
				}
				else{
					t2=o[j];
				}
			}
		}
		FOR(j,m){
			cin>>z;
			if(o[j]==t1){
				c[j]=t2+z;
			}else{
				c[j]=t1+z;
			}
		}
		swap(c,o);
	}
	cout<<(*min_element(o,o+m))<<endl;


}

