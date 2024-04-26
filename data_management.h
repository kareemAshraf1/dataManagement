// data_management.h
#include <stdio.h>
#include <stdlib.h>
#ifndef DATA_MANAGEMENT_H
#define DATA_MANAGEMENT_H


struct Student {
    int id;
    char name[100];
    char degree[100];
};


// Function to read student data from file into structure based on ID
struct Student readStudentFromFile(const char *filename, int target_id);
void addStudentToFile(const char *filename, struct Student student);
#endif
