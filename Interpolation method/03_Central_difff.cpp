#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    double y[50][50],x[50];
    int n,i,j,st,v=0;
    double p,e,s,d,sum=0,r,sum1=0,r1,g1,g2,g3,g4;
    cout<<"Enter n="<<endl;
    cin>>n;
    cout<<"Starting Point="<<endl;
    cin>>s;
    cout<<"End Point="<<endl;
    cin>>e;
    cout<<"Difference="<<endl;
    cin>>d;
    p=(e-s)/d;
    st=n/2;
    cout<<"X"<<"\t"<<"Y"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>x[i]>>y[0][i];
    }
     cout<<"X"<<"\t"<<"Y"<<endl;
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            y[i][j]=y[i-1][j+1]-y[i-1][j];
        }
    }
    cout<<"Forward Difference Table"<<endl;
    for(j=0;j<n;j++)
    {
       printf("%lf",x[j]);
        for(i=0;i<n-j;i++)
        {
            if(y[i][j]>0.0001)
            {
                 printf("\t%lf",y[i][j]);
            }

        }
        printf("\n");
    }
    g1=p;
    g2=(p*(p-1))/2;
    g3=((p+1)*p*(p-1))/6;
    g4=((p+1)*p*(p-1)*(p-2))/24;

    r=y[v][st]+g1*y[v+1][st]+g2*y[v+2][st]+g3*y[v+3][st]+g4*y[v+4][st];
    cout<<"Root is="<<r<<endl;

    return 0;
}
