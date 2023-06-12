#include<iostream>
using namespace std;

void getCGPA(int num){
	int i;
	float sub[num],crdthr[num],totalPoints =0,totalcrdthr=0;
	
	cout<<"Enter the marks and credit of "<<num<<" each subject:"<<endl;
	for(i=0;i<num;i++){
		
		cin>>sub[i]>>crdthr[i];
		totalPoints += (sub[i]/10)*crdthr[i];
		totalcrdthr += crdthr[i];
		
		if(i<num-1){
				cout<<"NEXT ONE PLEASE:"<<endl;	
		}
		
	}
	
	float gpa = ((totalPoints/totalcrdthr)*10)/25;
	
	if(gpa >3.6 || gpa == 4 ){
		cout<<"Your Grade is A+"<<endl<<"CGPA="<<gpa<<endl;
	}
	else if(gpa == 3.6 || gpa > 3.2 ){
		cout<<"Your Grade is A"<<endl<<"CGPA="<<gpa<<endl;
	}
	else if(gpa == 3.2 || gpa > 2.8 ){
		cout<<"Your Grade is B+"<<endl<<"CGPA="<<gpa<<endl;
	}
	else if(gpa == 2.8 || gpa > 2.4 ){
		cout<<"Your Grade is B"<<endl<<"CGPA="<<gpa<<endl;
	}
	else if(gpa == 2.4 || gpa > 2 ){
		cout<<"Your Grade is C+"<<endl<<"CGPA="<<gpa<<endl;
	}
	else if(gpa == 2 || gpa > 1.6 ){
		cout<<"Your Grade is C"<<endl<<"CGPA="<<gpa<<endl;
	}
	else{
		cout<<"Sorry,Your GPA is "<<gpa<<endl;
	}
	
	cout<<"Total Credit Hours = "<<totalcrdthr<<endl;
	
}




int main(){
	float mark;
	int n;
	
	cout<<":------------------------------------------------------------:"<<endl;
	cout<<" Note:Each subject has total of 100 marks and 4 credit hours :"<<endl;
	cout<<":------------------------------------------------------------:"<<endl<<endl<<endl;
	
	cout<<"Enter the total subjects:";
	cin>>n;
	
	getCGPA(n);
	
	return 0;
}