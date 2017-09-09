/*************************************************
Copyright: 2017, Tianyu Soft.
File name: BiharmonicSplineInterpolation.cpp
Description: GRIDATA Interpolates scattered data.
Author: Ryan
Date: 2017-08-28
**************************************************/
#include "BiharmonicSplineInterp.h"

vector<vector<double>> BiharmonicSplineInterp(vector<double> &x, vector<double> &y, vector<double> &v, vector<vector<double>> &xq, vector<vector<double>> &yq, int w, int h)
{
    vector<double> xtemp;
	xtemp.resize(w);
	xtemp = linspace(*(min_element(begin(x), end(x))), *(max_element(begin(x), end(x))), w);

	vector<double> ytemp;
	ytemp.resize(h);
	ytemp = linspace(*(min_element(begin(y), end(y))), *(max_element(begin(y), end(y))), h);

	//vector<vector<double>> Xq;
	//vector<vector<double>> Yq;
	meshgrid(xtemp, ytemp, xq, yq);

	vector<vector<double>> vq;
	gdatav4(x, y, v, xq, yq, vq);

    return vq;
}
