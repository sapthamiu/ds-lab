/*Samuel wants to store the data of his employees, which includes the following fields:
(i) Name of the employee (ii) Date of birth which is a collection of {day, month, year}
(iii) Address which is a collection of {house number, zip code and state}. Write a 'C'
program to read and display the data of N employees using pointers to array of
structures.*/
#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int day;
	char month[10];
	int year;
}DOB;
typedef struct{
	int hno;
	int zip;
	char state[20];
}Address;
typedef struct{
	char name[20];
	DOB dob;
	Address add;
}Employee;
void read(Employee *emp){
	printf("Enter name and dob in dd mm yyyy format: ");
	scanf("%s %d %s %d", emp->name, &emp->dob.day, emp->dob.month, &emp->dob.year);
	printf("Enter house number, zip code and state: ");
	scanf("%d %d %s", &emp->add.hno, &emp->add.zip, emp->add.state);
}
void disp(Employee *emp){
	printf("\nName: %s\nDOB: %02d-%s-%d\nAddress:\nHouse no.: %d\nZip code: %d\nState: %s", emp->name, emp->dob.day, emp->dob.month, emp->dob.year, emp->add.hno, emp->add.zip, emp->add.state);
}
void main(){
	int n;
	printf("Enter number of employees: "); 
	scanf("%d", &n);
	Employee *emp = (Employee*)malloc(n * sizeof(Employee));
	for(int i =0; i<n; i++){
		printf("Details of employee %d:\n",i+1);
		read(&emp[i]);
	}
	printf("\n---Employee Details---\n");
	for(int i =0; i<n;i++)
		disp(&emp[i]);
}
	
