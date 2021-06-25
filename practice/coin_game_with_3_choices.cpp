#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define F first
#define S second
#define FOR(i,b,e) for(int (i)=(b);(i)<(e);(i)++)

void solve();
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		//cerr<<"TEST "<<t+1<<":\n";
		solve();
	}
	return 0;
}

void solve(){
	int n,x,y;
	cin>>n>>x>>y;
	int o[n+1];
	bool b[n+1];
	o[0]=0;
	o[1]=1;
	b[0]=false;
	b[1]=true;
	FOR(i,2,n+1){
		bool xok{},yok{},dok{};
		if(x==i){xok=true;}
		else if(x<i){
			xok=b[i-x-o[i-x]];
		}
		if(!xok){
			if(y==i){yok=true;}
			else if(y<i){
				yok=b[i-y-o[i-y]];
			}
		}
		if(!xok && !yok){
			if(i==1)dok=true;
			else
			dok=b[i-1-o[i-1]];
		}
		if(xok){
			o[i]=x;b[i]=true;
		}else if(yok){
			o[i]=y;b[i]=true;
		}else{
			o[i]=1;
			b[i]=dok;
		}
		cout<<o[i]<<" "<<b[i]<<" "<<xok<<" "<<yok<<" "<<dok<<endl;
		
	}
	int cnt=0;
	while(n){
		cnt++;
		n-=o[n];
	}
	cout<<(cnt%2==1?"A":"B")<<endl;

}

