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
	int stack1[] = { 3, 2, 1, 1, 1 };
	int stack2[] = { 4, 1, 2 };
	int stack3[] = { 1, 4, 4, 1 };
	int s1=sizeof(stack1)/sizeof(int);
	int s2=sizeof(stack2)/sizeof(int);
	int s3=sizeof(stack3)/sizeof(int);
	int sm1,sm2,sm3;
	sm1=sm2=sm3=0;
	int i1,i2,i3;
	i1=i2=i3=0;
	int mx=0;
	while(i1<s1 && i2<s2 && i3<s3){
		D(i1,i2,i3,endl);
		D("-",sm1,sm2,sm3,endl);
		if(sm1<sm2){
			if(sm1<sm3){
				//1 min
				sm1+=stack1[i1];
				i1++;
			}else{
				// 3 min
				sm3+=stack3[i3];
				i3++;
			}
		}else{
			if(s2<s3){
				//2 min
				sm2+=stack2[i2];
				i2++;
			}else{
				// 3 min
				sm3+=stack3[i3];
				i3++;
			}
			if(sm1==sm2 && sm2==sm3)mx=max(mx,sm1);
		}
		
	}
	cout<<mx<<endl;

}

