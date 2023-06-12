#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<map>
#include<vector>
#include<chrono>
#include<ctime>
using namespace std;

class Record{
			
			char name[30];
		    string username;
		    string item[50];
			float qty[50];
			float NetRate[50];
			float NetAmt[50];
		
			int n;
			
			map<string,vector<string>> users;
			
			public:
			Record(){
				
			}
			
			void LoadUsers(){ //load the users data into map
			
				string key,val1,val2,val3,val4;
				ifstream file("data.txt",ios::in);
				while(file>>key>>val1>>val2>>val3>>val4){
					users[key].push_back(val1);
					users[key].push_back(val2);
					users[key].push_back(val3);
					users[key].push_back(val4);
				}
				file.close();
				
			}
			
			void saveUsers(map<string,vector<string>> users,string key){ // to store informations of map into file
				
				ofstream file("data.txt",ios::out);
				file<<left<<setw(14)<<key<<" ";
				
				for(const auto& value:users[key]){
				file<<value<<" ";
			 	}
			 	file<<endl;
				file<<left<<setw(15);

				
				cout<<endl;
			 file.close();
			}
			
			void setData(){
				cout<<"Enter the name:";
				cin.getline(name,30);
				cout<<"Enter username:";
				cin>>username;
				cout<<"Enter the total number of products:";
				cin>>n;
				
				
				
			}
			
			void setItems(){
				cout<<endl;
				
				for(int i=0;i<n;i++){
					
				cout<<"Enter the name of the item:";
				cin>>item[i];
				cout<<"Enter the Quantity of the product:";
				cin>>qty[i];
				cout<<"Enter the Net Rate of the product:";
				cin>>NetRate[i];
				NetAmt[i] = qty[i]*NetRate[i];
				
			
				
				users[username].push_back(item[i]);
				users[username].push_back(to_string (qty[i]));
				users[username].push_back(to_string(NetRate[i]));
				users[username].push_back(to_string(NetAmt[i]));
				
				saveUsers(users,username);
				}
			}
			
			void getData(){
				cout<<"=============================INVOICE============================="<<endl<<endl;
				
				auto now = std::chrono::system_clock::now();
    			auto in_time_t = std::chrono::system_clock::to_time_t(now);
				
				
				cout<<"Bill Date:"<<ctime(&in_time_t)<<endl;
				cout<<"Customer Name:"<<name<<endl<<endl<<endl;
				
				cout<<"-----------------------------------------------------------------"<<endl<<endl;
				cout<<left<<setw(15)<<"Items"<<right<<setw(10)<<"Qty"<<right<<setw(10)<<"Net Rate"<<right<<setw(10)<<"Net Amt"<<endl<<endl;
				cout<<"-----------------------------------------------------------------"<<endl<<endl;
				
				float sum =0;
				for(int i=0;i<n;i++){
				cout<<left<<setw(15)<<item[i]<<right<<setw(10)<<qty[i]<<right<<setw(10)<<NetRate[i]<<right<<setw(10)<<NetAmt[i]<<endl;
				sum += NetAmt[i];	
				}
				
				
				cout<<"-----------------------------------------------------------------"<<endl<<endl;
				cout<<left<<setw(15)<<"Grand Total:"<<right<<setw(30)<<sum<<endl<<endl;
				cout<<"-----------------------------------------------------------------"<<endl<<endl;
				
				
				
			}
			
				
					
			
};

int main(){
	Record r;
		
		 r.setData();
		 r.setItems();
		 r.getData();
	
	return 0;
}
