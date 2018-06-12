#include <iostream>

using namespace std;



void line_gaozi()
{
	/*double A[3][4] = 
	{
		{2,-1,3,1},
		{4, 2,5,4},
		{1, 2,0,7}
	};
	double x[3];
	double N = 3;*/
	double A[2][3] = 
	{
	{0.00001,1,1},
	{1,1,2}
	};
	double x[2];
	double N = 2;
    double temp;
    double SUM=0;
    for(int i=0;i<N-1;i++)    //完全主元素
    {
        for(int j=i+1;j<N;j++)
        {
            if(A[i][i]>=A[j][i])
				continue;
            else
            {
                for(int k=i;k<N+1;k++)
				{
					temp = A[i][k];
					A[i][k] = A[j][k];
					A[j][k] = temp;
				}
            }
        }
        if(A[i][i]==0)
            printf("no unique solution!\n");
        for(int m=i+1;m<N;m++)
        {
            for(int n=i+1;n<N+1;n++)
				A[m][n]=A[m][n]-((A[m][i]*A[i][n])/A[i][i]);
			
        }
    }
    for(i=N-1;i>=0;i--)  //回代
    {
        x[i]=(A[i][2]-SUM)/A[i][i];
        SUM = 0;
        int k = i-1;
        for(int j=i-1;j<N-1;j++)
        {
			SUM = SUM+x[++k]*A[i-1][k];
        }
    }
	cout<<"所求解分别为"<<endl;
    for(int num = 0;num<N;num++)
	{
		printf("%.3lf",x[num]);
		cout<<endl;
	}
    
}

void yanzheng()
{
	double A[2][3] = 
	{
		{0.00001,1,1},
		{1,1,2}
	};
	double x[2];
	double N = 2;
    double SUM=0;
    for(int i=0;i<N-1;i++)    //完全主元素
    {
        for(int m=i+1;m<N;m++)
        {
            for(int n=i+1;n<N+1;n++)
				A[m][n]=A[m][n]-((A[m][i]*A[i][n])/A[i][i]);
			
        }
    }
    for(i=N-1;i>=0;i--)  //回代
    {
        x[i]=(A[i][2]-SUM)/A[i][i];
        SUM = 0;
        int k = i-1;
        for(int j=i-1;j<N-1;j++)
        {
			SUM = SUM+x[++k]*A[i-1][k];
        }
    }
	cout<<"不进行行变换所求解分别为"<<endl;
    for(int num = 0;num<N;num++)
	{
		cout<<int(x[num]);
		cout<<endl;
	}
}
int main()
{
	yanzheng();
	line_gaozi();
	
	return 0;
}