#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

    int Computerchoice(){
		srand(time(0));
		int choice = rand()%3 +1;
		return choice;
    }
   

int main(){
	int Userchoice,Compchoice,n;
	int user=0, computer = 0;
	cout<<"Enter the total turns of game:"<<endl;
	cin>>n;
	cout<<"Enter 1 for rock:"<<endl<<"Enter 2 for paper:"<<endl<<"Enter 3 for scissor:"<<endl;

	
	while(n!=0){
		
			cout<<"Enter the number"<<endl;
	cin>>Userchoice;
	 
	Compchoice = Computerchoice();
	
	if(Userchoice == 1 || Userchoice == 2 || Userchoice == 3){	
		if((Compchoice == 1 && Userchoice == 2)|| (Compchoice == 2 && Userchoice == 3) || (Compchoice == 3 && Userchoice == 1)){
		user++;
		
	    }
		else {
		computer++;
	 }
		
	}
	else
	{
		cout<<"Invalid choice! Try Again"<<endl;
		
	}
	
	n--;
 } 
 
 cout<<"\n"<<endl;
 
	if(computer >user){
			cout<<"Sorry, Computer wins!"<<endl;
	} 
	else if(computer<user){
		cout<<"Congratulation! You win!"<<endl;	
	}
	else{
		cout<<left<<":----- Match Draw ------:"<<endl;
	}
	
 cout<<"Your Score: "<<user<<endl;
 cout<<"Computer Score: "<<computer<<endl;
	
	
	return 0;
}