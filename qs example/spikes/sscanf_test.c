#include <stdio.h>
 
int main(void)
{
        char aInput[256];
        char bInput[256];
        char cInput[256];
        double a, b, c;
 
        printf("Enter a, b, and c:\n");
        
        
        fgets(aInput, sizeof(aInput), stdin);
        sscanf(aInput, "%lf", &a);
        printf("a = %lf\n", a);
        
        fgets(bInput, sizeof(bInput), stdin);
	sscanf(bInput, "%lf", &b);        
	printf("b = %lf\n", b);	
		
        fgets(cInput, sizeof(cInput), stdin);
        sscanf(cInput, "%lf", &c);
        printf("c = %lf\n", c);

        printf("\n");
        return 0;
}