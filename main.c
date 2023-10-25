#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "system.h"


//animation
void print_progress(int percent)
{
  const int mul = 2; // width factor
  percent = min(100, percent);

  // spinning animation
  static int spin_index = 0;
  char spinning[] = "_-\\|/-";

  // bar filler
  int len = (percent * mul / 10) + 1;
  char *bar = malloc(len);
  memset(bar, '<', len - 1);
  bar[len - 1] = 0;

  // write display

  printf("%c Loading: [%*s] %*d%%\r",
         percent == 100 ? ' ' : spinning[spin_index],
         mul * 10, bar,
         3, percent
        );
  spin_index = (spin_index + 1) % strlen(spinning);

  free(bar);
}

//--------------------------------

struct student scan(void);

int main()
{



 printf("SCHOOL SYSTEM Is Loading...\n");
    for (int i = 10; i <= 100; i += 5)
    {
        print_progress(i);
        Sleep(180);
    }

    system("cls");

//-----------------------------------------------------------------




 int option,exist_id,index,edit_op,edited;
    struct student s1;
    struct student s2[50];

    int check,count=0;


while(1){
  start_system();
  scanf("%d",&option);

struct student scan(void);
 if(option==1){

            system("cls");
            s1 =scan();
            check= check_id(s2,s1.id,count);

            if(check){
                s2[count]=s1;
                count++;
            }else{

                system("cls");
                printf("\n\n\033[1;31mThis ID Is Already Exist!\033[1;37m");

                Sleep(3000);

            }
            system("cls");



 }else if(option==2){
    system("cls");

    printf("ID: ");
    scanf("%d",&exist_id);
    int flag=0;
    for(int i=0;i<count;i++){
        if(exist_id==s2[i].id){
            index=i;
            flag=1;
        }
    }
     if(flag == 1){
                system("cls");
                printf("Options to edit: \n");
                printf("1- Name\n");
                printf("2- ID\n");
                printf("3- Age\n");
                printf("4- Phone\n\n");
                printf("Choose: ");
                scanf("%d", &edit_op);

                if(edit_op == 1){

                   edit_ItemName(s2, index);
                    system("cls");
                }

                if(edit_op == 2){
                    edit_Itemid(s2, index);
                    system("cls");
                }

                if(edit_op == 3){
                    edit_Itemage(s2, index);
                    system("cls");
                }

                if(edit_op == 4){
                    edit_Itemphone(s2, index);
                    system("cls");
                }

            }

        else{
            system("cls");
            printf("\n\033[1;31mNot Exist!\033[1;37m");
            Sleep(3000);
            system("cls");

        }


 }else if(option==3){

      system("cls");
            printf("ID: ");
            scanf("%d", &exist_id);
            printf("\n\n\n\n");
            print_student(s2, exist_id, count);


 }else if(option==4){

     system("cls");
            printf("ID: ");
            scanf("%d", &exist_id);
            printf("\n\n\n\n");
            call_student(s2,exist_id,count);


 }else if(option==5){

 system("cls");
 printf("ID: ");
 scanf("%d",&exist_id);
 printf("\n\n\n");

 saerch_student(s2,exist_id,count);

 }else if(option==6){
   printAll(s2,count);

 }else{

 system("cls") ;
 printf("\033[1;31mGood Bye\033[0m\n");
 return -1;



 }
}


    return 0;
}
