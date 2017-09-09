/*************************************************
Function: inverse
Description: Compute the inverse of matrix by Gauss.
Author:Ryan
Date:2017-08-28
*************************************************/
#include "BiharmonicSplineInterp.h"

bool inverse(vector<vector<double> > &A, vector<vector<double> > &B)
{
	if(A.size() != A[0].size())
	{
		printf("%s","The width and the height of A must be equal!");
		return false;
	}

	double max, temp;
	vector<vector<double> > t;
	t.resize(A.size());
	for(int i = 0; i < A.size(); i++)
		t[i].resize(A[0].size());

	// The matrix A is saved to temp matrix t, and initialize the matrix B.
	for(int i = 0; i < A.size(); i++)
	{
		for(int j = 0; j < A[0].size(); j++)
		{
			t[i][j] = A[i][j];
			B[i][j] = (i == j) ? 1.0 : 0.0;
		}
	}

	int k;
	for(int i = 0; i < A.size(); i++)
	{
		//Ѱ����Ԫ
		max = t[i][i];
		k = i;
		for(int j = i + 1; j < A.size(); j++)
		{
			if(fabs(t[j][i]) > fabs(max))
			{
				max = t[j][i];
				k = j;
			}
		}
		//�����Ԫ���ڵ��в��ǵ�i�У������н���
		if(k != i)
		{
			for(int j = 0; j < A.size(); j++)
			{
				temp = t[i][j];
				t[i][j] = t[k][j];
				t[k][j] = temp;
				//B���潻��
				temp = B[i][j];
				B[i][j] = B[k][j];
				B[k][j] = temp;
			}
		}
		//�ж���Ԫ�Ƿ�Ϊ0�����ǣ������A�������Ⱦ��󣬲����������
		if(t[i][i] == 0)
		{
			printf("%s","There is no inverse matrix!");
			return false;
		}
		//��ȥA�ĵ�i�г�ȥi������ĸ���Ԫ��
		temp = t[i][i];
		for(int j = 0; j < A.size(); j++)
		{
			t[i][j] = t[i][j] / temp; //���Խ����ϵ�Ԫ�ر�Ϊ1
			B[i][j] = B[i][j] / temp; //�������
		}
		for(int j = 0; j < A.size(); j++) //��0��->��n��
		{
			if(j != i)                    //���ǵ�i��
			{
				temp = t[j][i];
				for(k = 0; k < A.size(); k++)  //��j��Ԫ�� - i��Ԫ�� * j��i��Ԫ��
				{
					t[j][k] = t[j][k] - t[i][k] * temp;
					B[j][k] = B[j][k] - B[i][k] * temp;
				}
			}
		}
	}
	return true;
}
/*************************************************/
