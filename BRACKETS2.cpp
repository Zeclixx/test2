#define SIZE 10001
#include <stdio.h>

char stack[SIZE];
char *top = stack;

int isEmpty(){
	if(top==stack){
		return 0; //empty
	}
	return 1;
}

void push(char c){
	*top = c;
	top++;
}

char pop(){
	if(isEmpty()==0){
		return 'e'; // errorcode
	}
	top--;
	return *top;
}

void initStack(){
	top = stack;
}



void checkBracket(char* bString){
	int i=0;
	char temp;
	
	initStack();
	
	while(bString[i]!='\0'){
		if((bString[i]=='(')||(bString[i]=='{')||(bString[i]=='[')){
			push(bString[i]);
		}else if(bString[i]==')'){
			temp = pop();
			if(temp!='('){
				printf("NO\n");
				return;
			}
		}else if(bString[i]=='}'){
			temp = pop();
			if(temp!='{'){
				printf("NO\n");
				return;
			}
		}else if(bString[i]==']'){
			temp = pop();
			if(temp!='['){
				printf("NO\n");
				return;
			}
		}
		
		
		i++;
	}
	if(isEmpty()!=0){
		printf("NO\n");
		return;
	}
	printf("YES\n");
}

int main(void){
	int testNum=0;
	char bracketString[SIZE]="";
	int i;
	
	scanf("%d", &testNum);
	for(i=0;i<testNum;i++){
		scanf("%s", bracketString);
		checkBracket(bracketString);
	}
	
	return 0;
}
