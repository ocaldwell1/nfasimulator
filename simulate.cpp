#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
int main(int argc, char *argv[]) { 
  std::ifstream inFile;
  std::string line;
  std::string insideLine;
  std::string trash;
  int numberOfStates;
  int alphabetSize;
  int acceptingState;
  int alphabetAscii;
  std::vector<int> acceptingStates;
  std::vector<int> states;
  std::vector<char> alphabet;
 // std::set<int> set;
  std::string word;
  std::string line2;
  std::set<int> set;
  std::set<int>::iterator set_it;
  std::map<std::string, std::set<int>>::iterator map_it; 
  std::map<std::string, std::set<int>> possibleTransitions;
  // opens file which should be first command line arg
  inFile.open(argv[1]);
 int startState = 0; 
 int numberOfRows = 3;
 int columnNumber = 0;
  // anaylyzes each line of txt file one by one 
  for(int i = 0; i < numberOfRows;i++) {
	  std::getline(inFile, line);
	  std::istringstream ss(line);
	
		if(i == 0){ ss >> trash >> trash >> trash >> numberOfStates;
			numberOfRows = numberOfStates + 3;
			for(int j = 0; j < numberOfStates; j++){
			    states.push_back(j);
			    }
			    }
		else if(i == 1){  
			ss >> trash >> trash >> alphabetSize;
			 alphabetAscii = 97;
			 alphabet.push_back('*');
			 for(int k = 0; k < alphabetSize;k++) {
			   alphabet.push_back(char(alphabetAscii));
			   alphabetAscii++;
		 	   }
			   }
			
                else if(i == 2) {  
			ss >> trash >> trash;
			while(ss.peek() != '\n' && ss >> acceptingState) {
		        acceptingStates.push_back(acceptingState);
			}	       
			}
		else{ 	
			for(int m = 0; m < alphabet.size(); m++) {
			  ss >> word;
			  for(int l = 0; l < word.size(); l++){
				  if(word[l] == ','|| word[l] == '}' || word[l] == '{'){
				  
				  } else {
				  // checks if next char is number if so we need extra math to determine state
				 	if(word[l+1] == '{' || word[l+1] == '}' || word[l+1] == ',') {
				  	int x = word[l] - '0';
					set.insert(x);
				  } else {
				  // convert char number to int number
				 int x = (word[l] - '0') * 10 + (word[l+1] - '0');
				 set.insert(x);
				 l++; //skip next number as it has already been calculated 
				  }			 
			  // put set in map with key as concat of #ofrows - 3 and col. Minus 3 is used to offset earlier 3 lines of txt files
			}
			  }
			  possibleTransitions[std::to_string(states.at(i-3)) + std::to_string(alphabet.at(m))] = set;
			  set.clear();
		
		}
  		}
  		}
  		std::vector<int> currentStateSet;
  		std::set<int> set2;
  		//extract each line and read through each index of line
  		while (std::getline(std::cin, line2)){
		currentStateSet.push_back(startState);
		if (line2.size() < 1) 
			set2.insert(startState);
			
		for(int i = 0; i < line2.size(); i++) {
			// goes through each number in a vector of "possible" current states and 
			// inserts numbers of possible states based on map built when reading NFA to get a new vector of possible current states
			for(int ii = 0; ii < currentStateSet.size();ii++) {
			std::string  s = std::to_string(currentStateSet.at(ii)) + std::to_string(line2[i]);
			auto set2iterator = possibleTransitions.find(s);
			//std:: cout << "Iterator points to " << set2iterator->first <<   
		      // " = " << std::endl; 
		//	loop for set since set is second elemnt of iterator(first is the key?)
       			for(int y : set2iterator->second){
				set2.insert(y);
			//std::cout << y << '\n';			
			}
			}
			// clear and reinitialize current state vector in order to go through next iteration of for loop reading the next alphabet
			// input(index) on a NEW current state vector based on the previous current state vector and input.
			currentStateSet.clear();
			for (int z : set2) {
				currentStateSet.push_back(z);	
			}
		       // clear set2 in order to avoid keeping states from prev. sets
		       set2.clear();	
			
		}
		set2.clear();

		int foundAcceptingState = 0;
		for(int i = 0; i < acceptingStates.size(); i++) {
			for(int ii = 0; ii < currentStateSet.size(); ii++) {
				if( acceptingStates.at(i) == currentStateSet.at(ii)) {
					foundAcceptingState++;
					std::cout << "accept" << '\n';
				//	std::cout << "current state set:" << '\n';
				//	for(int j = 0; j < currentStateSet.size();j++)
					//	std::cout << currentStateSet.at(j) << " " << '\n';
				}
				
			}
		}
		if(foundAcceptingState == 0){ 
			std::cout << "reject" << '\n';
			// for(int j = 0; j < currentStateSet.size();j++)
			// std::cout << currentStateSet.at(j) << " " << '\n';
		}
		// clear current state set to avoid keeping states from prev. sets before going back to beginning of while loop
		currentStateSet.clear();
		}
	//Debug
  //	std::cout << numberOfStates << " " << alphabetSize << " " ;
//	std::cout << "Accepting states" << '\n';
//	for(int i = 0; i < acceptingStates.size(); i++){
//		std::cout << acceptingStates.at(i) << " ";
//	}
//	std::cout << "alphabet:" << '\n';
//	for(int i = 0; i < alphabet.size(); i++){
//	                std::cout << alphabet.at(i) << " ";
//			        }
//	 std::cout << "states:" << '\n';
	 //        for(int i = 0; i < states.size(); i++){
	//	 std::cout << states.at(i) << " ";
		//}
	
//	for(map_it = possibleTransitions.begin(); map_it != possibleTransitions.end(); ++map_it){
//		std::cout << "Possible Transitions" << " key: " << map_it->first << ": ";
//		for(set_it = map_it->second.begin(); set_it != map_it->second.end(); ++set_it)
//		  std::cout << *set_it << " "; 
//		std::cout << std::endl;
//	}	
	inFile.close();
	
}

