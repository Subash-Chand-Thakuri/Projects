#include<iostream>
#include<cstring>
#include<fstream>
#include<map>
using namespace std;
class User{
	private:
		map <string,string> users;
		void Loadusers(){
			ifstream file("users.txt",ios::in);
			string username,password;
			while(file>>username>>password){
				users[username] = password;
				}
				
				file.close();
			
		}
	public:
		
		User(){
			Loadusers();
		}
		
		void registration(const string& username,const string& password){
			

			
			if(users.find(username) == users.end()){
			 users[username]=password;
			ofstream file;
			file.open("users.txt", ios::app);
				file<<username<<" "<<password<<endl;
			file.close();
				cout<<"Registered successfully!"<<endl;
			}
			else{
				cout<<"Unavailable username.Try next one!"<<endl;
			}
			
		}
		
		bool login(const string& username,const string& password){
		
			auto iterator = users.find(username);
			
			if(iterator != users.end() && iterator->second == password){
				cout<<"Successfully logged in!"<<endl;
				return true;
			}
			else{
				cout<<"Wrong password.Try again...!"<<endl;
				return false;
			}
			
		}
		
		
		
		void saveUsers(const map<string,string>& users ){
			ofstream file("users.txt");
			for(const auto& user:users){
				file<<user.first<<" "<<user.second<<endl;
			}
			
			file.close();
		}
		
		
		
		void changePassword(const string& username,string& password){
				auto iterator = users.find(username);
				
			if(iterator != users.end() && iterator->second == password){
				cout<<"Enter new password:";
				cin>>password;
				
			}
			else{
				cout<<"Invalid username."<<endl;
			}
			
			users[username]=password;
			saveUsers(users);
			}
			
		 	
		
		
		
};


int main(){
	User u;
 int choice;
    string username, password;

    while (choice !=4) {
        cout << "1. Register\n2. Login \n3. Change Password\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                u.registration(username, password);
                break;
            case 2:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                u.login(username, password);
                break;
                
            case 3:   cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                u.changePassword(username, password);
                break;  
            case 4:
                cout << "Exited...!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << std::endl;
        }
    }	
	
 return 0;
}