#include <iostream>
using namespace std;
int main()
{
    char choice;
    char arr[3][3] = { {'b','r','r'},
                 {'b','g','b'},
                {'g','r','g'} };
    char newarr[3][3];
    do {
        cout << "***Menu list***" << endl;
        cout << "w for upwards moment" << endl;
        cout << "s for downwords moment" << endl;
        cout << "d for right moment" << endl;
        cout << "a for left moment" << endl;
        cout << "q for the exist program";
        cout << endl<<"Enter a choice" << endl;
        cin >> choice;
        if (choice == 's') {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char newrowindex = (i + 1) % 3;
                    newarr[newrowindex][j] = arr[i][j];
                }
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << newarr[i][j] << " ";
                }
                cout << endl;
            }
        }
        else if (choice == 'w') {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char newrowindex = (i - 1 + 3) % 3;
                    newarr[newrowindex][j] = arr[i][j];
                }
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << newarr[i][j] << " ";
                }
                cout << endl;
            }
        }
        else if (choice == 'd') {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char newrowindex = (j + 1) % 3;
                    newarr[i][newrowindex] = arr[i][j];
                }
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << newarr[i][j] << " ";
                }
                cout << endl;
            }
        }
        else if (choice == 'a') {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char newrowindex = (j - 1 + 3) % 3;
                    newarr[i][newrowindex] = arr[i][j];
                }
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << newarr[i][j] << " ";
                }
                cout << endl;
            }
        }
        else
            cout << "Invalid choice";
    } while (choice != 'q');
    return 0;
}