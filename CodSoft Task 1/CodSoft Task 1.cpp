#include<iostream>
using namespace std;
int main()
{
	double num1;
	double num2;
	char operation;
	double result;
	cout << "Enter the first number: ";
	cin >> num1;
	cout << "Enter the second number: ";
	cin >> num2;
	cout << "Enter the operation (+,-,*,/): ";
	cin >> operation;
	switch (operation)
	{
	case'+':
		result = num1 + num2;
		break;
	case'-':
		result = num1 - num2;
		break;
	case'*':
		result = num1 * num2;
		break;
	case'/':
		if (num2 == 0) {
			cout << "Division not possible" << endl;
			return 1;
		}
		result = num1 / num2;
		break;
	default:
		cout << "Invalid Operation!";
		return 1;
	}
	cout << "Result= " << num1 << operation << num2 << " = " << result << endl;
	return 0;
}