#include <stdio.h>
#include <stdlib.h>
#include "AppLication.h"
#include "Card.h"
#include "Terminal.h"
#include "Server.h"

extern Card card;
extern DataBase Server;

//extern int TransactionDate[2];

void AppStart()
{
	/*Card*/
	GetCardHolderName();
	GetCardExpiryDate();
 	GetCardPAN();

 	/*Terminal*/
	int* TransactionDate =GetTransactionDate();

	if (!IsCardExpried(TransactionDate))
	{
		GetTransactionAmount();
		SetMaxAmount();

		if (IsBelowMaxAmount())
		{
			/*Server*/
			RecieveTransactionData();

			if (IsValidAccount())
			{
				if(IsAmountAvailable())
				{
					saveTransaction();
					printf ("Done There is in Your Account now %d LE",Server.Account_Amount);
				}
				else
				{
					printf("\nInsuffecient fund\n");
					exit(0);
				}
			}
			else
			{
				printf("\nNot Valid Account\n");
				exit(0);
			}
		}
		else
		{
			printf("\nAmount Exceeding Limit\n");
			exit(0);
		}
	}
	else
	{
		printf("\nExpired Card\n");
		exit(0);
	}

}