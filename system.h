
struct person{
char name[20];
int age;
char phone[15];
};
int option;

struct student {
int id;
char name[20];
int age;
char grade[10];
char phone[15];
struct person father;
struct person mother;
struct person* brothers;

int no_brothers;

};

struct student scan(void);




