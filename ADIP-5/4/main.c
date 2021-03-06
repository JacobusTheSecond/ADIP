#include <stdio.h>
#include <stdlib.h>

typedef struct student{
	unsigned int MtrkNr;
	char* firstname;
	char* secondname;
}student;

typedef struct node{
	struct node* next;
	void* data;	
}node;

typedef enum{false,true} bool;

void printStudent(student* S){
	printf("-----------------\nVorname:     %s\nNachname:    %s\nMatrikelNr.: %d\n",S->firstname,S->secondname,S->MtrkNr);
}

void removedata(student* S){
	free(S->firstname);
	free(S->secondname);
	free(S);
}

student* getStudentByMtrkNr(node* head, unsigned int MtrkNr){
	node* iterator = head;
	while(iterator->next != (void*)0){
		if( ((student*)(iterator->next->data))->MtrkNr == MtrkNr){
			return ((student*)(iterator->next->data));
		}
		iterator = iterator->next;
	}
	return (void*)0;
}

bool addStudent(node* head, student* S){
	if(getStudentByMtrkNr(head,S->MtrkNr) == (void*)0){
		node* newStudent = malloc(sizeof(node));
		newStudent->next = (void*)0;
		newStudent->data = S;
		node* iterator = head;
		while(iterator->next != (void*)0){
			iterator = iterator->next;
		}
		iterator->next = newStudent;
		return true;
	}else{
		return false;
	}
}

bool removeStudent(node* head, unsigned int MtrkNr){
	node* iterator = head;
	while(iterator->next != (void*)0){
		if(((student*)(iterator->next->data))->MtrkNr == MtrkNr){ 
			node* toberemoved = iterator->next;
			iterator->next = iterator->next->next;
			removedata((student*)toberemoved->data);
			free(toberemoved);
			return true;
		}
		iterator = iterator->next;
	}
	return false;
}

char* getName(node* head, unsigned int MtrkNr){
	node* iterator = head;
	while(iterator->next != (void*)0){
		if(((student*)(iterator->next->data))->MtrkNr == MtrkNr){
			return ((student*)(iterator->next->data))->secondname;	
		}
		iterator = iterator->next;
	}
	return (void*)0;
}

bool clearStudents(node* head){
	node* iterator;
	while(head->next != (void*)0){
		iterator = head->next;
		head->next=iterator->next;
		removedata((student*)iterator->data);
		free(iterator);
	}
	return true;
}

void printStudents(node* head){
	node* iterator = head;
	while(iterator->next != (void*)0){
		printStudent((student*)iterator->next->data);
		iterator = iterator->next;
	}
}

student* readStudent(node* head){
	student* newStudent = malloc(sizeof(student));
	printf("New Student\nEnter firstname:\n");
	char* v = malloc(256);
	char* n = malloc(256);
	scanf("%s",v);
	printf("Enter surname:\n");
	scanf("%s",n);
	printf("Enter Matrikel number:\n");
	scanf("%i",&newStudent->MtrkNr);
	newStudent->firstname=v;
	newStudent->secondname=n;
	return newStudent;
}

int main(){
	node* head = calloc(sizeof(node),1);
	bool again = true;
	unsigned int mtr;
	char input;
	student* S;
	while(again){
		printf("-----\n[a]dd student\n[g]et surname by Matrikel number\n[p]rint student\n[P]rint all students\n[r]emove student\n[R]emove all data\n[e]xit\n-----\n");
		scanf("%c",&input);
		switch(input){
			case 'a':
				S = readStudent(head);
				if(addStudent(head,S)){
					printf("Student has been added\n");
				}else{
					printf("Student with same Matrikel number already exists!\n");
				}
				getchar();
				break;
			case 'r':
				printf("Enter Matrikel number of the student:\n");
				scanf("%d",&mtr);
				if(removeStudent(head,mtr)){
					printf("Student has been removed\n");
				}else{
					printf("There is no student with this Matrikel number!\n");
				}
				getchar();
				break;
			case 'g':
				printf("Enter Matrikel number of the student:\n");
				scanf("%d",&mtr);
				char* name = getName(head,mtr);
				if(name != (void*)0){
					printf("%s is in database!\n",name);
				}else{
					printf("There is no student with this Matrikel number!\n");
				}
				getchar();
				break;
			case 'P':
				printStudents(head);
				getchar();
				break;
			case 'R':
				clearStudents(head);
				getchar();
				break;
			case 'e':
				again = false;
				break;
			case 'p':
				printf("Enter Matrikel number of the student:\n");
				scanf("%d",&mtr);
				S = getStudentByMtrkNr(head,mtr);
				if(S!=(void*)0){
					printStudent(S);
				}else{
					printf("There is no student with this Matrikel number!\n");
				}
				getchar();
				break;
			default: 
				printf("not a valid input\n");
				getchar();
		}
	}
	clearStudents(head);
	free(head);
	return EXIT_SUCCESS;
}
