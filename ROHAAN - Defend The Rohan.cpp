#include <bits/stdc++.h>
//#include<windows.h>
using namespace std;
#define INF 0x7f7f7f7f
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FILL(A,value) memset(A,value,sizeof(A))
int main(int argc, char**argv) {
    int n,node,p;
    int DP[52][52];
    int road[52][2];
    cin>>n;
    FOR(x,1,n+1)
    {
        FILL(DP,INF);
        //cout<<DP[0][0]<<endl;
        cin>>node;
        FOR(i,0,node)
        {
            FOR(j,0,node)
                cin>>DP[i][j];
        }
        cin>>p;
        FOR(i,0,p)
            FOR(j,0,2)
            {
                cin>>road[i][j];
                road[i][j]--;
            }
        FOR(i,0,node)
            FOR(j,0,node)
                FOR(k,0,node)
                    if(DP[j][i]+DP[i][k]<DP[j][k])
                    {
                        DP[j][k]=DP[j][i]+DP[i][k];
                    }
        int total=0;
        FOR(i,0,p)
            total+=DP[road[i][0]][road[i][1]];    
        
        cout<<"Case #"<<x<<": "<<total<<endl;
        //system("pause");
    }
}
