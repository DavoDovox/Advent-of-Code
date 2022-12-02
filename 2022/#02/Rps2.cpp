#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ifstream strategy("input.txt");
	string round;
	char G1, G2, outcome;
	unsigned long score = 0;
	
	while(getline(strategy, round)){
		G1 = round[0];
		outcome = round[2];
		
		switch(outcome){
			case 'X':
				G2 = (G1=='A') ? 'C' : G1-1;
				break;
			case 'Y':
				score += 3;
				G2 = G1;
				break;
			case 'Z':
				score += 6;
				G2 = (G1=='C') ? 'A' : G1+1;
				break;
		}
		
		score += (G2-64);
	}
	
	cout<<score<<"\n";
	system("pause");
	return 0;
}