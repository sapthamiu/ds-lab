/*Write a C program to implement the following functions. Use pointers and
dynamic memory management functions.
i. To read one Student object where Student is a structure with name, roll
number and CGPA as the data members 
ii. To display one Student object
iii. To sort an array of Student structures according to the roll number.*/
#include<stdio.h>
#include<stdlib.h>
typedef struct{
	char name[20];
	int rollno;
	float cgpa;
}Student;
void read(Student *st){
	printf("Enter name, roll no. and cgpa of student: ");
	scanf("%s %d %f", st->name, &st->rollno, &st->cgpa);
}
void disp(Student *st){
	printf("\nName: %s\nRoll No.: %d\nCGPA: %.2f", st->name, st->rollno, st->cgpa);
}
void sort(Student *st, int n){
	for(int i = 0; i<n-1; i++){
		int small = i;
		for(int j = i+1; j<n; j++){
			if(st[j].rollno < st[small].rollno)
				small = j;
		}
		Student temp = st[small];
		st[small] = st[i];
		st[i] = temp;
	}
}
void main(){
	int n;
	printf("enter n. of students: ");
	scanf("%d", &n);
	Student *s = (Student*) malloc(n * sizeof(Student));
	for(int i = 0; i<n; i++)
		read(&s[i]);
	printf("\n---Student Details---\n");
	for(int i = 0; i<n; i++)
		disp(&s[i]);
	printf("\n---Sorted Student Details---\n");
	sort(s,n);
	for(int i = 0; i<n; i++)
		disp(&s[i]);
}
	

