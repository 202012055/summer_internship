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
#	define D(args...) 0
#	define DN(args...) 0
#endif

void solve();
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	//cin>>t;
	FOR(i,t){
		DN("\e[7mTEST CASE:",i+1,"\e[0m");
		solve();
	}
	return 0;
}

ll n;
ll *mapping;
list<ll> *e;
ll *p;
ll *cnt;
ll curr;

void make_tree(ll m,ll n){
	p[m]=n;
	cnt[m]=2;
	for(auto c:e[m]){
		if(c!=n){
			make_tree(c,m);
			cnt[m]+=cnt[c];
		}
	}
}
void make_parent(ll i,ll j){
	DN("make_parent",i,j);
	if(p[i])make_parent(p[i],i);
	cnt[i]+=cnt[p[i]]-cnt[j];
	p[i]=j;
}
void solve(){
	cin>>n;
	stack<ll> fin;
	mapping=new ll[n+1];
	e=new list<ll>[n+1];
	p=new ll[n+1];
	cnt=new ll[n+1];
	cnt[0]=0;
	vector<ll> paths;
	FOR(i,n)cin>>mapping[i+1];
	FOR(i,n-1){
		ll a,b;
		cin>>a>>b;
		e[mapping[a]].push_back(mapping[b]);
		e[mapping[b]].push_back(mapping[a]);
	}
	make_tree(n,0);
	for(curr=n;curr>0;curr--){
		make_parent(curr,0);
		ll ans=0;
		paths.clear();
		for(auto ch:e[curr]){ if(ch<curr) paths.PB(cnt[ch]); }
		ll psize=paths.size();
		for(ll i=0;i<psize-1;i++){
			for(ll j=i+1;j<psize;j++){
				ans+=paths[i]*paths[j];
			}
		}
		ans/=2;
		DN(ans);
		fin.push(ans+cnt[curr]-1);
		for(auto a:e[curr])p[a]=0;
	}
	while(fin.size()){
		cout<<fin.top()<<' ';
		fin.pop();
	}


}

