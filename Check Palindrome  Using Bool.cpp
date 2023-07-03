#include <iostream>
using namespace std;
class FindPalidrom {
private:
    long int a1,an,rev;
public:
    FindPalidrom() {
        a1 = 0;
        an = 0;
        rev = 0;
    }
    
    //12321
    bool findpalidrom(long int n) {
      an=n; 
       while(an>0)
       {
       	a1=an%10;
       	rev=(rev*10)+a1;
       	an=an/10;
       	
       	//cout<<"an = "<<an<<endl;
       	//cout<<"rev ="<<rev<<endl;
       	//system("pause");
	   }
	   if(n==rev)
	   {
	   return true;
	   }
	   else
	   {
	   	return false;
	   }
	   
	   
    }
    
    
    void display(bool found){
    if (found == true)
        cout << endl << "Number is palidrome";
    else
        cout << endl << "Number is not palidrome";
    }
};
int main()
{
    FindPalidrom obj1;
    long int n;
    cout << "Enter a number: ";
    cin >> n;
    bool found = obj1.findpalidrom(n);
   obj1.display(found);
    return 0;
}
