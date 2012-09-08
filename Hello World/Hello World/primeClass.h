#include<iostream>
using namespace std;



class primeTool
{
	int* list; // Array of consecutive primes
	int listSize;
	int* check; // Array of all numbers with primes equal to themselves and everything else equal to 0
	int checkSize;
	
	void LoadPrimeCheck(const int& a);
	void LoadPrimeList(const int& a);

public:

	primeTool(){listSize = 0; checkSize = 0;};
	bool isPrime(const int& a);// Returns true if "a" is prime
	int* primeArray(const int& a);// Returns pointer to array of "a" consecutive primes
	int uniquePrimeFactors(int a);
};

int* PrimeLister(int);
int* PrimeChecker(int);