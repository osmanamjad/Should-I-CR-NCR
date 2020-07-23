#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define MAX_INPUT 15 
int main()
{
    char buf[MAX_INPUT];
    char grad_cgpa[MAX_INPUT];
    char crse_gpa[MAX_INPUT];
    char grade[MAX_INPUT];
    double total = 0;
    double cgpa = 0;
    double expected_cgpa;
    double graduat_cgpa = 0;
    double course_gpa = 0;
    int num_courses = 0;
    printf("If you have your cGPA from courses you've completed, please type it in. Otherwise, type in 'n'.\n");
    fgets(buf, MAX_INPUT, stdin);
    if (strcmp(buf, "n\n") == 0 || strcmp(buf, "'n'\n") == 0) {
        printf("Please type in each of your official final grades followed by an enter. Press enter twice to move on.\n");
        while (strcmp(fgets(grade, MAX_INPUT, stdin), "\n") != 0) {
            num_courses++;
            total += atof(grade);
        }
        cgpa = total / num_courses;
    }
    else {
        cgpa = atof(buf);
        char courses[MAX_INPUT];
        printf("Please type in the number of courses this cGPA is based on. Do not include courses that have been cr/ncred in the past.\n");
        fgets(courses, MAX_INPUT, stdin);
        num_courses = atoi(courses);
        total += num_courses * cgpa;
    }
    printf("Your cGPA based on %d courses is: %f.\n", num_courses, cgpa);
    printf("Please type in each expected GPA of courses you are not considering cr/ncr and you have no official final grade currently - each of them followed by pressing enter. Press enter twice to move on.\n");
    while (strcmp(fgets(grade, MAX_INPUT, stdin), "\n") != 0) {
        num_courses++;
        total += atof(grade);
    }
    expected_cgpa = total / num_courses;
    printf("Your expected cGPA after completing %d courses (excluding cr/ncr courses) is: %f.\n", num_courses, expected_cgpa);
    printf("Please type in the expected GPA of the course you're unsure about cr/ncring.\n");
    fgets(crse_gpa, MAX_INPUT, stdin);
    course_gpa = atof(crse_gpa);
    printf("Please type in your expected cGPA upon graduation. Be a little pessimistic. Type in your current cGPA if you are unsure.\n");
    fgets(grad_cgpa, MAX_INPUT, stdin);
    graduat_cgpa = atof(grad_cgpa);
    // 6 + 1 cases to consider
    if (course_gpa < expected_cgpa && expected_cgpa <= graduat_cgpa) {
        printf("You want to graduate with a cGPA of, %f, and your current expected cGPA is, %f, so you should cr/ncr this course with GPA, %f.\n", graduat_cgpa, expected_cgpa, course_gpa);
    }
    else if (course_gpa > expected_cgpa && course_gpa <= graduat_cgpa) {
        printf("You want to graduate with a cGPA of, %f, and your current expected cGPA is, %f, so you should NOT cr/ncr this course with GPA, %f.\n", graduat_cgpa, expected_cgpa, course_gpa);
    }
    else if (course_gpa < expected_cgpa && course_gpa >= graduat_cgpa) {
        printf("You want to graduate with a cGPA of, %f, and your current expected cGPA is, %f, so you should NOT cr/ncr this course with GPA, %f.\n", graduat_cgpa, expected_cgpa, course_gpa);
    }
    else if (course_gpa > expected_cgpa && expected_cgpa >= graduat_cgpa) {
        printf("You want to graduate with a cGPA of, %f, and your current expected cGPA is, %f, so you should NOT cr/ncr this course with GPA, %f.\n", graduat_cgpa, expected_cgpa, course_gpa);
    }
    else if (course_gpa >= expected_cgpa && expected_cgpa < graduat_cgpa) {
        printf("You want to graduate with a cGPA of, %f, and your current expected cGPA is, %f, so you should NOT cr/ncr this course with GPA, %f.\n", graduat_cgpa, expected_cgpa, course_gpa);
    }
    else if (course_gpa <= expected_cgpa && expected_cgpa > graduat_cgpa) {
        printf("You want to graduate with a cGPA of, %f, and your current expected cGPA is, %f, so you should cr/ncr this course with GPA, %f.\n", graduat_cgpa, expected_cgpa, course_gpa);
    }
    else if (course_gpa == expected_cgpa && expected_cgpa == graduat_cgpa) {
        printf("You want to graduate with a cGPA of, %f, and your current expected cGPA is, %f, so it won't make a difference whether or not you cr/ncr this course with GPA, %f.\n", graduat_cgpa, expected_cgpa, course_gpa);
    }
    return 0;
}
