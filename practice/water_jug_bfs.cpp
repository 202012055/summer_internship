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
#define ADD(m,n)  {DN("adding",m,n);if(d[m][n]==0){ \
			d[m][n]=1;\
			p[m][n][0]=c.F;\
			p[m][n][1]=c.S;\
			q.emplace(m,n); }}
void solve(){
	int x,y,a;
	cin>>x>>y>>a;
	if(x<y)swap(x,y);
	DN(x,y,a);
	int p[y+1][x+1][2];
	bool d[y+1][x+1]{};
	queue<pair<int,int>> q;
	q.emplace(0,0);
	d[0][0]=1;
	while(q.size()){
		auto c=q.front();
		DN(c.F,c.S);
		if((c.F==a&&c.S==0) || (c.S==a&&c.F==0))break;
		q.pop();
		if(c.F==0)ADD(y,c.S);
		if(c.S==0)ADD(c.F,x);
		if(c.F==y)ADD(0,c.S);
		if(c.S==x)ADD(c.F,0);
		if(c.F!=0 && c.S!=x){
			//from y to x
			int m=min(c.F,x-c.S);
			DN("y2x",c.F-m,c.S+m);
			ADD(c.F-m,c.S+m);
		}
		if(c.S!=0 && c.F!=y){
			//from x to y
			int m=min(c.S,y-c.F);
			DN("x2y",c.F+m,c.S-m);
			ADD(c.F+m,c.S-m);
		}
	}
	int m=0,n=0;
	int t1,t2;
	DN("ANS");
	if(d[a][0]){m=a;}
	else if(d[0][a]){n=a;}
	if(m+n==0)cout<<"NOT POSSIBLE"<<endl;
	else{
		while(m+n!=0){
			cout<<n<<" "<<m<<endl;
			t1=p[m][n][0];
			t2=p[m][n][1];
			m=t1;
			n=t2;
		}
		cout<<n<<" "<<m<<endl;
	}
	DN("\nimpossible");
	FOR(i,x+1){
	FOR(j,y+1){
		if(!d[j][i] && (i==0||j==0))DN(i,j);
	}
	}
	
}

