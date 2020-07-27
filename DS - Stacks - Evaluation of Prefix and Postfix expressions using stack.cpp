//============================================================================
// Name        : DS.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

int Perform(char oper, int op1, int op2){

	if( oper == '+'){
		return (int)op1 + (int)op2;
	} else if( oper == '-'){
		return (int)op1 - (int)op2;
	} else if(oper == '*'){
		return (int)op1 * (int)op2;
	}else if( oper == '/'){
		return (int)op1 / (int)op2;
	}
	return 0;



}

int EvaluatePostfix(char* exp){

	stack<char> S;


	for(int i = 0; i < strlen(exp) - 1; i++){

		if( isdigit(exp[i])){ // checks whether exp[i] in a number - is it a operand
			S.push(exp[i]);
		}else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
			int op1,op2,result;
			op2 = S.top();
			S.pop();
			op1 = S.top();
			S.pop();
			result = Perform(exp[i], op1, op2);
			S.push(result);
		}else{
			i++;
		}

	}

	return S.top();
}



int main() {

	char C[51];
	cout << "Enter PostFix expression : " ;
	cin >> C;
	printf("expression is: %s", C);
	cout << endl;
	cout << isdigit(C[0]);
	cout << "Result of Postfix is: " << EvaluatePostfix(C);

	return 0;
}
