#include<bits/stdc++.h>
using namespace std;

#define REP(_x,_y) for(int (_x)=0;(_x)<(_y);(_x)++)
#define FOR(_x,_y,_z) for(int (_x)=(_y);(_x)<=(_z);(_x)++)
#define FORD(_x,_y,_z) for(int (_x)=(_y);(_x)>=(_z);(_x)--)
#define RESET(_x,_y) memset((_x),(_y),sizeof(_x))
#define SZ(_x) ((int)(_x).size())
#define LEN(_x) strlen(_x)
#define ALL(_x) (_x).begin(),(_x).end()
#define LL long long
#define ULL unsigned LL
#define PII pair<int,int>
#define VI vector<int>
#define VII vector< PII >
#define VVI vector< VI >
#define MP make_pair
#define PB push_back
#define FI first
#define SE second
const int INF=1e9;
const int MOD=1e9+7;
// >.<
int len,dp[100000][3][2];
char num[100001];
bool vis[100000][3][2]={0};
string an;
int f(int x,int y,int z){
	if(x==len){
		if(y==0&&z==1)return 0;
		return -INF;
	}
	if(vis[x][y][z])return dp[x][y][z];
	int ret=-INF;
	ret=max(ret,f(x+1,y,z));
	if(z==1||num[x]!='0'){
		ret=max(ret,f(x+1,(y+num[x]-'0')%3,1)+1);
	}
	vis[x][y][z]=1;
	return dp[x][y][z]=ret;
}
void g(int x,int y,int z){
	if(x==len)return;
	int xx=f(x+1,y,z);
	int yy=f(x+1,(y+num[x]-'0')%3,1)+1;
	if((z==1||num[x]!='0')&&(yy>0&&xx<yy)){
		an.PB(num[x]);
		g(x+1,(y+num[x]-'0')%3,1);
	}
	else{
		g(x+1,y,z);
	}
}
int main(){
	gets(num);
	len=LEN(num);
	f(0,0,0);
	g(0,0,0);
	if(SZ(an)==0){
		REP(i,len){
			if(num[i]=='0'){
				an.PB('0');
				break;
			}
		}
	}
	if(SZ(an)==0)return 0*puts("-1");
	cout<<an<<endl;
	return 0;
}
