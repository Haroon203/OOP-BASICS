#include <iostream>
using namespace std;
class Bird {
private:
	string name;
	string sound;
	int nowings;
public:
	Bird() {
		name = "Eagle";
		sound = "zooo";
		nowings = 2;
	}
	~Bird() {
		cout << "Bird object is destroyed" << endl;
	}
	Bird(string Name, string Sound, int Nowings) {
		name = Name;
		sound = Sound;
		nowings = Nowings;
	}
	Bird(Bird& temp) {
		this->name = temp.name;
		this->sound = temp.sound;
		this->nowings = temp.nowings;
	}
	void display() {
		cout << endl << endl;
		cout << "Name of bird: " << name << endl;
		cout << "Sound of bird: " << sound << endl;
		cout << "Number of wings of bird: " << nowings << endl;
		cout << endl << endl;
	}
};
int main()
{
	int choice, nowings;
	string name, sound;
	int choice2=1;
	Bird obj1, obj2;
	while (1)
	{
		cout << "----Welcome to Our Pet Shop----" << endl;
		cout << "Press 1 to call default constructor" << endl;
		cout << "Press 2 to call parameterized constructor" << endl;
		cout << "Press 3 to call copy constructor" << endl;
		cout << "Press 0 to end the program" << endl;
		cout << "Enter choice: ";
		cin >> choice;

		if (choice == 1)
		{
			Bird def;
			def.display();
		}
		else if (choice == 2)
		{
			system("cls");
			string name, sound;
			int noofwings;
			cout << "Enter Name of Bird = " << endl;
			cin >> name;
			cout << "Enter Sound of Bird = " << endl;
			cin >> sound;
			cout << "Enter Wings of Bird = " << endl;
			cin >> noofwings;

			Bird parameter(name, sound, noofwings);

			parameter.display();
		}
		else if (choice == 3)
		{
			Bird copy1;
			Bird copy2(copy1);

			copy2.display();

		}

		else
		{
			cout << endl;
			cout << "Wrong Input, Try Again" << endl;
		}

		system("pause");
		system("cls");
		continue;

		//system("cls");
	}



	return 0;
}