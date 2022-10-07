#include <stdio.h>

#include "Server.h"
#include "Card.h"

extern Card card;

DataBase Server={150000,1234};

DataBase_Transaction Transaction;

extern int TransactionAmount;

void RecieveTransactionData(void)
{
	Transaction.Transaction_Amount=TransactionAmount;
	printf("Enter PAN: ");
	scanf ("%d",&Transaction.PAN);
	printf("Enter PIN: ");
	scanf ("%d",&Transaction.PIN);
}

int IsValidAccount()
{
	if (Server.Password == Transaction.PIN && card.CardPAN== Transaction.PAN)
		return 1;
	else
		return 0;
}

int IsAmountAvailable()
{
	if (Transaction.Transaction_Amount <= Server.Account_Amount )
		return 1;
	else
		return 0;
}

void saveTransaction()
{
	Server.Account_Amount-=Transaction.Transaction_Amount;
}