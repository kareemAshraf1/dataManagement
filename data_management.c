#include <stdio.h>
#include "data_management.h"

struct Student readStudentFromFile(const char *filename, int target_id) {
    struct Student student;
    FILE *file = fopen(filename, "r");

    // Read data from file line by line
    while (fscanf(file, "%d, %99[^,], %99[^\n]", &student.id, student.name, student.degree) == 3) { //#
       if (student.id == target_id) {
            fclose(file);
            return student;
        }
    }
    student.id = 0;
    fclose(file);
    return student;
}

void addStudentToFile(const char *filename, struct Student student) {
    FILE *file = fopen(filename, "a"); // Open file in append mode

    // Write student data to file
    fprintf(file, "%d,%s,%s\n", student.id, student.name, student.degree);

     fclose(file);
}

void deleteStudentFromFile(const char *filename, int target_id) {
    FILE *tempFile;
    FILE *file = fopen(filename, "r");
    tempFile = fopen("temp.csv", "w"); // #

    struct Student student;

    // Read data from file line by line
    while (fscanf(file, "%d, %99[^,], %99[^\n]", &student.id, student.name, student.degree) == 3) { // #
        if (student.id != target_id) {
            fprintf(tempFile, "%d,%s,%s\n", student.id, student.name, student.degree);
        }
    }

    fclose(file);
    fclose(tempFile);

    // Remove original file
    remove(filename);

    // Rename temporary file to original file
    rename("temp.csv", filename);
}
