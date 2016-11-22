#include <stdio.h>
#include <stdlib.h>

typedef struct student{
	int MtrkNr;
	char* firstname;
	char* secondname;
}student;

typedef struct node{
	struct node* next;
	void* data;	
}node;

node* head;

int printStudent(student* S){
	printf("-----------------\nVorname:     %s\nNachname:    %s\nMatrikelNr.: %d\n",S->firstname,S->secondname,S->MtrkNr);
	return EXIT_SUCCESS;
}

int removedata(student* S){
	free(S->firstname);
	free(S->secondname);
	free(S);
}

student* getStudentByMtrkNr(int MtrkNr){
	node* iterator = head;
	while(iterator->next != (void*)0){
		if( ((student*)(iterator->next->data))->MtrkNr == MtrkNr){
			return ((student*)(iterator->next->data));
		}
		iterator = iterator->next;
	}
	return (void*)0;
}

int addStudent(student* S){
	if(getStudentByMtrkNr(S->MtrkNr) == (void*)0){
		node* newStudent = malloc(sizeof(node));
		newStudent->next = (void*)0;
		newStudent->data = S;
		node* iterator = head;
		while(iterator->next != (void*)0){
			iterator = iterator->next;
		}
		iterator->next = newStudent;
		return EXIT_SUCCESS;
	}else{
		return EXIT_FAILURE;
	}
}

int removeStudent(int MtrkNr){
	node* iterator = head;
	while(iterator->next != (void*)0){
		if(((student*)(iterator->next->data))->MtrkNr == MtrkNr){ 
			node* toberemoved = iterator->next;
			iterator->next = iterator->next->next;
			removedata((student*)toberemoved->data);
			free(toberemoved);
			return EXIT_SUCCESS;
		}
		iterator = iterator->next;
	}
	return EXIT_FAILURE;
}

char* getName(int MtrkNr){
	node* iterator = head;
	while(iterator->next != (void*)0){
		if(((student*)(iterator->next->data))->MtrkNr == MtrkNr){
			return ((student*)(iterator->next->data))->secondname;	
		}
		iterator = iterator->next;
	}
	return (void*)0;
}

int clearStudents(){
	node* iterator;
	while(head->next != (void*)0){
		iterator = head->next;
		head->next=iterator->next;
		removedata((student*)iterator->data);
		free(iterator);
	}
	return EXIT_SUCCESS;
}

int printStudents(){
	node* iterator = head;
	while(iterator->next != (void*)0){
		printStudent((student*)iterator->next->data);
		iterator = iterator->next;
	}
}

student* readStudent(){
	student* newStudent = malloc(sizeof(student));
	printf("New Student\nEnter firstname:\n");
	char* v = malloc(256);
	char* n = malloc(256);
	scanf("%s",v);
	printf("Enter surname:\n");
	scanf("%s",n);
	printf("Enter Matrikel number:\n");
	scanf("%d",&newStudent->MtrkNr);
	newStudent->firstname=v;
	newStudent->secondname=n;
	return newStudent;
}

int main(){
	head = calloc(sizeof(node),1);
	int again = 1;
	int mtr;
	char input;
	student* S;
	while(again){
		printf("-----\n[a]dd student\n[g]et surname by Matrikel number\n[p]rint student\n[P]rint all students\n[r]emove student\n[R]emove all data\n[e]xit\n-----\n");
		scanf("%c",&input);
		switch(input){
			case 'a':
				S = readStudent();
				if(addStudent(S) == EXIT_SUCCESS){
					printf("Student has been added\n");
				}else{
					printf("Student with same Matrikel number already exists!\n");
				}
				getchar();
				break;
			case 'r':
				printf("Enter Matrikel number of the student:\n");
				scanf("%d",&mtr);
				if(removeStudent(mtr) == EXIT_SUCCESS){
					printf("Student has been removed\n");
				}else{
					printf("There is no student with this Matrikel number!\n");
				}
				getchar();
				break;
			case 'g':
				printf("Enter Matrikel number of the student:\n");
				scanf("%d",&mtr);
				char* name = getName(mtr);
				if(name != (void*)0){
					printf("%s is in database!\n",name);
				}else{
					printf("There is no student with this Matrikel number!\n");
				}
				getchar();
				break;
			case 'P':
				printStudents();
				getchar();
				break;
			case 'R':
				clearStudents();
				getchar();
				break;
			case 'e':
				again = 0;
				break;
			case 'p':
				printf("Enter Matrikel number of the student:\n");
				scanf("%d",&mtr);
				S = getStudentByMtrkNr(mtr);
				if(S!=(void*)0){
					printStudent(S);
				}else{
					printf("There is no student with this Matrikel number!\n");
				}
				getchar();
				break;
			default: printf("not a valid input\n");
		}
	}
	clearStudents();
	free(head);
}


