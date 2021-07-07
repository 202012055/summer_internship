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
	string S;cin>>S;
	int N=S.size();
	if(N==1){cout<< (S[0]=='T')<<endl;return;}
        N/=2;
        int a[N][N][2];
        for(int i=N-1;i>=0;i--){
            int k=i*2+1;
            switch(S[k]){
                case '&':a[i][i][0]=(S[k-1]=='T'&&S[k+1]=='T');break;
                case '|':a[i][i][0]=(S[k-1]=='T'||S[k+1]=='T');break;
                case '^':a[i][i][0]=(S[k-1]=='T'^S[k+1]=='T');break;
            }
            a[i][i][1]=!(a[i][i][0]);
            //cout<<a[i][i][0]<<" "<<a[i][i][1]<<endl;
            for(int j=i+1;j<N;j++){
                int ct=0,cf=0;
                for(int x=i;x<=j;x++){
                    int lt,lf,rt,rf;
                    lt=lf=rt=rf=0;
                    if(x==i){
                        if(S[x*2]=='T'){lt=1;lf=0;}
                        else{lt=0;lf=1;}
                    }else{
                        lt=a[i][x-1][0];
                        lf=a[i][x-1][1];
                    }
                    if(x==j){
                        if(S[x*2+2]=='T'){rt=1;rf=0;}
                        else{rt=0;rf=1;}
                    }
                    else{
                        rt=a[x+1][j][0];
                        rf=a[x+1][j][1];
                    }
		    //cout<<lt<<" "<<lf<<" "<<rt<<" "<<rf<<endl;
                    switch(S[x*2+1]){
                        case '&':
                            ct+=lt*rt;
                            cf+=lt*rf+lf*rt+lf*rf;
                            break;
                        case '|':
                            ct+=lt*rt+lt*rf+lf*rt;
                            cf+=lf*rf;
                            break;
                        case '^':
                            ct+=lt*rf+lf*rt;
                            cf+=lt*rt+lf*rf;
                            break;
                    }
		    //cout<<"c:"<<ct<<":"<<cf<<endl;
                }
                a[i][j][0]=ct;
                a[i][j][1]=cf;
		//cout<<ct<<":"<<cf<<" ";
            }
	    //cout<<endl;
	}
           cout<<a[0][N-1][0]<<endl;

}

