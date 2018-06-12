#include <iostream>
#include "cmath"
#include <iomanip>
using namespace std;

double max;//上界
double min;//下界
double precis;//精度
double x0;//牛顿初始值

double f(double x)
{
	return x*x*x-x-1;
	//return 1/x-3;
}

double p(double x)
{
	return 3*x*x-1;
	//return log(x);
}

void Binary(double min,double max,double precis)
{

	double mid = 0;
	int i = 0;
	cout<<"二分法迭代如下："<<endl;
	cout<<" 次数     值"<<endl;

	for(i=1;precis<fabs((max-min));i++)
	{
		mid = (min + max)/2.0;
		if(f(min)*f(mid)<0)
			max = mid;
		else if(f(mid) == 0.00)
			break;
		else 
			min = mid;
		cout<<setw(2)<<i<<""<<setw(10)<<mid<<endl;

	}
	cout<<"总共进行了"<<i<<"次迭代。"<<endl;
}



void Newton(double x0,double precis)
{
	int flag;
	double x1 = 0;
	int k = 1;
	cout<<"牛顿法迭代如下："<<endl;
	cout<<" 次数     值"<<endl;
	while(1)
	{

		if(p(x0) == 0)
		{
			flag = 1;
			break;
		}
		x1 = x0 - f(x0)/p(x0);
		if(fabs(x1-x0)<precis)
			break;
		else
		{
			cout<<setw(2)<<k<<""<<setw(10)<<x0<<endl;
		}
		k++;
		x0 = x1;
		if(k>1000)	break;
		
	}
	if(k<1000)
		cout<<"总共进行了"<<k-1<<"次迭代。"<<endl;
	else	
		cout<<"牛顿序列发散！"<<endl;
}

int main()
{
	cout<<"请输入函数的区间下限";
	cin>>min;
	cout<<endl;
	cout<<"请输入函数的区间上限";
	cin>>max;
	cout<<endl;
	cout<<"请设置精度";
	cin>>precis;
	cout<<endl;
	Binary(min,max,precis);
	cout<<endl;
	cout<<"请输入牛顿的初始值：";
	cin>>x0;
	Newton(x0,precis);
	return 0;
}
