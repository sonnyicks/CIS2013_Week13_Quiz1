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
	double deposit();
	double withdraw();
	void print();
	
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
	double minimum_balance = 0.00;
	double withdrawal_limit = 0.00;
};
class Checking: public BankAccount{
	double overdraft_fee = 0.00;
};

void menu();
void choice();
void open_account();

Checking mine;

int main(){
	menu();
	while(true){
		choice();
	}

	
	return 0;
}

void menu(){
	cout << "Open New Bank Account (o): " << endl
		 << "Deposit money (d): " << endl
		 << "Withdrawal money (w): " << endl
		 << "Print totals: (t): " << endl;
}
void choice(){
	char pick;
	bool invalid = true;
	while (invalid){
		cout << "What would you like to do?: ";
		cin >> pick;
		if (pick == 'w'){
			mine.withdraw();
			invalid = false;
		}
		else if (pick=='d'){
			mine.deposit();
			invalid = false;
		}
		else if (pick=='t'){
			mine.print();
			invalid = false;
		}	
		else if (pick=='o'){
			open_account();
			invalid = false;
		}
		else {cout << "invalid entry - choose another.";
		}
	}
}

void open_account(){
	char a;
	cout << "What type of account do you want to open? \n"
		 << "Savings (s) or Checking (c): ";
	cin >> a;
	if (a=='c'){
		Checking b;
	}
	else if (a=='s'){
		Savings a;
	}
}

double BankAccount::withdraw(){
	double w;
	cout << "How much would you like to withdrawal?: ";
	cin >> w;
	if (w>balance){
		cout << "You have overdrawn.";
	}
	else {balance-=w;}
	print();
}

double BankAccount::deposit(){
	double d;
	cout << "How much would you like to deposit?: ";
	cin >> d;
	balance+=d;
	print();
}

void BankAccount::print(){
	cout << "Name: " << name << endl
		 << "Account number: " << acct_number << endl
		 << "Phone number: " << phone << endl
		 << "Balance: $" << balance << endl
		 << "Interest Rate:" << rate << endl << endl; 
}












