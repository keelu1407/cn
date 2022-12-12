//ip adderss

#include<iostream>
using namespace std;

class IpAddress{
	private:
		string ip;
		int arr[4];
	public:
		IpAddress(){
			ip="";
		}
		void enter(){
			char c;
			int flag=0,count=0;
			do{
				c=' ';
				cout<<"\n\tEnter Ip Address:";
			 	cin>>ip;
			 	if(checkDots()&&checkNums());
			 	else {cout<<"\n\tInvalid Input. Please input again\n\n\tPress y to input again!";
			 	cin>>c;
				 }
			}while(c=='y'||c=='Y');
			
		}
		bool checkDots(){int count=0;
			for(int i=0;i<ip.length();i++){
			 	if(ip[i]=='.'){count++;
				}}
				if(count!=3)
				return false;
				else return true;
		}
		bool checkNums(){bool flag=false;
			if(checkDots()){
				int i=0;
				flag=true;
				for(int j=0;j<4;j++){
					arr[j]=0;
				}
				for(int j=0;j<4;j++){
					do{if(ip[i]=='.')i++;
						arr[j]=(arr[j]*10+ip[i])-'0';i++;
						if(arr[j]>255||arr[j]<0) flag=false;
					}while(ip[i]!='.'&&flag&&i<ip.length());if(ip[i]=='.')i++;
				}
			}return flag;
		}
		char Class(){
			int n=arr[0];char c;
			if(n>=0&&n<=127)
				c='A';
			else if(n>=128&&n<=191)
				c='B';
			else if(n>=192&&n<=223)
				c='C';
			else if(n>=224&&n<=239)
				c='D';
			else c='E';
			return c;
		}
		void details(){
			char c=Class();
			switch(c){
				case 'A':{
					cout<<"\n\tClass: A";
					cout<<"\n\tHost Id : "<<arr[1]<<"."<<arr[2]<<"."<<arr[3];
					cout<<"\n\tNetwork Address : "<<arr[0]<<".0.0.0";
					cout<<"\n\tBroadcast Address : "<<arr[0]<<".255.255.255";
					break;
				}
				case 'B':{
					cout<<"\n\tClass: B";
					cout<<"\n\tHost Id : "<<arr[2]<<"."<<arr[3];
					cout<<"\n\tNetwork Address : "<<arr[0]<<"."<<arr[1]<<".0.0";
					cout<<"\n\tBroadcast Address : "<<arr[0]<<"."<<arr[1]<<".255.255";
					break;
				}
				case 'C':{
					cout<<"\n\tClass: C";
					cout<<"\n\tHost Id : "<<arr[3];
					cout<<"\n\tNetwork Address : "<<arr[0]<<"."<<arr[1]<<"."<<arr[2]<<".0";
					cout<<"\n\tBroadcast Address : "<<arr[0]<<"."<<arr[1]<<"."<<arr[2]<<".255";
					break;
				}
				case 'D':{
					cout<<"\n\tClass: D";
					break;
				}
				case 'E':{
					cout<<"\n\tClass: E";
					break;
				}
			}
		}
		
};
int main(){
	IpAddress ob;
	ob.enter();
	ob.details();
}
