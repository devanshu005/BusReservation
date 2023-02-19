#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ch[10][130]={"KA-1","KA-2","KA-3","KA-4","KA-5"};//declaring and initialization bus name
char name[32][100]={'\0'};
char number[32][2]={'\0'};
int num1[32]={0};
int busno;
void bus();//for list of bus
void name_number(int booking,char numstr[100]);
void booking();//for booking the tickets
int read_number(int busno);//for reading the number from the file
void read_name(int busno);//for reading the name from the file
void status();//for printing the status by user input
void status_1(int busno);//for printing the status while booking ticket
void cancel();

int main()
{
    system("color f1");

	login();
    int num,i;
    do{
    system("cls");
    printf("\n\n\n");//printing main menu
    printf("======================================      BUS RESERVATION SYSTEM      ======================================\n\n\n");
    printf("\t\t\t\t\t[1]=> BUS LIST\n");
    printf("\n");
    printf("\t\t\t\t\t[2]=> BOOK TICKETS\n");
    printf("\n");
    printf("\t\t\t\t\t[3]=> CANCEL BOOKING\n");
    printf("\n");
    printf("\t\t\t\t\t[4]=> BUS STATUS\n");
    printf("\n");
    printf("\t\t\t\t\t[5]=> EXIT\n\n");
    printf("===============================================================================================================\n\n");
    printf("\t\t\tENTER YOUR CHOICE FROM MENU:: ");
    scanf("%d",&num);
    switch(num)//different task choice
    {
    case 1:
         system("color f2");
        bus();//for list of bus
        printf("\n\n\t\t\t\tPRESS ANY KEY TO CONTINUE.......");
        break;
    case 2:
         system("color f3");
        booking();//for booking the tickets
        break;
    case 3:
        system("CLS");
         system("color f4");
        cancel();
        break;
    case 4:
        system("CLS");
         system("color f5");
        status();
        break;
    case 5:
         system("CLS");
         system("color f1");
         printf("\t----------------------------------------------------------------------------------------------------------\n");
         printf("\t\t\t\t\tTHANK YOU FOR USING OUR SYSTEM\t\t\t\t\t\t\n");
         printf("\t----------------------------------------------------------------------------------------------------------\n");
         _getch();
         return 0;
    }
_getch();
    }while(num != 6);
    system("CLS");
    printf("\t----------------------------------YOU ENTERED WRONG CHOICE------------------------------------------------\n");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tTHANK YOU FOR USING OUR SYSTEM\t\t\t\t\t\n");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    _getch();
    return 0;
}


void bus()
{
    system("cls");
    printf("\n\n\n");//bus list and details
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    printf("===========================================  AIRPORT BUS TERMINAL ============================================\n\n");
    printf("   S.NO.   |   BUS NO.   |    SOURCE  |    DESTINATION  |        DAYS     |       TIMING      |   PRICE");
    printf("\n           |             |            |                 |                 |                   |  ");
    printf("\n    1.     |     %s    |  AIRPORT   |     BAGLUR      |  MONDAY-FRIDAY  |  7am,2pm,8pm      |   200  ",ch[0]);
    printf("\n           |             |            |                 |                 |                   |  ");
    printf("\n    2.     |     %s    |  AIRPORT   |     MYSORE      |     EVERYDAY    |  7am,2pm,4pm,7pm  |   200  ",ch[1]);
    printf("\n           |             |            |                 |                 |                   |  ");
	printf("\n    3.     |     %s    |  AIRPORT   |     YELANKHA    |     EVERYDAY    |  7am,2pm,5pm,8pm  |   200  ",ch[2]);
    printf("\n           |             |            |                 |                 |                   |  ");
	printf("\n    4.     |     %s    |  AIRPORT   |     HUBALI      |  MONDAY-FRIDAY  |   7am,2pm,8pm     |   200  ",ch[3]);
    printf("\n           |             |            |                 |                 |                   |  ");
	printf("\n    5.     |     %s    |  AIRPORT   |     JALAHALLI   |     EVERYDAY    |  7am,2pm,4pm,7pm  |   200  ",ch[4]);

}


void booking()
{

    int i=0;
    char numstr[100];
system("cls");
printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");//for entering bus number
bus();//for seeing bus list
printf("\n\nENTER BUS NUMBER(1 / 2 / 3 / 4 / 5) :--->");
scanf("%d",&busno);//input bus no. choice
system("cls");
printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");//for selecting seat
printf("\n\nYOUR BUS NUMBER IS %d ********** %s",busno,ch[busno-1]);
status_1(busno);
 FILE *f1, *fopen();//for reading the seats from the user.
 char sbs1[80]="32",sbs2[4],sbs3[4];
 int seat1,seat2,booking=0;
if(busno == 1)
{
 f1 = fopen("bs1.txt","r+");//r+ searches file and read from 1st character
 fgets(sbs1,80,f1);
 fclose(f1);
}else if(busno == 2)
{
 f1 = fopen("bs2.txt","r+");
 fgets(sbs1,80,f1);
 fclose(f1);
}else if(busno == 3)
{
 f1 = fopen("bs3.txt","r+");
 fgets(sbs1,80,f1);
 fclose(f1);
}
else if(busno == 4)
{
 f1 = fopen("bs4.txt","r+");
 fgets(sbs1,80,f1);
 fclose(f1);
}
else if(busno == 5)
{
 f1 = fopen("bs5.txt","r+");
 fgets(sbs1,80,f1);
 fclose(f1);
}
seat1=atoi(sbs1);//covert the string into number
if(seat1 <= 0)
{
 printf("\n\nTHERE IS NO BLANK SEAT");
}else
{
printf("\n\n\n\t\t\t\tAVAILABLE SEATS:------>%d\n",seat1);
printf("\n\t\t\t\tNUMBER OF TICKETS:----->");
scanf("%d",&booking);//no of tickets input
printf("\n");

seat1=seat1-booking;
itoa(busno,numstr,10);
name_number(booking,numstr);
printf("\n\t\t\t\tTHE TOTAL AMOUNT TO BE PAID IS %d",200*booking);
printf("\n\t\t\t\tPRESS ANY KEY TO CONTINUE.......");
itoa(seat1, sbs1, 10);//for reading the seats from the user.
if(busno == 1)
{
 f1 = fopen("bs1.txt","w");//write the name and no. of passenger in file
 fputs(sbs1,f1);
 fclose(f1);
}
else if(busno == 2)
{
 f1 = fopen("bs2.txt","w");
 fputs(sbs1,f1);
  fclose(f1);
}
else if(busno == 3)
{
 f1 = fopen("bs3.txt","w");
 fputs(sbs1,f1);
  fclose(f1);
}
else if(busno == 4)
{
 f1 = fopen("bs4.txt","w");
 fputs(sbs1,f1);
  fclose(f1);
}
else if(busno == 5)
{
 f1 = fopen("bs5.txt","w");
 fputs(sbs1,f1);
 fclose(f1);
}
}
}



void name_number(int booking,char numstr[100])
{
char tempstr[100],tempsbs1[12]="status",tempsbs2[12]="number";
int number;
    FILE *a,*b;
    int i=0;
   strcat(numstr,".txt");
   strcat(tempsbs1,numstr);
   strcat(tempsbs2,numstr);
   a = fopen(tempsbs1,"a");//for open the file to write the name in the file
   b = fopen(tempsbs2,"a");//for open the file for writing the number in the file
for(i=0; i<booking; i++)//for entering the person name and seat number in the file
{
    printf("============================ENTER DETAILS FOR %d TICKET ============================\n\n\n",i+1);
      printf("\t\t\t\tENTER SEAT NUMBER:--->");
      scanf("%d",&number);
      printf("\t\t\t\tENTER NAME OF PERSON:--->");
      scanf("%s",name[number-1]);
    printf("\n======================================================================================================\n\n");
    printf("\n");
      itoa(number, tempstr, 10);
      fprintf(a,"%s ",name[number-1]);
      fprintf(b,"%s ",tempstr);

}
fclose(a);
fclose(b);
}



int read_number(int busno)//for putting the numeric value in the array
{
char tempstr[100],tempsbs2[12]="number";
FILE *a,*b;
char numstr[100];
int i=0,j=0,k;
itoa(busno,numstr,10);
strcat(numstr,".txt");
strcat(tempsbs2,numstr);
a = fopen(tempsbs2,"a+");//for open the file to read the name in the file
   while(!feof(a))//file end of file
   {
      number[i][j] = fgetc(a);//gets the character from file pointer a

      if(number[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
      j++;
      }
   }
   k=i;
   for(i=0; i<k; i++)
   {
       num1[i] = atoi(number[i]);//atoi string to integer
   }
   fclose(a);
   return k;
}


void read_name(int busno)//for putting the numeric value in the array
{
char tempsbs1[12]="status";
FILE *b;
char numstr[100];
int i=0,j=0,k=0;
itoa(busno,numstr,10);
strcat(numstr,".txt");
strcat(tempsbs1,numstr);
b = fopen(tempsbs1,"a+");//for open the file to write the name in the file
   while(!feof(b))
   {
      name[i][j] = fgetc(b);

      if(name[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
        j++;
      }

   }
   name[i][j]='\0';
   k=i;
   fclose(b);
}
void status()
{
system("cls");//seat matrix
printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int i,busno,index=0,j;
    printf("ENTER BUS NUMBER:---->");
    scanf("%d",&busno);
    j=read_number(busno);
    read_name(busno);
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                     BUS NO. -->%d---->%s                                                            \n",busno,ch[busno-1]);
    printf("____________________________________________________________________________________________________________________\n");
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
    }
}

void status_1(int busno)
{
    printf("YOUR BUS NUMBER IS %d ********** %s",busno,ch[busno-1]);
    system("cls");
printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int i,index=0,j;
    j=read_number(busno);//read and save seat no
    read_name(busno);//read and save name of person
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
}
}

void cancel()
{
 int seat_no,i,j;
 char numstr[100],tempsbs2[15]="number",tempsbs1[15]="status";
 printf("_____________________________________________________________________________________________________________\n");
 printf("\n\nCANCELLATION FEE = Rs 50 PER TICKET\n");
 printf("_____________________________________________________________________________________________________________\n");
 printf("\n");
 printf("\n\nENTER BUS NUMBER:---->");
 scanf("%d",&busno);
 itoa(busno,numstr,10);
 strcat(numstr,".txt");
 strcat(tempsbs1,numstr);
 strcat(tempsbs2,numstr);
 read_number(busno);
 read_name(busno);
 status_1(busno);
 printf("\nENTER THE SEAT NUMBER:--->");
 scanf("%d",&seat_no);
 FILE *a,*b;
 a = fopen(tempsbs1,"w+");
 b = fopen(tempsbs2,"w+");
 for(i=0; i<32; i++)
 {
     if(num1[i] == seat_no)
     {
         for(j=0; j<32; j++)
         {
             if(num1[j] != seat_no && num1[j] != 0)
             {
                 fprintf(b,"%d ",num1[j]);
                 fprintf(a,"%s",name[j]);
             }
             else if(num1[j] == seat_no && num1[j] != 0)
             {
                 strcpy(name[j],"Empty ");
             }
         }
     }
 }
fclose(a);
fclose(b);
printf("\n\n");
 printf("======================================================================================================\n");
 printf("\t\t\t\tYOUR BOOKING HAS BEEN CANCELLED\t\t\t\n");
    printf("======================================================================================================\n");
 printf("\t\t\t\tYOUR 150 RUPEES WILL BE REFUNDED IN 2 - 3 DAYS\t\t\t\n");
    printf("======================================================================================================\n");
    printf("\n\t\t\t\tPRESS ANY KEY TO CONTINUE.....");
}

void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
	system("cls");

    printf("\n  =========================     LOGIN     =========================  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=_getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPRESS ANY KEY TO CONTINUE....");
	_getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		_getch();//holds the screen

	}
}
	while(a<=9);
	if (a>9)
	{
		printf("\nSorry you have entered the wrong username and password for many times!!!");

		_getch();

		}
		system("cls");
}


