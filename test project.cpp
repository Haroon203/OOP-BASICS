#include <iostream>
#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

using namespace std;
const int MAX_LECTURERS = 10;
const int MAX_COURSES = 20;
const int MAX_STUDENTS = 100;
const int MAX_COURSES_PER_LECTURER = 3;
const int MAX_COURSES_PER_STUDENT = 5;

class Course {
private:
    string nameofcourse;
    string lecturerName;

public:
    Course() {
        nameofcourse = "";
        lecturerName = "";
    }

    Course(string name, string lecturerName) {
        this->nameofcourse = name;
        this->lecturerName = lecturerName;
    }

    string getNameofcourse() {
        return nameofcourse;
    }

    string getLecturerName() {
        return lecturerName;
    }
};

class Lecturer {
private:
    string id;
    string name;
    Course assignedCourses[MAX_COURSES_PER_LECTURER];
    int assignedCourseCount;

public:
    Lecturer() {
        id = "1";
        name = "lecturer";
        assignedCourseCount = 0;
    }

    Lecturer(string id, string name) {
        this->id = id;
        this->name = name;
        assignedCourseCount = 0;
    }

    string getId() {
        return id;
    }

    string getName() {
        return name;
    }

    bool login(string id, string name) {
        return this->id == id && this->name == name;
    }

    void assignCoursestolecturer(const Course& course) {
        if (assignedCourseCount < MAX_COURSES_PER_LECTURER) {
            assignedCourses[assignedCourseCount] = course;
            assignedCourseCount++;
        }
        else {
            cout << "Error: Maximum courses assigned to the lecturer." << endl;
        }
    }

    void displayAssignedCourses() {
        if (assignedCourseCount > 0) {
            cout << name << "'s assigned courses:" << endl;
            for (int i = 0; i < assignedCourseCount; i++) {
                cout << "- " << assignedCourses[i].getNameofcourse() << endl;
            }
        }
        else {
            cout << name << " has not been assigned any courses." << endl;
        }
    }
};

class Student {
private:
    int rollno;
    string name;
    string password;
    Course enrolledCourses[MAX_COURSES_PER_STUDENT];
    int enrolledCourseCount;

public:
    Student() {
        rollno = 0;
        name = "student";
        password = "123";
        enrolledCourseCount = 0;
    }
    Student(int rollno, string name, string password) {
        this->rollno = rollno;
        this->name = name;
        this->password = password;
        enrolledCourseCount = 0;
    }

    bool login(int rollno, string password) {
        return this->rollno == rollno && this->password == password;
    }

    bool enrollCourse(Course& course) {
        if (enrolledCourseCount < MAX_COURSES_PER_STUDENT) {
            enrolledCourses[enrolledCourseCount] = course;
            enrolledCourseCount++;
            return true;
        }

        cout << "Error: Maximum courses enrolled by the student." << endl;
        return false;
    }

    void displayEnrolledCourses() {
        if (enrolledCourseCount > 0) {
            cout << name << "'s enrolled courses:" << endl;
            for (int i = 0; i < enrolledCourseCount; ++i) {
                cout << "- " << enrolledCourses[i].getNameofcourse() << endl;
            }
        }
        else {
            cout << name << " has not enrolled in any courses." << endl;
        }
    }
};

class Administration {
private:
    string username;
    string password;
    Lecturer lecturers[MAX_LECTURERS];
    Course courses[MAX_COURSES];
    int lecturerCount;
    int courseCount;

public:
    Administration() {
        username = "admin";
        password = "password";
        lecturerCount = 0;
        courseCount = 0;
    }

    bool login(string username, string password) {
        return this->username == username && this->password == password;
    }

    void addLecturer(const Lecturer& lecturer) {
        if (lecturerCount < MAX_LECTURERS) {
            lecturers[lecturerCount] = lecturer;
            lecturerCount++;
            cout << "Lecturer added successfully." << endl;
        }
        else {
            cout << "Maximum number of lecturers reached." << endl;
        }
    }

    void addCourse(const Course& course) {
        if (courseCount < MAX_COURSES) {
            courses[courseCount] = course;
            courseCount++;
            cout << "Course added successfully." << endl;
        }
        else {
            cout << "Maximum number of courses reached." << endl;
        }
    }

    void displayLecturers() {
        if (lecturerCount > 0) {
            cout << "List of Lecturers: " << endl;
            for (int i = 0; i < lecturerCount; i++) {
                cout << "- " << lecturers[i].getName() << " (ID: " << lecturers[i].getId() << ")" << endl;
            }
        }
        else {
            cout << "No lecturers found." << endl;
        }
    }

    void displayCourses() {
        if (courseCount > 0) {
            cout << "List of Courses: " << endl;
            for (int i = 0; i < courseCount; i++) {
                cout << "- " << courses[i].getNameofcourse() << " (Lecturer: " << courses[i].getLecturerName() << ")" << endl;
            }
        }
        else {
            cout << "No courses found." << endl;
        }
    }
};

void clearConsole() {
    system(CLEAR_SCREEN);
}

void showAdministrationMenu(Administration& admin) {
    string username, password;
    cout << "Administration Login:" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (admin.login(username, password)) {
        int choice;
        do {
            clearConsole();
            cout << endl << "----- Administration Menu -----" << endl;
            cout << "1. Add Lecturer" << endl;
            cout << "2. Add Course" << endl;
            cout << "3. Display Lecturers" << endl;
            cout << "4. Display Courses" << endl;
            cout << "0. Logout" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
            case 1: {
                string id, name;
                cout << "Enter Lecturer ID: ";
                cin >> id;
                cout << "Enter Lecturer Name: ";
                cin.ignore();
                cin >> name;
                Lecturer lecturer(id, name);
                admin.addLecturer(lecturer);
                break;
            }
            case 2: {
                string name, lecturer;
                cout << "Enter Course Name: ";
                cin.ignore();
                cin >> name;
                cout << "Enter Lecturer Name: ";
                cin >> lecturer;
                Course course(name, lecturer);
                admin.addCourse(course);
                break;
            }
            case 3:
                clearConsole();
                admin.displayLecturers();
                break;
            case 4:
                clearConsole();;
                admin.displayCourses();
                break;
            case 0:
                cout << "Logging out from the Administration portal." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
        } while (choice != 0);
    }
    else {
        cout << "Login failed. Invalid admin credentials." << endl;
    }
}

void showLecturerMenu(Lecturer& lecturer) {
    string id, name;
    cout << "Lecturer Login: " << endl;
    cout << "ID: ";
    cin >> id;
    cout << "Name: ";
    cin.ignore();
    cin >> name;

    if (lecturer.login(id, name)) {
        int choice;
        do {
            clearConsole();
            cout << endl << "----- Lecturer Menu -----" << endl;
            cout << "1. Display Assigned Courses" << endl;
            cout << "2.Assign course to lecturer" << endl;
            cout << "0. Logout" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
            case 1:
                clearConsole();
                lecturer.displayAssignedCourses();
                break;
            case 2:
                string coursename ,lecturername;
                cin.ignore();
                cout << "Enter Course Name: ";
                cin >> coursename;
                cout << "Enter Lecturer Name: ";
                 cin >> lecturername;
                Course course(coursename, lecturername);
                lecturer.assignCoursestolecturer(course);
                 break;
            case 0:
                cout << "Logging out from the Lecturer portal." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
        } while (choice != 0);
    }
    else {
        cout << "Login failed. Invalid lecturer credentials." << endl;
    }
}


void showStudentMenu(Student& student) {
    int rollno;
    string password;

    cout << "Student Login:\n";
    cout << "Roll no: ";
    cin >> rollno;
    cout << "Password: ";
    cin >> password;

    if (student.login(rollno, password)) {
        int choice;
        do {
            clearConsole();
            cout << endl << "----- Student Menu -----" << endl;
            cout << "1. Display Enrolled Courses" << endl;
            cout << "2. Enroll in a Course" << endl;
            cout << "0. Logout" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
            case 1:
                clearConsole();
                student.displayEnrolledCourses();
                break;
            case 2: {
                string courseName, lecturerName;
                cout << "Enter Course Name: ";
                cin.ignore();
                cin >> courseName;
                cout << "Enter Lecturer Name: ";
                cin >> lecturerName;
                Course course(courseName, lecturerName);
                if (student.enrollCourse(course)) {
                    cout << "Enrollment successful." << endl;
                }
                break;
            }
            case 0:
                cout << "Logging out from the Student portal." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
        } while (choice != 0);
    }

    else {
        cout << "Login failed. Invalid student credentials." << endl;
    }
}


int main() {
    Administration admin;
    Lecturer lecturer;
    Student student;

    int choice;
    do {
        clearConsole();
        cout << "----- Admission system of an university -----" << endl;
        cout << "1. Administration" << endl;
        cout << "2. Lecturer" << endl;
        cout << "3. Student" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            showAdministrationMenu(admin);
            break;
        case 2:
            showLecturerMenu(lecturer);
            break;
        case 3:
            showStudentMenu(student);
            break;
        case 0:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    } while (choice != 0);

    return 0;
}
