#include "dataManagement.h"
int readStudentRecord(const char *openfile, int target_id, StudentRecord *student) {
    FILE *file = fopen(openfile, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 0;
    }

    while (fscanf(file, "%d,%49[^,],%49[^,],%f\n", &student->id, student->name, student->course, &student->gpa) == 4) {
        if (student->id == target_id) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

void editStudentRecord(StudentRecord *student, const char *newName, const char *newCourse, float newGPA) {
    if (newName != NULL) {
        strcpy(student->name, newName);
    }
    if (newCourse != NULL) {
        strcpy(student->course, newCourse);
    }
    if (newGPA >= 0) {
        student->gpa = newGPA;
    }
    printf("Record with ID %d has been updated.\n", student->id);
}
