#include <iostream>
#include "BigInt.h"

// --------------------------------------------------
//               BigInt functionality
// --------------------------------------------------


BigInt::BigInt(char* a)
{
	int strln = 0;
	for(int i = 0; a[i] != 0; i++)
		strln++;
	for(int i = 0; i < strln; i++)
		x.push_back(a[strln-i-1]-48);

}
BigInt::BigInt(int y)
{
	char temp[32] = {0};
	_itoa_s(y,temp,10);
	int strln = 0;
	for(int i = 0; temp[i] != 0; i++)
		strln++;
	for(int i = 0; i < strln; i++)
		x.push_back(temp[strln-i-1]-48);
	
}
int& BigInt::operator[](const int a){return x[a];}

// Operators
BigInt BigInt::operator*(const BigInt& a)
{
	BigInt b;
	b.x = multiply(x,a.x);
	return b;	 
}
BigInt BigInt::operator+(const BigInt& a)
{
	BigInt b;
	b.x = add(x,a.x);
	return b;	 
}
BigInt BigInt::operator-(const BigInt& a)
{
	BigInt b;
	b.x = subtract(x,a.x);
	return b;
}
BigInt BigInt::operator^(const int a)
{
	BigInt b;
	b.x = power(x,a);
	return b;
}
BigInt BigInt::operator/(const BigInt& a)
{
	BigInt b;
	b.x = divide(x,a.x);
	return b;
}
BigInt BigInt::operator%(const BigInt& a)
{
	BigInt b;
	b.x = mod(x,a.x);
	return b;
}
BigInt BigInt::BIDivideIfDivides(const BigInt& a)
{
	BigInt b;
	b.x = DivideIfDivides(x,a.x);
	return b;
}
bool BigInt::operator>(const BigInt& a)
{

	if(x.size() > a.x.size())
		return true;
	else if(x.size() < a.x.size())
		return false;
	else if(x.size() == a.x.size())
	{
		for(int i = x.size()-1; i > -1; i--)
		{
			if(x[i] > a.x[i])
				return true;
			else if(x[i] < a.x[i])
				return false;
		}
		return false;
	}
	else return false;

}
bool BigInt::operator<(const BigInt& a)
{

	if(x.size() < a.x.size())
		return true;
	else if(x.size() > a.x.size())
		return false;
	else if(x.size() == a.x.size())
	{
		for(int i = x.size()-1; i > -1; i--)
		{
			if(x[i] < a.x[i])
				return true;
			else if(x[i] > a.x[i])
				return false;
		}
		return false;
	}
	else return false;

}
bool BigInt::operator== (const BigInt& a)
{
	if(a.x == x)
		return true;
	else
		return false;
}
int BigInt::bToi()
{
	int y = 0;
	int ten = 1;
	for(unsigned int i = 0; i < x.size(); i++)
	{
		y = y + x[i]*ten; 
		ten = ten*10;
	}
	return y;
}
int BigInt::size()
{
	return x.size();
}
void BigInt::print()
{
	for(unsigned int i = 0; i < x.size(); i++)
		cout << x[x.size()-1-i];
	cout << endl;
}
void BigInt::printx(){
	for(unsigned int i = 0; i < x.size(); i++)
		cout << x[x.size()-1-i] << endl;
}


void BigInt::truncateRight()
{
	x.erase(x.begin());
}
void BigInt::truncateLeft()
{
	x.pop_back();
}
void BigInt::permuteBackward() // Cycles all digits one to left
{
	BigInt B;
	B.x = x;
	x[0] = x[x.size()-1];
	for(unsigned i = 0; i < x.size() -1; i++)
		x[i+1] = B.x[i];
}
void BigInt::swapDigits(int a, int b)
{
	int temp = 0;
	temp = x[a];
	x[a] = x[b];
	x[b] = temp;
}
void BigInt::nextPermutation() 
{//changes B to the next highest permutation of digits


	int i = 0;// Smallest digit right of pivot 
	int j = 1;// Pivot

	while(x[i] <= x[j])
		{	
			i++;
			j++;
			if(j == x.size())
				break;
		}

	i = 0; 
		
	if(j == x.size());
	
	else
	{
		while(x[j] >= x[i])
			i++;
		
		int temp = x[i];
		x[i] = x[j];
		x[j] = temp;

		
		BigInt C = 0;
		int p = j;

		while(C.size() < p)
			C.x.push_back(0);
	
		for(int a = 0 ; a < p; a++)
		{
			C.x[C.size() - a -1] = x[a];	
		}

					
		for(int a = 0 ; a < p; a++)	
		{
			x[a] = C[a];
		}
	
	}
	
}
void BigInt::insert(int a, int  b) // inserts integer a at the bth position
{
	x.insert(x.begin() + b, a);
}
void BigInt::push_back(int a)
{
	x.push_back(a);
}

bool BigInt::isPalindrome()
{
	for(unsigned int i = 0; i < x.size()/2; i++)
	{
		if(!(x[i] == x[x.size()-1-i]))
		{
			return false;
		}
	}
	return true;
}
bool BigInt::isPandigitalNine()
{
	if(x.size() != 9)
		return false;
	for(int i =0; i < 9; i++)
		if(x[i] == 0)
			return false;
	int arrCheck[9] = {0};
	for(int i = 0; i < 9; i++)
		arrCheck[x[i]-1] = 1;

	for(int i = 0; i < 9; i++)
	{
		if(arrCheck[i] == 0)
			return false;
	}

	return true;
}
bool BigInt::isPandigitalY(int Y)
{
	if(Y > 10)
		return false;
	if(x.size() != Y)
		return false;
	for(int i =0; i < Y; i++)
		if(x[i] == 0)
			return false;
	int arrCheck[9] = {0};
	for(int i = 0; i < Y; i++)
		arrCheck[x[i]-1] = 1;

	for(int i = 0; i < Y; i++)
	{
		if(arrCheck[i] == 0)
			return false;
	}

	return true;
}
bool BigInt::isPermutationOf(BigInt a)
{
	BigInt b;
	b.x = x;
	if(a.size() != b.size())
		return false;
	vector<int> aDigitProfile;
	vector<int> bDigitProfile;
	for(int i = 0; i < 10; i++)
	{
		aDigitProfile.push_back(0);
		for(int j = 0; j < a.size(); j++)
		{
			if(a[j] == i)
			{
				aDigitProfile[i]++;
			}
		}
		bDigitProfile.push_back(0);
		for(int j = 0; j < b.size(); j++)
		{
			if(b[j] == i)
				bDigitProfile[i]++;
		}
	}
	bool equal = false;
	for(int i = 0; i<10; i++)
	{
		if(aDigitProfile[i] != bDigitProfile[i])
			return false;
	}
	return true;
}
vector<BigInt> BigInt::sortBigInt(const vector<BigInt>& a)
{
	return a;
}

// --------------------------------------------------
//                Vector functionality
// --------------------------------------------------


bool greaterthan(const vector<int>& num1, const vector<int>& num2)
{

	if(num1.size() > num2.size())
		return true;
	else if(num1.size() < num2.size())
		return false;
	else if(num1.size() == num2.size())
	{
		for(int i = num1.size()-1; i > -1; i--)
		{
			if(num1[i] > num2[i])
				return true;
			else if(num1[i] < num2[i])
				return false;
		}
		return false;
	}
	else return false;

}
bool lessthan(const vector<int>& num1, const vector<int>& num2)
{

	if(num1.size() < num2.size())
		return true;
	else if(num2.size() < num1.size())
		return false;
	else if(num2.size() == num1.size())
	{
		for(int i = num1.size()-1; i > -1; i--)
		{
			if(num2[i] > num1[i])
				return true;
			else if(num2[i] < num1[i])
				return false;
		}
		return false;
	}
	else return false;

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
		
		int j = i+1;
		sum[i] = sum[i] + num1[i] + num2[i];
		if(sum[i] > 9)
		{
			if(i == sum.size()-1) // Make sum vector one larger if last term is greater than 9
				sum.push_back(0);
			sum[i] = sum[i]-10;
			sum[i+1]++;
			
		}
	}

	if(num1.size() > num2.size()) // Assign remainder of larger number to digits of sum
	{
		for(int i = minsize; i < maxsize; i++)
		{
			sum[i] = sum[i] + num1[i];
			if(sum[i] > 9)
			{
				if(i == sum.size()-1) // Make sum vector one larger if last term is greater than 9
					sum.push_back(0);
				sum[i] = sum[i]-10;
				sum[i+1]++;
			
			}
		}
	}	

	else
	{
		for(int i = minsize; i < maxsize; i++)
		{
			sum[i] = sum[i] + num2[i];
			if(sum[i] > 9)
			{
				if(i == sum.size()-1) // Make sum vector one larger if last term is greater than 9
					sum.push_back(0);
				sum[i] = sum[i]-10;
				sum[i+1]++;
			
			}
		}
			
	}
	
	


	return sum;
}
vector<int> subtract(const vector<int>& num1, const vector<int>& num2)
{
	
	vector<int> big(1, 0); // larger of two numbers passed in
	vector<int> small(1, 0); //smaller of two numbers passed in
	if(greaterthan(num1,num2))
	{
		big = num1;
		small = num2;
	}
	else if(lessthan(num1,num2))
	{
		big = num2;
		small = num1;
	}
	else 
		return vector<int>(1,0);

	while(big.size()>small.size())
		small.push_back(0);

	int carry = 0;

	for(unsigned int i = 0; i < small.size(); i++)
	{
		big[i] = big[i] - small[i];
		if(big[i] < 0)
		{
			big[i] = big[i] + 10;
			big[i+1] = big[i+1] - 1;
		}
	}
	
	while(big[big.size()-1] == 0)
		big.pop_back();

	return big;
}
vector<int> multiply(const vector<int>& num1, const vector<int>& num2)
{
	vector<int> a = num1;
	vector<int> b = num2;
	vector<int> product;
	
	if(num1.size() > num2.size())
	{
		a = num1;
		b = num2;
	}
	
	else
	{
	a = num2;
	b = num1;
	}

	int carry = 0;
	product.resize(a.size() + b.size(),0);

	for(unsigned int i = 0; i < a.size(); i++) // Digits of larger number a
	{
		for(unsigned int j = 0; j < b.size(); j++) // Smaller number b
		{
			product[i + j] = product[i + j] + a[i]*b[j];
			product[i + j] = product[i + j] + carry;
			
			carry = 0;

			while(product[i + j] > 9) // Reduce i+jth element to less than 10, counting how many times to add to next cell
			{
				product[i + j] = product[i + j] - 10;
				carry++;
			}

			if(j == b.size() - 1)
			{
				product[i + j + 1] = product[i + j + 1] + carry;
				carry = 0;
			}
			
		}
	}

	if(product.back() == 0)
		product.pop_back();
	return product;
}
vector<int> divide(const vector<int>& num1, const vector<int>& num2)
{
	// Divide a by b with a remainder r -- Long division by hand style
	vector<int> a = num1;
	vector<int> b = num2;
	vector<int> aTemp = a;
	vector<int> bTemp = b;
	vector<int> answ;
	int count = 0;
	int countTen = 0; 
	bool equal = true;
	while(!(lessthan(aTemp,b)))
	{
		equal = false;
		count = 0;
		while(bTemp.size() < aTemp.size()) // Multiply b by 10 until it is the same digit size as a
		{
			bTemp.insert(bTemp.begin(),0);
			countTen++;
		}

		if(lessthan(aTemp, bTemp)) // Divide b by 10 until it is smaller than a. 
		{
			bTemp.erase(bTemp.begin());
			countTen--;
		}
		while(!(lessthan(aTemp,bTemp))) // Subtract b from a until a>=b
		{
			aTemp = subtract(aTemp, bTemp);
			count++;
		}
		
		answ.insert(answ.begin(),count); // create answer vector
	}
	if(equal)
		return vector<int>(1,1);
	for(int i = 0; i < countTen; i++) // Add the appropriate amount of 0's to the end of the answer based on current countTen
		answ.insert(answ.begin(),0);
	while(answ.back() == 0)
		answ.pop_back();
	return answ;
}
vector<int> mod(const vector<int>& num1, const vector<int>& num2)
{
	// Divide a by b with a remainder r
	vector<int> a = num1;
	vector<int> b = num2;
	vector<int> aTemp = a;
	vector<int> bTemp = b;
	vector<int> answ;

	while(!(lessthan(aTemp,b)))
	{
		while(bTemp.size() < aTemp.size()) // Multiply b by 10 until it is the same digit size as a
		{
			bTemp.insert(bTemp.begin(),0);
		}

		if(lessthan(aTemp, bTemp)) // Divide b by 10 until it is smaller than a. 
		{
			bTemp.erase(bTemp.begin());
		}
		while(!(lessthan(aTemp,bTemp))) // Subtract b from a until a>=b
		{
			aTemp = subtract(aTemp, bTemp);
		}
	}

	return aTemp;
}
vector<int> DivideIfDivides(const vector<int>& num1, const vector<int>& num2)
{
	vector<int> a = num1;
	vector<int> b = num2;
	vector<int> aTemp = a;
	vector<int> bTemp = b;
	vector<int> answ;
	int count = 0;
	int countTen = 0; 
	bool equal = true; // Bool value to return 1 if the two inputs are equal

	if(lessthan(a,b))
		return vector<int>(1,0);

	while(!(lessthan(aTemp,b)))
	{
		equal = false;
		count = 0;
		while(bTemp.size() < aTemp.size()) // Multiply b by 10 until it is the same digit size as a
		{
			bTemp.insert(bTemp.begin(),0);
			countTen++;
		}

		if(lessthan(aTemp, bTemp)) // Divide b by 10 until it is smaller than a. 
		{
			bTemp.erase(bTemp.begin());
			countTen--;
		}
		while(!(lessthan(aTemp,bTemp))) // Subtract b from a until a>=b
		{
			aTemp = subtract(aTemp, bTemp);
			count++;
		}
		
		answ.insert(answ.begin(),count); // create answer vector
	}
	if(equal)
		return vector<int>(1,1);
	
	if(!(aTemp == vector<int>(1,0)))
		return vector<int>(1,0);
	else
	{
		for(int i = 0; i < countTen; i++) // Add the appropriate amount of 0's to the end of the answer based on current countTen
			answ.insert(answ.begin(),0);
		while(answ.back() == 0)
			answ.pop_back();
		return answ;
	}
}
vector<int> power(const vector<int>& x, int n) 
{
	vector<int> y = x;

	for(int i = 0; i < n-1; i++)
	{
		y = multiply(x,y);
	}
	
	return y;
}
void print(vector<int>& num1){
	for(unsigned int i = 0; i < num1.size(); i++)
		cout << num1[num1.size()-1-i];
}


// --------------------------------------------------
//                     Extras
// --------------------------------------------------


int* PrimeList(int howmany) // returns "howmany" consecutive primes starting with 2
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
int* PrimeCheck(int howhigh) // Generates pointer to array of size howhigh, with prime members of array equal to themselves, and all other members equal to 0
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
int* TriangleNumbers(int howMany) //Returns array of all 0s, except when a number is a triangle number then the corresponding array slot will be a 1
{
	int* triangleNumbers = new int[howMany*(howMany + 1)/2];

	for(unsigned i = 0; i < howMany*(howMany +1)/2; i++)
		triangleNumbers[i] = 0;

	for(unsigned i = 0; i < howMany; i++)
	{
		triangleNumbers[i*(i+1)/2] = 1;
	}

	return triangleNumbers;
}

int fact(int a) // Factorial of integer a
{
	if(a == 0)// Definition of 0! = 1
		return 1;
	else if(a < 0) // Not defined for negative integers
		return 0;
	else // if a is positive > 0, return a * (a - 1) * (a-2) ... * 2
	{
		int product = 1;
		while(a > 1)
		{
			product = product * a;
			a--;
		}
		return product;
	}
	
}

int nCr(int n, int r) // n choose r
{
	if(n <= 0) //Not defined for n < 0
		return 0;
	if(r > n || r < 0) //Not defined for 0 > r > n
		return 0;
	

	int numerator = 1;
	int denominator = 1;

	for(int i = 0; i < (n-r); i++)
	{
		numerator = numerator * (n-i);
	}

	for(int i = 0; i < (n-r); i++)
	{
		denominator = denominator * ((n-r)-i);
	}

	return numerator / denominator;

}

