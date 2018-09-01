#include<iostream>
#include<cmath>
#include<iomanip>
#define M_PI 3.14159265358979323846
using namespace std;

long double gcd(long double a,long double b){
    while(fabs(a)>1e-4&&fabs(b)>1e-4){
        long double temp=b;
        b=a-floor(a/b)*b;
        a=temp;
    }
    return a+b;
}

long double Area(long double x0,long double y0,long double x1,long double y1,long double x2,long double y2)
{
    return 0.5*fabs(x0*y1+x2*y0+x1*y2-x2*y1-x0*y2-x1*y0);
}

int main()
{
    long double x1,y1,x2,y2,x3,y3,x,y;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    long double anga,angb,angc;
    long double a,b,c;
    a=sqrt((x1-x2)*(x1-x2)+(y2-y1)*(y2-y1));
    b=sqrt((x3-x2)*(x3-x2)+(y2-y3)*(y2-y3));
    c=sqrt((x1-x3)*(x1-x3)+(y3-y1)*(y3-y1));
    anga=(b*b+c*c-a*a)/(2*b*c);
    angb=(a*a+c*c-b*b)/(2*a*c);
    angc=(a*a+b*b-c*c)/(2*a*b);
    anga=acos(anga);
    angb=acos(angb);
    angc=acos(angc);
    long double ang=gcd(anga,angb);
    ang=gcd(ang,angc);
    long double rad=(a*b*c)/Area(x1,y1,x2,y2,x3,y3)/4;
    int n=round(M_PI/ang);
    long double area=0.5*n*rad*rad*sin(2*M_PI/n);
    //cout<<a<<" "<<b<<" "<<c<<" "<<anga<<" "<<angb<<" "<<angc<<" "<<ang<<" "<<rad<<" "<<n<<endl;
    cout<<setprecision(20)<<area<<endl;
    return 0;
}