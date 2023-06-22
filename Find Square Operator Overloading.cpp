#include <iostream>
using namespace std;
class FindSquare{
private:
	int size;
	int *arr;
public:
	FindSquare()
	{
		size = 10;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = i+1;
		}
	}

	int sizeGetter()
	{
		return size;
	}

	FindSquare operator*(FindSquare & temp)
	{
		FindSquare Result;
		for (int i = 0; i < sizeGetter(); i++) {

			Result.arr[i] = this->arr[i] * temp.arr[i];
		}
		return Result;
	}



	void print()
	{
		for (int i = 0; i < sizeGetter(); i++) {
			cout << i + 1 << " squared : " << arr[i] << endl;
		}

	}


public:

};
int main()
{
	FindSquare obj1, obj2, Result;
	cout << "Array Before Finding Square = " << endl;
	Result.print();

	Result = obj1 * obj2;


	cout << "Array After Finding Square = " << endl;
	Result.print();

	return 0;
}