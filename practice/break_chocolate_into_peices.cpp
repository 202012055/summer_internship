#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define F first
#define S second
#define FOR(i,e) for(int i=0;i<(e);i++)
#define ALL(i) begin(i),end(i)
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
	int m,n;
	cin>>m>>n;
	int x[m-1],y[n-1];
	FOR(i,m-1)cin>>x[i];
	FOR(i,n-1)cin>>y[i];
	sort(x,x+m-1,greater<int>());
	sort(y,y+n-1,greater<int>());
	int xp,yp;
	xp=yp=1;
	int i,j,ans=0;
	i=j=0;
	while(i<m-1&&j<n-1){
		int xb=x[i]*yp;
		int yb=y[j]*xp;
		if(xb>yb){
			ans+=xb;
			xp++;
			i++;
		}else{
			ans+=yb;
			yp++;
			j++;
		}
		
	}
	while(i<m-1){
		ans+=x[i]*yp;
		i++;
	}
	while(j<n-1){
		ans+=y[i]*xp;
		j++;
	}
	cout<<ans<<endl;

}

