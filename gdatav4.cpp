/*************************************************
Function: gdatav4
Description: Interpolation using value or
gradient of value in any dimension.
Reference: David T. Sandwell, Biharmonic spline
interpolation of GEOS-3 and SEASAT altimeter
data, Geophtsical Research Letters, 2, 139-142,
1987.
Author:Ryan
Date:2017-08-28
*************************************************/
#include "BiharmonicSplineInterp.h"

bool gdatav4(vector<double> &x, vector<double> &y, vector<double> &v, vector<vector<double> > &xq, vector<vector<double> > &yq, vector<vector<double> > &vq)
{
	// Check to make sure sizes of input arguments are correct/consistent.
	if(v.size() != x.size() || v.size() != y.size())
	{
		printf("%s", "Length of x, y, and v must be equal!");
        return false;
	}
	if(xq.size() != yq.size() || xq[0].size() != yq[0].size())
	{
		printf("%s", "Size of xq and yq must be equal!");
        return false;
	}

	// Initialize Output.
	// vector<vector<double>> vq;
	vq.resize(xq.size());
	for(int i = 0; i < xq.size(); i++)
		vq[i].resize(xq[0].size());


	for(int i = 0; i < xq.size(); i++)
		for(int j = 0; j < xq[0].size(); j++)
			vq[i][j] = 0.0;

	vector<vector<double> > G;
	G.resize(v.size());
	for(int i = 0; i < v.size(); i++)
		G[i].resize(v.size());

	for(int i = 0; i < v.size(); i++)
		for(int j = 0; j < v.size(); j++)
			G[i][j] = 0.0;

	double d = 0.0;
	for(int i = 0; i < v.size(); i++)
	{
		for(int j = 0; j < v.size(); j++)
		{
			d = 0.0;
			if(i != j)
				d = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
			if(d >= 1.0e-7)
				G[i][j] = (d * d) * (log(d) - 1.0);//Green's function.
		}
	}

	// Compute weights, especially G * weights = v.
	vector<double> weights;
	weights.resize(v.size());

	//weights = G \ v;
	vector<vector<double> > inverseG;
	inverseG.resize(G.size());
	for(int i = 0; i < G.size(); i++)
		inverseG[i].resize(G[0].size());

	inverse(G, inverseG);
	for(int i = 0; i < inverseG.size(); i++)
	{
		for(int j =0; j < v.size(); j++)
			weights[i] += inverseG[i][j] * v[j];
	}

	// Find 2D interpolated surface through irregular/regular x, y grid points
	vector<double> g;
	g.resize(weights.size());

	for(int i = 0; i < weights.size(); i++)
		g[i] = 0;

	for(int i = 0; i < vq.size(); i++)
	{
		for(int j = 0; j < vq[0].size(); j++)
		{
			double sum = 0.0;
			for(int k = 0; k < v.size(); k++)
			{
				d = 0.0;
				d = sqrt((xq[i][j] - x[k]) * (xq[i][j] - x[k]) + (yq[i][j] - y[k]) * (yq[i][j] - y[k]));
				if(d >= 1.0e-7)
					g[k] = (d * d) * (log(d) - 1.0);//Green's function
				else
					g[k] = (d * d) * (-100.0); // g[k] = 0;

				sum += g[k] * weights[k];
			}
			vq[i][j] = sum;
		}
	}
	G.clear();
	g.clear();
	weights.clear();
	return true;
}
/*************************************************/
