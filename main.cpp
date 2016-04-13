#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

static int nkata;

vector<string> GetQuestion(){
	vector<string> questions;

	ifstream infile("question.txt");
	string question;
	while(getline(infile,question)){
		questions.push_back(question);
		nkata++;
	}
	return questions;
}

bool FindValue(vector<int> v, int val){
	vector<int>::iterator it;

	it= find (v.begin(),v.end(),val);
	if (it!=v.end())
		return true;
	else
		return false;
}

int RandomValue(int a){
	int val;
	val= rand() % a;
	return val;
}

string AcakKata(string str){
	vector<int> randomval;
	string acak="";
	while(randomval.size()!=str.length()){
		int val=RandomValue(str.length());
		while(FindValue(randomval,val)){
			val--;
			if (val<0){
				val=str.length()-1;
			}
		}
		randomval.push_back(val);
		acak.append(1u,str[val]);
	}
	return acak;
}

bool CheckAns(string s1, string s2){
	return s1 == s2;
}

int main(){
	srand(time(NULL));
	string ans;
	vector<string> questions= GetQuestion();
	vector<int> randomval;
	while(randomval.size()!=questions.size()){
		int val= RandomValue(questions.size());
		while(FindValue(randomval,val)){
			val--;
			if (val<0){
				val=questions.size()-1;
			}
		}
		randomval.push_back(val);

		cout<< "Tebak kata: "<< AcakKata(questions[val])<<"\n";
		do{
			cout<< "Jawab: ";	
			cin >> ans;
		}while(!CheckAns(ans,questions[val]));
		cout<< "\n";
		cout<< "BENAR!\n";
	}
	return 0;

}