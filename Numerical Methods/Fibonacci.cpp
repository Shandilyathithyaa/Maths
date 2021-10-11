#include<iostream>
#include<math.h>
using namespace std;
#define PI 3.1415
int F[10]={1,1,2,3,5,8,13,21,34,55};
float rnd(float x)
{
	x = round(x*10000);
	x = x/10000;
	return x;
}
float f(float x)
{
//	a = a*PI/180;
//	return 4*sin(a)*(1+cos(a));
	return x*x + 2*x;
}

int main()
{
	int i=2,n=6,i1=1,i2=2;
	float a=-3,b=4;
	float L0=b-a,L=L0,Lstar,x1,x2;
	for(int i=2;i<=6;i++)
	{
		
		Lstar=rnd(((float)F[n-i]/F[n-(i-2)])*L);
		x1 = rnd(a+Lstar);
		x2 = rnd(b-Lstar);
		
		cout<<"L2* = "<<Lstar<<"interval: ["<<a<<","<<b<<"]"<<endl;
		cout<<"x"<<i1<<" = a + L2* = "<<x1<<", f(x"<<i1<<") = "<<f(x1)<<endl;
		cout<<"x"<<i2<<" = b - L2* = "<<x2<<", f(x"<<i2<<") = "<<f(x2)<<endl;
		cout<<"new interval: ["<<a<<","<<b<<"]"<<endl<<endl;
		
		if(f(x1)>f(x2))
		{
			a = x1;
			//i1++;	
		}
		else
		{
			b = x2;
			//i2++;
		}
		L = b-a;

	}
	cout<<"x* = "<<x2;
//	while(1)
//	{
//		cin>>a;
//		//cout<<sin(a)<<endl;
//		cout<<i<<' '<<90*pow(0.618,i)<<' '<<f(a)<<endl<<endl;
//	}
	return 0;
}
