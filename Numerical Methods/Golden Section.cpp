#include<iostream>
#include<math.h>
using namespace std;
#define PI 3.1415

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
//	return x*x + 2*x;
//	if(x>=0 && x<=2)	return 4*x;
//	else	return 4-x;
	float z = -1*(x*x);
	float fx = 1 - (x*(pow(2.7183,z)));
	return fx;
}

int main()
{
	int i=2,n=4,i1=1,i2=2;
	float a=0,b=1;
	float L0=b-a,L=L0,Lstar,x1,x2,epsilon=0.1;
	cout<<f(0.736)<<endl;
	//for(int i=2;i<=6;i++)
	do
	{
		cout<<L<<endl;
		Lstar=pow(0.618,i)*L0;
		x1 = rnd(a+Lstar);
		x2 = rnd(b-Lstar);
		
		cout<<"L2* = "<<Lstar<<endl<<"interval: ["<<a<<","<<b<<"]"<<endl;
		cout<<"x"<<i1<<" = a + L2* = "<<x1<<", f(x"<<i1<<") = "<<f(x1)<<endl;
		cout<<"x"<<i2<<" = b - L2* = "<<x2<<", f(x"<<i2<<") = "<<f(x2)<<endl;
		
		
		if(f(x1)<f(x2))
		{
			b = x2;
			//i1++;	
		}
		else
		{
			a = x1;
			//i2++;
		}
		cout<<"new interval: ["<<a<<","<<b<<"]"<<endl<<endl;
		L = b-a;
		i++;

	}while(fabs(L)>epsilon);
	cout<<"x* = ("<<a<<" + "<<b<<")/2 = "<<rnd((a+b)/2)<<endl;
	cout<<"f(x*) = "<<f((a+b)/2);
}
