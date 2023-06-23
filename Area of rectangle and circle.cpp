#include <iostream>
using namespace std;
class Rectangle {
private:
	float lenght, width;
public:
	Rectangle() {
		lenght = 0;
		width = 0;
	}
	float rectanglearea(float lenght, float width) {
		return lenght * width;
	}
};
class Circle {
private:
	float radius, pi;
public:
	Circle() {
		radius = 0;
		pi = 3.14;
	}
	float circlearea(float radius) {
		return pi * radius * radius;
	}

};
int main() {
	float lenght, width, radius;
	cout << "Enter the lenght for area of rectangle: ";
	cin >> lenght;
	cout << "Enter the width for area of rectangle: ";
	cin >> width;
	Rectangle rec;
	cout << "Area of rectangle is: " << rec.rectanglearea(lenght, width) << endl;
	cout << endl << endl << endl;
	cout << "Enter the radius for circle area: ";
	cin >> radius;
	Circle cir;
	cout << "Area of circle is: " << cir.circlearea(radius) << endl;
	return 0;
}
