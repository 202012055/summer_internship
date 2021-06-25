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
#define MOD(x) (x)%1000000007
#define endl '\n'

//#define DEBUG
#ifdef DEBUG
void _debug_print(){} 
void _debug_print(char c){ cerr<<c; if(c!='\n')cerr<<' '; }
template <typename T,typename... Ts>void _debug_print(T t,Ts... ts){cerr<<t<<' ';_debug_print(ts...);} //multi arg
#	define D(args...) _debug_print(args)
#else
#	define D(args...) 0
#endif

void solve();
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	FOR(i,t){
		D("\e[7mTEST CASE:",i+1,"\e[0m",endl);
		solve();
	}
	return 0;
}

int nCr(int n,int r){
	if(r<0 || r>n)return 0;
	if(r>n-r)r=n-r;
	int ans=1;
	while(r>0){
		ans*=n;
		ans/=r;
		n--;
		r--;
	}
	return ans;

}
void solve(){
	int n;cin>>n;
	unordered_map<ll,int> c;
	FOR(i,n){
		ll k;
		cin>>k;
		c[k]++;
	}
	ll ans=0;
	for(auto p:c){
		D(p.F,p.S,endl);
		if(p.S>1){
			ans+=p.S*(p.S-1);
		}
	}
	cout<<ans<<endl;
}

