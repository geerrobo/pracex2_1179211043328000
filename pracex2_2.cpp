#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;

void sort(float x[], int N){
	for(int i = 1; i < N; i++){
		for(int j = i; j > 0; j--){
			if(x[j] > x[j-1]){
				float temp = x[j];
				x[j] = x[j-1];
				x[j-1] = temp;
			}else{
				break;
			} 
		}
	}
}

int main(){
	ifstream source("score1.txt");
	string line;
	float tempF[20];
	int tempI1, tempI2;

	for(int i=0;i<20;i++){
		getline(source,line);
		tempF[i] = atof(line.c_str());
	}
	sort(tempF,20);

	ofstream dest("result.txt");
	for(int i = 0; i < 20;i++){		
		if(tempF[i]==tempF[i-1]){
			dest << tempI1 << " : " << tempF[i] << "\n";
		}
		else{
			dest << i+1 << " : " << tempF[i] << "\n";
			tempI1 = i+1;
		}
	}
	dest.close();	

	return 0;
}

