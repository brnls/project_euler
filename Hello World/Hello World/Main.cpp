#include "BigInt.h"
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main () 
{
	string s = "123456789";
size_t k = 3;
do
{
   cout << string(s.begin(),s.begin() + k);
   cin >> k;
}
while(next_permutation(s.begin(),s.begin() + k));//s.end()));
	system("pause");
}
