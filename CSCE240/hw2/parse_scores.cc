/* 
 * Copyright 2020 Matthew Graham
 */
#include "parse_scores.h" // NOLINT

// Returns a specified grade
double GetGrade(int student_id, int grade_no, const char* file_name) {
  double return_val = 0.0;
  ifstream reader;
  reader.open(file_name);
  if (!reader.is_open())
    return -3.0;
  int num_of_student;
  reader >> num_of_student;
  int id;
  for (int i = 0; i < num_of_student; ++i) {
    reader >> id;
    int no_of_grades;
    reader >> no_of_grades;
    if (grade_no <= 0 || no_of_grades <= 0)
      return -2.0;
    for (int j = 0; j < no_of_grades; ++j) {
      double grade;
      reader >> grade;
      if (student_id == id && grade_no == j+1) {
        cout << grade << endl;
        return grade;
        break;
        }
      }
    return_val = -1.0;
    }
  return return_val;
}

// Returns ID of student with highest grade
int GetMaxGradeStudentId(const char* file_name) {
  ifstream reader;
  reader.open(file_name);
  if (!reader.is_open())
    return -3;
  double grade_temp = 0.0;
  int id_temp, num_of_student;
  reader >> num_of_student;
  if (num_of_student <= 0)
    return -2;

  int id;
  for (int i = 0; i < num_of_student; ++i) {
    reader >> id;
    int no_of_grades;
    reader >> no_of_grades;
    if (no_of_grades <= 0)
      return -2;

    for (int j = 0; j < no_of_grades; ++j) {
      double grade;
      reader >> grade;
      if (grade >= 0.0) {
        if (grade > grade_temp) {
          grade_temp = grade;
          id_temp = id;
          }
        }
      }
    }
  cout << id_temp << endl;
  return id_temp;
}

// Returns avg of all student grades
double GetAvgGrade(const char* file_name) {
  ifstream reader;
  reader.open(file_name);
  if (!reader.is_open())
    return -3.0;
  double sum = 0, no_of_grades_tot = 0;
  int num_of_student;
  reader >> num_of_student;
    if (num_of_student <= 0)
      return -1.0;
  int id;
  for (int i = 0; i < num_of_student; ++i) {
    reader >> id;
    int no_of_grades;
    reader >> no_of_grades;
    if (no_of_grades <= 0)
      return -2.0;
    no_of_grades_tot += no_of_grades;
    for (int j = 0; j < no_of_grades; ++j) {
      double grade;
      reader >> grade;
      sum += grade;
      }
    }
  if (sum == 0)
    return -2.0;
  double avg = sum / no_of_grades_tot;
  cout << avg << endl;
  return avg;
}
