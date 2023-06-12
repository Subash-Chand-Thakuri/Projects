#include <iostream>
#include <map>
#include <vector>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;


int main() {
  int n,opt2;
  
	for(int i =0;i<5;i++)
	{ 
	cout<<"Enter the number:";
	cin>>n;
//		srand(time(0));
		opt2 = rand()%5 +1;
		if(n == 2){
			cout<<"It is broken from 2."<<endl;
			cout<<"Random number:"<<opt2<<endl;
			break;
		}
		
		if(n == 3){
			cout<<"It is broken from 3."<<endl;
			cout<<"Random number:"<<opt2<<endl;
			break;
		}
		if(n == 2){
			cout<<"It is broken from 2."<<endl;
			cout<<"Random number:"<<opt2<<endl;
			break;
		}
		if(n == 4){
			cout<<"It is broken from 4."<<endl;
			cout<<"Random number:"<<opt2<<endl;
			break;
		}
		cout<<"Random number:"<<opt2<<endl;
		
	}
	

    return 0;
}
