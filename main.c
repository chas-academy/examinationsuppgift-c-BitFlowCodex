//Write your code in this file

#include <stdio.h>

#define STUDENTS 5
#define TESTS 13 

void capitalize_name(char name[]) {
  if (name[0] >= 'a' && name[0] <= 'z') {
    name[0] -= 32;
  }
}

float filter_student_average(float student_average[STUDENTS]) {
  float highest = 0;
  for (int i = 0; i < STUDENTS; i++) {
    if (highest < student_average[i]) {
      highest = student_average[i];
    }
  }
  return highest;
} 

void print_student_results(float highest_student_average, float class_average, char names[][11], float student_average[STUDENTS]) {
  // Student with the highest average
  for (int i = 0; i < STUDENTS; i++) {
    if (highest_student_average == student_average[i]) {
      printf("%s\n", names[i]);
    }
  }
  // Students that are below the class_average
  for (int i = 0; i < STUDENTS; i++) {
    if (class_average > student_average[i]) { 
      printf("%s\n", names[i]);
    } 
  }
}

void calculate_average(char names[][11], int scores[][TESTS]) {
  float student_average[STUDENTS] = {0};
  float class_average = 0;

  for (int i = 0; i < STUDENTS; i++) {
    capitalize_name(names[i]);
    for (int j = 0; j < TESTS; j++) {
      student_average[i] += scores[i][j]; // Sums test results per student
    }
    student_average[i] /= TESTS; // Average of all students
  } 

  for (int i = 0; i < STUDENTS; i++) {
    class_average += student_average[i];
  }
  class_average /= STUDENTS; // Class average based on all of students's averages

  float highest_student_average = filter_student_average(student_average);
  print_student_results(highest_student_average, class_average, names, student_average);
}

void input_data(char names[][11], int scores[][TESTS]) {
  for (int i = 0; i < STUDENTS; i++) {
    scanf("%s", names[i]); // store names
    for (int j = 0; j < TESTS; j++) {
      scanf("%d", &scores[i][j]); // store scores
    };
  };
}

int main() {
  char student_names[STUDENTS][11]; 
  int student_scores[STUDENTS][TESTS];
  
  input_data(student_names, student_scores);
  calculate_average(student_names,student_scores);
  return 0;
}