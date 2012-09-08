#include "GeometricNumbers.h"

	void pentagonalTool::LoadPentagonalList(const int& a)
	{
		for(double i = list.size(); i < a; i++)
		{
			list.push_back((3*i*i-i)/2);
		}
	}

	int nthPentagonal(const int& a)
	{
		return (int)(sqrt((double)(24*a + 1)) +1) / 6;
	}
	vector<double>& pentagonalTool::pentagonalArray(const int& a)// Returns pointer to array of "a" consecutive pentagonals
	{
		if(list.size() >= a)
			return list;
		else
		{
			LoadPentagonalList(a);
			return list;
		}
	}

	bool isPentagonal(double a)
	{
		double calc = sqrt(1 + (double)(24*a));
		return fmod(calc, 6) == 5;
	}

	bool isHexagonal(double a)
	{
		double calc = sqrt((double)(8*a) +1);
		return fmod(calc,4) == 3;
	}