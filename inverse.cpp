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
		//寻找主元
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
		//如果主元所在的行不是第i行，进行行交换
		if(k != i)
		{
			for(int j = 0; j < A.size(); j++)
			{
				temp = t[i][j];
				t[i][j] = t[k][j];
				t[k][j] = temp;
				//B伴随交换
				temp = B[i][j];
				B[i][j] = B[k][j];
				B[k][j] = temp;
			}
		}
		//判断主元是否为0，若是，则矩阵A不是满秩矩阵，不存在逆矩阵
		if(t[i][i] == 0)
		{
			printf("%s","There is no inverse matrix!");
			return false;
		}
		//消去A的第i列除去i行以外的各行元素
		temp = t[i][i];
		for(int j = 0; j < A.size(); j++)
		{
			t[i][j] = t[i][j] / temp; //主对角线上的元素变为1
			B[i][j] = B[i][j] / temp; //伴随计算
		}
		for(int j = 0; j < A.size(); j++) //第0行->第n行
		{
			if(j != i)                    //不是第i行
			{
				temp = t[j][i];
				for(k = 0; k < A.size(); k++)  //第j行元素 - i行元素 * j列i行元素
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
