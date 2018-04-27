#ifndef BULLMATH_H
#include "string"
#include "iostream"
using namespace std;

int BullMath()
{
	freopen("input.txt","r",stdin);
	char A[41];//考虑到末尾会有'\n'
	char B[41];//末尾会有‘\n’
	//string B;
	int result[80];//result最多八十位
	for(int i = 0;i < 80 ;i++)//初始化
	{
		result[i] = 0;
	}

	cin >> A >> B;
	int len_A,len_B;
	len_A = strlen(A);
	//len_B = B.length();
	len_B = strlen(B);
	int n = len_A+len_B;//n作为该次乘法所得结果的最大可能位数
	for (int i = 0;i < len_A;i++)//相应位置的先乘起来再求和
	{
		for (int j = 0;j<len_B;j++)
		{
			result[i+j+1] += (A[i]-'0')*(B[j]-'0');//让相应位置的下一位成为当前的求和的值
		}
	}
	//考虑是否进位
	for (int i = n-1;i >0;i--)//注意循环只到顺数第二位，因为上面后退了一位
	{
		if (result[i]>9)//如果需要进位
		{
			result[i-1] += result[i]/10;//进位
			result[i] = result[i]%10;//保留个数位
		}
	}

	cout << A << " " << B << endl;

	int k = 0;
	if (result[0] == 0)//如果首位为0 则从第二位输入
	{
		k = 1;
	}
	for (k; k< n;k++)
	{
		cout << result[k];
	}
	cout<< endl;
	
	cout << len_A<< len_B << endl;
	cout << n << endl;

	
	return 0;
}


#define BULLMATH_H
#endif
