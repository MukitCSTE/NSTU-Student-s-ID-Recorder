/* This function retreives data from the database as well as do data processing according to user requests.
   The function provides functionality for menu options provided to both employee as well as administrator user*/
void getData(int option)
{
 FILE *db,*tempdb;
 char anotherEmp;
 int choice;
 int showMenu,posx,posy;
 char checkSave,checkAddNew;
 int i;

 struct employee
 {
        char firstname[30];
  char lastname[30];
	char password[30];
	int  empid;
	char contact[30];
	char bgr[4];
	char date[10];
	char loginhour;
	char loginmin;
	char loginsec;
	char logouthour;
	char logoutmin;
	char logoutsec;
	int yr;
	char mon;
	char day;
 };

 struct employee empData;

 char confirmPassword[30];
 long int size;
 char lastNameTemp[30],firstNameTemp[30],password[30],contact[30],bgr[4], date[10];
 int searchId;
 char pass[30];
 char findEmployee;
 char confirmDelete;

 struct date today;
 struct time now;

 clrscr();

 /* Opens the Employee Database*/
 db=fopen("d:/empbase.dat","rb+");
 if(db==NULL)
	{
		db=fopen("d:/empbase.DAT","wb+");
		if(db==NULL)
		{
			printf("The File could not be opened.\n");
			exit();
		}
	}
  printf("Application Database \n");
  size=sizeof(empData);
  showMenu=0;
  while(showMenu==0)
  {
   fflush(stdin);
   choice=option;

   /* Based on the choice selected by admin/employee, this switch statement processes the request*/
   switch(choice)
   {

   /* To add a new employee to the database*/
   case 1:
	   fseek(db,0,SEEK_END);
	   anotherEmp='y';

	   while(anotherEmp=='y')
	   {
                   checkAddNew=0;
		   while(checkAddNew==0)
		   {
		   clrscr();
		   gotoxy(25,3);
		   printf("ADD A NEW STUDENT");
		   gotoxy(13,22);
		   printf("Warning: Password Must Contain Six(6) AlphaNumeric Digits.");
		   gotoxy(5,8);
		   printf("Enter First Name: ");
		   scanf("%s",&firstNameTemp);
		   gotoxy(5,10);
		   printf("Enter Last Name: ");
		   scanf("%s",&lastNameTemp);
            gotoxy(5,12);
		   printf("Enter Blood Group: ");
		   scanf("%s",&bgr);
		   gotoxy(5,14);
		   printf("Enter Contact No: ");
		   scanf("%s",&contact);


		   gotoxy(43,8);
		   printf("Enter Password: ");
		   for (i=0;i<6;i++)
		   {
		    password[i]=getch();
		    printf("* ");
		   }
		   password[6]='\0';

		   while(getch()!=13);

		   gotoxy(43,10);
		   printf("Confirm Password: ");
		   for (i=0;i<6;i++)
		   {
		    confirmPassword[i]=getch();
		    printf("* ");
		   }
		   confirmPassword[6]='\0';

		   while(getch()!=13);
		   if (strcmp(password,confirmPassword))
		   {
		      gotoxy(24,12);
        	      printf("Passwords do not match.");
		      gotoxy(23,13);
		      printf("Press any key to continue.");
		      getch();
		   }
		   else
		   {
		   checkAddNew=1;
		   rewind(db);
		   empData.empid=0;
		   while(fread(&empData,size,1,db)==1);
		   if (empData.empid<2000)
		   empData.empid=20400;

		   empData.empid=empData.empid+1;
		   gotoxy(30,16);
		   printf("Save Student Information? (y/n): ");
		   checkSave=getche();
		   if (checkSave=='y')
		   {
		   strcpy(empData.firstname,firstNameTemp);
		   strcpy(empData.lastname,lastNameTemp);

		   strcpy(empData.bgr,bgr);
		   strcpy(empData.contact,contact);
		   strcpy(empData.date,date);
		   strcpy(empData.password,password);
		   empData.loginhour='t';
		   empData.logouthour='t';
		   empData.day='j';
		   fwrite(&empData,size,1,db);
		   }
		   gotoxy(28,16);
		   printf("                        ");
		   gotoxy(31,16);
		   printf("Would like to add another student? (y/n):");
		   fflush(stdin);
		   anotherEmp=getche();
		   printf("\n");
		   }
		   }
	   }
	   break;

   /* To view time records for all employees*/
   case 2:

	   clrscr();
	   gotoxy(21,2);
	   printf("  .     VIEW STUDENT INFORMATION ");
	    gotoxy(21,3);
	   printf("           ~CSTE - 7th Batch~ ");
	   gotoxy(1,5);
	   printf("  ID:        Student Name:      Student Blood Gr:  Contact No:     Date of log\n\n");
	   rewind(db);
	   posx=3;
	   posy=7;
	   while(fread(&empData,size,1,db)==1)
	   {
	    empData.firstname[0]=toupper(empData.firstname[0]);
	    empData.lastname[0]=toupper(empData.lastname[0]);
	    gotoxy(posx,posy);
	    printf("%d",empData.empid);
	    gotoxy(posx+10,posy);
	    printf("| %s, %s",empData.firstname,empData.lastname);
	    gotoxy(posx+30,posy);
	    	    printf("%s",empData.bgr);
gotoxy(posx+30,posy+2);
	    if (empData.loginhour=='t')
	    {
	     printf("");
	    }
	    else
	    printf("");

	    gotoxy(posx+49,posy);

	    printf("%s",empData.contact);

	    if (empData.logouthour=='t')
	    {
	    printf("");
	    }
	    else
	    printf("");
	    if (empData.day=='j')
	    {
	    gotoxy(posx+64,posy);
	    printf("| Not Log yet");
	    }
	    else
	    {
	    gotoxy(posx+64,posy);
	    printf("| %d/%d/%d",empData.mon,empData.day,empData.yr);
	    }

	    posy=posy+1;
	   }
       	   getch();

	   printf("\n");
	   break;

  /* To search a particular employee and view their time records*/
  case 3:

	   clrscr();
	   gotoxy(27,5);
	   printf("SEARCH STUDENT INFORMATION");
	   gotoxy(25,9);
	   printf("Enter Student Id to Search: ");
	   scanf("%d", &searchId);
	   findEmployee='f';
	   rewind(db);
           while(fread(&empData,size,1,db)==1)
	   {
	       if (empData.empid==searchId)
	       {
		gotoxy(33,11);
		textcolor(YELLOW+BLINK);
		cprintf("Student Information is Available.");
		textcolor(YELLOW);
		gotoxy(25,13);
		printf("Student name is: %s %s",empData.firstname,empData.lastname);
		if(empData.loginhour=='t')
		{
		gotoxy(25,14);
		printf("Log In Time: Not Logged In");
		}
		else
		{
		gotoxy(25,14);
		printf("Log In Time is: %d:%d:%d",empData.loginhour,empData.loginmin,empData.loginsec);
		}
		if(empData.logouthour=='t')
		{
		gotoxy(25,15);
		printf("Log Out Time: Not Logged Out");
		}
		else
		{
		gotoxy(25,15);
		printf("Log Out Time is: %d:%d:%d",empData.logouthour,empData.logoutmin,empData.logoutsec);
		}
		findEmployee='t';
	       getch();
	       }
	   }
	   if (findEmployee!='t')
	   {
	   gotoxy(30,11);
	   textcolor(YELLOW+BLINK);
	   cprintf("StudentInformation not available. Please modify the search.");
	   textcolor(YELLOW);
	   getch();
	   }
	   break;

  /* To remove entry of an employee from the database*/
  case 4:
	   clrscr();
	   gotoxy(25,5);
	   printf("REMOVE AN STUDENT");
	   gotoxy(25,9);
	   printf("Enter Student Id to Delete: ");
	   scanf("%d", &searchId);
	   findEmployee='f';
	   rewind(db);
           while(fread(&empData,size,1,db)==1)
	   {

	       if (empData.empid==searchId)
	       {
		gotoxy(33,11);
		textcolor(YELLOW+BLINK);
		cprintf("Student Information is Available.");
		textcolor(YELLOW);
		gotoxy(25,13);
		printf("Student name is: %s %s",empData.firstname,empData.lastname);
		findEmployee='t';

	       }
	   }
	   if (findEmployee!='t')
	   {
	   gotoxy(30,11);
	   textcolor(YELLOW+BLINK);
	   cprintf("Student Information not available. Please modify the search.");
	   textcolor(YELLOW);
	   getch();
	   }
	   if (findEmployee=='t')
	   {
	   gotoxy(29,15);
	   printf("Do you want to Delete the Student? (y/n)");
	   confirmDelete=getche();
		if (confirmDelete=='y' || confirmDelete=='Y')
		{
		tempdb=fopen("d:/tempo.dat","wb+");
		rewind(db);
		while(fread(&empData,size,1,db)==1)
			{
			 if (empData.empid!=searchId)
			 {
			 fseek(tempdb,0,SEEK_END);
			 fwrite(&empData,size,1,tempdb);
			 }
			}
		fclose(tempdb);
		fclose(db);
		remove("d:/empbase.dat");
		rename("d:/tempo.dat","d:/empbase.dat");
		db=fopen("d:/empbase.dat","rb+");
		}
	   }
	   break;

  /* To login an employee into the system and record the login date and time*/
  case 5:
	   clrscr();
	   gotoxy(20,4);
	   printf("DAILY TIME RECORDING SYSTEM");
	   gotoxy(20,23);
	   printf("Warning: Please Enter Numeric Values Only.");
	   gotoxy(23,7);
	   printf("Enter Your Id to Login: ");
	   scanf("%d", &searchId);
	   gotoxy(20,23);
	   printf("                                            ");
	   findEmployee='f';
	   rewind(db);
           while(fread(&empData,size,1,db)==1)
	   {
	       if (empData.empid==searchId)
	       {
		gotoxy(23,8);
		printf("Enter Your Password: ");

                 for (i=0;i<6;i++)
		   {
		    pass[i]=getch();
		    printf("* ");
		   }
		   pass[6]='\0';
		 while(getch()!=13);

		if (strcmp(empData.password,pass))
		{
		 gotoxy(23,11);
		 textcolor(YELLOW+BLINK);
		 cprintf("You Have Supplied a Wrong Password.");
		 textcolor(YELLOW);
		 findEmployee='t';
		 getch();
		 break;
		}
		gotoxy(23,11);
		textcolor(YELLOW+BLINK);
		cprintf("You have successfully Logged In the System.");
		textcolor(YELLOW);
		gotoxy(23,13);
		printf("Student name: %s %s",empData.firstname,empData.lastname);
		gettime(&now);
		getdate(&today);
		gotoxy(23,14);
		printf("Your LogIn Time: %2d:%2d:%2d",now.ti_min,now.ti_hour,now.ti_sec);
		gotoxy(23,15);
		printf("Your Log In Date: %d/%d/%d",today.da_mon,today.da_day,today.da_year);
		empData.day=today.da_day;
		empData.mon=today.da_mon;
		empData.yr=today.da_year;
		fseek(db,-size,SEEK_CUR);
		empData.loginhour=now.ti_min;
		empData.loginmin=now.ti_hour;
		empData.loginsec=now.ti_sec;
		fwrite(&empData,size,1,db);
		findEmployee='t';
		getch();

	       }
	   }
	   if (findEmployee!='t')
	   {
	   gotoxy(30,11);
	   textcolor(YELLOW+BLINK);
	   cprintf("Student Information is not available.");
	   textcolor(YELLOW);
	   getch();
	   }

	   break;

  /* To logout an employee and record the logout date and time*/
  case 6:

           clrscr();
	   gotoxy(20,4);
	   printf("DAILY EMPLOYEE TIME RECORDING SYSTEM");
	   gotoxy(20,23);
	   printf("Warning: Please Enter Numeric Values Only.");
	   gotoxy(23,7);
	   printf("Enter Your Id to Logout: ");
	   scanf("%d", &searchId);
	   gotoxy(20,23);
	   printf("                                            ");
	   findEmployee='f';
	   rewind(db);
           while(fread(&empData,size,1,db)==1)
	   {
	       if (empData.empid==searchId)
	       {
		gotoxy(23,8);
		printf("Enter Password: ");

                 for (i=0;i<6;i++)
		   {
		    pass[i]=getch();
		    printf("* ");
		   }
		   pass[6]='\0';
		 while(getch()!=13);

		if (strcmp(empData.password,pass))
		{
		 gotoxy(30,11);
		 textcolor(YELLOW+BLINK);
		 cprintf("You Have Supplied a Wrong Password.");
		 textcolor(YELLOW);
		 findEmployee='t';
		 getch();
		 break;
		}
		gotoxy(23,11);
		textcolor(YELLOW+BLINK);
		cprintf("You have successfully Logged Out of the System.");
		textcolor(YELLOW);
		gotoxy(23,13);
		printf("Student name is: %s %s",empData.firstname,empData.lastname);
		gettime(&now);
		getdate(&today);
		gotoxy(23,14);
		printf("Your Log Out Time: %2d:%2d:%2d",now.ti_min,now.ti_hour,now.ti_sec);
		gotoxy(23,15);
		printf("Your Log Out Date: %d/%d/%d",today.da_mon,today.da_day,today.da_year);
		fseek(db,-size,SEEK_CUR);
		empData.logouthour=now.ti_min;
		empData.logoutmin=now.ti_hour;
		empData.logoutsec=now.ti_sec;
		fwrite(&empData,size,1,db);
		findEmployee='t';
		getch();

	       }
	   }
	   if (findEmployee!='t')
	   {
	   gotoxy(23,11);
	   textcolor(YELLOW+BLINK);
	   cprintf("Student Information is not available.");
	   textcolor(YELLOW);
	   getch();
	   }

	   break;

  /* Show previous menu*/
  case 9:

	   printf("\n");
	   exit();
	   }
   fclose(db);
   showMenu=1;
   }
 }
