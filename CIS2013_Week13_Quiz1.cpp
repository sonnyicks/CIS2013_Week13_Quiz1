#include <iostream>
#include <cstring>
using namespace std;

class BankAccount{
	public:
	string name;
	int acct_number;
	long phone;
	double balance;
	double rate;
	double deposit(double, double);
	double withdraw(double, double);
	
	BankAccount(){
		string set_name();
		long set_phone();
		int set_account();
	}
	string set_name(){
		cout << "account name: ";
		cin >> name;
		return name;
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


int main(){
	menu();
	
	
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
	cout << "What would you like to do?: ";
	cin >> pick;
	if (pick == 'o'){}
	
}

// void open_account














