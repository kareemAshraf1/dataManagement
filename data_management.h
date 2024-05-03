#include<stdio.h>
#ifndef DATA_MANAGEMENT_H
#define DATA_MANAGEMENT_H
typedef struct {
    int id;
    char name[50];
    char course[50];
    float gpa;
} StudentRecord;

int DDM_nReadStudentRecord(const char *openfile,int local_nTargetId, StudentRecord *student);
void DDM_vEditStudentRecord(StudentRecord *student, const char *local_cNewName, const char *local_cNewCourse, float local_fNewGPA);

#endif // DATA_MANAGEMENT_H
