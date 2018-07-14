#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;
string dedup(string input, int chunk) {
    map<string, string> output;
    int len = input.length()/chunk;
    int ptr = 0;
    map<string,string>::iterator it;
    for (int i = 0 ; i < len ; i++) {
        string st = input.substr(ptr,chunk);
        ptr+= chunk;
        it = output.find(st);
        if (it == output.end()){
            output[st] = to_string(i);
        }
        else {
            string temp = it->second +","+to_string(i);
            output[st] = temp;
        }
    }
    string out = "";
    for (std::map<string,string>::iterator it=output.begin(); it!=output.end(); ++it) {
        std::cout << it->first << " => " << it->second << '\n';
        out += it->first+":"+it->second+"|";
    }
    return out.substr(0,out.length()-1);
}
string redup(string str, int chunk) {
    //std::string myText("some-text-to-tokenize");
    //cout <<"Started\n";
    istringstream iss(str);
    string token;
    string output[5] ;
    while (getline(iss, token, '|'))
    {
        string index_token;
        istringstream ist(token);
        getline(ist, index_token, ':');
        //cout << index_token << std::endl;
        string key = index_token;
        getline(ist, index_token, ':');
        string value = index_token;
        //cout <<"Key: "<<key <<"\t Value: " <<value <<"\n";
        
        string i;
        istringstream istr(value);
        while(getline(istr, i, ',')){
            //cout <<key; 
            output[stoi(i)] = key;
        }
        //std::cout << token << std::endl;
    }
    //cout<<"output is \n";
    string strr = "";
    for(int j = 0 ; j < 5 ; j++){
        strr += output[j];
    }
    //cout <<"\nEnded\n";
    return strr;
}
int main() {
    string input = "abcdeaaaaaabcdebbbbbabcde";
    int chunk = 5;
	string str = dedup(input, chunk);
	cout<< "output is: " <<str <<"\n";
	string output = redup(str, chunk);
	cout <<"output : ---"<<output <<"---\n";
	return 0;
}
