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

#define DEBUG
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
	//cin>>t;
	FOR(i,t){
		D("\e[7mTEST CASE:",i+1,"\e[0m",endl);
		solve();
	}
	return 0;
}

void solve(){
	int n;cin>>n;
	int c[n];
	FOR(i,n)cin>>c[i];
	int d;
	cin>>d;
	pair<ull,ull> lr[d];
	FOR(i,d)cin>>lr[i].F>>lr[i].S;
	ull r=0;
	ull l=ULLONG_MAX;
	FOR(i,d){
		l=min(l,lr[i].F);
		r=max(r,lr[i].S);
	}
	D(r-l,endl);
	sort(c,c+n);
	vector<int> fc;
	FOR(i,n){
		bool got=false;
		for(auto j:fc){
			if(c[i]%j==0){
				got=true;
				break;
			}
		}
		if(!got)fc.PB(c[i]);
	}
	for_each(ALL(fc),[](int x){D(x);});
	D(endl);
	bool a[r-l+1]{};
	for(int i=l;i<=r;i++){
		bool got=false;
		for(auto j:fc){
			if(i%j==0){
				got=true;
				break;
			}
		}
		if(got)a[i-l]=true;
	}
	FOR(i,d){
		ull cnt=0;
		for(int j=lr[i].F;j<=lr[i].S;j++){
			if(a[j-l])cnt++;
		}
		cout<<cnt<<endl;
	}

}

