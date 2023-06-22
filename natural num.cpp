#include <iostream>
using namespace std;
class Findsquare{
	private:
	int arr[10];
	int size;
	public: 
	Findsquare(){
		size=10;
	}
	void calculatesquare(){
		for(int i=0;i<size;i++){
        arr[i]=(i+1)*(i+1);
    }
	}
	void displaysquare(){
		for(int i=0;i<size;i++){
        cout<<"square of "<<i+1<<" is: "<<arr[i]<<endl;
    }
	}
}; 
int main()
{
	Findsquare obj1;
	obj1.calculatesquare();
	obj1.displaysquare();
	return 0;
}
