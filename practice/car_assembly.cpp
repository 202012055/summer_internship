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
	int a[][4] = { { 4, 5, 3, 2 },
				{ 2, 10, 1, 4 } };
	int t[][4] = { { 0, 7, 4, 5 },
				{ 0, 9, 2, 8 } };
	int e[] = { 10, 12 }, x[] = { 18, 7 };
	int n=4;
	int c1=x[0]+a[0][n-1];
	int c2=x[1]+a[1][n-1];
		cout<<c1<<" "<<c2<<endl;
	for(int i=n-2;i>=0;i--){
		int tmp=c1;
		cout<<"choices:"<<(c1+a[0][i])<<" "<<((c2+t[1][i+1])+a[0][i])<<endl;
		cout<<"choices2:"<<(c2+a[1][i])<<" "<<((c1+t[0][i+1])+a[1][i])<<endl;
		c1=min(c1,c2+t[1][i+1])+a[0][i];
		c2=min(c2,tmp+t[0][i+1])+a[1][i];
		cout<<"a:"<<a[0][i]<<" "<<a[1][i]<<endl;
		cout<<"t:"<<t[0][i+1]<<" "<<t[1][i+1]<<endl;
		cout<<c1<<" "<<c2<<endl;
	}
	c1+=e[0];
	c2+=e[1];
	cout<<min(c1,c2)<<endl;
}

