// accounts.h
#ifndef ACCOUNTS_H
#define ACCOUNTS_H
#define MAX_NAME_CHAR 50
#define MAX_PIN_NUM 4

typedef struct {
    int acountNum;
    char name[MAX_NAME_CHAR];
    int pin[MAX_PIN_NUM];
    float money;
} Accounts;

void clearBuffer(void);
int pinComfirm(int masterPin[]);
int accComfirm(Accounts *listOfUsers, int size);
#endif
