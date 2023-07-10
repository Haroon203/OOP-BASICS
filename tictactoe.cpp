#include <iostream>
#include <ctime>
using namespace std;

class Tictactoe {
	int toss;
	char arr[3][3];
	int turnRow;
	int turnCol;
public:

	Tictactoe() {
		toss = 0;
		turnRow = 0;
		turnCol = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				arr[i][j] = ' ';
			}
		}
	}

	void tossGenerator() {
		srand(time(0));

		toss = rand();
		toss = (toss % 2) + 1;

		if (toss == 1)
		{
			cout << endl;
			cout << "Player 1 has won the toss" << endl;
			this->playerTurn(toss);
		}
		else if (toss == 2)
		{
			cout << endl;
			cout << "Player 2 has won the toss" << endl;
			this->playerTurn(toss);
		}
		else
		{
			cout << "Toss Failed, Try Again" << endl;
		}
		//cout << random << endl;

	}

	void board() {
		system("cls");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (j == 0)
				{
					cout << "|";
				}
				cout << arr[i][j] << " " << "|";
			}
			cout << endl;
		}

	}

	               //1,2
	int playerTurn(int playerValue)
	{
		if (playerValue == 1)
		{
			cout << endl;
			cout << "Player 1" << endl;
		}
		else if (playerValue == 2)
		{
			cout << endl;
			cout << "Player 2" << endl;
		}

			while (1)
			{

				cout << "Please do your turn, 1-9 = ";
				cin >> this->turnRow;
				cin >> this->turnCol;


				if (arr[turnRow][turnCol] != ' ')
				{
					cout << "Wrong Input, Try Again" << endl;

					continue;
				}
				else if (turnRow > 2 || turnRow < 0)
				{
					cout << "Wrong Input, Try Again" << endl;

					continue;
				}
				else if (turnCol > 2 || turnCol < 0)
				{
					cout << "Wrong Input, Try Again" << endl;

					continue;
				}

				break;
			}
			
			if (playerValue == 1)
			{
				arr[turnRow][turnCol] = 'x';

				/*if (winChecker() == true)
				{
					return 0;
				}
				else if (drawChecker() == true)
				{
					return 0;
				}*/

				board();
				playerTurn(2);
			}
			else if (playerValue == 2)
			{
				arr[turnRow][turnCol] = 'o';

				/*if (winChecker() == true)
				{
					return 0;
				}
				else if (drawChecker() == true)
				{
					return 0;
				}*/

				board();
				playerTurn(1);

			}

			

			return 0;
	}


	bool winChecker()
	{
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
			if(arr[i][0]==arr[i][1] && arr[i][1]==arr[i][2])
			return true;
			if(arr[0][j]==arr[1][j] && arr[1][j]==arr[2][j])
			return true;
			if(arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2] )
			return true;
			if(arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0])
			return true;
			return false;
		}
		}
	}
	bool drawChecker()
	{
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(arr[i][0]!=arr[i][1] || arr[i][1]!=arr[i][2])
			return true;
			if(arr[0][j]!=arr[1][j] || arr[1][j]!=arr[2][j])
			return true;
			if(arr[0][0]!=arr[1][1] || arr[1][1]!=arr[2][2])
			return true;
			if(arr[0][2]!=arr[1][1] || arr[1][1]!=arr[2][0])
			return true;
			return false;
		}
	}
	}


};

int main()
{
	Tictactoe obj1;
	obj1.board();
	obj1.tossGenerator();
	bool found=obj1.winChecker();
	if (found == true)
	cout<<"Player 1 win";
 	else
 	cout<<"Player 2 win";
 	bool check=obj1.drawChecker();
 	if(check==true)
 	cout<<"Draw!";
 	else 
 	cout<<"Not draw!";
	return 0;

}
