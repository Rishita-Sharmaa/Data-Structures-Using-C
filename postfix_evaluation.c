#include <stdio.h>
  #include <string.h>

  int top = -1;
  int stack[100];

  /* push the given data into the stack */
  void push (int data) {
        stack[++top] = data;
  }

  /* Pop the top element from the stack */
  int pop () {
        int data;
        if (top == -1)
                return -1;
        data = stack[top];
        stack[top] = 0;
        top--;
        return (data);
  }

  int main() {
        char str[100];
        int i, data = -1, operand1, operand2, result;
        /* Get the postfix expression from the user */
        printf("Enter ur postfix expression:");
        fgets(str, 100, stdin);
        for (i = 0; i < strlen(str); i++) {
                if (isdigit(str[i])) {
                        /*
                         * if the i/p char is digit, parse
                         * character by character to get
                         * complete operand
                         */
                        data = (data == -1) ? 0 : data;
                        data = (data * 10) + (str[i] - 48);
                        continue;
                }

                if (data != -1) {
                        /* if the i/p is operand, push it into the stack */
                        push(data);
                }

                if (str[i] == '+' || str[i] == '-'
                        || str[i] == '*' || str[i] == '/') {
                        /*
                         * if the i/p is an operator, pop 2 elements
                         * from the stack and apply the operator
                         */
                        operand2 = pop();
                        operand1 = pop();
                        if (operand1 == -1 || operand2 == -1)
                                break;
                        switch (str[i]) {
                                case '+':
                                        result = operand1 + operand2;
                                        /* push the result into the stack */
                                        push(result);
                                        break;
                                case '-':
                                        result = operand1 - operand2;
                                        push(result);
                                        break;
                                case '*':
                                        result = operand1 * operand2;
                                        push(result);
                                        break;
                                case '/':
                                        result = operand1 / operand2;
                                        push(result);
                                        break;
                        }
                }
                data = -1;
        }
        if (top == 0)
                printf("Output:%d\n", stack[top]);
        else
                printf("u have given wrong postfix expression\n");
        return 0;
  }