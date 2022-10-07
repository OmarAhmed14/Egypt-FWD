#include <stdio.h>
#include "Terminal.h"
#include "Card.h"

extern Card card; /*in Card File*/

int TransactionDate[2];

int MaxAmount,TransactionAmount;

int* GetTransactionDate(void)
{
	printf ("Enter Transaction Date:\n");
	printf ("First, Enter Year: ");
	scanf ("%d",&TransactionDate[0]);
	printf ("First, Enter Month: ");
	scanf ("%d",&TransactionDate[1]);

	return TransactionDate;
}

int IsCardExpried(int* TransactionDate)
{
	if (card.ExpiryDate[0]>TransactionDate[0]) //2025>2022    
		return 0;
	else if (card.ExpiryDate[0]==TransactionDate[0] && (card.ExpiryDate[1]>TransactionDate[1]))
		return 0;
	else
		return 1;
}

void GetTransactionAmount(void)
{
	printf("Enter Transaction Amount: ");
	scanf ("%d",&TransactionAmount);
}

void SetMaxAmount()
{
	MaxAmount=25000;
}

int IsBelowMaxAmount()
{
	if (TransactionAmount>MaxAmount)
		return 0;
	else 
		return 1;
}



