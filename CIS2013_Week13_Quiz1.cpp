#include <iostream>
#include <cstring>
using namespace std;

class BankAccount{
	public:
	string name;
	string acct_number;
	string phone;
	double balance;
	double rate = 5.50;
	
	double deposit(){
	double d;
	cout << "How much would you like to deposit?: ";
	cin >> d;
	balance+=d;
	print();
}
	double withdraw(){
	double w;
	cout << "How much would you like to withdrawal?: ";
	cin >> w;
	if (w>balance){
		cout << "You have overdrawn. \n";
	}
	else {balance-=w;}
	print();
}

	void choice(){
	char pick;
	bool invalid = true;
	while (invalid){
		cout << "What would you like to do?: ";
		cin >> pick;
		if (pick == 'w'){
			withdraw();
			invalid = false;
		}
		else if (pick=='d'){
			deposit();
			invalid = false;
		}
		else if (pick=='t'){
			print();
			invalid = false;
		}	
		else {cout << "invalid entry - choose another.";
		}
	}
}
	void print(){
	cout << "Name: " << name << endl
		 << "Account number: " << acct_number << endl
		 << "Phone number: " << phone << endl
		 << "Balance: $" << balance << endl
		 << "Interest Rate:" << rate << endl << endl; 
}
	
	BankAccount(){
		set_name();
		set_phone();
		set_account();
		set_balance();
		print();
	}
	string set_name(){
		cout << "account name: ";
		cin >> name;
		return name;
	}
	string set_phone(){
		cout << "Account phone number: ";
		cin >> phone;
		return phone;
	}
	string set_account(){
		cout << "Account number: ";
		cin >> acct_number;
		return acct_number;
	}
	double set_balance(){
		cout << "Starting balance: ";
		cin >> balance;
		return balance;
	}
	
};

class Savings: public BankAccount{
	public:
	double minimum_balance = 10.00;
	
	double withdrawal(){
		double w;
		if (w<=1000){
			balance-=w;
			if (balance<10){cout << "Warning, account below minimal balance.";}
		}
		else {cout << "Withdrawal amount too high; transaction cancelled.";}
	}
	
	void header(){
		cout << "Savings: \n";
	}
	
	void choice(){
	char pick;
	bool invalid = true;
	while (invalid){
		cout << "What would you like to do?: ";
		cin >> pick;
		if (pick == 'w'){
			withdraw();
			invalid = false;
		}
		else if (pick=='d'){
			deposit();
			invalid = false;
		}
		else if (pick=='t'){
			print();
			invalid = false;
		}	
		else {cout << "invalid entry - choose another.";
		}
	}
}
	Savings(){
		void header();
	}
};
class Checking: public BankAccount{
	public:
	double overdraft_fee = 25.00;
	
	double withdraw(){
	double w;
	cout << "How much would you like to withdrawal?: ";
	cin >> w;
	if (w>balance){
		cout << "You have overdrawn.";
		balance-=(w+25);
	}
	else {balance-=w;}
	print();
	}
	
	void header(){
		cout << "Checking: \n";
		}
	
	void choice(){
	char pick;
	bool invalid = true;
	while (invalid){
		cout << "What would you like to do?: ";
		cin >> pick;
		if (pick == 'w'){
			withdraw();
			invalid = false;
		}
		else if (pick=='d'){
			deposit();
			invalid = false;
		}
		else if (pick=='t'){
			print();
			invalid = false;
		}	
		else {cout << "invalid entry - choose another.";
		}
	}
}
	Checking(){
		void header();
	}
};

void menu();
void open_account();
char account_count = 0;
Checking a;
Savings b;
char c_or_s;


int main(){
	menu();
	open_account();
	while(true){
		cout << "checking or savings (c/s): ";
		cin >> c_or_s;
		if ((c_or_s=='c')||(c_or_s=='C')){a.choice();}
		if ((c_or_s=='s')||(c_or_s=='S')){b.choice();}
	}

	
	return 0;
}

void menu(){
	cout << "Open New Bank Account (o): " << endl
		 << "Deposit money (d): " << endl
		 << "Withdrawal money (w): " << endl
		 << "Print totals: (t): " << endl;
}


void open_account(){
	char a;
	char b;
	cout << "Would you like to open a new account (y/n)?: ";
	cin >> a;
	if ((a=='y')||(a=='Y')){
		cout << "What type of account do you want to open? \n"
		 << "Savings (s) or Checking (c): ";
		cin >> b;
		if (b=='c'){
			Checking mine;
			mine.print();
		}
		else if (b=='s'){
			Savings mine;
			mine.print();
		}
	}
}


















