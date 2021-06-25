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
	vector<int> TargetPos(2);
	int N;
	 pair<int,int>t;
	cin>>N>>t.F>>t.S>>TargetPos[0]>>TargetPos[1];
	bool mat[N+1][N+1]{};
	    queue<pair<int,int>>q;
	    pair<int,int> tar{TargetPos[0],TargetPos[1]};
	    int s=0;
	    int n;
	    auto mv=[](pair<int,int>k,int x,int y){k.first+=x;k.second+=y;return k;};
	    auto valid=[N](pair<int,int>k,bool*m){
	        int x=k.first,y=k.second;
	        return x>0&&y>0&&x<=N&&y<=N&&!m[y*(N+1)+x];
	    };
	    DN(t.F,t.S);
	    q.push(t);

	    while(n=q.size()){
	        for(int i=0;i<n;i++){
	            auto f=q.front();
		    DN(f.F,f.S);
	            if(f==tar){cout<<s<<endl;return;}
	            if(valid(t=mv(f,-2,-1),(bool*)mat)){mat[t.second][t.first]=1;q.push(t);}
	            if(valid(t=mv(f,-2,1),(bool*)mat)){mat[t.second][t.first]=1;q.push(t);}
	            if(valid(t=mv(f,-1,+2),(bool*)mat)){mat[t.second][t.first]=1;q.push(t);}
	            if(valid(t=mv(f,-1,-2),(bool*)mat)){mat[t.second][t.first]=1;q.push(t);}
	            if(valid(t=mv(f,1,+2),(bool*)mat)){mat[t.second][t.first]=1;q.push(t);}
	            if(valid(t=mv(f,1,-2),(bool*)mat)){mat[t.second][t.first]=1;q.push(t);}
	            if(valid(t=mv(f,2,-1),(bool*)mat)){mat[t.second][t.first]=1;q.push(t);}
	            if(valid(t=mv(f,2,1),(bool*)mat)){mat[t.second][t.first]=1;q.push(t);}
	            q.pop();
	        }
	        s++;
	    }
	    cout<<-1<<endl;
	    return ;

}

