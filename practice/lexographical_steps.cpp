#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define F first
#define S second
#define PB push_back 
#define PF push_front 
#define FOR(i,e) for(int i=0;i<(e);i++)
#define ALL(i) begin(i),end(i)
#define endl '\n'

#define MODBASE 1000000007
inline ll MWRAP(ll i,ll b=MODBASE){return i%b;}
ll MPOW(ll a,ll b,ll n=MODBASE){ ll x=1,y=a; while(b){ if(b%2)x=MWRAP(x*y,n); y=MWRAP(y*y,n); b>>=1; } return x; }
inline ll MINV(ll a,ll n=MODBASE){ return MPOW(a,n-2,n); }

#undef DEBUG
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
	int t=1;
	cin>>t;
	FOR(i,t){
		DN("\e[7mTEST CASE:",i+1,"\e[0m");
		solve();
	}
	return 0;
}

void solve(){
	ll x,y,k;
	cin>>x>>y>>k;
	k++;
	ll mn,mx;
	tie(mn,mx)=minmax(x,y);
	DN(mn,mx);
	ll tot=1;
	for(ll i=x+y;i>mx;i--)tot*=i;
	for(ll i=1;i<=mn;i++)tot/=i;
	DN(tot);
	ll lb=0;
	string ans;
	while(x>0 || y>0){
		if(x>0&&y>0){
			ll left=tot*x/(x+y);
			DN("left",left,lb,tot,k);
			if(k>(lb+left)){
				DN('v');
				ans.PB('V');
				lb+=left;
				tot-=left;
				y--;
			}else{
				DN('h');
				ans.PB('H');
				tot=left;
				x--;
			}
		}else if(x>0){
			ans.PB('H');
			x--;
		}else{
			ans.PB('V');
			y--;
		}
	}
	cout<<ans<<endl;

}

