#include <iostream>
using namespace std;
class OddNumber {
private:
	int i;
	int count;
public:
	OddNumber() {
		i = 0;
		count = 0;
	}
	void findoddnumbers() {
		while (count < 100) {
			if (i % 2 != 0) {
				cout << i << endl;
				count++;
			}
			i++;
		}
	}
};
int main()
{
	OddNumber obj1;
	obj1.findoddnumbers();
	return 0;
}