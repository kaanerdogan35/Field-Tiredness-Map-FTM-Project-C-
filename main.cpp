#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	int sizeX,sizeY,startXCoord,startYCoord,endXCoord,endYCoord,CurrentYear,plantingCount;
	string filename;
	cin>>filename;
	ifstream ReadingFile;
	ReadingFile.open(filename.c_str());
	if(!ReadingFile.is_open()){
		cout<<"File can't open"<<endl;
	}
	else{
		ReadingFile>>sizeX>>sizeY;
		if(sizeX>40||sizeY>40||sizeX<=0||sizeY<=0){
			exit(0);
		}
		int tirednessmap[sizeY][sizeX];
		int temptirednessmap[sizeY][sizeX];
		for(int i=0;i<sizeY;i++){
			for(int j=0;j<sizeX;j++){
				tirednessmap[i][j]=0;
			}
		}
		while(ReadingFile>>CurrentYear&&CurrentYear<2018){
		ReadingFile>>plantingCount;
	
				for(int i=0;i<sizeY;i++){
				for(int j=0;j<sizeX;j++){
					temptirednessmap[i][j]=0;
				}
			}
			for(int n=0;n<plantingCount;n++){
					ReadingFile>>startXCoord>>startYCoord>>endXCoord>>endYCoord;
			for(int i=0;i<sizeY;i++){
				for(int j=0;j<sizeX;j++){
					if(i>=startYCoord&&i<=endYCoord&&j>=startXCoord&&j<=endXCoord){
					temptirednessmap[i][j]=1;
					}
				}
			}
		}
	
		for(int i=0;i<sizeY;i++){
				for(int j=0;j<sizeX;j++){
					if(temptirednessmap[i][j]==0&&tirednessmap[i][j]>0){
						tirednessmap[i][j]-=1;
					}
					if(temptirednessmap[i][j]==1){
						tirednessmap[i][j]+=1;
					}
				}
			}
	}
			for(int i=0;i<sizeY;i++){
				for(int j=0;j<sizeX;j++){
					cout<<tirednessmap[i][j];}
					cout<<endl;}
					ReadingFile.close();
}}
