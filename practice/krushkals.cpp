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

int find(int i,int*par){
	if(par[i]!=i){
		par[i]=find(par[i],par);
	}
	return par[i];
}

int non_mutating_find(int i,int*par){
	if(par[i]!=i){
		return find(par[i],par);
	}
	return par[i];
}

void print_connected(int*par,int n){
	bool d[n]{};
	FOR(i,n){
		if(!d[i]){
			d[i]=1;
			int p=non_mutating_find(i,par);
			cout<<p<<" : "<<i<<' ';
			for(int j=i+1;j<n;j++){
				if(!d[j]){
					if(p==non_mutating_find(j,par))d[j]=1,cout<<j<<' ';
				}
			}
			cout<<endl;
		}
	}
}

bool _union(int i,int j,int*par,int*size){
	D("union",i,j);
	int ip=find(i,par);
	int jp=find(j,par);
	if(ip!=jp){
		if(size[ip]<size[jp]){
			par[ip]=jp;
			size[jp]+=size[ip];
			size[ip]=0;
		}else{
			par[jp]=ip;
			size[ip]+=size[jp];
			size[jp]=0;
		}
		DN("true");
		return true;
	}
		DN("false");
	return false;
}

void solve(){
	int n,e;
	cin>>n>>e;
	typedef tuple<int,int,int> triple; //w,s,d
	vector<triple> edges;
	int w,s,d;
	FOR(i,e){
		cin>>w>>s>>d;
		edges.emplace_back(w,s,d);
	}
	sort(ALL(edges));
	int par[n],size[n];
	FOR(i,n)par[i]=i,size[i]=1;
	int ans=0;
	FOR(i,e){
		if(_union(get<1>(edges[i]),get<2>(edges[i]),par,size))ans+=get<0>(edges[i]),DN(ans);
		DN("connected:");
		print_connected(par,n);
	}
	cout<<ans<<endl;
}

