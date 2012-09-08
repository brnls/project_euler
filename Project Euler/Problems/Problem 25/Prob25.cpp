
#include <iostream>
#include <vector>
#include "brian.h"
using namespace std;

void printb(const vector<int>& a)
{
	for(int i = 0; i < (int)a.size(); i++)
	{
		cout << a[a.size() - 1 - i];
	}
	cout << endl;
}

vector<int> add(const vector<int>& num1, const vector<int>& num2)
{
	int maxsize = 0;
	int minsize = 0;

	if(num1.size() > num2.size()) // Determine larger/smaller of two numbers
	{
		maxsize = num1.size();
		minsize = num2.size();
	}
	else if(num1.size() < num2.size())
	{
		maxsize = num2.size();
		minsize = num1.size();	
	}
	else
	{
		maxsize = num1.size();
		minsize = num1.size();
	}

	vector<int> sum(maxsize, 0); // Create answer vector with size of larger of {num1,num2}
	
	
	for(int i = 0; i < minsize ; i++)  // Perform addition digit by digit up to size of smaller number
	{
		sum[i] = sum[i] + num1[i] + num2[i];
		if(sum[i] > 9)
		{
			if(i == sum.size()-1)
				sum.push_back(0);
			sum[i] = sum[i]-10;
			sum[i+1]++;
		}
	}

	if(num1.size() > num2.size()) // Assign remainder of larger number to digits of sum
	{
		for(int i = minsize; i < maxsize; i++)
			sum[i] = sum[i] + num1[i];
			
	}	

	else
	{
		for(int i = minsize; i < maxsize; i++)
			sum[i] = sum[i] + num2[i];
			
	}
	


	return sum;
}



int main()
{
	
	vector<int> num1(1,1);
	vector<int> num2(1,1);
	vector<int> h;
	int count = 2;

	while(num2.size() < 1000)
	{
	
	num2 = add(num1,num2);
	num1 = subtract(num2,num1);
	count++;
	
	}
			
	cout << count;
	

	system("pause");

}