#include<iostream>
using namespace std;

int main(){

	loop:
	string data;
	cout << "Enter the outcome of the race: ";
	cin >> data;
	for(int i=0; i<=data.size(); i++){
	data[i] = toupper(data[i]);
	}
	
	if(data == "DONE")return 0;

	int team = 0;
	int scores['Z'+1] = {};
	int runner['Z'+1] = {};

	for(int i = 0; i < data.length(); ++i) {
	if(scores[data[i]]==0)++team;
	scores[data[i]] = scores[data[i]]+(i+1);
	runner[data[i]] = ++runner[data[i]];
	}

	for(int i = 'A'; i <'Z'+1; i++){
		if(runner[i]!=0){
			if(runner[data[0]]!=runner[i]){
			cout<<"The members on the team are off count! Please try again!\n"<<endl;
			goto loop;
			}
		}
	}

	cout << "\nThere are " << team << " teams.";
	cout << "\nThere are " << runner[data[0]] << " runners on each teams.";

	double average =scores[data[0]]/(runner[data[0]]*1.0);
	char winner=data[0];
	cout << "\n\nTEAM \tSCORE";

	for(int i=0; i<'Z'+1;i++){
		if(scores['A'+i]!=0){
			cout<< "\n " << (char)('A'+i)<<" \t "<<scores['A'+i]/(runner['A'+i]*1.0);
			if(average>scores['A'+i]/(runner['A'+i]*1.0)){
			average=scores['A'+i]/(runner['A'+i]*1.0);
			winner = 'A'+i;
			}
		}
	}
	
	cout<<"\n\nThe winning team is team "<<winner<<" with a score of "<<average;

	return 0;
}
