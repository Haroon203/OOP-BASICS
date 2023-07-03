#include <iostream>
using namespace std;
int main()
{
    int temp;
    char arr[3][3] = { {'b','r','r'},
						{'b','g','b'},
						{'g','r','g'} };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp = arr[0][j];
            arr[0][j] = arr[1][j];
            arr[1][j] = temp;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp = arr[1][j];
            arr[1][j] = arr[2][j];
            arr[2][j] = temp;
        }
    }
    // column
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp = arr[i][0];
            arr[i][0] = arr[i][1];
            arr[i][1] = temp;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp = arr[i][1];
            arr[i][1] = arr[i][2];
            arr[i][2] = temp;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}
