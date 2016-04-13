#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include "question.h"

using namespace std;

int main(){
	srand(time(NULL));
	Question question;
	cout << question.questions.size()<<"\n";
	for(int i=0; i<question.questions.size();i++){
		cout<< question.questions[i]<<"\n";
	}
	cout<< "\nacak \n\n";
	for(int i=0; i<question.questions.size();i++){
		cout<< question.AcakKata(question.questions[i])<<"\n";
	}

	cout<< "\nacak lagi \n\n";
	for(int i=0; i<question.questions.size();i++){
		cout<< question.AcakKata(question.questions[i])<<"\n";
	}
	cout << question.CheckAns(0,"test");

}