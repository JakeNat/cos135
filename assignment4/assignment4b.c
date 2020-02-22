#include <stdio.h>
#define MAX 20

void rankStudentGrades(int *gradeOne, int *gradeTwo, int *gradeThree) {
	int temp;

	if (gradeTwo < gradeOne) {
		temp = *gradeOne;
		*gradeOne = *gradeTwo;
		*gradeTwo = temp;
	}
}

int main() {
	char studentName[MAX];
	int * firstGrade;
	int * secondGrade;
	int * thirdGrade;

	printf("Enter student's name = ");
	fgets(studentName, MAX, stdin);

	printf("Enter student's first grade = ");
	scanf("%d", &firstGrade);

	printf("Enter student's second grade = ");
	scanf("%d", &secondGrade);

	printf("Enter student's third grade = ");
	scanf("%d", &thirdGrade);

	rankStudentGrades(firstGrade,secondGrade,thirdGrade);

	printf("%s\t%d\t%d\t%d", studentName, firstGrade, secondGrade, thirdGrade);
}
