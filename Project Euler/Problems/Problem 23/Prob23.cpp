
#include<iostream>
#include<math.h>
using namespace std;


int main()
{
	int t = 28124;
	int answ = 0;
	int abnt[28124]= {0};
	int abuntcomb[28124] = {0};

	for(int i = 0; i < t; i++)
	{
		int abntsum = 0;
		for(int j = 1; j < (i/2 + 1); j++)
		{
			if(i % j == 0)
			abntsum = abntsum + j;
		}
		if(abntsum > i)
			abnt[i] = i;
	}

	for(int i = 0; i < t; i++)
	{
		if(abnt[i] != 0)
		{
			for(int j = i; j < t; j++)
			{
				if(abnt[j] != 0)
				{
					if(i+j < t)
						abuntcomb[i+j] = i+j;
				}

			}
		}
	}


	


	for(int i = 0; i < t; i++)
		if(abuntcomb[i] == 0)
			answ = answ + i;
	cout << answ;
	cin >> answ;
	
}