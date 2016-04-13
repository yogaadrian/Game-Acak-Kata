#ifndef __QUESTION_H
#define __QUESTION_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

struct Question {
  Question();
  string AcakKata(string str);
  bool CheckAns(int val, string s);

  vector<string> questions;
  int nkata;
};

//konstuktor: memasukkan kata-kata dari file eksternal ke questions
Question::Question() {
	nkata=0;
  	ifstream infile("question.txt");
	string question;
	while(getline(infile,question)){
		questions.push_back(question);
		nkata++;
	}
}
//Menentukan apakah integer val ada didalam vector<integer> v
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

//mengacak string str menjadi string acak yang komposisi hurufnya sama dengan string str;
string Question::AcakKata(string str){
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

bool Question::CheckAns(int val, string s){
	return questions[val] == s;
}


#endif