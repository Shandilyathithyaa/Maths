#include<iostream>
#include<math.h>
using namespace std;

float f(float x)
{
	//float fx = 0.65 - 0.75/(1+x*x) - 0.65*x*atan(1/x);
	//float fx = 3*x*x*x - 10*x*x - 56*x + 5;
	//float fx = x*x*x - 6*x*x + 4*x + 12;
	float fx = x/log(x);
	return fx;
}

float f1(float x)
{
	//float fx = ((2.15*x+0.65*x*x*x)/pow((1+x*x),2)) - (0.65*atan(1/x));
	//float fx = 9*x*x - 20*x - 56;
	float fx = (log(x)-1)/(2*log(x));
	return fx;
}

float f2(float x)
{
	//float fx = (2.8-3.2*x*x)/pow((1+x*x),3);
	//float fx = 18*x - 20;
	float fx = 1/(4*x*log(x));
	return fx;
}

void newton()
{
	int i=1;
	float epsilon = 0.0001,x1 = 3;
	do
	{
		cout<<"Iteration-"<<i<<endl;
		cout<<"x"<<i<<" = "<<x1<<"\t f(x"<<i<<") = "<<f(x1)<<endl;
		cout<<"f'(x"<<i<<") = "<<f1(x1)<<"\t f\"(x"<<i<<") = "<<f2(x1)<<endl;
		x1 = x1 - f1(x1)/f2(x1);
		i++;
		cout<<"x"<<i<<" = "<<x1<<endl;
		cout<<"Convergence Check:-\n"
			<<"|f'(x"<<i<<")| = |"<<fabs(f1(x1))<<"| > epsilon = "<<epsilon<<endl<<endl;
	}while(fabs(f1(x1))>epsilon&&i<6);
	cout<<"x* ~= x"<<i<<" = "<<x1;
}
int main()
{
	newton();
	//cout<<fabs(f1(0.1));

	return 0;
}
