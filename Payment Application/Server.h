#ifndef SERVER_H_
#define SERVER_H_

typedef struct Server
{
	int Account_Amount;
	int Password;
}DataBase;

typedef struct Transaction
{
	unsigned long int PAN;
	int Transaction_Amount;
	int PIN;
}DataBase_Transaction;

void RecieveTransactionData(void);

int IsValidAccount();

int IsAmountAvailable();

void saveTransaction();

#endif