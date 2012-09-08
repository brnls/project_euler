#include <math.h>
#include <vector>
using namespace std;

class pentagonalTool
{
	vector<double> list; // Array of consecutive pentagonals
	void LoadPentagonalList(const int& a);

public:

	pentagonalTool(){};
	int nthPentagonal(const int& a); // Returns "a(th)" pentagonal number
	vector<double>& pentagonalArray(const int& a);// Returns pointer to array of "a" consecutive pentagonals
	
};

bool isPentagonal(double a);

bool isHexagonal(double a);