#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int getnum(string n){
	char starter = n[0];
	int matchCount = 0;	
	for(int i = 0; i < n.length(); i++){
		if (n[i] == starter){
			matchCount++;
		}
	}
	return matchCount;
}


bool RaceValid(string race, int &teams, int &runners, char (&names)[26]){

	int len = race.length();
	sort(race.begin(), race.end());
	int nRunners = getnum(race);

	if(len % nRunners != 0){
		return false;
	}
	if(nRunners == 1){
		for(int i = 0; i < len ; i++){
			for(int j = i+1; j < len; j++){
				if(race[i] == race[j]){
					return false;
				}
			}
			names[i] = race[i];
		}

	}
	else{			
		for(int i = 0; i < len; i += nRunners){
			names[i/nRunners] = race[i];
			
			string check = race.substr(i,nRunners+1);
			for(int j = 0; j < check.length(); j++){
				
				if(j == check.length()-1 && i != len-nRunners){
					if(check[0] == check[j]){
						cout << check << endl;
						return false;
					}
				}
				else{
					if(check[0] != check[j]){
						return false;
					}
				}
				
			}

		}
	}
	teams = len/nRunners;
	runners = nRunners;
	return true;
}


void CalculateScores(char (&strnames)[26], string input, int nTeams, int (&scores)[26]){
	for(int j = 0; j < nTeams; j++){
		for(int i = 0; i < input.length(); i++){
			if(input[i] == strnames[j]){
				scores[j] += (i+1);
			}
		} 	
	}	
}

void clearScores(int (&scores)[26]){
	for(int i = 0; i < 26; i++){
		scores[i] = 0;
	}
}

int main(){
	char strnames[26];
	int nTeams;
	int nRunners;
	int scores[26] = {0};
	string input;
	string race = "";

	reenter:
	cout << "Please input a race: either on one line or separaed by lines" << endl;
	cout << "When done, type \"done\" on a new line" << endl;
	while(true){
		cin >> input;
		if(input == "done") 
			break;
		if(input != "")
			race += input;
	}

	while(true){
		if(RaceValid(race, nTeams, nRunners, strnames)){
			cout << "There are " << nTeams << " teams."<< endl;
			cout << nRunners << " player(s) on each team. "<< endl;
			break;
		}
		else {
			clearScores(scores);
			cout << "Not Valid!!!" << endl;
			cout << "Re-enter: ";
			input = "";
			race = "";
			goto reenter;
		}
	}
	CalculateScores(strnames, race, nTeams, scores);
	

	cout << "Team Scores: " << endl;
	int highest = 0;
	for(int i = 0; i < nTeams; i++){
		cout << strnames[i] << " " << ((double)scores[i])/nRunners << endl; 
		if((double)scores[i]/nRunners <= (double)scores[highest]/nRunners){
			highest = i;
		}
	}
	cout << "The highest scoring team is " << strnames[highest] << " with a score of " << (double)scores[highest]/nRunners << endl;
	return 0;
}














