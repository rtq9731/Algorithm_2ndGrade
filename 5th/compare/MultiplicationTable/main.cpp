//20402 ±Ç¼ººó
#include <iostream>

using namespace std;

void multiplication(int firstNum)
{	
	if (firstNum == 10)
		return;

	for (int i = 0; i < 10; i++)
	{
		cout << firstNum << " * " << i << " = " << firstNum * i << endl;
	}

	return multiplication(firstNum+1);
}

int main() 
{
	multiplication(1);
	return (0);
}