#include <stdio.h>
#define MAX 20

void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;

	return;
}


void rankStudentGrades(int *gradeOne, int *gradeTwo, int *gradeThree) {

	if (*gradeOne > *gradeTwo) {
		swap(gradeOne,gradeTwo);
	}
	if (*gradeTwo > *gradeThree) {
		swap(gradeThree,gradeTwo);
	}
	if (*gradeTwo < *gradeOne) {
		swap(gradeOne,gradeTwo);
	}
}

int calcAverage(int gradeOne, int gradeTwo, int gradeThree) {
	int average;
	int sum;

	sum = gradeOne + gradeTwo + gradeThree;
	average = sum / 3;

	return average;
}

int main() {
	char studentName[MAX];
	int firstGrade;
	int secondGrade;
	int thirdGrade;
	float averageGrade;

	printf("Enter student's name = ");
	fgets(studentName, MAX, stdin);

	printf("Enter student's first grade = ");
	scanf("%d", &firstGrade);

	printf("Enter student's second grade = ");
	scanf("%d", &secondGrade);

	printf("Enter student's third grade = ");
	scanf("%d", &thirdGrade);

	averageGrade = calcAverage(firstGrade,secondGrade,thirdGrade);

	rankStudentGrades(&firstGrade,&secondGrade,&thirdGrade);

	printf("%s\t%d\t%d\t%d\t%.2f", studentName, firstGrade, secondGrade, thirdGrade, averageGrade);
}
