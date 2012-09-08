#include <vector>
using namespace std;

class BigInt
{
vector<int> x;

public:
	
	BigInt(){};
	BigInt(char*);
	BigInt(int);
	int& operator[](const int);
	BigInt operator* (const BigInt&); // These operators are analogous to the corresponding "int" operators
	BigInt operator+ (const BigInt&);
	BigInt operator- (const BigInt&); 
	BigInt operator/ (const BigInt&);
	BigInt operator^ (int);
	BigInt operator% (const BigInt&);
	BigInt BigInt::BIDivideIfDivides(const BigInt& a);
	bool operator> (const BigInt& a);
	bool operator< (const BigInt& a);
	bool operator== (const BigInt&);
	int bToi(); // returns BigInt to data type int
	void print(); //prints 
	void printx(); //vector check
	int size(); //returns number of digits 

	//Modifiers of a BigIntB
	void truncateRight();
	void truncateLeft();
	void permuteBackward();
	void swapDigits(int a, int b);
	void nextPermutation();
	void insert(int a, int b);
	void push_back(int a);
	bool isPalindrome();
	bool isPandigitalNine();
	bool isPandigitalY(int Y);
	bool isPermutationOf(BigInt a);
	vector<BigInt> sortBigInt(const vector<BigInt>&);

};

// Vector functionality	
vector<int> power(const vector<int>& x, int n);
vector<int> multiply(const vector<int>&, const vector<int>&);
vector<int> add(const vector<int>&, const vector<int>&);
vector<int> subtract(const vector<int>& num1, const vector<int>& num2);
vector<int> divide(const vector<int>& num1, const vector<int>& num2);
vector<int> mod(const vector<int>& num1, const vector<int>& num2);
vector<int> DivideIfDivides(const vector<int>& num1, const vector<int>& num2); // if num1 divides num2, function returns the num1/num2, else returns 0
void print(vector<int>& num1);
bool greaterthan(const vector<int>& num1, const vector<int>& num2);
bool lessthan(const vector<int>& num1, const vector<int>& num2);


//Extras
int* PrimeList(int);
int* PrimeCheck(int);
int* TriangleNumbers(int);
int fact(int a);
int nCr(int n, int r);

