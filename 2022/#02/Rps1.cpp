#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ifstream strategy("input.txt");
	string round;
	char G1, G2;
	unsigned long score = 0;
	
	while(getline(strategy, round)){
		G1 = round[0];
		G2 = round[2]-23;
		
		score += (G2-64);
		
		if(G1==G2){
			score += 3;
			continue;
		}
		
		switch(G2){
		case 'A':
			score += (G1%2==0) ? 0 : 6;
			break;
		case 'B':
			score += (G1>G2) ? 0 : 6;
			break;
		case 'C':
			score += (G1%2==0) ? 6 : 0;
			break;
		}
	}
	
	cout<<score<<"\n";
	system("pause");
	return 0;
}