#ifndef CARD_H_
#define CARD_H_

typedef struct card_s
{
	char Name[50];
	int ExpiryDate[2];
	unsigned long int CardPAN;
}Card;

void GetCardHolderName(void);

void GetCardExpiryDate(void);

void GetCardPAN(void);

#endif
