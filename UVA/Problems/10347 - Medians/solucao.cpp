#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push
#define N 2001000
using namespace std;

double m1,m2,m3;
double semiperimetro()
{
	return (m1+m2+m3)/2;
}

double Area()
{
	double p=semiperimetro();
	return (4*sqrt(p*(p-m1)*(p-m2)*(p-m3)))/3 ;
}

bool possible(double a,double b,double c)
{
	if(a>=b+c || fabs(b-c)>=a)
		return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	while(cin>>m1>>m2>>m3)
	{
		cout<<fixed<<setprecision(3);
		if(!possible(m1,m2,m3) || !possible(m2,m1,m3) || !possible(m3,m2,m1))
			cout<<"-1.000\n";
		else
			cout<<Area()<<'\n';
	}	
}