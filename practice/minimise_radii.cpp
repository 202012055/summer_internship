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
	int x1,y1,x2,y2;
	int t1,t2;
	int x,y;
	ll sd1[n],sd2[n];
	ll d1[n];
	ll d2[n];
	ll*d1p=d1,*d2p=d2;
	cin>>x1>>y1>>x2>>y2;
	int p[n][2];
	FOR(i,n){
		cin>>x>>y;
		p[i][0]=x;
		p[i][1]=y;
		t1=x-x1;
		t2=y-y1;
		d1[i]=llabs(((ll)t1*t1)+((ll)t2*t2));
		t1=x-x2;
		t2=y-y2;
		d2[i]=llabs(((ll)t1*t1)+((ll)t2*t2));
		sd1[i]=i;
		sd2[i]=i;
	}
	sort(sd1,sd1+n,[d1p](int i,int j){
			return d1p[i]<d1p[j];
		});
	sort(sd2,sd2+n,[d2p](int i,int j){
			return d2p[i]<d2p[j];
		});
	bool d[n]{};
	ll ans=d2[sd2[n-1]];
	ll nans;
	int p2=n-1;
	FOR(i,n){
		d[sd1[i]]=1;
		while(p2>=0&&d[sd2[p2]])p2--;
		nans=d1[sd1[i]]+((p2!=-1)?d2[sd2[p2]]:0);
		DN(i,p2,d1[sd1[i]],((p2!=-1)?d2[sd2[p2]]:0));
		if(nans<ans){ans=nans;}
	}
	cout<<ans<<endl;

}

