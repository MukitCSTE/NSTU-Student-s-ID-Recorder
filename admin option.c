void selectAdminOption(void)
{
  char chc[1];
  int chooseNew,chooseShow,chooseSearch,chooseRemove,chooseClose;

  gets(chc);

  chooseNew=strcmp(chc,"1");
  chooseShow=strcmp(chc,"2");
  chooseSearch=strcmp(chc,"3");
  chooseRemove=strcmp(chc,"4");
  chooseClose=strcmp(chc,"5");

  if (!(chooseNew==0 || chooseShow==0 || chooseSearch==0 || chooseRemove==0 || chooseClose==0))
  {
     gotoxy(19,21);
     textcolor(RED+BLINK);
     cprintf("Invalid Input!");
     gotoxy(34,21);
     textcolor(YELLOW);
     cprintf("Press any key to continue.");
  }

  if (chooseNew==0)
  {
     clrscr();
     gotoxy(25,5);
     getData(1);
  }
  else if(chooseShow==0)
  {
     getData(2);
  }
  else if(chooseSearch==0)
  {
     clrscr();
     getData(3);
  }
  else if(chooseRemove==0)
  {
     getData(4);
  }
  else if (chooseClose==0)
  {
     showAdminMenu=1;
  }
}
