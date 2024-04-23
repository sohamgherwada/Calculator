#include <stdio.h>
#include <string.h>
#define ERROR -1

int errorChecker(char operator);
int calculate(int num1, int num2, char operator);
void printData(int num1, int num2, char operator, int result);
int main(){
    int num1, num2;
    char operator;
    while (1)
    {
        printf("what would You like to calculate (use the following format ie 1 + 1): ");

        char input[10];
        fgets(input, sizeof(input), stdin);
        int status = sscanf(input, "%d %c %d", &num1, &operator, &num2);
        if (status != 3) {
            if (strlen(input) == 2 && input[0] == 'f') {
                printf("Exiting calculator...\n");
                break;
            }
            printf("Invalid input format\n");
            continue;
        }else{
            if(errorChecker(operator) == ERROR){
                printf("Invalid operator\n");
            }else{
                printData(num1, num2, operator, calculate(num1, num2, operator));
            }
        }
    }
        
    return 0;
}
int errorChecker(char operator){
    switch (operator) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            break;
        default:
            return ERROR;
    }
    
}
int calculate(int num1, int num2, char operator){
    int result;
    switch(operator){
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        case '%':
            result = num1 % num2;
            break;
        case '^':
            result = 1;
            for(int i = 0; i < num2; i++){
                result *= num1;
            }
            break;
    }
    return result;
}
void printData(int num1, int num2, char operator, int result){
    printf("%d %c %d = %d\n", num1, operator, num2, result);
}