#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void c(char* p ,int x){

	printf("p is \"%s\" and x is %i\n",p,x);
}




int main(){
	
	printf("Hello World\n");

	char* h="Hello ";
	char* w="World!";
	char* h_w= (char*)malloc(strlen(h)+strlen(w));
	strcpy(h_w,h);
	strcpy(h_w+strlen(h),w);
	printf("%s\n",h_w);

	c("foo",7);
	c("Bika",19);

	return 0;

}