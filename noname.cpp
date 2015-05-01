#include <stdio.h>

void checkBracket(char* bString){
	int i=0;
	int roundOpenCount=0;
	int curlyOpenCount=0;
	int squareOpenCount=0;
	int roundCloseCount=0;
	int curlyCloseCount=0;
	int squareCloseCount=0;
	
	while(bString[i]!='\0'){
		if(bString[i]=='('){
			roundOpenCount++;
			if((bString[i+1]=='}')||(bString[i+1]==']')){
				printf("NO\n");
				return;
			}
		}else if(bString[i]=='{'){
			curlyOpenCount++;
			if((bString[i+1]==')')||(bString[i+1]==']')){
				printf("NO\n");
				return;
			}
		}else if(bString[i]=='['){
			squareOpenCount++;
			if((bString[i+1]=='}')||(bString[i+1]==')')){
				printf("NO\n");
				return;
			}
		}
		
		if(bString[i]==')'){
			roundCloseCount++;
			if(roundCloseCount>roundOpenCount){
				printf("NO\n");
				return;
			}
		}else if(bString[i]=='}'){
			curlyCloseCount++;
			if(curlyCloseCount>curlyOpenCount){
				printf("NO\n");
				return;
			}
		}else if(bString[i]==']'){
			squareCloseCount++;
			if(squareCloseCount>squareOpenCount){
				printf("NO\n");
				return;
			}
			
		}		
		i++; 
	}
	if((roundOpenCount!=roundCloseCount)||(curlyOpenCount!=curlyCloseCount)||(squareOpenCount!=squareCloseCount)){
		printf("NO\n");
		return;
	}else{
		printf("YES\n");
		return;
	}
}


int main(void){
	int testNum=0;
	char bracketString[10001]="";
	int i;
	
	scanf("%d", &testNum);
	for(i=0;i<testNum;i++){
		
		scanf("%s", bracketString);
		checkBracket(bracketString);
	}
	
	return 0;
}
