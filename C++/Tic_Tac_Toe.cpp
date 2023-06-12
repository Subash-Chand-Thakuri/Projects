#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
	char box[][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	
void board( );
void choice();
void winner();


 int main(){
 	int i,j;

	board();
	
	choice();
	
	
	return 0;
}

 void board(){
 int count;
	cout<<endl;
	for(int i=0;i<3;i++){
		count = 0;
		cout<<"              ";
	for(int j=0;j<3;j++){
	 
	 	cout<<box[i][j];
		if(j < 2 )
		cout<<" | ";
			
		count++;
	    if(count == 3 && i<2){
		cout<<endl<<"             ___________"<<endl;
	}
	}	
	}
	
	cout<<endl;	
}


void choice(){
	int count =0;
	char opt1;
	int opt2;
	
	
	for(int i=0;i<5;i++){
		
	if(count<9){
		
	cout<<"Enter the number of the box:";
	cin>>opt1;
		if(opt1 == '1' ){
		box[0][0] = 'X';
	}
	else if(opt1 == '2' ){
		box[0][1] = 'X';
	}
	else if(opt1 == '3' ){
		box[0][2] = 'X';
	}
	else if(opt1 == '4' ){
		box[1][0] = 'X';
	}
	else if(opt1 == '5' ){
		box[1][1] = 'X';
	}
	else if(opt1 == '6' ){
		box[1][2] = 'X';
	}
	else if(opt1 == '7' ){
		box[2][0] = 'X';
	}
	else if(opt1 == '8' ){
		box[2][1] = 'X';
	}
	else if(opt1 == '9' ){
		box[2][2] = 'X';
	}	
	
	
	count++;
	}


	
	if(count<9){
		for(int j =0;j<9;j++){

//		srand(time(0));
		opt2 = rand()%9 +1;
	

	if(opt2 == 1 && box[0][0] == '1'){
		
		box[0][0] = 'O';
		break;
	}
	 if(opt2 == 2 && box[0][1] == '2'  ){
		box[0][1] = 'O';
		break;
	}
	 if(opt2 == 3 && box[0][2] == '3' ){
		box[0][2] = 'O';
		break;
	}
	 if(opt2 == 4 && box[1][0] == '4' ){
		box[1][0] = 'O';
		break;
	}
	 if(opt2 == 5 && box[1][1] == '5' ){
		box[1][1] = 'O';
		break;
	}
	 if(opt2 == 6 && box[1][2] == '6' ){
		box[1][2] = 'O';
		break;
	}
	 if(opt2 == 7 && box[2][0] == '7' ){
		box[2][0] = 'O';
		break;
	}
	 if(opt2 == 8 && box[2][1] == '8' ){
		box[2][1] = 'O';
		break;
	}
	 if(opt2 == 9 && box[2][2] == '9' ){
		box[2][2] = 'O';
		break;
	}
	}
	count++;

		}
	
	board();
	
	if((box[0][0]=='X'&& box[1][1]=='X' && box[2][2]=='X') || (box[0][0]=='X' && box[0][1]=='X' && box[0][2]=='X') || (box[0][0]=='X' && box[1][0]=='X' && box[2][0]=='X') ){
		cout<<"Congratulations,You win !"<<endl;
		return;
	}
	else if( (box[0][1]=='X'&& box[1][1]=='X' && box[2][1]=='X') || (box[0][2]=='X' && box[1][3]=='X' && box[3][3]=='X') || (box[1][0]=='X' && box[1][1]=='X' && box[1][2]=='X')
	|| ( box[2][0]=='X'&& box[2][1]=='X' && box[2][2]=='X' ) ){
		cout<<"Congratulations,You win ! "<<endl;	
		return;
	}
	else if( (box[0][0]=='O'&& box[1][1]=='O' && box[2][2]=='O') || (box[0][0]=='O' && box[0][1]=='O' && box[0][2]=='O') || (box[0][0]=='O' && box[1][0]=='O' && box[2][0]=='O') ){
			cout<<"You lose..."<<endl;
			return;
	}
	else if( (box[0][1]=='O'&& box[1][1]=='O' && box[2][1]=='O') || (box[0][2]=='O' && box[1][3]=='O' && box[3][3]=='O') || (box[1][0]=='O' && box[1][1]=='O' && box[1][2]=='O')
	|| ( box[2][0]=='O' && box[2][1]=='O' && box[2][2]=='O' ) ){
			cout<<"You lose..."<<endl;
			return;
	}	
	
	
	}
}

void winner(){
	if((box[0][0]=='X'&& box[1][1]=='X' && box[2][2]=='X') || (box[0][0]=='X' && box[0][1]=='X' && box[0][2]=='X') || (box[0][0]=='X' && box[1][0]=='X' && box[2][0]=='X') ){
		cout<<"Congratulations,You win !"<<endl;
	}
	else if( (box[0][1]=='X'&& box[1][1]=='X' && box[2][1]=='X') || (box[0][2]=='X' && box[1][3]=='X' && box[3][3]=='X') || (box[1][0]=='X' && box[1][1]=='X' && box[1][2]=='X')
	|| ( box[2][0]=='X'&& box[2][1]=='X' && box[2][2]=='X' ) ){
		cout<<"Congratulations,You win ! "<<endl;	
	}
	else if( (box[0][0]=='O'&& box[1][1]=='O' && box[2][2]=='O') || (box[0][0]=='O' && box[0][1]=='O' && box[0][2]=='O') || (box[0][0]=='O' && box[1][0]=='O' && box[2][0]=='O') ){
			cout<<"You lose..."<<endl;
	}
	else if( (box[0][1]=='O'&& box[1][1]=='O' && box[2][1]=='O') || (box[0][2]=='O' && box[1][3]=='O' && box[3][3]=='O') || (box[1][0]=='O' && box[1][1]=='O' && box[1][2]=='O')
	|| ( box[2][0]=='O' && box[2][1]=='O' && box[2][2]=='O' ) ){
			cout<<"You lose..."<<endl;
	}
	else{
		cout<<"Match Draw!"<<endl;
	}
	}