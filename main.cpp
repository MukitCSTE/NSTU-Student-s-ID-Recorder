/******************************************

  Application: Record Entry System
  Compiled on: Borland Turbo C++ 4.0
  Programmer: Md.Mukit khan/NSTU_CSTE7th
  Organization: MEU-Lab

******************************************/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>
#include <dos.h>
#include <ctype.h>


void dataentry(void);
void selectAdminOption(void);
void getData(int option);
int showAdminMenu;

void main()
{
  int cancelOption,timeOption,entryOption,exitOption;
	char choice[1];
	char selectOption[1];


	textcolor(YELLOW);
	cancelOption=0;

	/* Shows the main menu for the application*/
        while (cancelOption==0)
	{
		clrscr();

       	textcolor(YELLOW);

		gotoxy(25,2);
		textcolor(YELLOW);
		printf("NOAKHALI SCIENCE & TECHNOLOGY UNIVERSITY");
		gotoxy(8,3);
	    printf("DEPARTMENT OF COMPUTER SCIENCE & TELECECOMMUNICATION ENGINEERING");

		gotoxy(30,10);
		printf("Daily Time Record [1] ");
		gotoxy(30,11);
		printf("Enter Student Informtion [2] ");
		gotoxy(30,12);
		printf("Close             [3] ");
		gotoxy(30,15);
		printf("Please Enter Your Choice (1/2/3): ");
		scanf("%s",&choice);
		timeOption=strcmp(choice,"1");
		entryOption=strcmp(choice,"2");
		exitOption=strcmp(choice,"3");




		if (timeOption==0)
		{
		clrscr();
		gotoxy(23,6);
		printf("NOAKHALI SCIENCE & TECHNOLOGY UNIVERSITY");
		gotoxy(23,8);
		printf("Student's log information");
		gotoxy(16,24);
		printf("Input Any Other key to Return to Previous Screen.");
		gotoxy(31,10);
		printf("[1] ID Log In ");
		gotoxy(31,11);
		printf("[2] ID  Log Out");
		gotoxy(28,12);
		printf("Please Enter Your Option: ");
		scanf("%s",&selectOption);
		if (strcmp(selectOption,"1")==0)
		{
		   getData(5);
		}
		if (strcmp(selectOption,"2")==0)
		{
		   getData(6);
		}
		cancelOption=0;
		}
		if (entryOption==0)
		{
		dataentry();
		cancelOption=0;
		}
		if (exitOption==0)
		{
		cancelOption=1;
		}

		if (!(timeOption==0 || entryOption==0 || exitOption==0))
		{
                   gotoxy(10,17);
		   printf("You Have Entered an Invalid Option. Please Choose Either 1, 2 or 3. ");
		   getch();
		   cancelOption=0;
		}

	}
	clrscr();
	gotoxy(25,11);
	printf("       ~~~~~ MEU-LAB ~~~~~~");

	gotoxy(23,13);
	printf("The Application will Close Now. Thanks!");
	getch();
}

/* This function only allowed to administrator user.*/
void dataentry(void)
{

char adminName[10], passwd[5],buffer[1];
char t[6],sel[1];
int validUserNameOption,validUserPwdOption,returnOption,UserName,inc,tmp;
char plus;
	clrscr();
	validUserNameOption=0;
	validUserPwdOption=0;
	while (validUserPwdOption==0)
	{
		clrscr();
		while (validUserNameOption==0)
		{
			clrscr();
			gotoxy(20,5);
			printf("STUDENT'S IDENTITY ENTRY SYSTEM-ADMIN INTERFACE");
			gotoxy(20,24);
			printf("Info: Type return to go back to the main screen.");
			gotoxy(28,10);
			printf("Enter Administrator Name: ");
			scanf("%s",&adminName);
			returnOption=strcmp(adminName,"return");
			UserName=strcmp(adminName,"mukit");

			if (returnOption==0)
			{
			goto stream;
			}
			if (!(UserName==0 || returnOption==0))
			{

			gotoxy(32,11);
			printf("Administrator Name is Invalid.");
			getch();
			validUserNameOption=0;
			}
			else
			validUserNameOption=1;

		}

	gotoxy(30,11);
	printf("Enter Password: ");
	inc=0;
		while (inc<5)
	{
	 passwd[inc]=getch();
	 t[inc]=passwd[inc];
	 inc=inc+1;
	 printf("* ");
	}
	while(getch()!=13);

	if (!( t[0]=='c'&&t[1]=='s'&&t[2]=='t'&&t[3]=='e'&&t[4]=='7'))
		{
                        gotoxy(28,13);
			printf("You have Entered a Wrong Password. Please Try Again. ");
			getch();
			validUserPwdOption=0;
			validUserNameOption=0;
		}
		else
		{
			clrscr();
			gotoxy(24,11);
			textcolor(LIGHTGREEN+BLINK);
			cprintf("You Have Successfully Logged In.");
			gotoxy(24,17);
			textcolor(YELLOW);
			printf("Press Any Key to Continue.");
			validUserPwdOption=1;
			validUserNameOption=1;
			getch();
			showAdminMenu=0;

		     while (showAdminMenu==0)
		     {
			clrscr();
			gotoxy(24,4);
			printf("ADMIN OPTIONS");
			gotoxy(26,9);
			printf("Add New STUDENT      [1]");
			gotoxy(26,11);
			printf("Show Daily Entries     [2]");
			gotoxy(26,13);
			printf("Search STUDENT Record [3]");
			gotoxy(26,15);
			printf("Remove STUDENT        [4]");
			gotoxy(26,17);
			printf("Close                  [5]");
			gotoxy(24,21);
			printf("Please enter your choice: ");
			selectAdminOption();
		   }
		}
	}
stream:{}

}
