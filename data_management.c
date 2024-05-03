/*
***************************************************************
@file        data_management.c
@version     1.0.0
@brief       data management module.
@details     this file contains the data management module which responsible for edit student data.
@author      kareem ashraf.
@Created     on may 3, 2024.
***************************************************************
*/
#include "data_management.h"
/*
    Function: DDM_nReadStudentRecord

    Description:
    Reads student records from a file until the target student ID is found.

    Parameters:
    openfile - A pointer to the string containing the file name to be opened.
    local_nTargetId - The target student ID to search for.
    student - A pointer to the StudentRecord structure where the data will be stored.

    Returns:
    1 if the target student ID is found, otherwise 0.
*/
int DDM_nReadStudentRecord(const char *openfile, int local_nTargetId, StudentRecord *student) {
    FILE *file = fopen(openfile, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 0;
    }

    while (fscanf(file, "%d,%49[^,],%49[^,],%f\n", &student->id, student->name, student->course, &student->gpa) == 4) {
        if (student->id == local_nTargetId) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}
/*
    Function: DDM_vEditStudentRecord

    Description:
    Edits the details of a student record if new values are provided.

    Parameters:
    student - A pointer to the StudentRecord structure to be edited.
    local_cNewName - A pointer to the string containing the new name.
    local_cNewCourse - A pointer to the string containing the new course.
    local_fNewGPA - The new GPA value.

    Returns:
    None
*/
void DDM_vEditStudentRecord(StudentRecord *student, const char *local_cNewName, const char *local_cNewCourse, float local_fNewGPA) {
    if (local_cNewName != NULL) {
        strcpy(student->name, local_cNewName);
    }
    if (local_cNewCourse != NULL) {
        strcpy(student->course, local_cNewCourse);
    }
    if (local_fNewGPA >= 0) {
        student->gpa = local_fNewGPA;
    }
    printf("Record with ID %d has been updated.\n", student->id);
}
