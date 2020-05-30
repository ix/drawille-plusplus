#include <iostream>
#include <fstream>
#include <vector>
#include <locale>
#include "../drawille.hpp"

using namespace std;
using namespace Drawille;
using std::wcout;
using std::locale;

//this class contains datasets that you can import and draws a graph using them
class counter{
	public:
	int dataset_a;
	int dataset_b;
};

vector<counter> cntrTemp, cntr;


void inputDataset(){
	int pos=0;

	/*The data.bin file was made using
	
		ofstream fout("data.bin", ios::binary|ios::app);
		fout.write((char*)&elmnt, sizeof(elmnt));
	
	where elmnt is a data memeber of the counter class*/
	
	ifstream fin("data.bin", ios::binary);
	cntrTemp.emplace_back(counter());

	while(fin.read((char*)&cntrTemp[pos], sizeof(cntrTemp[pos]))){
		cntrTemp.emplace_back(counter());
		pos = cntrTemp.size()-1;
	}

	fin.close();

	//initializing pos such that only the last 3000 points will be 
	//entered into cntr
	if(cntrTemp.size()<3000) pos=0;
	else pos = cntrTemp.size() - 3000;
	
	//initialising cntr with last 3000 values. i am using 3000 as a limit
	//because that is how many will fit on my monitor
	for(int i=pos; i<cntrTemp.size(); i++){
		cntr.emplace_back(counter());
		cntr[cntr.size()-1] = cntrTemp[i];
	}
}

int main(){

	inputDataset();

	locale::global(locale(""));
  	Canvas canvas(165, 42);

  	for(int i = 0; i <= cntr.size(); i++) {
		
		/*to fill in the points, the syntax is canvas.set(x,y) where 
		x and y are the coordinates of the points.
		however as it measures the y axis distance from upper left corner
		instead of lower left corner, we instead write canvas.set(x,y_max-y)
		where y_max is the max limit of the y axis (in characters)
		
		for scaling the output you can multiply or divide by any number
		division will compress the graph and multiplication will stretch it
		*/
		
    		canvas.set(i/9,160-cntr[i].dataset_b/3); 	
  	}	
        
  	for(int i = 0; i <= cntr.size(); i++) {
    		canvas.set(i/9,160-cntr[i].dataset_a/3);
  	}	

  	canvas.draw(wcout);


	return 0;
}
