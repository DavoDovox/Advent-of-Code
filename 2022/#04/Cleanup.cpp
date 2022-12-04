#include <iostream>
#include <fstream>

using namespace std;

int power(int, int);
unsigned stoui(string);

int main(){
	ifstream list("input.txt");
	string pair;
	int lower1, upper1, lower2, upper2, contained = 0, overlapping = 0;
	bool first;
	
	while(getline(list, pair)){
		first=true;
		for(int i=0; i<pair.length(); i++){
			switch(pair[i]){
				case '-':
					if(first)
						lower1 = stoui(pair.substr(0, i));
					else{
						lower2 = stoui(pair.substr(0, i));
						upper2 = stoui(pair.substr(i+1));
						i = pair.length()-2;
					}
					break;
				case ',':
					upper1 = stoui(pair.substr(0, i));
					first = false;
					break;
				default:
					continue;
			}
			pair = pair.substr(i+1);
			i = -1;
		}
		if((lower1<lower2)==(upper1>upper2))
			contained++;
		else if(lower1==lower2||upper1==upper2)
			contained++;
		if(lower1<=lower2&&lower2<=upper1)
			overlapping++;
		else if(lower2<=lower1&&lower1<=upper2)
		    overlapping++;
	}
	cout<<"Contained are: "<<contained<<"\nOverlapping are: "<<overlapping<<"\n";
	system("pause");
}

int power(int b, int e){
	for(int i=1; i<e; i++)
		b*=b;
	return (e==0) ? 1 : b;
}

unsigned stoui(string s){
	unsigned num = 0, max_power = s.length()-1;
	for(int i=0; i<s.length(); i++)
		num += (s[i]-48)*power(10, max_power-i);
	return num;
}