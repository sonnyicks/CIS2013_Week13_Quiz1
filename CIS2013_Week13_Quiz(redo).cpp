#include <iostream>
#include <cstring>
using namespace std;

int account_num = 1;

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
		cout << "Balance: " << balance << endl;
		cout << "Interest rate: " << rate << endl;
	}
	BankAccount(){
		get_name();
		get_acct();
		get_phone();
		get_balance();
		info();
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
};

void open_account(int);
int main(){
	open_account(account_num);
	return 0;
}

void menu(){
	cout << "Withdraw (w): " << endl	
		 << "Deposit (d): " << endl
		 << "Open account (o): " << endl
		 << "Print account info (p): " << endl;
}

void open_account(int num){
	char a;
	cout << "Checking (c) or savings (s)?: ";
	cin >> a;
	if ((a=='c')||(a=='C')){
		Savings s[num];
	}
}