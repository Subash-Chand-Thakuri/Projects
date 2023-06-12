#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std;

class Account {
private:
    string username;
    long long acc_no;
    long total_amt;
    string password;
    long deposit, withdraw;

public:
    Account() {
        total_amt = 0;
    };

    void create_Acc(map<string, vector<string>>& my_maps) {

			
			cout<<"Enter the usernname:";
			getline(cin,username);
			
			
			cout<<"Set the password:";
			getline(cin,password);
			
			
			cout<<"Deposit the first amount in the account:";
			cin>>deposit;
			
			cin.ignore();
			
			total_amt += deposit;
			string balance = to_string(total_amt);
			cout<<"Now your balance is:"<<total_amt<<endl;
			
			my_maps.insert(make_pair(username,vector<string>{password,balance}));
			
			LoadintoFile(my_maps);
			reset();
			my_maps.clear();
    }

    void Withdraw(map<string, vector<string>>& my_maps) {
        if (confirmation(my_maps)) {
            cout << "Enter the amount to be withdrawn:";
            cin >> withdraw;

            auto iterator = my_maps.find(username);
            total_amt = stol(iterator->second[1]);

            total_amt = total_amt - withdraw;
            string balance = to_string(total_amt);

            my_maps[username].at(1) = balance;

            saveEditedInfo(my_maps);

            cout << "Now your balance is:" << total_amt << endl;
        } else {
            cout << "False information." << endl;
        }
    }

    void Deposit(map<string, vector<string>>& my_maps) {
        if (confirmation(my_maps)) {
            cout << "Enter the amount to be deposited:";
            cin >> deposit;

            auto iterator = my_maps.find(username);
            total_amt = stol(iterator->second[1]);

            total_amt += deposit;
            string balance = to_string(total_amt);

            my_maps[username].at(1) = balance;

            saveEditedInfo(my_maps);

            cout << "Now your balance is:" << total_amt << endl;
        } else {
            cout << "False information." << endl;
        }
    }

    bool confirmation(map<string, vector<string>>& my_maps) {
        cout << "Enter the usernname:";
        getline(cin, username);

        cout << "Enter the password:";
        getline(cin, password);

        LoadintoMap(my_maps);

        auto it = my_maps.find(username);
        if (it != my_maps.end()) {
            if (password == it->second[0]) {
                cout << "Now are in." << endl;
                return true;
            }
        } else {
            cout << "Account doesn't exist." << endl;
            return false;
        }

        return false;
    }

    void LoadintoMap(map<string, vector<string>>& my_maps) {
        my_maps.clear();
        ifstream infile("data.txt");
        string key, val1, val2;
        while (infile >> key >> val1 >> val2) {
            my_maps[key].push_back(val1);
            my_maps[key].push_back(val2);
        }
        infile.close();
    }

    void LoadintoFile(map<string, vector<string>>& my_maps) {
        ofstream outfile("data.txt", ios::app | ios::out);
        for (auto& it : my_maps) {
            outfile << it.first << " ";
            for (auto& value : it.second) {
                outfile << value << " ";
            }
            outfile << endl;
        }

        outfile.close();
    }
    
    void saveEditedInfo(map<string, vector<string>>& my_maps){
    	ofstream outfile("data.txt", ios::out);
        for (auto& it : my_maps) {
            outfile << it.first << " ";
            for (auto& value : it.second) {
                outfile << value << " ";
            }
            outfile << endl;
        }

        outfile.close();
    }
    
    void reset(){
    	total_amt = 0;
    	
	}
	
};

int main() {
    int choice, count;
    Account a1;
    map<string, vector<string>> my_maps;

    

    while (count != 4) {
        cout << "1.Create Account \n2.Withdraw \n3.Deposit \n4.Exit" << endl;
        cout << "Enter the choice:";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                a1.create_Acc(my_maps);
                break;

            case 2:
                a1.Withdraw(my_maps);
                break;

            case 3:
                a1.Deposit(my_maps);
                break;

            case 4:
                count = 4;
                return false;

            default:
                cout << "Wrong choice.Try Again!" << endl;
                break;
        }
    }

    return 0;
}
