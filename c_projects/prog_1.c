#include<stdio.h>
#include<string.h>

struct Student
{
   int roll;
   char name[50];
   float c_lang_marks;
   float python_marks;
};



struct Student students[100];

int count = 0;

int isDuplicateRoll(int roll);
void addStudent();
void displayStudents();
void searchStudent();

int main()
{
    int choice;

    do
    {
        printf("\n=========================================\n");
        printf("STUDENT RECORD MANAGEMENT SYSTEM\n");
        printf("\n=========================================\n");
        printf("1. Add Student\n");
        printf("2. Display Student\n");
        printf("3. Search Students\n");
        printf("4. Exit\n");
        printf("Enter your choice:(1 or 2 or 3 or 4) ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            addStudent();
            break;

            case 2:
            displayStudents();
            break;

            case 3:
            searchStudent();
            break;

            case 4:
            printf("Thank you!\n");
            break;

            default:
            printf("Invalid choice!\n");
        }

    } while(choice != 4);
    
    return 0;
}



int isDuplicateRoll(int roll)
{
    int i;

    for(i=0; i < count; i++)
    {
        if(students[i].roll == roll)
        {
            return 1;
        }
    }

    return 0;
} 





void addStudent()
{
    if(count >= 100)
    {
        printf("Student List is Full!\n");
        return;
    }

    printf("\nEnter Roll Number : ");
    scanf("%d", &students[count].roll);
    if(isDuplicateRoll(students[count].roll))
    {
        printf("Roll Number already exists!\n");
        return;
    }
    getchar();
     
    printf("Enter Name : ");
    fgets(students[count].name,sizeof(students[count].name),stdin);

    students[count].name[strcspn(students[count].name,"\n")] = '\0';

    printf("Enter C language marks : ");
    scanf("%f", &students[count].c_lang_marks);

    printf("Enter Python MARKS : ");
    scanf("%f", &students[count].python_marks);

    count++;

    printf("\nStudent Added Successfully!\n");
} 
void displayStudents()
{
    int i;
    float average;

    if(count == 0)
    {
        printf("No Record Found!\n");
        return;
    }
    
    printf("\n------------------------------------------------------------------------------------\n");
    printf("Roll_No\tName\t\tC_Marks\tpython_Mraks\t\tAverage\n");
    printf("-------------------------------------------------------------------\n");

    for(i = 0; i < count; i++)
    {
        average = (students[i].c_lang_marks + students[i].python_marks)  /2;
        printf("%d\t%-15s\t%.2f\t%.2f\t\t\t%.2f\n",
        students[i].roll,
        students[i].name,
        students[i].c_lang_marks,
        students[i].python_marks,
        average);
    }
}
void searchStudent()
{
    int roll;
    int i;
    float average;

    if(count == 0)
    {
        printf("No Records Found!\n");
        return;
    }
        printf("\nEnter Roll Number to search : ");
        scanf("%d", &roll);
        for(i = 0; i < count; i++)
        {
            if(students[i].roll == roll)
            {
                average = (students[i].c_lang_marks + students[i].python_marks)/2;

                printf("\nstudent Found\n");
                printf("--------------------------------------\n");
                printf("Roll Numder       : %d\n", students[i].roll);
                printf("Name              : %s\n", students[i].name);
                printf("C Language Marks  : %.2f\n", students[i].c_lang_marks);
                printf("Python Marks      : %.2f\n", students[i].python_marks);
                printf("Average Marks     : %.2f\n", average);

                return ;
            }
        }
        printf("Student Not Found!\n");
}