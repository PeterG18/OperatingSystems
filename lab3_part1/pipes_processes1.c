#include <stdio.h>
    
int main()
{
    
    //here is two char variable one if for user input and one to concetinate
    char p1[100] , p2[100] = "howard.edu",n1[100]="gobison.org";
    
    // Declare a new Strings
    // to store the concatenated String
    char p3[100],p4[100];
    
    int i = 0, j = 0;
    
    printf("Enter a string to concatenate:");
    for(i=0;i<1;i++) //here we are taking input from the user for input string one.
    {
	
    scanf("%s",&p1[i]);
}
    // Inserting the first string
    i=0;
    while (p1[i] != '\0') {
        p3[j] = p1[i];
        i++;
        j++;
    }
    
    // Inserting the second string 
    i = 0;
    while (p2[i] != '\0') {
        p3[j] = p2[i];
        i++;
        j++;
    }
    p3[j] = '\0';
    printf("\nOutput string is: %s", p3);
    
    printf("\nInput: %s",n1);
    
	// Inserting the second string into the result of first string string
    i=0;
    while (n1[i] != '\0') {
        p3[j] = n1[i];
        i++;
        j++;
    }
    p3[j] = '\0';
    
    // Prining the concatenated string
    
    printf("\nOutput string is: %s", p3);
    
    return 0;
}