#include <iostream>
#include <cstring>
using namespace std;

int account_num = 1;
void open_account(int);

class BankAccount{
	public:
	string name;
	int acct;
	string phone;
	double balance;
	double rate = 5.5;
	
	void get_name(){
		cout << "account name: ";
		cin >> name;
	}
	
	void get_acct(){
		acct = account_num;
		account_num++;
	}
	
	void get_phone(){
		cout << "Phone number: ";
		cin >> phone;
	}
	
	void get_balance(){
		cout << "Starting Balance: ";
		cin >> balance;
	}
	
	void deposit(){
		double d;
		cout << "Deposit amount: ";
		cin >> d;
		balance+=d;
	}
	
	void info(){
		cout << "Account name: " << name << endl;
		cout << "Account number: " << acct << endl;
		cout << "Phone: " << phone << endl;
		cout << "Balance: $" << balance << endl;
		cout << "Interest rate: " << rate << endl << endl;
	}
	

	BankAccount(){
		get_name();
		get_acct();
		get_phone();
		get_balance();
	}
};
class Savings: public BankAccount{
	public:
	void withdrawal(){
		double w;
		cout << "How much would you like to withdrawal?: ";
		cin >> w;
		if (w>1000){
			cout << "Withdrawal limit is $1000. \n";
		}
		else {
			balance-=w;
			if (balance<=10){
				cout << "WARNING - below minimum balance of $10. \n";
			}
		}	
	}
	
		void choose(){
	char a;
	bool valid;
	while (!valid){
		cout << "What would you like to do?: ";
		cin >> a;
		if ((a=='w')||(a=='W')){
			withdrawal();
		} 
		else if ((a=='d')||(a=='D')){
			deposit();
		}
		else if ((a=='o')||(a=='O')){
			open_account(account_num);
		}
		else if ((a=='p')||(a=='P')){
			info();
		}
		else if ((a=='b')||(a=='B')){
			valid = true;
		}
		else {cout << "invalid entry - ";}
	}
}
};
class Checking: public BankAccount{
	public:
	void withdrawal(){
		double w;
		cout << "How much would you like to withdrawal?: ";
		cin >> w;
		if (w>balance){
			cout << "Overdrafted; an additional $25 has been "
				 << "$25 has been charged to your account";
			balance-=(w+25);
		}
		else {
			balance-=w;
		}	
	}
	
	void choose(){
		char a;
		bool valid = false;
		while(!valid){
			cout << "What would you like to do?: ";
			cin >> a;
			if ((a=='w')||(a=='W')){
				withdrawal();
			} 
			else if ((a=='d')||(a=='D')){
				deposit();
			}
			else if ((a=='o')||(a=='O')){
				open_account(account_num);
			}
			else if ((a=='p')||(a=='P')){
				info();
			}
			else if ((a=='b')||(a=='B')){
				valid = true;
			}
			else {cout << "invalid entry - ";}
		}
	}
};

void menu();
void action (Checking, Savings);

int main(){
	cout << "Checking: " << endl;
	Checking c;
	cout << "Savings: " << endl;
	Savings s;
	while (true){
		menu();
		cout << "Checking or Savings?: ";
		action(c, s);
		
	}
	return 0;
}

void menu(){
	cout << "Withdraw (w): " << endl	
		 << "Deposit (d): " << endl
		 << "Open account (o): " << endl
		 << "Print account info (p): " << endl 
		 << "Back (b): " << endl << endl;
}

void open_account(int num){
	char a;
	bool valid = false;
	while (!valid){
		cout << "Checking (c) or savings (s)?: ";
		cin >> a;
		if ((a=='s')||(a=='S')){
			Savings s;
			valid = true;
		}
		else if ((a=='c')||(a=='C')){
			Checking c;
			valid = true;
		}
		else {cout << "invalid entry -";}
	}
}

void action (Checking a, Savings b){
	char x;
	cin >> x;
	if((x=='c')||(x=='C')){
		a.choose();
	}
	else if ((x=='s')||(x=='S')){
		b.choose();
	}
}


















