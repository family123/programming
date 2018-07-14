
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

string dedup(std::string input_str, int chunk_size) {
    // Write your code here.
    map<string, string> unique_str;
    map<string, string>::iterator it;
    //it = mymap.find('b');
    //if (it != mymap.end())
    int loop_count = input_str.length()/chunk_size;
    cout << "loop --"<<loop_count<< "\n";
    if(loop_count == 1)
        return input_str;

    int ptr = 0;
    for(int index = 0 ; index < loop_count ; index++) {
        string str = input_str.substr(ptr, chunk_size);
        ptr += chunk_size;
        
        it = unique_str.find(str);
        if( it != unique_str.end()){ // chunk already at map
            string value_str = it->second + "," + to_string(index);
            unique_str[str] = value_str;
        }
        else { //new chunk
            unique_str[str] = to_string(index);
        }
    }
    //iterate map and construct dedup string;
    string output_str = "";
    for (std::map<string,string>::iterator it=unique_str.begin(); it!=unique_str.end(); ++it) {
        output_str += it->first + ":" + it->second + "-";
    }
    cout << "ANS-- " <<output_str.substr(0,output_str.length()-1) << "\n"; 
    return output_str.substr(0,output_str.length()-1);
}


string redup(std::string deduplicated_str, int chunk_size) {
    //cout << "deduplicated_str: " << deduplicated_str <<"\n";
    istringstream iss(deduplicated_str);
    string token;
    string output[1000];
    int count = 0;
    //vector<string> output(1);
    //vector<string>::iterator it;
    while (getline(iss, token, '-'))
    {
        string index_token;
        istringstream ist(token);

        getline(ist, index_token, ':'); // for key
        string key = index_token;

        getline(ist, index_token, ':'); // for value
        string value = index_token;
        //cout <<"Key: "<<key <<"\t Value: " <<value <<"\n";
        
        string i;
        istringstream istr(value);
        while(getline(istr, i, ',')){
            output[stoi(i)] = key;
            count++;
            //it = output.begin();
            //cout <<key; 
            //output.insert(it+stoi(i), key);
        }
    }
    string original = "";
    //output.shrink_to_fit();
    //cout << "Size is: " <<output.size() << "\n";
    for(int j = 0 ; j < count; j++) {
        original += output[j];
    }
    //cout << "original string: " << original <<"\n";
    return original;
}
int main() {
    string input = "uqulkfffhxenqcjjncbnuqulkfffhxenqcjjncbnuqulkfffhxenqcjjncbnuqulkfffhxenqcjjncbnuqulkfffhxenqcjjncbn";
    int chunk = 10;
	string str = dedup(input, chunk);
	cout<< "output is: " <<str <<"\n";
	string output = redup(str, chunk);
	cout <<"output : ---"<<output <<"---\n";
	return 0;
}
