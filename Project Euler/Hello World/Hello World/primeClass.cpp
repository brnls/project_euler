#include <math.h>
#include "primeClass.h"
	
	
	
	void primeTool::LoadPrimeList(const int& a)
	{
		list = PrimeLister(a);
		listSize = a;
	}
	int* PrimeLister(int howmany) // returns "howmany" consecutive primes starting with 2
{
	int bufsize = 1;
	if(howmany < 9592) // These "if" statements attempt to create the smallest buffer given how many primes the user requests
		bufsize = 100000;
	else if(howmany < 78498)
		bufsize = 1000000;
	else if(howmany < 664579)
		bufsize = 10000000;
	else if(howmany < 1000002)
		bufsize = 15485900;
	else if(howmany < 5761455)
		bufsize = 100000000;

	int* buf = new int[bufsize];

	for(int i = 0; i < bufsize; i++) // Create buffer buf with all numbers
			buf[i] = i;

	buf[1] = 0;
	int j = 2;
	int count = 0;
	while(count < howmany) // Cancel out multiples in buf to leave primes
	{
		if(buf[j] == 0)// If Number has already been cancelled out, move to check next one
			j++;

		else
		{
			for(int i = 2; i < bufsize/j + 1; i++) // If number has not been cancelled, it is prime. 
				buf[j*i] = 0;
			j++;
			count++;
		}
	}

	int* primes = new int[count];
	int primecount = 0;
	
	for(int i = 0; primecount < count; i++)
		if(buf[i] != 0)
		{
			primes[primecount] = buf[i];
			primecount++;
		}
		
	return primes;
}
	int* primeTool::primeArray(const int& a)
	{
		if(a <= listSize)
		{
			return list;
		}
		else
		{
			LoadPrimeList(a);
			listSize = a;
			return list;
		}
	} // Returns array of "a" consecutive primes

	bool primeTool::isPrime(const int& a)
	{
		if(checkSize >= a)
		{
			if(check[a] != 0)
				return true;
			else
				return false;
		}
		else
		{
			check = PrimeChecker(a);
			checkSize = a;
			if(check[a] != 0)
				return true;
			else
				return false;
		}
	}
	int* PrimeChecker(int howhigh) // Generates pointer to array of size howhigh, with prime members of array equal to themselves, and all other members equal to 0
{
	
	int* buf = new int[howhigh];

	for(int i = 0; i < howhigh; i++) // Create buffer buf with all numbers
			buf[i] = i;

	buf[1] = 0;
	int j = 2;
	int count = 0;
	while(j < howhigh) // Cancel out multiples in buf to leave primes
	{
		if(buf[j] == 0)
			j++;

		else
		{
			for(int i = 2; i < howhigh/j + 1; i++)
				buf[j*i] = 0;
			j++;
		}
	}

	buf[1] = 0; // 1 is not a prime!

	return buf;

}

	int primeTool::uniquePrimeFactors(int a)
	{
		if(listSize == 0)
		{
			list = PrimeLister(50000);
			listSize = 50000;
		}

		int count = 0;
		int temp = 0; // used to store prime that divides "a" to determine if count should be incremented.
		for(int i = 0; i < a; i++)
		{
			
			if(a % list[i] == 0)
			{
				a = a / list[i];
				i--;
				if(temp != list[i])
					count++;
				temp = list[i];
			}
		}
		return count;
	}
	