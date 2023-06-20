#include <iostream>
using namespace std;

//checking
class Bird{
	private:
	string name;
	string sound;
	int nowings;
	public:
		Bird(string Name,string Sound,int Nowings){
		name=Name;
		sound=Sound;
		nowings=Nowings;	
	}
	Bird(Bird &obj2){
		name=obj2.name;
		sound=obj2.sound;
		nowings=obj2.nowings;
		}
	~Bird(){
		cout<<"Bird object destroyed"<<endl;
	}	
	void display(){
		cout<<"Name of bird: "<<name<<endl;
		cout<<"Sound of bird: "<<sound<<endl;
		cout<<"Number of wings of bird: "<<nowings<<endl;	
	}	
};
int main()
{
	Bird obj1("","",0);
	Bird obj2("","",0);
	int choice,nowings;
	string sound,name;
	cout<<"Enter choice: ";
	cin>>choice;
	do{
		switch(choice){
			case 1:
				cout<<" create Bird"<<endl;
				cout<<"Enter the name of bird"<<endl;
				cin>>name;
				cout<<"Enter the sound of bird"<<endl;
				cin>>sound;
				cout<<"Enter the number of wings of bird"<<endl;
				cin>>nowings;
				obj1=Bird(name,sound,nowings);
				obj1.display();
				break;
				case 2:
				obj2=Bird(obj1);
				obj2.display();
				break;
				case 0:
					cout<<"Exist the program"<<endl;
					break;
				default:
					cout<<"Invalid choice"<<endl;
		}
		cout<<endl;
	}while(choice!=0);
	return 0;
}
