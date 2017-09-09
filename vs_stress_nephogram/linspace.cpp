/*************************************************
Function: linspace
Description: Generate linearly spaced vector.
Author:Ryan
Date:2017-08-29
*************************************************/
#include "BiharmonicSplineInterp.h"

vector<double> linspace(double min, double max, int num)
{
	double dis = (max - min) * 1.0 / (num - 1);
	vector<double> res;
	res.resize(num);
	double value = min;
	for(int i = 0; i < num; i++)
	{
		res[i] = value;
		value += dis;
	}
	return res;
}
/*************************************************/

