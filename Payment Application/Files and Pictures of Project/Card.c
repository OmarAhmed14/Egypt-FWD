#include <stdio.h>

#include "Card.h"

Card card;

void GetCardHolderName(void)
{
	printf("Enter Card Holder Name: ");
	gets(card.Name);
}

void GetCardExpiryDate(void)
{
	printf("Enter Card Expiry Date:\n");

	printf("First, Enter Year: ");
	scanf("%d",&card.ExpiryDate[0]);

	printf("Second, Enter Month: ");
	scanf("%d",&card.ExpiryDate[1]);
}

void GetCardPAN(void)
{
	printf("Enter Card PAN: ");
	scanf("%lu",&card.CardPAN);
}