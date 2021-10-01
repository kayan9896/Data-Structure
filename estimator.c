// Implement your cycle count tool here.
#include <stdio.h>
#include <string.h>

#define ADD 1
#define SUB 1
#define MUL 3
#define DIV 24
#define MOV 1
#define LEA 3
#define PUSH 1
#define POP 1
#define PET 1

void printCounts(char** s, int* count, int* cycles, int instructions);

int main() {
	char* string[9] = {"add", "sub", "mul", "div", "mov", "lea", "push", "pop", "pet"};
	char* upperString[9] = {"ADD", "SUB", "MUL", "DIV", "MOV", "LEA", "PUSH", "POP", "PET"};
	int cycles[9] = {ADD, SUB, MUL, DIV, MOV, LEA, PUSH, POP, PET};

	int count[9] = {0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0};

	int instructions = 0;
	
	char buffer[5];
	FILE* filePointer;
	filePointer = fopen("barebones.s", "r");	
	
	while (1 == fscanf(filePointer, "%s", buffer)) {
		int i;
		for (i = 0; i < 9; i++) {
			if(strstr(buffer, string[i]) != NULL) {
				instructions++;
				count[i]++;
				break;
			}
		}	
	}
	fclose(filePointer);
	printCounts(upperString, count, cycles, instructions);
	return 0;
}

void printCounts(char** s, int* count, int* cycles, int instructions) {
	int totalCycles = 0;
	int i;
	for (i = 0; i < 9; i++){
		printf("%s %d\n", s[i], count[i]);
		totalCycles += count[i] * cycles[i];
	
	}
	printf("Total Instructions =  %d\n", instructions);
	printf("Total Cycles = %d\n", totalCycles);
}