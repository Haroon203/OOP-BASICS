#include <iostream>
using namespace std;

//operator overloading


// + - * / ++ --

// obj1 + obj2

// value1 +value2

// 2 + 3i

class ComplexNum {
	int real;
	int imaginary;
public:
	ComplexNum(int real, int imaginary)
	{
		this->real = real;
		this->imaginary = imaginary;
	}

	// overloading + operator

	ComplexNum operator + (ComplexNum & obj2) {
		ComplexNum result(0,0);
		result.real = this->real + obj2.real;
		result.imaginary = this->imaginary + obj2.imaginary;
		return result;
	}

	void output()
	{
		cout << real << " + " << imaginary << "i" << endl;
	}

};


int main()
{
	ComplexNum Num1(2, 3);
	ComplexNum Num2(1, 5);
	ComplexNum result(0, 0);
	result = Num1 + Num2;
	result.output();


	return 0;
}
