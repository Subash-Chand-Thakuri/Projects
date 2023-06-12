#include<iostream>
#include<fstream.h>
#include<iomanip.h>
#include<string.h>
using namespace std;

class Record{
			
			char name[20];
		    string email;
		    int mob;
			int qty;
			float wt;
			float price;
			
			public:
				Record {
				name="..."; emai="..."; mob=0; qty=0; wt=0.00; price=0.00;
				}
				
			void create(){
				
			}		
			
};

int main(){
	Record r;
		cout<<"Enter the data: "<<endl;
		 r.create()
	
	return 0;
}
