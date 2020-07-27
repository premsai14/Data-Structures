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

// checks wheteher parenthesis opening and closing are paired ( for ), [ for ] and { for }, otherwise return false(not paired)
bool IsItPaired(char opening, char closing){

	if(opening == '(' && closing == ')' ){
		return true;
	}else if (opening == '[' && closing == ']'){
		return true;
	}else if(opening == '{' && closing == '}'){
		return true;
	}else
		return false;

}

bool CheckBalancedParenthesis(char *exp){


	stack<char> S;

	for( int i = 0; i < strlen(exp); i++){

		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[' ){
			S.push(exp[i]);
		}
		else if( exp[i] ==  ')' || exp[i] =='}' || exp[i] ==']'){

			if(S.empty() || !IsItPaired(S.top(), exp[i])){
				return false;
			}
			else
				S.pop();
		}

	}

	return S.empty() ? true : false;

}



int main() {

	char C[51];
	printf("Enter a expression of parentheses: ");
	cin >> C;
	printf("Output: %s", C);
	cout <<  endl;

	// testing for outputting separate char of parentheses
	for(int i = 0; i < strlen(C) ; i++ ){
		cout << C[i] << " " ;
	}



	bool IsBalanced = CheckBalancedParenthesis(C);

	if(IsBalanced){
		cout << "Parentheses are Balanced";
	}else {
		cout << "Parantheses are NOT Balanced";
	}



	return 0;
}
