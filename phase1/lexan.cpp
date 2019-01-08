
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

static string keywords[] = {
	"auto", "break", "case", "char", "const", 
	"continue", "default", "do", "double", "else", "enum", 
	"extern", "float", "for", "goto", "if", "int", "long",
	"register", "return", "short", "signed", "sizeof", 
	"static", "struct", "switch", "typedef", "union", 
	"unsigned", "void", "volatile", "while"
}

int isKeyword(string s){
	for(i = 0; i < keywords.size(); i++){
		if(s == keywords[i]){
			return 1;
		}
	}
	return 0;
}

int isignored(char character){

	switch(character){
		case ' ':
		case '\t':
		case '\n':
		case '\f':
		case '\v':
		case '\r':
			return 1;
		default:
			return 0;
	}

}

int lexan(string& lexbuf){

	char input = cin.peek();

	while(!cin.eof()){

		lexbuf.clear()

		//handle whitespace or otherwise ignored characters
		if(isignored(input)){
			do {
				cin.get();
				input = cin.peek();
			} while(isignored(input));
		}

		//handle numbers
		if(isdigit(input)){
			do {
				lexbuf += input;
				cin.get();
				input = cin.peek();
			} while(isdigit(input));

			return INTEGER;

			//Check for a period immediately afterwards
			//Check for an [eE] immediately afterwards
		}

		//handle identifiers
		if(input == '_'){
			do {
				lexbuf += input;
				cin.get();
				input = cin.peek();
			} while( input == ' ' || isalpha(input) || isdigit(input));
			return ID;
		}

		//handle identifiers OR keywords
		if(isalpha(input)){

			do {
				lexbuf += input;
				cin.get();
				input = cin.peek();
			} while(input == '_' || isalpha(input) || isdigit(input));

			if(isKeyword(lexbuf)){
				return KEYWORD;
			}
			else{
				return ID;
			}

		}


	}

	return DONE;

}

int main(){

	int myout = isignored(' ');

	printf("%d",myout);

}