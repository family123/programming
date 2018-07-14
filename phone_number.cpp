#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
	ifstream in("read.txt");
	if(!in) {
		cout<< "Cannot open input file!" << endl;
		return 1;
	}
    string line;
    string str = "";
    while(getline(in, line)) 
    {
        string str = "";
        for(int i = 0 ; i < line.length() ; i++) {
            if(line[i] >= 48 && line[i] <= 57)
                str = str+"x";
            else {
                str = str+line[i];
            }
        }
        std::size_t found1 = str.find("(xxx) xxx-xxxx");
        std::size_t found2 = str.find("xxx-xxx-xxxx");
        //cout << str <<"\n";
        if (found1!=std::string::npos) {
            std::string str2 = line.substr(found1,14);
            cout << str2 << "\n";
        }
        if (found2!=std::string::npos) {
            std::string str2 = line.substr(found2,12);
            cout << str2 << "\n";
        }
        //cout << line;
    }
    return 0;
}
