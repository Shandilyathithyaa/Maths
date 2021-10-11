#include<iostream>
#include<math.h>
using namespace std;

float f(float x)
{
	float fx = 0.65 - 0.75/(1+x*x) - 0.65*x*atan(1/x);
	//float fx = x/log(x);
	return fx;
}

double f1(float x)
{
	float fx = (2.15*x+0.65*x*x*x)/pow((1+x*x),2) - 0.65*atan(1/x);
	//float fx = (log(x)-1)/(2*log(x));
	return fx;
}

float f2(float x)
{
	float fx = (2.8-3.2*x*x)/pow((1+x*x),3);
	return fx;
}

void setab()
{
	int i=1;
	float A=0,B=0,t0=0.1;
	while(f1(A)<0)
	{
		B = pow(2,i-1)*t0;
		cout<<char(64+i)<<" = A + "<<pow(2,i-1)<<"t0 = "<<A<<"\t f'("<<char(64+i)<<") = "<<f1(A)<<" < 0"<<endl;
		cout<<char(65+i)<<" = "<<B<<"\t\t\t f'("<<char(65+i)<<") = "<<f1(B)<<endl;
		i++;
		A = B;
	}
}

void secant()
{
	int i=1;
	double epsilon = 0.01,x1 = 0.1;
	double A=0,B=0,t0=0.1;
	while(f1(B)<0)
	{
		B = pow(2,i-1)*t0;
		cout<<char(64+i)<<" = A + "<<pow(2,i-1)<<"t0 = "<<A<<"\t f'("<<char(64+i)<<") = "<<f1(A)<<" < 0"<<endl;
		cout<<char(65+i)<<" = "<<B<<"\t\t\t f'("<<char(65+i)<<") = "<<f1(B)<<" < 0"<<endl<<endl;
		i++;
		if(f1(B)<0)
		A = B;
	}
	
	i=1;
	
	do
	{
		float x;
		cout<<"Iteration-"<<i<<endl;
		cout<<"A = "<<A<<"\t f'(A) = "<<f1(A)<<" < 0"<<endl;
		cout<<"B = "<<B<<"\t f'(B) = "<<f1(B)<<" > 0"<<endl;
		//x = x1;
		x1 = A - (f1(A)*(B-A))/(f1(B)-f1(A));
		cout<<"x"<<i+1<<" = A - f'(A)(B-A)/f'(B)-f'(A) = "<<x1<<endl;
		
		i++;
		cout<<"Convergence Check:-\n"
			<<"|f'(x"<<i<<")| = |"<<fabs(f1(x1))<<"| > epsilon = "<<epsilon<<endl<<endl;
		B=x1;
	}while(fabs(f1(x1))>epsilon);
	cout<<"x* ~= x"<<i<<" = "<<x1;
}
int main()
{
	secant();
	return 0;
}
