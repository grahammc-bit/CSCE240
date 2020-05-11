/* Copyright 2020 CSCE 240 Spring */

#include <iostream>

#include "../hw2/parse_scores.h"

bool TestGetGradeGood(const char* filename);
bool TestGetGradeNoStudent(const char* filename);
bool TestGetGradeNoGrades(const char* filename);
bool TestGetGradeNoFile(const char* filename);

bool TestGetMaxGradeGood(const char* filename);
bool TestGetMaxGradeNoStudents(const char* filename);
bool TestGetMaxGradeNoGrades(const char* filename);
bool TestGetMaxGradeNoFile(const char* filename);

bool TestGetAvgGradeGood(const char* filename);
bool TestGetAvgGradeNoStduents(const char* filename);
bool TestGetAvgGradeNoGrades(const char* filename);
bool TestGetAvgGradeNoFile(const char* filename);

int main(int argc, char* argv[]) {
  int return_val = 0;

  const int kFilenameIdx = 1;
  if (argc <= kFilenameIdx) {
    std::cout
      << "ERROR: Missing Filename\n\tUsage: test_parse_scores filename"
      << std::endl;
    return 1;
  }

  std::cout << "Testing function GetGrade: ";
  if (TestGetGradeGood(argv[kFilenameIdx])) {
    std::cout << "PASSED" << std::endl;
  } else {
    std::cout << "FAILED" << std::endl;
    return_val = 1;
  }

  std::cout << "Testing function GetMaxGradeStudentId: ";
  if (TestGetMaxGradeGood(argv[kFilenameIdx])) {
    std::cout << "PASSED" << std::endl;
  } else {
    std::cout << "FAILED" << std::endl;
    return_val = 1;
  }

  std::cout << "Testing function GetAvgGradeStudentId: ";
  if (TestGetAvgGradeGood(argv[kFilenameIdx])) {
    std::cout << "PASSED" << std::endl;
  } else {
    std::cout << "FAILED" << std::endl;
    return_val = 1;
  }

  return return_val;
}

bool TestGetGradeGood(const char* filename) {
  return GetGrade(101, 2, filename) == 40.0
    && GetGrade(294, 3, filename) == 30.0
    && GetGrade(376, 1, filename) == 75.0;
}

bool TestGetMaxGradeGood(const char* filename) {
  return GetMaxGradeStudentId(filename) == 376;
}

bool TestGetAvgGradeGood(const char* filename) {
  return GetAvgGrade(filename)
    == (60.0 + 40.0 + 10.0 + 20.0 + 30.0 + 75.0) / 6.0;
}
