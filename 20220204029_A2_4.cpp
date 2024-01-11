#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include<stdlib.h>

char dateString[20];

typedef struct AccountInformation
{
    char name[50];
    char pass[50];
    int AccNo;
    double bal;
    char date[20];
} AccInfo;

AccInfo info;

bool checkAccNo(int i);
void openAccount();
bool check();
void deposit();
void withdraw();
void accountDetails();
void adminLogin();

int main()
{
    int choice;

    while (1)
    {
        printf("\nBanking System Menu:\n");
        printf("1. Open an Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. View Account Details\n");
        printf("5. Admin login to show all details\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        system("cls");

        if (choice == 0)
            break;

        switch (choice)
        {
        case 1:
            time_t rawtime;
            struct tm *timeinfo;
            time(&rawtime);
            timeinfo = localtime(&rawtime);
            strftime(dateString, sizeof(dateString), "%Y-%m-%d", timeinfo);
            openAccount();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            accountDetails();
            break;
        case 5:
            adminLogin();
            break;
        default:
            printf("!!Wrong press!!");
        }
    }

    return 0;
}
bool checkAccNo(int i)
{
    FILE *fptr = fopen("20220204029_A2_4.txt", "rb");

    while (fread(&info, sizeof(info), 1, fptr) > 0 )
    {
        if (info.AccNo == i)
        {
            fclose(fptr);
            return true;
        }
    }

    fclose(fptr);
    return false;
}

void openAccount()
{
    static int i=100001;
    FILE *fptr = fopen("20220204029_A2_4.txt", "ab");
    while(checkAccNo(i))
    {
        i++;
    }


    printf("Enter your name: ");
    scanf("%s", info.name);
    getchar();
    printf("Enter your password: ");
    scanf("%s", info.pass);
    strcpy(info.date, dateString);
    info.AccNo = i;
    info.bal = 0.0;

    fwrite(&info, sizeof(info), 1, fptr);

    printf("Account Opened Successfully\nYour Account No is: %d\n", info.AccNo);

    fclose(fptr);
}

bool check()
{
    FILE *fptr = fopen("20220204029_A2_4.txt", "rb");
    int a;
    char p[50];
    printf("Enter your Account Number: ");
    scanf("%d", &a);
    printf("Enter your Password: ");
    scanf("%s", p);

    while (fread(&info, sizeof(info), 1, fptr) > 0)
    {
        if (info.AccNo == a && strcmp(info.pass, p) == 0)
        {
            fclose(fptr);
            return true;
        }
    }

    fclose(fptr);
    return false;
}

void deposit()
{
    double amount;
    if (check())
    {
        printf("Log in successfully!!!\nEnter the amount: ");
        scanf("%lf", &amount);
        info.bal += amount;
        FILE *fptr = fopen("20220204029_A2_4.txt", "wb+");
        fseek(fptr, -sizeof(info), SEEK_CUR);
        fwrite(&info, sizeof(info), 1, fptr);
        fclose(fptr);
        printf("Updated Balance: %lf\n", info.bal);
    }
    else
        printf("Wrong Information!!\n");
}

void withdraw()
{
    double amount;
    if (check())
    {
        printf("Log in successfully!!!\nEnter the amount: ");
        scanf("%lf", &amount);

        if (info.bal>=300)
        {
            info.bal -= amount;
            FILE *fptr = fopen("20220204029_A2_4.txt", "wb+");
            fseek(fptr, -sizeof(info), SEEK_CUR);
            fwrite(&info, sizeof(info), 1, fptr);
            fclose(fptr);
            printf("Updated Balance: %lf\n", info.bal);
        }
        else
        {
            printf("Insufficient balance!\n");
        }
    }
    else
    {
        printf("Wrong Information!!\n");
    }
}

void accountDetails()
{
    if (check())
    {
        printf("Your Account Details:\n");
        printf("Name: %s\n", info.name);
        printf("Account no: %d\n", info.AccNo);
        printf("Balance: %lf\n", info.bal);
        printf("Password: %s\n", info.pass);
        printf("Account opening Date: %s\n",info.date);
    }
    else
    {
        printf("Wrong Information!!\n");
    }
}

void adminLogin()
{
    char pass[20];
    printf("Enter your Password to Show All details: ");
    scanf("%s", pass);

    if (strcmp(pass, "1234r") == 0)
    {
        FILE *file = fopen("20220204029_A2_4.txt", "rb");
        printf("\nALL Account Information:\n\n");


        while (fread(&info, sizeof(info), 1, file) > 0)
        {
            printf("Account no: %d   Name: %s    Balance: %lf   Password: %s    Opening date: %s\n", info.AccNo,info.name,info.bal,info.pass,info.date);
        }

        fclose(file);
    }
    else
    {
        printf("Incorrect password for Admin login.\n");
    }
}
