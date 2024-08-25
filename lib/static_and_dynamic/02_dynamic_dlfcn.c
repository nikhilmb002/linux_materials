#include <stdio.h>
#include <dlfcn.h>	// for dynamic run time linking
int main() {

	int r, op, a, b;
	void* handler;	// handler to hold dynamic library address
	int(*p)(int, int);	// function pointer to hold function resoloved address
	
	printf("Enter two numbers\n");
	scanf("%d%d", &a, &b);

	printf("Enter your op \n1. sum\n2. mul\n");
	scanf("%d", &op);
	handler = dlopen("./libabc.so", RTLD_LAZY);	// load the library into RAM
	
	if(handler == 0) {
	
		printf("%s\n", dlerror());
		return 1;
	}

	switch(op) {
	
		case 1 : 

			p = dlsym(handler, "sum");	// if successfully loaded then  locate fn address

			if(p == 0) {
			
				printf("%s\n", dlerror());	// if address is not resolved then print error
				return 1;
			}
			
			r = (*p) (a,b);	// if fn located successfully in library then call indirectly using fn ptr	
			printf("r = %d\n", r);
			break;

		case 2 : 

			p = dlsym(handler, "mul");

			if(p == 0) {
			
				printf("%s\n", dlerror());
				return 1;				
			}

			r = (*p)(a,b);
			printf("r = %d\n", r);
			break;

		default : 

			printf("wrong op\n");
	}

	dlclose(handler);	
	return 0;
}
