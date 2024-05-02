#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataManagement.h"
int main() {
    const char *filename = "test.csv";
    StudentRecord student;

    int targetId;
    printf("Enter the ID of the student you want to edit: ");
    scanf("%d", &targetId);

    if (readStudentRecord(filename, targetId, &student) == 0) {
        printf("Failed to find student with ID %d.\n", targetId);
        return 1;
    }

    char newName[50];
    char newCourse[50];
    float newGPA;

    printf("Enter new name for the student: ");
    scanf("%49s", newName);

    printf("Enter new course for the student: ");
    scanf("%49s", newCourse);

    printf("Enter new GPA for the student: ");
    scanf("%f", &newGPA);

    editStudentRecord(&student, newName, newCourse, newGPA);

    printf("\nUpdated records:\n");
    printf("ID: %d, Name: %s, Course: %s, GPA: %.2f\n", student.id, student.name, student.course, student.gpa);

    return 0;
}
