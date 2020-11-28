#include <stdio.h>
#include <string.h>

/**
 * This program demonstrates data organization using structures. We have created structure of student which hold all
 * his important data....
 *
 * @author IT MASTERS TEAM :)
 * @date 27. 11. 2020
 * @version 1.0
 *
 * @see https://www.programiz.com/c-programming/c-structures
 * @see http://www.kiwiki.info/index.php/Strcpy_(jazyk_C)
 *
 */



/**
 * Structure which holds data of a current subject
 */

typedef struct
{
    char name[20]; // name of subject, for example Maths
    char grade; // grade of this subject, for example A,B,C,D,E,F
} subject;


/**
 * Structure which holds the entire data of a student
 */

typedef struct
{
  char first_name[20]; // first name of this student, for example: Bruce
  char last_name[20]; // last name of this student, for example: Benton
  int age; // age of this student, for example: 20

  unsigned ID; // personal ID, for example: 12345

  // all subjects of this student
  // NOTE: this is an array of 5 elements of type subject (array od structures inside another structure)
  subject his_subjects[5];

} student;

/**
 * Setter: Function which sets main data of a student from its parameters.
 *
 * @param f_name -> first name of student
 * @param l_name –> last name of student
 * @param age –> age of student
 * @param ID -> personal ID of student
 *
 * @return -> structure of student with valid data
 */

student newStudent(char f_name[20], char l_name[20], int age, unsigned ID);


/**
 * Setter 1: Function which sets main data of a student from keyboard.
 * @return -> structure of student with valid data
 */

student scanStudent();

/**
 * Function prints main data of a student (name, age, ID) on the screen.
 * @param Someone -> structure of student to print
 */

void print_student_data(student Someone);

/**
 * Setter 2: Function which modify a subject data of a student.
 * @param Someone -> structure of student, where we modify data
 * @return -> structure of student with valid data
 */

student newSubjects(student Someone);

/**
 * Function prints subject data of a student (name, grade) on the screen.
 * @param Someone -> structure of student to print
 */

void print_his_subjects(student Someone);

// driver program

int main()
{

    student First = scanStudent(); // we have created a new student whose main data are loaded form the keyboard

    // after 1st semester:
    First = newSubjects(First); // we have modified his subjects and his grades

    print_student_data(First); // we printed all his data on the screen
    print_his_subjects(First);


    return 0;
}

student newStudent(char f_name[20], char l_name[20], int age, unsigned ID)
{
    student Tmp;

    Tmp.age = age;
    Tmp.ID = ID;
    strcpy(Tmp.first_name, f_name); //first and last name are char arrays (strings)!
    strcpy(Tmp.last_name, l_name);

    return Tmp;
}


student scanStudent()
{
    student Tmp;

    printf("\nEnter new name, age and personal ID\n");
    scanf("%s", Tmp.first_name);
    scanf("%s", Tmp.last_name);
    scanf("%d", &Tmp.age);
    scanf("%u", &Tmp.ID);

    return Tmp;
}

void print_student_data(student Someone)
{
    printf("\nFirst Name: %s \nLast Name: %s\n",Someone.first_name, Someone.last_name);
    printf("Age: %d \nID: %u\n",Someone.age, Someone.ID);
}


student newSubjects(student Someone)
{
    printf("Enter subject and grade of %s %s:",Someone.first_name, Someone.last_name);

    for (int i = 0; i < 5; ++i)
    {
        printf(" \n%d. subject: ",i+1);
        scanf("%s %c", Someone.his_subjects[i].name, &Someone.his_subjects[i].grade); //his_subjects is an array inside struct student
    }

    return Someone;
}

void print_his_subjects(student Someone)
{
    printf("\nHis subjects and evaluation:\n");
    for (int i = 0; i < 5; ++i)
    {
        printf("%s %c\n", Someone.his_subjects[i].name, Someone.his_subjects[i].grade);
    }
}


