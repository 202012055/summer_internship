#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define F first
#define S second
#define FOR(i,e) for(int i=0;i<(e);i++)
#define ALL(i) begin(i),end(i)
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

void solve(){
	int l;cin>>l;
	string s;cin>>s;
	sort(ALL(s));
	bool p[l]{};
	p[0]=true;
	int t=pow(2,l);
	FOR(i,t-1){
		FOR(i,l){ if(p[i])cout<<s[i]; }cout<<endl;
		int j=l-1;
		while(j>0&&!p[j])j--;
		if(j==l-1){
			int k=l-2;
			while(!p[k])k--;
			p[k]=false;
			p[k+1]=true;
			for(int m=k+2;m<l;m++)p[m]=false;
		}else{
			p[j+1]=true;
		}
	}

}

