#include <iostream>
using namespace std;
class FindPalidrom {
private:
    int a1, a2, a3, a4, an, rev;
public:
    FindPalidrom() {
        a1 = 0;
        a2 = 0;
        a3 = 0;
        a4 = 0;
        an = 0;
        rev = 0;
    }
    bool findpalidrom(int n) {
        int a1, a2, a3, a4, an, rev;
        an = n;
        a1 = n % 10;
        n = n / 10;
        a2 = n % 10;
        n = n / 10;
        a3 = n % 10;
        n = n / 10;
        a4 = n;
        rev = (a1 * 1000) + (a2 * 100) + (a3 * 10) + a4;
        cout << "Reverse is: " << rev;
        if (rev == an)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void display(){
    	bool found;
    if (found == true)
        cout << endl << "Number is palidrome";
    else
        cout << endl << "Number is not palidrome";
    }
};
int main()
{
    FindPalidrom obj1;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    bool found = obj1.findpalidrom(n);
   obj1.display();
    return 0;
}
