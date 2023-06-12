#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
class User{
	public:
		void registration(const string& name,const string& username,const string& password){
			fstream file;
			file.open("users.txt",ios::in | ios::app | ios::out);
			
			if(!file){
				cout<<"File couldn't open."<<endl;
				return;
			}
			
			while(!file.eof()){
				string line;
				 getline(file,line);
				string str = line.substr(line.find(",")+1,line.rfind(",") - line.find(",") - 1);
				
				if(str == username){
					cout<<"Username already taken.Try another one!"<<endl;
				//	break;
				}
				else{
					file<<name<<","<<username<<","<<password<<endl;
					cout<<"Successfully registered!"<<endl;
				
				}
			}
			
			file.close();
		}
		
		void login(const string& username,const string& password){
			
			ifstream file;
			file.open("users.txt",ios::in);
			
			if(!file){
				cout<<"File couldn't open."<<endl;
				return;
			}
			
			while(!file.eof()){
				string line;
				 getline(file,line);
				string str = line.substr(line.find(",")+1,line.rfind(",") - line.find(",") - 1);
				string pss = line.substr(line.rfind(","+1));
				
				if(str == username && pss == password ){
					cout<<"Login successful!"<<endl;
					//break;
				}
				else{
					cout<<"Invalid password.Try again!"<<endl;
				
				}
			}
			
			file.close();
		}
		
		
};


int main(){
	User u;
	string garbage,name,username,password;
	int choice;

	
		
	while(choice != 3){
		 			cout<<"1.Register"<<endl;
					cout<<"2.Login"<<endl;
					cout<<"3.Exit"<<endl;
					
		cout<<"Enter the choice:";
		cin>>choice;
		
		switch(choice){
			case 1:
				getline(cin,garbage);					
				cout<<"Enter the name:";
				getline(cin,name);
				cout<<"Enter the username:";
				getline(cin,username);
				cout<<"Enter the password:";
				getline(cin,password);
				u.registration(name,username,password);
				break;
				
			case 2:	getline(cin,garbage);
					cout<<"Enter the username:";
					getline(cin,username);
					cout<<"Enter the password:";
					getline(cin,password);
					u.login(username,password);
					break;
					
			case 3: cout<<"Exited!"<<endl;
			     	break;			
		}
		
	}	
	
 return 0;
}