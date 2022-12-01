/*Program that find the calories of the elf with more and
the sum of the calories of the three ones who carry more
- Advent of code #01*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
	ifstream input("input.txt");
	string line;
	vector<int> sums;
	unsigned max[3] = {0, 1, 2};
	sums.push_back(0);
	while(getline(input, line)){
		if(line!=""){
			sums.back()+=stoi(line);
		}
		else{
			if(sums.back()>max[2]){
			    max[0] = max[1];
			    max[1] = max[2];
			    max[2] = sums.back();
			}
			else if(sums.back()>max[1]){
			    max[0] = max[1];
			    max[1] = sums.back();
			}
			else if(sums.back()>max[0])
			    max[0] = sums.back();
			sums.push_back(0);
		}
	}
	cout<<max[2]<<"\n";
	cout<<max[0]+max[1]+max[2]<<"\n";
	system("pause");
	return 0;
}
