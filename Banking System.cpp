#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int yes=1, choice;
char cpass[100];

///convert
char nine[10][20]= {"ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
char teen[10][20]= {"TEN","ELEVEN","TWELVE","THIRTEEN","FOURTEEN","FIFTEEN","SIXTEEN","SEVENTEEN","EIGHTEEN","NINETEEN"};
char ty[8][20]= {"TWENTY","THIRTY","FORTY","FIFTY","SIXTY","SEVENTY","EIGHTY","NINETY"};

int top=-1,stack[100];

///



FILE *fp;
struct info
{

    char name[30];
    char address[30];
    char acc[30];
    char date[15];
    char bdt[15];
    char nid[30];
    char phone[20];
    int age;
    double balance;
    struct info *next;

};
typedef struct info node;

/// required function
void showMenu();
void create();
int home();
node *read();
void customar_list(node *head);
int information(node *head);
void write(node *head);
int update(node *head);
int transactions(node *head);
int deletion(node *head);
void upper_string(char s[]);  ///for name make uppercase

///word converter
void push(int p);
int pop();
void len_2(int num);
void len_3(int num);
void len_4(int num);
void len_5(int num);
void conversion(int num);
///
void push(int p)
{
    top++;
    stack[top]=p;
}
int pop()
{
    int p;
    p=stack[top];
    top--;
    return p;
}

void showMenu()
{
    printf("\n                  \xb2\xb2  CUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM  \xb2\xb2  ");
    printf("\n                  \xb2\xb2\xb2\xb2       WELCOME TO THE MAIN MENU           \xb2\xb2\xb2\xb2 \n");
    printf("\n                              1.Create New Account");
    printf("\n                              2.Update Information of Existing Account");
    printf("\n                              3.For Transactions");
    printf("\n                              4.Check the Details of Existing Account");
    printf("\n                              5.Removing Existing Account");
    printf("\n                              6.View Customer's List");
    printf("\n                              7.Exit");
}
int information(node *head)
{
    int True;
    do
    {
        True=1;

        printf("Enter the Account number of the customer: ");
        gets(cpass);
        node *temp;
        temp=head;
        while(temp!=NULL)
        {
            if(strcmp(temp->acc,cpass) == 0)
            {
                //design
                system("cls");
                printf("Registration date is : ");
                printf("%s \n",temp->date);
                printf("The Account number is : ");
                printf("%s \n",temp->acc);
                printf("The Account holder's name is : ");
                printf("%s \n",temp->name);
                printf("The Account Birth Of Date is : ");
                printf("%s \n",temp->bdt);
                printf("The Account holder's Age is : ");
                printf("%d \n",temp->age);
                printf("The Account holder's Address is : ");
                printf("%s \n",temp->address);
                printf("The Account holder's NID is : ");
                printf("%s \n",temp->nid);
                printf("The Account holder's phone number is : ");
                printf("%s \n",temp->phone);
                printf("The Account Balance is : ");
                printf("%lf \n",temp->balance);
                printf("\n\nThe Balance in word= ");
                conversion(temp->balance);
                printf("TAKA ONLY \n");

                return home();
            }
            temp=temp->next;
        }
        printf("\n\nThe Account Is not exist !!!");
        Sleep(1500);
        system("cls");
        printf("\n\nPress 1 to try again,Press 2 to go home,Press any other key to exit");
        printf("\n\nEnter your choice= ");
        scanf("%d",&choice);
        fflush(stdin);
        if(choice==1)
        {
            system("cls");
        }
        else if(choice==2)
        {
            system("cls");
            return 2;
        }
        else
        {
            system("cls");
            printf("Made by MAHIR SHAHRIAR AWNY");
            Sleep(2000);
            exit(0);
        }
    }
    while(True==1);

}

void customar_list(node *head)
{
    node *temp;
    temp=head;
    //design
    if(head==NULL)
    {
        printf("\n\n\nCustomer list is empty !!\n\n");
    }
    else
    {
        printf("\nAccount Number \t Account Name \t Address \t Phone Number\n");
        while(temp!=NULL)
        {
            printf("\n");
            printf("  %s\t",temp->acc);
            printf("  \t%s\t",temp->name);
            printf("  \t%s\t",temp->address);
            printf("  \t%s\t",temp->phone);
            printf("\n\n");
            temp=temp->next;
        }
    }

}

node* read()
{

    node *start=NULL,*point,*temp1;

    fp=fopen("record.txt","r");

    node *temp;
    temp=new node();
    temp->next=NULL;
    char p;
    int c;
    while ( (c=fgetc(fp)) != EOF )
    {
        fscanf(fp,"%c ",&p);
        fscanf(fp,"%s ",temp->date);
        fscanf(fp,"%s ",temp->acc);
        fscanf(fp,"%s ",temp->name);
        fscanf(fp,"%s ",temp->bdt);
        fscanf(fp,"%d ",&temp->age);
        fscanf(fp,"%s ",temp->address);
        fscanf(fp,"%s ",temp->nid);
        fscanf(fp,"%s ",temp->phone);
        fscanf(fp,"%lf ",&temp->balance);

        if(start==NULL)
        {
            start=new node();
            start->next=NULL;
            strcpy(start->date,temp->date);
            strcpy(start->acc,temp->acc);
            strcpy(start->name,temp->name);
            strcpy(start->bdt,temp->bdt);
            strcpy(start->address,temp->address);
            strcpy(start->nid,temp->nid);
            strcpy(start->phone,temp->phone);
            start->age=temp->age;
            start->balance=temp->balance;

            point=start;

        }
        else
        {
            temp1=new node();
            temp1->next=NULL;
            strcpy(temp1->date,temp->date);
            strcpy(temp1->acc,temp->acc);
            strcpy(temp1->name,temp->name);
            strcpy(temp1->bdt,temp->bdt);
            strcpy(temp1->address,temp->address);
            strcpy(temp1->nid,temp->nid);
            strcpy(temp1->phone,temp->phone);
            temp1->age=temp->age;
            temp1->balance=temp->balance;

            point->next=temp1;
            point=temp1;

        }
    }
    fclose(fp);

    return start;
}
void upper_string(char s[])
{
   int c = 0;

   while (s[c] != '\0') {
      if (s[c] >= 'a' && s[c] <= 'z') {
         s[c] = s[c] - 32;
      }
      c++;
   }
}
void create()
{
    node *temp;
    temp=new node();
    temp->next=NULL;
    system("cls");

    printf("\n                      \xb2\xb2\xb2\xb2    ADD RECORD    \xb2\xb2\xb2\xb2 \n");
    fp=fopen("record.txt","a");
    fprintf(fp,". ");
    printf("\n\n");

    printf("Enter Today's Date(mm/dd/yyyy): ");
    gets(temp->date);
    fflush(stdin);
    fprintf(fp,"%s ",temp->date);
    printf("\n");

    printf("Enter the Account Number : ");
    gets(temp->acc);
    fflush(stdin);
    fprintf(fp,"%s ",temp->acc);
    printf("\n");

    printf("Enter the Name : ");
    gets(temp->name);
    fflush(stdin);
    upper_string(temp->name);  //uppercase for name
    fprintf(fp,"%s ",temp->name);
    printf("\n");

    printf("Enter the Date Of Birth(mm/dd/yyyy) : ");
    gets(temp->bdt);
    fflush(stdin);
    fprintf(fp,"%s ",temp->bdt);
    printf("\n");

    printf("Enter the Age : ");
    scanf("%d",&temp->age);
    fflush(stdin);
    fprintf(fp,"%d ",temp->age);
    printf("\n");

    printf("Enter the Address : ");
    gets(temp->address);
    fflush(stdin);
    fprintf(fp,"%s ",temp->address);
    printf("\n");

    printf("Enter the NID number : ");
    gets(temp->nid);
    fflush(stdin);
    fprintf(fp,"%s ",temp->nid);
    printf("\n");

    printf("Enter the Phone number : ");
    gets(temp->phone);
    fflush(stdin);
    fprintf(fp,"%s ",temp->phone);
    printf("\n");

    printf("Enter the amount to Deposit : BDT  : ");
    scanf("%lf",&temp->balance);
    fflush(stdin);
    fprintf(fp,"%lf",temp->balance);
    printf("\n");

    fprintf(fp,"\n\n");

    fclose(fp);
    printf("\n\nAccount created successfully!.....\n\n");

}
int home()
{
    int True;
    do
    {
        True=1;
        printf("Enter 1 to go to main menu and 0 to exit\n\n");
        int choice;
        printf("                Enter your choice : ");
        scanf("%d",&choice);
        if(choice == 1)
        {
            system("cls");
            return 2;

        }
        else if(choice==0)
        {
            system("cls");
            printf("\n\n\t\tMade by MAHIR SHAHRIAR AWNY");
            Sleep(2000);
            exit(0);
        }
        else
        {
            system("cls");
            printf("Invalid Choice !!!");
            Sleep(1000);
            system("cls");
        }
    }
    while(True==1);
}
void write(node *head)
{

    fp=fopen("record.txt","w");
    node *temp;
    temp=head;
    while(temp!=NULL)
    {
        fprintf(fp,". ");
        fprintf(fp,"%s ",temp->date);
        fprintf(fp,"%s ",temp->acc);
        fprintf(fp,"%s ",temp->name);
        fprintf(fp,"%s ",temp->bdt);
        fprintf(fp,"%d ",temp->age);
        fprintf(fp,"%s ",temp->address);
        fprintf(fp,"%s ",temp->nid);
        fprintf(fp,"%s ",temp->phone);
        fprintf(fp,"%lf ",temp->balance);
        fprintf(fp,"\n");

        temp=temp->next;
    }
    fclose(fp);

}
int update(node *head)
{
    int True;
    do
    {
        True=1;

        printf("Enter the Account number of the customer= ");
        gets(cpass);
        node *temp;
        temp=head;
        while(temp!=NULL)
        {
            if(strcmp(temp->acc,cpass) == 0)
            {
                //design
                system("cls");
                printf("What you want to update? \n1.Address\n2.phone number\nPress any other key to go home\n\nEnter your choice= ");
                scanf("%d",&choice);
                fflush(stdin);
                if(choice==1)
                {
                    system("cls");
                    printf("Enter new address : ");
                    gets(temp->address);
                    fflush(stdin);
                    write(head);
                    printf("\nAddress Update !!\n");
                }
                else if(choice==2)
                {
                    system("cls");
                    printf("Enter new phone number : ");
                    gets(temp->phone);
                    fflush(stdin);
                    write(head);
                    printf("\nPhone number Update !!\n");
                }
                else
                {
                    return 2;
                }
                return home();
            }
            temp=temp->next;
        }
        printf("\n\nThe Account Is not exist !!!");
        Sleep(1500);
        system("cls");
        printf("\n\nPress 1 to try again,Press 2 to go home,Press any other key to exit");
        printf("\n\nEnter your choice= ");
        scanf("%d",&choice);
        fflush(stdin);
        if(choice==1)
        {
            system("cls");
        }
        else if(choice==2)
        {
            system("cls");
            return 2;
        }
        else
        {
            system("cls");
            printf("Made by MAHIR SHAHRIAR AWNY");
            Sleep(2000);
            exit(0);
        }
    }
    while(True==1);

}
int transactions(node *head)
{
    int True;
    do
    {
        True=1;

        printf("Enter the Account number of the customer= ");
        gets(cpass);
        node *temp;
        temp=head;
        while(temp!=NULL)
        {
            if(strcmp(temp->acc,cpass) == 0)
            {
                //design
                system("cls");
                printf("\n\nYour Current Balance is : %lf\n\n",temp->balance);
                printf("What do you want? \n1.Deposit\n2.Withdraw\nPress any other key to go home\n\nEnter your choice : ");
                scanf("%d",&choice);
                fflush(stdin);
                if(choice==1)
                {

                    printf("\n\nEnter how much money you want to Deposit : ");
                    double x;
                    scanf("%lf",&x);
                    fflush(stdin);
                    temp->balance=temp->balance+x;
                    printf("\n\nNow your update balance is %lf BDT\n\n\n",temp->balance);
                    write(head);

                }
                else if(choice==2)
                {

                    printf("\n\nEnter how much money you want to Withdraw : ");
                    double x;
                    scanf("%lf",&x);
                    fflush(stdin);
                    temp->balance=temp->balance-x;
                    printf("\n\nNow your update balance is %lf BDT\n\n\n",temp->balance);

                    write(head);

                }
                else
                {
                    return 2;
                }
                return home();
            }
            temp=temp->next;
        }
        printf("\n\nThe Account Is not exist !!!");
        Sleep(1500);
        system("cls");
        printf("\n\nPress 1 to try again,Press 2 to go home,Press any other key to exit");
        printf("\n\nEnter your choice= ");
        scanf("%d",&choice);
        fflush(stdin);
        if(choice==1)
        {
            system("cls");
        }
        else if(choice==2)
        {
            system("cls");
            return 2;
        }
        else
        {
            system("cls");
            printf("Made by MAHIR SHAHRIAR AWNY");
            Sleep(2000);
            exit(0);
        }
    }
    while(True==1);
}
int deletion(node *head)
{
    int True;
    do
    {
        True=1;

        printf("Enter the Account number of the customer= ");
        gets(cpass);
        node *temp;
        temp=head;
        while(temp!=NULL)
        {
            if(strcmp(temp->acc,cpass) == 0)
            {
                //design
                system("cls");
                if(head->next==NULL)
                {
                    head=NULL;
                    delete(head);
                }
                else
                {
                    if(temp==head)
                    {
                        head=head->next;
                        delete(temp);
                    }
                    else
                    {
                        node *temp1;
                        temp1=head;
                        while(temp1->next!=temp)
                        {
                            temp1=temp1->next;
                        }
                        temp1->next=temp->next;
                        delete(temp);
                    }
                }
                write(head);
                printf("\nDeletion successful\n");
                return home();
            }
            temp=temp->next;
        }

        printf("\n\nThe Account Is not exist !!!");
        Sleep(1500);
        system("cls");
        printf("\n\nPress 1 to try again,Press 2 to go home,Press any other key to exit\n\n");
        printf("\n\n\t\tEnter your choice= ");
        scanf("%d",&choice);
        fflush(stdin);
        if(choice==1)
        {
            system("cls");
        }
        else if(choice==2)
        {
            system("cls");
            return 2;
        }
        else
        {
            system("cls");
            printf("Made by MAHIR SHAHRIAR AWNY");
            Sleep(2000);
            exit(0);
        }
    }
    while(True==1);

}


int main ()
{
    int yes;
    node *head=NULL;
    do
    {
        yes=1;
        char mpass[100]="csi218";

        printf("            Enter the Password to Login : ");
        gets(cpass);
        if(strcmp(mpass, cpass) == 0)
        {
            printf("\n\n\n\tPASSWORD MATCH!....\n\tLOADING!");
            for(int p=0; p<=10; p++)
            {
                printf(".");
                Sleep(500);
            }
            do
            {
                system("cls");
                yes=2;
                showMenu();
                printf("\n\n\n\n\n                          Enter choice: ");
                scanf("%d",&choice);
                fflush(stdin);
                if(choice== 1)
                {
                    system("cls");
                    create();
                    yes=home();

                }
                else if(choice==2)
                {
                    system("cls");
                    head=read();
                    yes=update(head);
                }
                else if(choice==3)
                {
                    system("cls");
                    head=read();
                    yes=transactions(head);
                }
                else if(choice==4)
                {
                    system("cls");
                    head=read();
                    yes=information(head);

                }
                else if(choice==5)
                {
                    system("cls");
                    head=read();
                    yes=deletion(head);

                }

                else if(choice==6)
                {
                    system("cls");
                    head=read();
                    customar_list(head);
                    yes=home();
                }
                else if(choice==7)
                {
                    system("cls");
                    printf("Made by MAHIR SHAHRIAR AWNY");
                    Sleep(2000);
                    exit(0);
                }
                else
                {
                    system("cls");
                    printf("Invalid Choice !!!");
                    Sleep(1000);
                    system("cls");
                }
            }
            while(yes==2);

        }
        else
        {
            printf("Wrong Password!!...\n");
            printf("Enter 1 to try again Or 0 to Exit\n");

            printf("Enter choice: ");
            scanf("%d",&choice);
            fflush(stdin);
            if(choice==1)
            {
                system("cls");

            }
            else
            {
                system("cls");
                printf("Made by MAHIR SHAHRIAR AWNY");
                Sleep(2000);
                exit(0);
            }
        }
    }
    while(yes==1);
    return 0;
}

void len_2(int num)
{
    if(num<=9)
    {
        printf("%s ",nine[num-1]);
    }
    else
    {
        int n;
        n=num;
        while(n!=0)
        {
            int p;
            p=n%10;
            push(p);
            n=n/10;
        }
        int x,y;
        x=pop();
        y=pop();
        if(x==1)
        {
            printf("%s ",teen[y]);
        }
        else
        {
            printf("%s ",ty[x-2]);
            printf("%s ",nine[y-1]);
        }
    }
}
void len_3(int num)
{
    int n;
    n=num;
    while(n!=0)
    {
        int p;
        p=n%10;
        push(p);
        n=n/10;
    }
    int x,y=0;
    x=pop();
    printf("%s ",nine[x-1]);
    if(x>=1)
    {
        printf("HUDRED ");
    }
    x=pop();
    y=y*10+x;
    x=pop();
    y=y*10+x;
    len_2(y);
}
void len_4(int num)
{
    int n;
    n=num;
    while(n!=0)
    {
        int p;
        p=n%10;
        push(p);
        n=n/10;
    }
    int x,y=0;
    x=pop();
    printf("%s ",nine[x-1]);
    if(x>=1)
    {
        printf("THOUSND ");
    }
    x=pop();
    y=y*10+x;
    x=pop();
    y=y*10+x;
    x=pop();
    y=y*10+x;
    if(y<=99)
    {
        len_2(y);
    }
    else
    {
        len_3(y);
    }
}
void len_5(int num)
{
    int n;
    n=num;
    while(n!=0)
    {
        int p;
        p=n%10;
        push(p);
        n=n/10;
    }
    int x,y=0,z=0;
    x=pop();
    z=z*10+x;
    x=pop();
    z=z*10+x;
    len_2(z);
    if(z>=1)
    {
        printf("THOUSND ");
    }
    x=pop();
    y=y*10+x;
    x=pop();
    y=y*10+x;
    x=pop();
    y=y*10+x;
    if(y<=99)
    {
        len_2(y);
    }
    else
    {
        len_3(y);
    }
}
void conversion(int num)
{
    int n,len=0;
    n=num;
    while(n!=0)
    {
        n=n/10;
        len++;
    }
    if(num==0)
    {
        printf("ZERO ");
    }
    else if(len<=2)
    {
        len_2(num);
    }
    else if(len==3)
    {
        len_3(num);
    }
    else if(len==4)
    {
        len_4(num);
    }
    else if(len==5)
    {
        len_5(num);
    }
}






