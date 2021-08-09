#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
struct student
{
 int sem,m1,m2,m3,m4,m5,m6;
 long unsigned int PRN;
 char name[50],add[50],brn[50],grd[5],r[10];
 char s1[10],s2[10],s3[10],s4[10],s5[10],s6[10];
};
struct student s[MAX];
int getdata(int);
int display(int);
int rem(int);
int edit();
int dis_stu(int);
int insert(int);
int sort(int);
void firstpg();
void admin();
int student();
void mainf();
void exitf();
void menu();
void main()
{
	clrscr();
	textbackground(WHITE);
	firstpg();
	getch();
}
void firstpg()
{
	clrscr();
	gotoxy(15,9);
	textcolor(BLACK);
	textbackground(WHITE);
	cprintf("<<...Government College Of Engineering Jalgaon...>> ");
	textcolor(YELLOW + BLINK);
	textbackground(BLACK);
	gotoxy(15,10);
	cprintf("\n\nPROJECT NAME : ");
	textcolor(WHITE);
	cprintf("M.I.S. Database");
	textcolor(YELLOW + BLINK );
	textbackground(BLACK);
	gotoxy(15,11);
	cprintf("\n\nCreated By :");
	textcolor(WHITE);
	gotoxy(30,13);
	cprintf("\n1) Sanket P. Rathod ");
	gotoxy(30,14);
	cprintf("\n2) Jayesh B. Wani ");
	gotoxy(30,15);
	cprintf("\n3) Rahul R. Kadam ");
	gotoxy(30,16);
	cprintf("\n4) Abhishek Thakare ");
	gotoxy(1,17);
	cprintf("\nPress Any Key To Continue........");
	getch();
	menu();
}
void menu()
{
	int ch;
	clrscr();
	clrscr();
	gotoxy(30,7);
	cprintf(".......WELCOME....... ");
	gotoxy(39,9);
	printf("TO");
	gotoxy(27,10);
	textbackground(WHITE);
	textcolor(BLACK);
	cprintf(" M.I.S. DATABASE MANAGEMENT ");
	gotoxy(30,15);
	printf("1) Administrator LOGIN ");
	gotoxy(30,17);
	printf("2) Student LOGIN ");
	gotoxy(30,19);
	printf("3) Exit ");
	gotoxy(30,22);
	printf("Enter your choice : ");
	scanf("%d",&ch);
	while(1)
	{
		switch(ch)
		{
			case 1:admin();break;
			case 2:student();break;
			case 3:exitf();break;
			default:printf("INVALID CHOICE!!!!");
		}
	}
}

void admin()
{
	int ch,n;
	textbackground(WHITE);
	textcolor(BLACK);
	clrscr();
	printf("\n****:Enter Student Data:****\n");
	printf("\nEnter Number OF Student To add:=\t");
	scanf("%d",&n);
	getdata(n);
	while(1)
	{
		clrscr();
		printf("\n");
		printf("\n\t\t\t******:MENU:******\t\t\t\n");
		printf("1.Enter Data of student(only one)\n");
		printf("2.Edit information of student\n");
		printf("3.Display Student record(by Branch & Subject)\n");
		printf("4.Display student(only one)\n");
		printf("5.Remove Any Student\n");
		printf("6.Sort a Data(only PRN and Branch)\n");
		printf("7.Exit\n");
		printf("\n====:Enter your choice:====\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case(1):n=insert(n);break;
			case(2):edit(n);break;
			case(3):display(n);break;
			case(4):dis_stu(n);break;
			case(5):n=rem(n);break;
			case(6):sort(n);break;
			case(7):menu();break;
			default:printf("Please...Enter valid option...\n");
		}
	}
}
//=================================================================

int getdata(int n)
{
	int i;
	clrscr();
	for(i=0;i<n;i++)
	{
		printf("\n");
		printf("Enter Name of the Student:=\t");
		scanf("%s",s[i].name);
		printf("Enter PRN no. of the student:=\t");
		scanf("%lu",&s[i].PRN);
		printf("Enter address of the student:=\t");
		scanf("%s",s[i].add);
		printf("Enter Branch:=\t");
		scanf("%s",s[i].brn);
		printf("Enter current semester of the student:=\t");
		scanf("%d",&s[i].sem);
		printf("Enter Subjects:=\n");
		printf("1)\t");
		scanf("%s",s[i].s1);
		printf("2)\t");
		scanf("%s",s[i].s2);
		printf("3)\t");
		scanf("%s",s[i].s3);
		printf("4)\t");
		scanf("%s",s[i].s4);
		printf("5)\t");
		scanf("%s",s[i].s5);
		printf("6)\t");
		scanf("%s",s[i].s6);
		printf("Enter  Marks of the respective subject:=\n");
		printf("1).");printf("%s:=\t",s[i].s1);
		scanf("%d",&s[i].m1);
		printf("2).");printf("%s:=\t",s[i].s2);
		scanf("%d",&s[i].m2);
		printf("3).");printf("%s:=\t",s[i].s3);
		scanf("%d",&s[i].m3);
		printf("4).");printf("%s:=\t",s[i].s4);
		scanf("%d",&s[i].m4);
		printf("5).");printf("%s:=\t",s[i].s5);
		scanf("%d",&s[i].m5);
		printf("6).");printf("%s:=\t",s[i].s6);
		scanf("%d",&s[i].m6);
	}
	getch();
	return(n);
}

//=================================================================

int display(int n)
{
	int j,i;
	char branch[50],sub[50];
	clrscr();
	printf("Enter branch:=\t");
	scanf("%s",branch);
	printf("Enter Subject:=\t");
	scanf("%s",sub);
	printf("\nPRN\t|\tNAME\t|\tSEM\t|\tMARKS\t\n");
	for(i=0;i<n;i++)
	{
	 if(!strcmp(s[i].brn,branch))
	 {
	  if(!strcmp(sub,s[i].s1))
	  {
	   printf("\n%lu\t|\t%s\t|\t%d\t|\t%d",s[i].PRN,s[i].name,s[i].sem,s[i].m1);
	  }
	  else if(!strcmp(sub,s[i].s2))
	  {
	   printf("\n%lu\t|\t%s\t|\t%d\t|\t%d",s[i].PRN,s[i].name,s[i].sem,s[i].m2);
	  }
	  else if(!strcmp(sub,s[i].s3))
	  {
	   printf("\n%lu\t|\t%s\t|\t%d\t|\t%d",s[i].PRN,s[i].name,s[i].sem,s[i].m3);
	  }
	  else if(!strcmp(sub,s[i].s4))
	  {
	   printf("\n%lu\t|\t%s\t|\t%d\t|\t%d",s[i].PRN,s[i].name,s[i].sem,s[i].m4);
	  }
	  else if(!strcmp(sub,s[i].s5))
	  {
	   printf("\n%lu\t|\t%s\t|\t%d\t|\t%d",s[i].PRN,s[i].name,s[i].sem,s[i].m5);
	  }
	  else if(!strcmp(sub,s[i].s6))
	  {
	   printf("\n%lu\t|\t%s\t|\t%d\t|\t%d",s[i].PRN,s[i].name,s[i].sem,s[i].m6);
	  }
	}
      }
	printf("\n");
	getch();
	return(n);
}

//=================================================================

int rem(int n)
{
 int i,loc;
 char nm[50];
 clrscr();
 printf("Enter Name :=\t");
 scanf("%s",nm);
 for(i=0;i<n;i++)
 {
  if(!strcmp(nm,s[i].name))
  {
   loc=i;
  }
 }
 for(i=loc;i<=n;i++)
 {
  {
   s[i]=s[i+1];
  }
 }
 printf("Data Succenfully Deleted");
 getch();
 return(n-1);
}

//=================================================================

int edit(int n)
{
 int i;
 long unsigned int prn;
 clrscr();
 printf("Enter PRN no. of the student:=\t");
 scanf("%lu",&prn);
 for(i=0;i<n;i++)
 {
  if(s[i].PRN==prn)
  {
   printf("\n");
   printf("Enter Name of the Student:=\t");
   scanf("%s",s[i].name);
   printf("Enter PRN no. of the student:=\t");
   scanf("%lu",&s[i].PRN);
   printf("Enter address of the student:=\t");
   scanf("%s",s[i].add);
   printf("Enter Branch:=\t");
   scanf("%s",s[i].brn);
   printf("Enter current semester of the student:=\t");
   scanf("%d",&s[i].sem);
   printf("Enter Subjects:=\n");
   printf("1)\t");
   scanf("%s",s[i].s1);
   printf("2)\t");
   scanf("%s",s[i].s2);
   printf("3)\t");
   scanf("%s",s[i].s3);
   printf("4)\t");
   scanf("%s",s[i].s4);
   printf("5)\t");
   scanf("%s",s[i].s5);
   printf("6)\t");
   scanf("%s",s[i].s6);
   printf("Enter  Marks of the respective subject:=\n");
   printf("1).");printf("%s:=\t",s[i].s1);
   scanf("%d",&s[i].m1);
   printf("2).");printf("%s:=\t",s[i].s2);
   scanf("%d",&s[i].m2);
   printf("3).");printf("%s:=\t",s[i].s3);
   scanf("%d",&s[i].m3);
   printf("4).");printf("%s:=\t",s[i].s4);
   scanf("%d",&s[i].m4);
   printf("5).");printf("%s:=\t",s[i].s5);
   scanf("%d",&s[i].m5);
   printf("6).");printf("%s:=\t",s[i].s6);
   scanf("%d",&s[i].m6);
   printf("\nNew Edited data:=\n");
   printf("\n=====================================================\n");
   printf("Name:=\t%s\n",s[i].name);
   printf("PRN:=\t%lu\n",s[i].PRN);
   printf("Branch:=\t%s\n",s[i].brn);
   printf("Address:=\t%s\n",s[i].add);
   printf("subject & marks:=\n");
   printf("%s:=\t%d\n",s[i].s1,s[i].m1);
   printf("%s:=\t%d\n",s[i].s2,s[i].m2);
   printf("%s:=\t%d\n",s[i].s3,s[i].m3);
   printf("%s:=\t%d\n",s[i].s4,s[i].m4);
   printf("%s:=\t%d\n",s[i].s5,s[i].m5);
   printf("%s:=\t%d\n",s[i].s6,s[i].m6);
   printf("\n=====================================================\n");
  }
 }
  getch();
  return(n);
}

//=================================================================

int dis_stu(int n)
{
 int i;
 long unsigned int prn;
 clrscr();
 printf("Enter PRN no. of the student:=\t");
 scanf("%lu",&prn);
 for(i=0;i<n;i++)
 {
  if(s[i].PRN==prn)
  {
   printf("\n=====================================================\n");
   printf("Name:=\t%s\n",s[i].name);
   printf("PRN:=\t%lu\n",s[i].PRN);
   printf("Branch:=\t%s\n",s[i].brn);
   printf("Address:=\t%s\n",s[i].add);
   printf("subject & marks:=\n");
   printf("%s:=\t%d\n",s[i].s1,s[i].m1);
   printf("%s:=\t%d\n",s[i].s2,s[i].m2);
   printf("%s:=\t%d\n",s[i].s3,s[i].m3);
   printf("%s:=\t%d\n",s[i].s4,s[i].m4);
   printf("%s:=\t%d\n",s[i].s5,s[i].m5);
   printf("%s:=\t%d\n",s[i].s6,s[i].m6);
   printf("\n=====================================================\n");
  }
 }
 getch();
 return(n);
}

//=================================================================

int insert(int n)
{  clrscr();
   printf("\n");
   printf("Enter Name of the Student:=\t");
   scanf("%s",s[n].name);
   printf("Enter PRN no. of the student:=\t");
   scanf("%lu",&s[n].PRN);
   printf("Enter address of the student:=\t");
   scanf("%s",s[n].add);
   printf("Enter Branch:=\t");
   scanf("%s",s[n].brn);
   printf("Enter current semester of the student:=\t");
   scanf("%d",&s[n].sem);
   printf("Enter Subjects:=\n");
   printf("1)\t");
   scanf("%s",s[n].s1);
   printf("2)\t");
   scanf("%s",s[n].s2);
   printf("3)\t");
   scanf("%s",s[n].s3);
   printf("4)\t");
   scanf("%s",s[n].s4);
   printf("5)\t");
   scanf("%s",s[n].s5);
   printf("6)\t");
   scanf("%s",s[n].s6);
   printf("Enter  Marks of the respective subject:=\n");
   printf("1).");printf("%s:=\t",s[n].s1);
   scanf("%d",&s[n].m1);
   printf("2).");printf("%s:=\t",s[n].s2);
   scanf("%d",&s[n].m2);
   printf("3).");printf("%s:=\t",s[n].s3);
   scanf("%d",&s[n].m3);
   printf("4).");printf("%s:=\t",s[n].s4);
   scanf("%d",&s[n].m4);
   printf("5).");printf("%s:=\t",s[n].s5);
   scanf("%d",&s[n].m5);
   printf("6).");printf("%s:=\t",s[n].s6);
   scanf("%d",&s[n].m6);
   printf("\nNew Edited data:=\n");
   printf("\n=====================================================\n");
   printf("Name:=\t%s\n",s[n].name);
   printf("PRN:=\t%lu\n",s[n].PRN);
   printf("Branch:=\t%s\n",s[n].brn);
   printf("Address:=\t%s\n",s[n].add);
   printf("subject & marks:=\n");
   printf("%s:=\t%d\n",s[n].s1,s[n].m1);
   printf("%s:=\t%d\n",s[n].s2,s[n].m2);
   printf("%s:=\t%d\n",s[n].s3,s[n].m3);
   printf("%s:=\t%d\n",s[n].s4,s[n].m4);
   printf("%s:=\t%d\n",s[n].s5,s[n].m5);
   printf("%s:=\t%d\n",s[n].s6,s[n].m6);
   printf("\n=====================================================\n");
   getch();
   return(n+1);
}

//=================================================================

int sort(int n)
{
 int i,j,flag;
 struct student temp;
 clrscr();
 for(i=0;i<n-1;i++)
 {
  flag=0;
  for(j=0;j<n-1-i;j++)
  {
   if(s[j].PRN>s[j+1].PRN)
   {
    temp=s[j];
    s[j]=s[j+1];
    s[j+1]=temp;
    flag=1;
   }
  }
  if(flag==0)
  break;
 }
 display(n);
 getch();
 return(0);
}
//=================================================================

int student()
{
 int i;
 long unsigned int prn;
 textbackground(WHITE);
 textcolor(BLACK);
 clrscr();
 printf("Enter Your Passward:=\t");
 scanf("%ld",&prn);
 for(i=0;i<50;i++)
 {
  if(prn==s[i].PRN)
  {
   printf("\n\n\xdb\xdb <<< You have been succefully loged in >>> \xdb\xdb\n\n");
   printf("Enter any key to continue...............");
   getch();
   clrscr();
   printf("\n\n\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
   printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
   printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
   printf("\n\n");
   printf("\n\n\t\t\tWELCOME\t\t\t\n\n");
   printf("Name            :=\t%s\n",s[i].name);
   printf("PRN             :=\t%lu\n",s[i].PRN);
   printf("Branch          :=\t%s\n",s[i].brn);
   printf("Address         :=\t%s\n",s[i].add);
   printf("subject & marks :=\n");
   printf("\t\t%s:=\t%d\n",s[i].s1,s[i].m1);
   printf("\t\t%s:=\t%d\n",s[i].s2,s[i].m2);
   printf("\t\t%s:=\t%d\n",s[i].s3,s[i].m3);
   printf("\t\t%s:=\t%d\n",s[i].s4,s[i].m4);
   printf("\t\t%s:=\t%d\n",s[i].s5,s[i].m5);
   printf("\t\t%s:=\t%d\n",s[i].s6,s[i].m6);
   printf("\n\n");
   printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
   printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
   printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
  }
 }
 getch();
 menu();
 return(0);
}
void exitf()
{
	textbackground(WHITE);
	clrscr();
	textbackground(BLACK);
	textcolor(WHITE);
	gotoxy(30,14);
	cprintf(".....THANK YOU.....");
	getch();
	exit(0);
}

