#include<iostream>
using l=int; l main() {l t;std::cin>>t;while(t--){l x,y,a,b,c,d;std::cin>>x>>y>>a>>b>>c>>d;l f[x+2][y+2];for(l i=0;i<=x+1;i++)f[i][0]=0;for(l i=0;i<=y+1;i++)f[0][i]=0;for(l i=1;i<=x+1;i++)for(l j=1;j<=y+1;j++){if(i==1&&j==1)f[i][j]=1;else if((i==a+1&&j==b+1)||(i==c+1&&j==d+1))f[i][j]=0;else f[i][j]=f[i-1][j]+f[i][j-1];}std::cout<<f[x+1][y+1]<<'\n';}}
/*
dp on grid untuk menghitung banyaknya jalan menuju (x,y).
dp[i][j] = dp[i-1][j] + dp[i][j-1], titik (i,j) bukan (x1,y1) atau (x2,y2).
           0, titik (i,j) merupakan salah satu dari (x1,y1) atau (x2,y2).
*/
