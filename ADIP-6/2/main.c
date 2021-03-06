#include <stdio.h>
#include <stdlib.h>

typedef struct student{
	unsigned int MtrkNr;
	char* firstname;
	char* secondname;
	double note;
}student;

typedef struct node{
	struct node* next;
	void* data;	
}node;

typedef enum{false,true} bool;

void printStudent(student* S){
	printf("-----------------\nVorname:     %s\nNachname:    %s\nMatrikelNr.: %d\nNote:        %.3g\n",S->firstname,S->secondname,S->MtrkNr,S->note);
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
	student* newStudent = calloc(1,sizeof(student));
	printf("New Student\nEnter firstname:\n");
	char* v = malloc(256);
	char* n = malloc(256);
	scanf("%s",v);
	printf("Enter surname:\n");
	scanf("%s",n);
	printf("Enter Matrikel number:\n");
	scanf("%i",&newStudent->MtrkNr);
	newStudent->note = 6.0;
	while(!(1.0<=newStudent->note&&newStudent->note<=5.0)){
		printf("Enter grade:\n");
		scanf("%lf",&newStudent->note);
	}
	newStudent->firstname=v;
	newStudent->secondname=n;
	return newStudent;
}

void printBest(node* head){
	node* iterator = head;
	double bestgrade = 6.0;
	while(iterator->next != (void*)0){
		if(((student*)(iterator->next->data))->note < bestgrade){
			bestgrade = ((student*)(iterator->next->data))->note;
		}
		iterator = iterator->next;
	}
	iterator = head;
	while(iterator->next != (void*)0){
		if(((student*)(iterator->next->data))->note == bestgrade)
			printStudent(((student*)(iterator->next->data)));
		iterator = iterator->next;
	}
}

void printAverage(node* head){
	node* iterator = head;
	double total = 0;
	int amount = 0;
	while(iterator->next != (void*)0){
		++amount;
		total+=((student*)(iterator->next->data))->note;
		iterator = iterator->next;
	}
	if(amount != 0)
		printf("Average is: %.2g\n-----\n",total/amount);
	else{
		printf("no Students in Database\n");
	}	
}

bool hasABetterGrade(void* a, void* b){
	if(((student*)a)->note < ((student*)b)->note){
		return true;
	}else{
		return false;
	}
}
node* sortRec(node* start, node* end,bool(*compare)(void*,void*)){
	node* iterator = start;

	//if There are 1 or 2 items to sort, return accordingly
	if(end == start){
		return start;
	}else if (start->next == end){
		if(compare(end->data,start->data)){
			node* swap = end->next;
			end->next = start;
			start->next = swap;
			return end;
		}else{
			return start;
		}
	}


	//calculate length
	int length = 0;
	while(iterator->next != end){
		++length;
		iterator = iterator->next;
	}
	node* mergeStartLower = start;
	node* mergeEndUpper = end->next;
	
	//find midpoint
	length /= 2;
	node* mergeEndLower = start;
	for(int k=0;k<length;++k){
		 mergeEndLower = mergeEndLower->next;
	}

	node* mergeStartUpper = sortRec(mergeEndLower->next,end,compare);
	mergeEndLower->next = mergeStartUpper;
	mergeStartLower = sortRec(start,mergeEndLower,compare);
	
	//finding new mergeEndLower after it has been sorted
	mergeEndLower = mergeStartLower;
	while(mergeEndLower->next != mergeStartUpper){
		mergeEndLower = mergeEndLower->next;
	}
	
	//merging
	node* lowerIterator = mergeStartLower;
	node* upperIterator = mergeStartUpper;
	node* firstElement;
	node* startIterator;

	//merging - setting the first element
	if(compare(lowerIterator->data,upperIterator->data)){
		firstElement = lowerIterator;
		startIterator = lowerIterator;
		lowerIterator = lowerIterator->next;
	}else{
		firstElement = upperIterator;
		startIterator = upperIterator;
		upperIterator = upperIterator->next;
	}

	//merging - concatenating the rest to the first element, until one part is empty
	while(lowerIterator != mergeStartUpper && upperIterator != mergeEndUpper){
		if(compare(lowerIterator->data,upperIterator->data)){
			startIterator->next = lowerIterator;
			lowerIterator = lowerIterator->next;
			startIterator = startIterator->next;
		}else{
			startIterator->next = upperIterator;
			upperIterator = upperIterator->next;
			startIterator = startIterator->next;
		}
	}

	//merging - adding the rest
	if(lowerIterator != mergeStartUpper){
		startIterator->next = lowerIterator;
		mergeEndLower->next = mergeEndUpper;
	}else if(upperIterator != mergeEndUpper){
		startIterator->next = upperIterator;
	}else{
		startIterator->next = mergeEndUpper;
	}

	//return the first element, as it is the pointer to the rest of the list
	return firstElement;
}
void sort(node** head){
	node* iterator = *head;
	while(iterator->next != (void*)0){
		iterator = iterator->next;
	}
	(*head)->next = sortRec((*(head))->next,iterator,&hasABetterGrade);
}

int main(){
	node* head = calloc(sizeof(node),1);
	bool again = true;
	unsigned int mtr;
	char input;
	student* S;
	while(again){
		printf("-----\n[a]dd student\n[g]et surname by Matrikel number\n[p]rint student\n[b]beste printen\n[A]verage ausgeben\n[P]rint all students\n[s]ort Students by Grade\n[r]emove student\n[R]emove all data\n[e]xit\n-----\n");
		scanf("%c",&input);
		switch(input){
			case 's':
				sort(&head);
				printStudents(head);
				getchar();
				break;
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
			case 'b':
				printBest(head);
				getchar();
				break;
			case 'A':
				printAverage(head);
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
