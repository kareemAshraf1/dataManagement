#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_management.h"
/*
    Function: main

    Description:
    The main function of the program that allows users to edit student records.

    Parameters:
    None

    Returns:
    0 on successful execution, otherwise non-zero.
*/
int main() {
    const char *filename = "test.csv"; // File name containing student records
    StudentRecord student; // Declare a StudentRecord structure to store student data

    int local_nTargetId; // Variable to store the target student ID
    printf("Enter the ID of the student you want to edit: ");
    scanf("%d", &local_nTargetId); // Read the target student ID from the user

    // Attempt to read the student record with the provided ID
    if (DDM_nReadStudentRecord(filename, local_nTargetId, &student) == 0) {
        printf("Failed to find student with ID %d.\n", local_nTargetId);
        return 1;
    }

    char local_cNewName[50]; // Array of char to store the new name for the student
    char local_cNewCourse[50]; // Array of char to store the new course for the student
    float local_fNewGPA; // Variable to store the new GPA for the student

    // Prompt the user to enter the new name for the student
    printf("Enter new name for the student: ");
    scanf("%49s", &local_cNewName);

    // Prompt the user to enter the new course for the student
    printf("Enter new course for the student: ");
    scanf("%49s", &local_cNewCourse);

    // Prompt the user to enter the new GPA for the student
    printf("Enter new GPA for the student: ");
    scanf("%f", &local_fNewGPA);

    // Edit the student record with the new details provided
    DDM_vEditStudentRecord(&student, local_cNewName, local_cNewCourse, local_fNewGPA);

    // Display the updated student record
    printf("\nUpdated records:\n");
    printf("ID: %d, Name: %s, Course: %s, GPA: %.2f\n", student.id, student.name, student.course, student.gpa);

    return 0; // Return 0 indicating successful execution
}
