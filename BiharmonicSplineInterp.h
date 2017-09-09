/*****************************************************************************
Copyright: 2017, TY Soft.
File name: BiharmonicSplineInterp.h
Description: Biharmonic Spline Interpolates scattered data.
Author: Ryan
Date: 2017-08-28
*****************************************************************************/
#ifndef _BIHARMONICSPLINEINTERP_H_
#define _BIHARMONICSPLINEINTERP_H_

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

bool gdatav4(vector<double> &x, vector<double> &y, vector<double> &v, vector<vector<double> > &xq, vector<vector<double> > &yq, vector<vector<double> > &vq);

bool inverse(vector<vector<double> > &A, vector<vector<double> > &B);

vector<double> linspace(double min, double max, int num);

void meshgrid(vector<double> &A, vector<double> &B, vector<vector<double> > &X, vector<vector<double> > &Y);

vector<vector<double> > BiharmonicSplineInterp(vector<double> &x, vector<double> &y, vector<double> &v, vector<vector<double> > &xq, vector<vector<double> > &vq, int w, int h);

#endif
