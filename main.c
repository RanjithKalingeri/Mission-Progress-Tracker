#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <time.h>
#include<string.h>
#define WIDTH 110
#define HEIGHT 20
#define X WIDTH/10
#define Y HEIGHT/2
#define XMAX WIDTH-X-1
#define XMIN -(WIDTH-X)
#define YMAX HEIGHT-Y
#define YMIN -(HEIGHT-Y)+1

//#include <graphics.h>
char z[10] = "yettocome";

typedef struct
{
    char missiontitle[200];
    char startdate[30];
    char enddate[30];
    int mainmissionstatus ;
    int expectedhours;
}mainmission;

typedef struct
{
    char submissions[20][200];
    int submissionsadded;
    int submissionstatus[20];
}submission;

typedef struct
{
    int day;
    char todaydate[100][25];
    int hoursworkedtoday[100];
} progress;

typedef struct
{
    int missionno;
    mainmission mainmiss;
    submission submiss;
    progress prog;
}   mission;

void addmission (mission* miss)
{
    system("cls");
    FILE* f;
    f= fopen("ranji.txt","ab+");
     printf("\n\n\n\n\n\n\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\xB2\xB2 enter title of mission :");
    scanf("%s",miss->mainmiss.missiontitle);
   // fgets(miss->mainmiss.missiontitle,200, stdin);
   // printf("mission is :%s \n",miss->mainmiss.missiontitle );

    time_t t = time(NULL);
    memcpy(miss->mainmiss.startdate,asctime(localtime(&t)),25);
   // printf("start date of the mission is :%s\n",miss->mainmiss.startdate);

    char *s = "yettocome";
    memcpy(miss->mainmiss.enddate,s,10);

    miss->mainmiss.mainmissionstatus = 0;

    printf("\n\xB2\xB2 enter expected hours you wana work in this mission :");
    scanf("%d",&miss->mainmiss.expectedhours);
  //  printf("expected hours to work on this mission is :%d \n",miss->mainmiss.expectedhours);
    miss->submiss.submissionsadded =0;

    for (int i =0 ;i<20;i++)
    {
        char *s = "yettocomeeeeeeeeeeeeeeee";
        memcpy(miss->submiss.submissions[i],s,25);
        miss->submiss.submissionstatus[i]=0;
    }

    for (int i =0;i<100;i++)
    {
       miss->prog.hoursworkedtoday[i]=24;
       char *s ="";
       memcpy(miss->prog.todaydate[i],s,1);
    }
    miss->prog.day = 0;
    fwrite(miss,sizeof(mission),1,f);
    fclose(f);
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");

   printf("Save any more?(Y / N):");
   if(getch()=='n')
   mainmenu();
   else
   system("cls");
   mission misss;
   addmission(&misss);
}

void viewallmissions()
{
    system("cls");
    FILE *f ;
    f= fopen("ranji.txt","rb");
    mission miss;
    int i=1;
    printf("\n\n\n\n\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    while (fread(&miss,sizeof(mission),1,f)==1)
    {
        printf("\xB2\xB2 mission%d title: %s\t\t\t\xB2\xB2status:%d\n\n",i,miss.mainmiss.missiontitle,miss.mainmiss.mainmissionstatus);
        i++;
     //   fseek(f,1,SEEK_CUR);
    }
     fclose(f);
 //    fread(&miss,sizeof(mission),1,f);
   //  printf("\xB2\xB2 mission %d title:%s\n",i,miss.mainmiss.missiontitle);
     printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    // fclose(f);

     printf("press 'b' to go back to mainmenu or select the mission you want to enter:");
     int b=getch();
     if (b =='b')mainmenu();
     submenu(b-48);
     return;
}
void submenu(int d)
{
   system("cls");
    FILE* f;
    f=fopen("ranji.txt","rb+");
    mission miss;
    for (int i=0 ; i<d; i++)
    {
        fread(&miss,sizeof(miss),1,f);
    }
   fclose(f);
   printf("\n\n\n\n\n\n\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
   printf("\n\xB2\xB2 MISSION TITLE :%s \n\n\xB2\xB2 1:ADD SUBMISSION \n\n\xB2\xB2 2:ADD PROGRESS \n\n\xB2\xB2 3:VIEW STATUS \n\n\xB2\xB2 4:EDIT COMPLETIONS STATUS \n\n\xB2\xB2 5:VIEW STATS \n\n\xB2\xB2 6:DELETE THIS MISSION\n\n",miss.mainmiss.missiontitle);
   printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
   printf("enter your choice or enter 'b' to go back to view list of mission :");

   switch (getch())
   {
      case '1':
        {
          addsubmission(d);
          printf("\n\n\xB2\xB2\xB2 submission added successfully press any key to go back to submenu ");
          if(getch())submenu(d);
        }
          break;
      case '2':
         {
          addprogress(d);
          printf("\n\n\xB2\xB2\xB2 progress added successfully press any key to go back to submenu ");
           if(getch())submenu(d);
         }
          break;
      case '3':
         {
          viewstatus(d);
          printf("\n\n\xB2\xB2\xB2 Got your status !!!press any key to go back to submenu ");
          if(getch())submenu(d);
         }
          break;
      case '4':
         {
          editcompletionstatus(d);
        //  printf("\n\n\xB2\xB2\xB2 STATUS UPDATION SUCCESSFULL ");
          if(getch())submenu(d);
         }
          break;
      case '5':
         {
          plotgraph(d);
          printf("\n\n\xB2\xB2\xB2 SEE THE MOTHERFUCKING GRAPH ");
          if(getch())submenu(d);
         }
          break;
      case '6':
        {
    system("cls");
    printf("\n\n\n\n\n\xB2\xB2\xB2 ARE YOU SURE YOU WANA DELETE THIS MISSION PRESS 'b' TO GO BACK PRESS 1 TO CONTINUE  \n");
    int b=getch();
    if (b =='b')submenu(d);
    if(b=='1')
   {

       deleteparticularmission(d);
   }
   printf("\n\n\xB2\xB2 YOU ENTERED ILLEGAL CHOICE DELETING MISSIONS FAILED PRESS ANY KEY TO CONTINUE....\n");
   if(getch())
   submenu(d);
        }
          break;
      case 'b':
        viewallmissions();
        default:
      {
      printf("\aWrong Entry!!Please re-entered correct option");
      if(getch())
      submenu(d);
     }
   }
}

void addsubmission (int n)
{
    system("cls");
    FILE* f;
    f= fopen("ranji.txt","rb+");
    mission miss;
    for (int i=0 ; i<n; i++)
    {
        fread(&miss,sizeof(miss),1,f);
    }
    fseek(f,-sizeof(mission),SEEK_CUR);
    int m;
    char s[200],p[200];
    char d[20][200];
    mainmission mainmiss;
    fread(&m,sizeof(int),1,f);
    fread(&mainmiss,sizeof(mainmission),1,f);
    printf("\n\n\n\n\n\n\xB2\xB2 hei no of submissions here is %d \n",miss.submiss.submissionsadded);
    fseek(f,miss.submiss.submissionsadded*sizeof(p),SEEK_CUR);
    printf("\n\n\xB2\xB2 enter submission you wana add: ");
    scanf("%s",p);
    fwrite(&p,sizeof(p),1,f);
   // printf("heeei what i read is %s\n",p);
    int tem = miss.submiss.submissionsadded;
    fseek(f,(19-tem)*sizeof(p),SEEK_CUR);
    tem++;
    fwrite(&tem,sizeof(int),1,f);
    fclose(f);
    return;

}

void viewstatus (int n)
{
    system("cls");
    FILE* f;
    f=fopen("ranji.txt","rb+");
     mission miss;
     for (int i=0 ; i<n; i++)
    {
        fread(&miss,sizeof(miss),1,f);
    }

    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\xB2 mission title is :%s\n\n ",miss.mainmiss.missiontitle);
    printf("\xB2 mission status is :%d\n\n",miss.mainmiss.mainmissionstatus);
    printf("\xB2 mission start date is :%.24s\n\n",miss.mainmiss.startdate);
    printf("\xB2 mission end date is:%.24s\n\n",miss.mainmiss.enddate);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");

    printf("\t\t\t-----------SUBMISSIONS------------\n\n");
    for(int i=0 ; i<miss.submiss.submissionsadded ;i++)
    {
        printf("\xB2\xB2 submission%d is: %s\t\t\t\xB2\xB2 STATUS: %d\n",i+1,miss.submiss.submissions[i],miss.submiss.submissionstatus[i]);
    }
     printf("\nno of submissions added is: %d\n",miss.submiss.submissionsadded);
     printf("\n");
     printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");

     printf("DAY\t\tHOURS WORKED\t\tTODAY DATE\n ");
     for(int i=0 ; i<miss.prog.day ;i++)
    {
      printf("%d\t\t%d\t\t%.24s\n",i+1,miss.prog.hoursworkedtoday[i],miss.prog.todaydate[i]);
     // printf("how many hours worked today is :%d\n\n",miss.prog.hoursworkedtoday[i]);
      //printf("%d,%s,%d\nnext\n",i+1,miss.prog.todaydate[i],miss.prog.hoursworkedtoday[i]);
    }
    printf("\nno of progress days added is :%d\n",miss.prog.day);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    fclose(f);
}

void addprogress (int n)
{
    system("cls");
    FILE* f;
    f= fopen("ranji.txt","rb+");

    mission miss;
    for (int i=0 ; i<n; i++)
    {
        fread(&miss,sizeof(miss),1,f);
    }
    fseek(f,-sizeof(mission),SEEK_CUR);
    fseek(f,sizeof(miss.missionno),SEEK_CUR);
    fseek(f,sizeof(mainmission),SEEK_CUR);
    fseek(f,sizeof(submission),SEEK_CUR);

    int m = miss.prog.day;
    int temp =m;
    temp++;
    fwrite(&temp,sizeof(miss.prog.day),1,f);

    char s[25];
    fseek(f,m*sizeof(s),SEEK_CUR);
    time_t t = time(NULL);
    memcpy(s,asctime(localtime(&t)),25);
    fwrite(s,sizeof(s),1,f);
    fseek(f,(99-m)*sizeof(s),SEEK_CUR);

    fseek(f,m*sizeof(int),SEEK_CUR);
    //printf("\n\n\n\n\n\n\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\n\n\n\n\n\n\n\xB2\xB2\xB2 enter number of hours you worked today:");
    //printf("\n\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    int b;
    scanf("%d",&b);
    fwrite(&b,sizeof(int),1,f);

    fclose(f);
    return;

}



void mainmenu()
{  FILE* f;
   f=fopen("ranji.txt","rb+");
   system("cls");
   printf("\n\n\n\n\n\n\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
   printf("\n\xB2\xB2 1: ADD MISSION \n\n\xB2\xB2 2: VIEW ALL MISSIONS\n\n\xB2\xB2 3: DELETE ALL MISSIONS \n\n");
   printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
   printf("select you option:");
   fclose(f);
  switch(getch())
  {
  case '1':
   {
    mission miss;
    addmission(&miss);
   }
    break;
  case '2':
    viewallmissions();
    break;
   case '3':
    {
    system("cls");
    printf("\n\n\n\n\n\xB2\xB2\xB2 ARE YOU SURE YOU WANA DELETE ALL MISSION PRESS 'b' TO GO BACK PRESS 1 TO CONTINUE  \n");
    int b=getch();
    if (b =='b')mainmenu();
    if(b=='1')
   {
    FILE* f;
    f=fopen("ranji.txt","wb+");
    fclose(f);
    printf("\n\n\n\n\n\xB2\xB2 ALL MISSIONS DELETED SUCCESSFULLY\n");
   if(getch())
   mainmenu();
   }
   printf("\n\n\xB2\xB2 YOU ENTERED ILLEGAL CHOICE DELETING MISSIONS FAILED PRESS ANY KEY TO CONTINUE....\n");
   if(getch())
   mainmenu();

    }
    break;
  default:
  {
    printf("\aWrong Entry!!Please re-entered correct option");
    if(getch())
    mainmenu();
  }
  }
fclose(f);
}

void editcompletionstatus (int n)
{
   system("cls");
    FILE* f;
    f=fopen("ranji.txt","rb+");
    mission miss;
    for (int i=0 ; i<n; i++)
    {
        fread(&miss,sizeof(miss),1,f);
    }
   fseek(f,-sizeof(mission),SEEK_CUR);
   printf("\n\n\n\n\n\n\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
   printf("\xB2\xB2 MISSION TITLE :%s \n\n\xB2\xB2 1: EDIT MAIN MISSION STATUS \n\n\xB2\xB2 2: EDIT SUBMISSION STATUS \n\n",miss.mainmiss.missiontitle);
   printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
   printf("enter your choice or enter 'b' to go back to view list of mission :");

   switch (getch())
   {
         case '1':
        {
          label:
          system("cls");
          char s[30];
          char u[30] = "yettocome";
          printf("\n\n\xB2\xB2\xB2 enter y if this mission is completed else enter n :");
          switch(getch())
          {
          case 'y':
            {
                  fseek(f,sizeof(miss.missionno),SEEK_CUR);
                  fseek(f,sizeof(miss.mainmiss),SEEK_CUR);
                  fseek(f,-sizeof(int),SEEK_CUR);
                  fseek(f,-sizeof(int),SEEK_CUR);
                  int i=1;
                  fwrite(&i,sizeof(int),1,f);
                  time_t t = time(NULL);
                  memcpy(s,asctime(localtime(&t)),24);
                  fseek(f,-sizeof(int),SEEK_CUR);
                  fseek(f,-sizeof(s),SEEK_CUR);
                  fwrite(s,sizeof(s),1,f);
                  printf("\n\n\xB2\xB2 CONGRATULATIONS DUUUDE !!, STATUS OF MISSION IS UPDATED SUCCESSFULLY" );
            }
            break;
          case 'n':
            {
                  fseek(f,sizeof(int),SEEK_CUR);
                  fseek(f,sizeof(miss.mainmiss),SEEK_CUR);
                  fseek(f,-sizeof(int),SEEK_CUR);
                  fseek(f,-sizeof(int),SEEK_CUR);
                  int i=0;
                  fwrite(&i,sizeof(int),1,f);
                  fseek(f,-sizeof(int),SEEK_CUR);
                  fseek(f,-sizeof(s),SEEK_CUR);
                  fwrite(u,sizeof(s),1,f);
                  printf("\n\n\xB2\xB2 STATUS OF MISSION IS UPDATED SUCCESSFULLY ");
            }
            break;
         default:
            {
                  printf("\aWrong Entry!!Please re-entered correct option");
                  if(getch())
                  goto label;
            }
          }
        }

          break;
      case '2':
          {
              system("cls");
              printf("\n");
              for(int i=0 ; i<miss.submiss.submissionsadded ;i++)
            {
                printf("\xB2\xB2 SUBMISSION%d is: %s\t\t\t\xB2\xB2 STATUS: %d\n\n",i+1,miss.submiss.submissions[i],miss.submiss.submissionstatus[i]);
            }
             printf("\n\xB2\xB2 SELECT SUBMISSION TO WHICH YOU WANA ADD STATUS:");
             int d;
             scanf("%d",&d);
             fseek(f,sizeof(int),SEEK_CUR);
             fseek(f,sizeof(miss.mainmiss),SEEK_CUR);
             fseek(f,sizeof(miss.submiss),SEEK_CUR);
             fseek(f,-(21-d)*sizeof(int),SEEK_CUR);
             label2:
             system("cls");
             int i;
           //  printf("\xB2\xB2 SELECTED SUBMISSION IS : %s\n",miss.submiss.submissions[d+1]);
             printf("\n\n\xB2\xB2\xB2 enter y if this mission is completed else enter n :");
             switch(getch())
             {
               case 'y':
                 {
                 i=1;
                 fwrite(&i,sizeof(int),1,f);
                  printf("\n\n\xB2\xB2 CONGRATULATIONS DUUUDE !!, STATUS OF MISSION IS UPDATED SUCCESSFULLY" );
                 }
                 break;

               case 'n':
                 {
                 i=0;
                 fwrite(&i,sizeof(int),1,f);
                  printf("\n\n\xB2\xB2 STATUS OF MISSION IS UPDATED SUCCESSFULLY" );
                 }
                 break;
                default:
                {
                  printf("\aWrong Entry!!Please re-entered correct option");
                  if(getch())
                  goto label2;
               }
            }
          break;

        case 'b':
        submenu(n);
        break;

        default:
      {
      printf("\aWrong Entry!!Please re-entered correct option");
      if(getch())
      editcompletionstatus(n);
     }
   }
}
fclose(f);
}

char grid[HEIGHT][WIDTH];

int plot(int x, int y);
void init_grid(int);
void show_grid(void);

void plotgraph(int n)
{
    system("cls");
    FILE* f;
    f=fopen("ranji.txt","rb+");

    mission miss;
    for (int i=0 ; i<n; i++)
    {
        fread(&miss,sizeof(miss),1,f);
    }
    if (miss.prog.day==0)
    {
         printf("\n\n\n\n\xB2\xB2\xB2 NO MISSION DATA YET AVAILABLE \n");
         if(getch())
            submenu(n);
    }


    int x,y;
    int a = 110 / miss.prog.day;
    init_grid(miss.mainmiss.expectedhours);

     float s=0 ;
     int i=0;
     for(x=0;x<=miss.prog.day-1;x++,i++)
    {
       s=s+miss.prog.hoursworkedtoday[i];
       printf("hours worked at day %d is %d \n",i,miss.prog.hoursworkedtoday[i]);
    }

    int j=0;

    for(x=0;x<=miss.prog.day-1;x+=1,j++)
    {

        plot(rintf(x*a),rintf(miss.prog.hoursworkedtoday[j]));
    }

    for(x=0;x<miss.prog.day;x+=1)
    {
        printf("\n");
    }
    show_grid();

    printf("X-AXIS: DAYS\t\t\tY-AXIS: HOURS \n");
    printf("\n\n\xB2\xB2TOTAL HOURS WORKED ON THIS MISSION: %f\t\t\t\xB2\xB2TOTAL HOURS YOU SUPPOSED TO WORK: %d \n\n",s,miss.prog.day*miss.mainmiss.expectedhours);
    printf("\xB2\xB2 AVERAGE HOURS YOU WORKED: %f\t\t\t\xB2\xB2HOURS YOU NEED TO WORK PER DAY: %d \n\n",s/miss.prog.day,miss.mainmiss.expectedhours);
    printf("\xB2\xB2 HOURS YOU ARE LAGGING OR AHEAD: %f",s-miss.prog.day*miss.mainmiss.expectedhours);

    return(0);
    fclose(f);
}

/* Set "pixel" at specific coordinates */
int plot(int x, int y)
{
    if( x > XMAX || x < XMIN || y > YMAX || y < YMIN )
        return(-1);

    grid[Y-y][X+x] = '*';
    return(1);
}

/* Initialize grid */
void init_grid(int n)
{
    int x,y;

    for(y=0;y<HEIGHT;y++)
        for(x=0;x<WIDTH;x++)
            grid[y][x] = ' ';
    /* draw the axis */
    for(y=0;y<HEIGHT;y++)
        grid[y][X] = '|';
    for(x=0;x<WIDTH;x++)
        grid[Y][x] = '-';
    grid[Y][X] = '+';
     for(x=X;x<WIDTH;x++)
            grid[Y-n][x] = '-';
}

/* display grid */
void show_grid(void)
{
    int x,y;

    for(y=0;y<HEIGHT;y++)
    {
        for(x=0;x<WIDTH;x++)
            putchar(grid[y][x]);
        putchar('\n');
    }
}

void deleteparticularmission (int n)
{
    system("cls");
    FILE* f;
    FILE* p;
    p=fopen("temp.txt","wb");
    f=fopen("ranji.txt","rb");
    mission miss;

     int i=1;
     while(fread(&miss,sizeof(miss),1,f)!=0)
     {
             if(i!=n)
             {
                   fwrite(&miss,sizeof(miss),1,p);

                   i++;
                   continue;
             }


          i++;
     }

  //  printf(" both files should exists \n");
    // getch();
      fclose(f);
      fclose(p);
     if(remove("ranji.txt") == 0)
          printf("\n\n\n\n\xB2\xB2\xB2 MISSION DELETED SUCCESSFULLT PRESS ANY KEY TO VIEW ALL MISSIONS \n");
        else
          printf("\n\n\n\n\xB2\xB2\xB2 Error deleting the file \n");
   rename("temp.txt","ranji.txt");


     getch();

//        printf("total no of missions is %d\n",i-1);
          viewallmissions();


}



int main()

{

  mainmenu();

}

