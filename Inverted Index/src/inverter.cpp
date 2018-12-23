#include <string>
#include <queue>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include "inverter.h"

using namespace std;


string build_inverted_index(string filename){

	map<string, set<int>> inverted_index;
	ifstream inputs;
	inputs.open(filename);
	string a_text_file = "";

	int file_counter = 0;
	
	while(inputs.is_open() && getline(inputs, a_text_file)){


		ifstream temp_stream;
		string a_line = "";
		// temp_stream >> noskipws >> a_line;
		temp_stream.open(a_text_file);
											//weve now opened the actual files containing text.
		
		while(temp_stream.is_open() && getline(temp_stream, a_line)){

			string temp_word = "";

			for(int i = 0; i <= a_line.length(); i++){
						//for a given line of text, go word for word (letter by letter
				if(i == a_line.length()){

					if(!temp_word.empty()){

						inverted_index[temp_word].insert(file_counter);
						temp_word = "";	
					}
					break;
				}

				if(isalnum(a_line.at(i)) ){					//builds words letter by letter			
					temp_word += a_line.at(i);
				}

				else if(!temp_word.empty()){
					
					inverted_index[temp_word].insert(file_counter);
					temp_word = "";	
				}
			}

		}

		++file_counter;

	}

		//once all indexes are recorded:

	//inverted_index.erase(inverted_index.begin()->first);	//stops first recorded entry from returning on the list ": 0\n"

	map<string,set<int>>::iterator iter;
	set<int>::iterator val_iter;
	string to_return;

			for(iter = inverted_index.begin(); iter != inverted_index.end(); iter++){	//for all map keys, print
				
				to_return+= iter->first + ":";


				for(val_iter = iter->second.begin(); val_iter != iter->second.end(); val_iter++){	//for all map values, print
					to_return += " " + to_string(*val_iter);
					//cout << 1 << endl;  
				}
				to_return += '\n';

			}
			cout << to_return << endl;
			return  to_return;
		}
		






















