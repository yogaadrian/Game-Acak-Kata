#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include "question.h"

using namespace std;

int main(){
	srand(time(NULL));
	string ans;
	Question question;
	vector<int> randomval;
	while(randomval.size()!=question.questions.size()){
		int val= RandomValue(question.questions.size());
		while(FindValue(randomval,val)){
			val--;
			if (val<0){
				val=question.questions.size()-1;
			}
		}
		randomval.push_back(val);

		cout<< "Tebak kata: "<< question.AcakKata(question.questions[val])<<"\n";
		do{
			cout<< "Jawab: ";	
			cin >> ans;
			if (!question.CheckAns(val,ans))
				cout<<  "SALAH! Silakan coba lagi \n";
			else 
				break;
		}while(true);
		cout<< "BENAR!\n";
	}
	return 0;

}
