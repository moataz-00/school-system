#include <stdio.h>
#include <stdlib.h>
#include "system.h"




void start_system(void){

printf("hello sir,how are you\n");
printf("please select an option\n");
printf("1- Enter 1 to Add Student\n");
printf("2- Enter 2 to Edit Student\n");
printf("3- Enter 3 to Print Student\n");
printf("4- Enter 4 to Call Student\n");
printf("5- Enter 5 to Search About Student\n");
printf("6- Enter 6 to Print All Students\n");
printf("7- Enter any number to exit\n\n\n");




}




//insert student


struct student scan(void){

    printf("welcome to insert mode\n\n");

struct student s;

printf("Name:");
scanf("%s",&s.name);

printf("ID:");
scanf("%d",&s.id);

printf("Age:");
scanf("%d",&s.age);

printf("Grade:");
scanf("%s",&s.grade);

printf("Phone:");
scanf("%s",&s.phone);



return s;

};

//----------------------------------------------------

// check id

int check_id(struct student *arr,int id,int size){
    int flag=1;
    int i;
for(i=0;i<size;i++){
    if(arr[i].id==id){
        flag=0;
        break;
    }

}

return flag;
}

//----------------------

// edit name

struct student edit_name(struct student*arr,int index){

struct student s;

printf("\nName:");
scanf("%s",&s.name);

s.age=arr[index].age;
s.id=arr[index].id;

for(int i=0;i<12;i++){
    s.phone[i]=arr[index].phone[i];
}

return s;


};

void edit_ItemName(struct student *arr, int index){

    arr[index]=edit_name(arr, index);

}

//------------------------------------------

//edit id

struct student edit_id(struct student*arr,int index){

struct student s;

printf("\nID:");
scanf("%d",&s.id);

s.age=arr[index].age;

for(int i=0;i<20;i++){
    s.name[i]=arr[index].name[i];
}


for(int i=0;i<12;i++){
    s.phone[i]=arr[index].phone[i];
}

return s;


};

void edit_Itemid(struct student *arr, int index){

    arr[index]=edit_id(arr, index);

}

//---------------------------------------

//edit age

struct student edit_age(struct student*arr,int index){

struct student s;

printf("\nAge:");
scanf("%d",&s.age);

s.id=arr[index].id;

for(int i=0;i<20;i++){
    s.name[i]=arr[index].name[i];
}


for(int i=0;i<12;i++){
    s.phone[i]=arr[index].phone[i];
}

return s;


};

void edit_Itemage(struct student *arr, int index){

    arr[index]=edit_age(arr, index);

}

//---------------------------------------

//edit phone

struct student edit_phone(struct student*arr,int index){

struct student s;

printf("\nPhone:");
scanf("%s",&s.phone);

s.id=arr[index].id;
s.age=arr[index].age;

for(int i=0;i<20;i++){
    s.name[i]=arr[index].name[i];
}




return s;


};

void edit_Itemphone(struct student *arr, int index){

    arr[index]=edit_phone(arr, index);

}

//-----------------------------------

// Function to print one student
void print_student(struct student *arr,int ID, int size){

    int flag = 0, index;
    for(int i = 0; i < size; i++){

        if(arr[i].id == ID){
            flag = 1;
            index = i;
            break;
        }

    }

    if(flag == 1){

        printf(" \033[1;37m------------------------------------------------------------------------------------------------------------------\n");
        printf("\033[1;35m|     \033[1;31mFirst Name  |     \033[1;33mID   |     \033[1;32mAge       |  \033[1;34mGrade      |  \033[1;34mPhone     |\n");
        printf(" \033[1;37m------------------------------------------------------------------------------------------------------------------\n");

        printf("\033[1;35m|     \033[1;37m%-8s  \033[1;36m|  \033[1;37m%-3d     \033[1;33m  |      \033[1;37m%-3d\033[1;32m     |      \033[1;37m%-11s \033[1;34m|     \033[1;37m%-11s \033[1;34m|\n", arr[index].name,arr[index].id, arr[index].age, arr[index].grade,arr[index].phone);
        printf(" \033[1;37m------------------------------------------------------------------------------------------------------------------\n");


    }

    else{
        printf("\n\033[1;31mNot Exist!\033[1;37m");
        Sleep(3000);
        system("cls");
        return;
    }


}
//---------------------------------------------

//print all
void printAll(struct student *arr,int size)
{

    system("cls");

    printf("   name    |  age  |  grade   |  phone\n");
    int i;
    for(i=0; i<size; i++)
    {
  printf("  %-8s  |  %4d |  %s  |  %s\n",arr[i].name,arr[i].age,arr[i].grade,arr[i].phone);
    }

printf("\n\n\n============================\n\n\n");


}


//---------------------------------------------


// Function to Call Student
void call_student(struct student *arr,int ID, int size){

    int c = 0, i = 0, flag = 0, index;

    for(int i = 0; i < size; i++){

        if(arr[i].id == ID){
            flag = 1;
            index = i;
            break;
        }

    }

    if(flag == 1){
        printf("\n\n%s ", arr[index].phone);
    }

    else{
        printf("\n\033[1;31mNot Exist!\033[1;37m");
        Sleep(3000);
        system("cls");
        return;
    }


    while(1){
        printf(".");
        Sleep(500);
        i++;
        if(i == 3){
            for(int i = 0; i < 3; i++){
                printf(" \b\b\b ");
                Sleep(500);
            }
            i = 0;
            c++;
        }

        if(c == 5){
            printf("\n\033[1;31mNo Reply\n\n\033[1;37m");
            Sleep(3000);
            system("cls");
            break;
        }

    }

}

//-------------------------------------

//search function

void saerch_student(struct student*arr,int id,int size){
    int index;
    int flag;
    for(int i=0;i<size;i++){
        if(arr[i].id==id){
            index=i;
            flag=1;
            break;
        }
    }

    if(flag==1){
        printf("found at index: \033[1;31m%d\033[0m  | name: \033[1;34m%s\033[0m | age: \033[1;32m%d\033[0m | Grade: \033[1;34m%s\033[0m | phone: \033[1;32m%s\033[0m ",index,arr[index].name,arr[index].age,arr[index].grade,arr[index].phone);

    }else{
    printf("\033[1;31mNot Found\033[0m");
    }
    printf("\n\n\n==============================\n\n\n");
}

