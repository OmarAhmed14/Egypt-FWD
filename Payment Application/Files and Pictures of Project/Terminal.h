#ifndef TERMINAL_H_
#define TERMINAL_H_


int* GetTransactionDate(void);

int IsCardExpried(int* TransactionDate);

void GetTransactionAmount(void);

int IsBelowMaxAmount(void);

void SetMaxAmount(void);

#endif