#include<stdio.h>
#ifndef DATA_MANAGEMENT_H
#define DATA_MANAGEMENT_H
typedef struct {
    int id;
    char name[50];
    char course[50];
    float gpa;
} StudentRecord;

int readStudentRecord(const char *openfile, int target_id, StudentRecord *student);
void editStudentRecord(StudentRecord *student, const char *newName, const char *newCourse, float newGPA);

#endif // DATA_MANAGEMENT_H
