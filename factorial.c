// gcc -Wall factorial.c -o factorial
// ./factorial

#include <stdio.h>

long double factorial(int n){
  // TODO: Implement iterative solution here
	if(n==0){
		return 1;
	}
	long double result = 1;
	int i = 1;
	while(i <= n){
		result *= i;
		i++;
	}
	return result;
};

long double factorial_rec(int n){
  // TODO: Implement recursive solution here
	if(n==0){
		return 1;
	}else{
		return n*factorial_rec(n-1);
	}
}

int main(){

  // Both of these should print the same result!
  printf("factorial(26 ) = %Lf\n",factorial(26));
  printf("factorial_rec(26 ) = %Lf\n",factorial_rec(26));
  return 0;
}
