/*************************************************
Function: meshgrid
Description: Create 2-D grid coordinates with
X-coordinates defined by the vector A and
Y-coordinates defined by the vector B.
Author:Ryan
Date:2017-08-29
*************************************************/
#include "BiharmonicSplineInterp.h"

void meshgrid(vector<double> &A, vector<double> &B, vector<vector<double>> &X, vector<vector<double>> &Y)
{
	int WIDTH = A.size();
	int HEIGHT = B.size();

	// Initialize vector X and Y.
	X.resize(HEIGHT);
	for(int i = 0; i < HEIGHT; i++)
	{
		X[i].resize(WIDTH);
	}

	Y.resize(HEIGHT);
	for(int i = 0; i < HEIGHT; i++)
	{
		Y[i].resize(WIDTH);
	}

	for(int i = 0; i < HEIGHT; i++)
	{
		for(int j = 0; j < WIDTH; j++)
		{
			X[i][j] = A[j];
			Y[i][j] = B[i];
		}
	}
}
/*************************************************/
