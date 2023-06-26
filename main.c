#include <stdio.h>  //printf(),scanf()
#include <stdlib.h> //exit(0),system()
#include <conio.h>  //getch()
#include <time.h>   //time(),ctime()

char name[20];
int dip_amt, amt = 10000, acc_no, ac, count = 0; // Global variables
int trans_amt;
int with_amt;

void deposit_money();
void withdraw_money();
void transfer_money();
void account_detail();
void last_details();
void transaction_detail();
void menu();

void divider()
{
  for (int i = 0; i < 50; i++)
  {
    printf("-");
  }
}

int main()
{
  FILE *ptr = fopen("Account.txt", "w");
  int ch;
  printf("Enter your name: ");
  gets(name);
  fprintf(ptr, "\nName : %s\n", name);
  printf("Enter your account No.: ");
  scanf("%d", &acc_no);
  fprintf(ptr, "Account No.: %d\n", acc_no);
  fclose(ptr);

  while (1)
  {

    menu();
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      system("cls");
      deposit_money();
      break;
    case 2:
      system("cls");
      withdraw_money();
      break;
    case 3:
      system("cls");
      transfer_money();
      break;
    case 4:
      system("cls");
      account_detail();
      break;
    case 5:
      transaction_detail();
      break;
    case 6:
      system("cls");
      last_details();
      exit(0);
    default:
      printf("INVALID CHOICE!!!");
      break;
    }
  }

  return 0;
}

void menu()
{
  system("cls");
  divider();
  printf("\nMAIN MENU\n");
  divider();
  printf("\n1. Deposit Money\n");
  printf("2. Withdraw Money\n");
  printf("3. Transfer Money\n");
  printf("4. Account Details\n");
  printf("5. Transaction Details\n");
  printf("6. Exit\n");
  divider();
}

void deposit_money()
{
  time_t tm;
  time(&tm);
  FILE *ptr = fopen("Account.txt", "a");

  divider();
  printf("\nDepositing money\n");
  divider();

  printf("\nEnter the amount you want to deposit: ");
  scanf("%d", &dip_amt);
  amt += dip_amt;
  printf("Money deposited\n");
  printf("Current balance: %d$\n", amt);
  fprintf(ptr, "%d$ had been deposited to your account \n", dip_amt);
  fprintf(ptr, "Date/time of transaction: %s\n", ctime(&tm));
  count++;

  fclose(ptr);
  printf("Press any key....\n");
  getch();
}

void withdraw_money()
{
  time_t tm;
  time(&tm);
  FILE *ptr = fopen("Account.txt", "a");
  divider();
  printf("\nWithdraw money\n");
  divider();

  printf("\nEnter the amount you want to withdraw: ");
  scanf("%d", &with_amt);
  if (amt < with_amt)
  {
    printf("INSUFFICIENT BALANCE!!!\n");
  }
  else
  {
    amt = amt - with_amt;
    printf("Money withdrawn!\n");
    printf("Current balance: %d\n", amt);
    fprintf(ptr, "\n%d$ had been withdrawn from your account \n", with_amt);
    fprintf(ptr, "Date/Time of transaction: %s\n", ctime(&tm));
    count++;
  }
  fclose(ptr);
  printf("Press any key....\n");
  getch();
}

void transfer_money()
{
  time_t tm;
  time(&tm);
  FILE *ptr = fopen("Account.txt", "a");
  divider();
  printf("\nTransferring Money\n");
  divider();

  printf("\nEnter the account No. in which you want to transfer the money: ");
  scanf("%d", &ac);
  printf("\nEnter the amount you want to transfer: ");
  scanf("%d", &trans_amt);

  if (amt < trans_amt)
  {
    printf("YOU HAVE NOT SUFFICIENT BALANCE!!!\n");
  }
  else
  {
    amt = amt - trans_amt;
    printf("Money transferred\n");
    printf("Current balance: %d\n", amt);
    fprintf(ptr, "\n%d$ had been transferred from your account to Account No. %d.\n", trans_amt, ac);
    fprintf(ptr, "Date/Time of transaction:  %s\n", ctime(&tm));
    count++;
  }

  fclose(ptr);
  printf("Press any key....\n");
  getch();
}

void account_detail()
{
  divider();
  printf("\nAccount Details\n");
  divider();

  printf("\nName: %s\n", name);
  printf("Account No.: %d\n", acc_no);
  printf("Total balance = %d\n ", amt);
  printf("\n%d transactions have been made from your account. \n", count);
  printf("Press any key.....");
  getch();
}

void transaction_detail()
{
  system("cls");
  FILE *ptr;
  ptr = fopen("Account.txt", "r");
  char c = fgetc(ptr);
  if (c == EOF)
  {
    divider();
    printf("\nTransaction Details\n");
    divider();
    printf("\nNO RECENT TRANSACTION\n");
  }
  else
  {
    divider();
    printf("\nTransaction Details\n");
    divider();
    printf("\n%d transactions have been made from your account. \n", count);
    while (c != EOF) // EOF=End of file
    {
      printf("%c", c);
      c = fgetc(ptr);
    }
  }

  getch();
}

void last_details()
{
  divider();
  printf("\nAccount Details\n");
  divider();

  printf("\nName: %s\n", name);
  printf("Account No.: %d\n", acc_no);
  printf("Total balance = %d\n", amt);

  printf("\n\nPress any key to exit.....\n");
  getch();
}