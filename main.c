#include<stdio.h>
#include "data_management.h"

int main() {
    const char *filename = "test.csv";
    int target_id,choose=0;
    // choose the operation you want
    printf(" Enter 1 to display student data  \n");
    printf(" Enter 2 to Add student data      \n ");
    printf("Enter 3 to delete student data   \n ");
    printf("Enter 4 to update student data   \n");
    scanf("%d",&choose);
    if(choose == 1){

    printf("Enter the ID of the student: ");
    scanf("%d", &target_id);

    // Read student data from file into structure based on given ID
    struct Student student = readStudentFromFile(filename, target_id);

    // Check if student with given ID exists
    if (student.id != 0) {
        // Print the data
        printf("Student ID: %d\n", student.id);
        printf("Name: %s\n", student.name);
        printf("Degree: %s\n", student.degree);
    } else {
        printf("Student with ID %d not found.\n", target_id);
    }
}else if(choose == 2){
   struct Student student;

    // Get student data from user
    printf("Enter student ID: ");
    scanf("%d", &student.id);

    printf("Enter student name: ");
    scanf("%s", &student.name);

    printf("Enter student degree: ");
    scanf("%s", &student.degree);

    // Add student data to file
    addStudentToFile(filename, student);

    printf("Student data added to file successfully.\n");

    }else if(choose == 3){
    printf("Enter ID of student to delete : ");

    scanf("%d", &target_id);

    // Read student data from file into structure based on given ID
    struct Student student = readStudentFromFile(filename, target_id);

    // Check if student with given ID exists
    if (student.id != 0) {
            int per;
        // Print the data
        printf("Student ID: %d\n", student.id);
        printf("Name: %s\n", student.name);
        printf("Degree: %s\n", student.degree);
        printf("To delete enter 0 : ");
        scanf("%d",&per);
    if(per == 0){
        deleteStudentFromFile(filename,target_id);
    }
    } else {
        printf("Student with ID %d not found.\n", target_id);
    }
    }

    return 0;
}
