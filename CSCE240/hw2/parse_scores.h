// Copyright 2020 Matthew Graham
#ifndef _HW2_PARSE_SCORES_H_
#define _HW2_PARSE_SCORES_H_
#include <fstream>// For reading of files
using std::ifstream;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;

/* Description:
 *   Extracts a single grade for a given student and given grade number.
 * Preconditions:
 * - If file exists, it is correctly formatted
 * Parameters:
 * - student_id: the id of the student for grade
 * - grade_no: the grade to be returned for matching student_id
 * - file_name: path and name of gradebook file
 * Returns:
 * - Grade selected
 * - floating point -1.0 when student is not found (or no students exist)
 * - floating point -2.0 when grade_no is not found (or no student grades)
 * - floating point -3.0 when file cannot be opened
 */
double GetGrade(int student_id, int grade_no, const char* file_name);


/* Description:
 *   Extracts the id of the student with the highest grade.
 * Preconditions:
 * - If file exists, it is correctly formatted
 * - Grades are nonnegative.
 * Parameters:
 * - file_name: path and name of gradebook file
 * Returns:
 * - The id of the student with the highest grade.
 * - Integer -1 when no students exist
 * - Integer -2 when no grades exist for students
 * - Integer -3 when the file cannot be opened
 */
int GetMaxGradeStudentId(const char* file_name);


/* Description:
 *   Calculates the average for all students in file.
 * Preconditions:
 * - If file exists, it is correctly formatted
 * - Grades are nonnegative. Adjust accordingly.
 * Parameters:
 * - file_name: path and name of gradebook file
 * Returns:
 * - The highest grade found.
 * - Floating point -1.0 when no students exist
 * - Floating point -2.0 when no grades exist
 * - Floating point -3.0 when the file cannot be opened
 */
double GetAvgGrade(const char* file_name);
#endif
