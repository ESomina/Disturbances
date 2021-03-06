// Disturbances.cpp : This file contains the 'main' function. Program execution begins and ends there.
// ПИВ
#include "pch.h"
#include <iostream>
#include <fstream>

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>

#include <vector>
#include "math.h"

#include "Disturbances.h"

using namespace std;

void Gaussian::init(int n)
{
	cout << "Constructor" << endl;
	for (int i = 0; i < n; i++)
	{
		R.push_back(100);
		L.push_back(100.);
	}
	/*R.push_back(500.);
	R.push_back(300.);
	L.push_back(100.);
	L.push_back(100.); */
}
	double Gaussian::getValue(vector<double> r, double Ne = 1)
	{
		double Ntid = 0;
		for (unsigned int i = 0; i < r.size(); i++)
		{
			Ntid += (0.5*pow((r[i]-R[i])/(L[i]),2));
		}
		Ntid = Ne*(ampl*exp(-Ntid) + 1);

		return (Ntid);
	}

	void Gaussian::showParameters()
	{
		cout << "Amplitude = " << ampl << "\n";
		cout << "R: ";
		for (unsigned int i = 0; i < R.size(); i++)
		{
			cout << R[i] << " ";
		}
		cout << endl;
		cout << "L: ";
		for (unsigned int i = 0; i < L.size(); i++)
		{
			cout << L[i] << " ";
		}
		cout << endl;
		//cout << "Ntid = " << Ntid;
	}