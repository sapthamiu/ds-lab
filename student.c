/*Create a structure STUDENT consisting of variables of structures:
i. DOB {day, month (use pointer ), year},
ii. STU_INFO {reg_no, name(use pointer), address},
iii. COLLEGE {college_name (use pointer), university_name}
where structure types from i to iii are declared outside the STUDENT independently.
Show how to read and display member variables of DOB type if pointer variable is created
for DOB inside STUDENT and STUDENT variable is also a pointer variable. The
program should read and display the values of all members of STUDENT structure.*/
#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int day;
	char *month;
	int year;
}DOB;
typedef struct{
	int regno;
	char* name;
	char address[100];
}STU_INFO;
typedef struct{
	char *clg;
	char uni[100];
}COLLEGE;
typedef struct{
	DOB *dob;
	STU_INFO studet;
	COLLEGE clgdet;
}STUDENT;
void read(STUDENT *st){
	st->studet.name = (char*) malloc(20*sizeof(char));
	st->dob = (DOB*) malloc(sizeof(DOB));
	st->dob->month = (char*) malloc(10*sizeof(char));
	st->clgdet.clg = (char*) malloc(20*sizeof(char));
	
	printf("Enter reg. no., name, address: ");
	scanf("%d %s %[^\n]",&st->studet.regno,st->studet.name, &st->studet.address);
	
	printf("Enter date of birth: ");
	scanf("%d %s %d",&st->dob->day, st->dob->month, &st->dob->year);
	
	printf("Enter college and university name: ");
	scanf("%s %s", st->clgdet.clg, st->clgdet.uni);
}
void disp(STUDENT *st){
	printf("\nReg. No: %d\nName: %s\nAddress: %s\nDate of Birth: %02d %s %d\nCollege: %s\nUniversity: %s", st->studet.regno, st->studet.name,st->studet.address,st->dob->day,st->dob->month, st->dob->year, st->clgdet.clg, st->clgdet.uni);
}
void main(){
	STUDENT *student = (STUDENT*) malloc(sizeof(STUDENT));
	read(student);
 	printf("\n---Student details---\n");
 	disp(student);
}
	
	
