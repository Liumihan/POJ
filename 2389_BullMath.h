#ifndef BULLMATH_H
#include "string"
#include "iostream"
using namespace std;

int BullMath()
{
	freopen("input.txt","r",stdin);
	char A[41];//���ǵ�ĩβ����'\n'
	char B[41];//ĩβ���С�\n��
	//string B;
	int result[80];//result����ʮλ
	for(int i = 0;i < 80 ;i++)//��ʼ��
	{
		result[i] = 0;
	}

	cin >> A >> B;
	int len_A,len_B;
	len_A = strlen(A);
	//len_B = B.length();
	len_B = strlen(B);
	int n = len_A+len_B;//n��Ϊ�ôγ˷����ý����������λ��
	for (int i = 0;i < len_A;i++)//��Ӧλ�õ��ȳ����������
	{
		for (int j = 0;j<len_B;j++)
		{
			result[i+j+1] += (A[i]-'0')*(B[j]-'0');//����Ӧλ�õ���һλ��Ϊ��ǰ����͵�ֵ
		}
	}
	//�����Ƿ��λ
	for (int i = n-1;i >0;i--)//ע��ѭ��ֻ��˳���ڶ�λ����Ϊ���������һλ
	{
		if (result[i]>9)//�����Ҫ��λ
		{
			result[i-1] += result[i]/10;//��λ
			result[i] = result[i]%10;//��������λ
		}
	}

	cout << A << " " << B << endl;

	int k = 0;
	if (result[0] == 0)//�����λΪ0 ��ӵڶ�λ����
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
