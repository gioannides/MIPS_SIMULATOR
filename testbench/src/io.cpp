#include "io.hpp"

std::string exec(const char* cmd) {
    char buffer[64];
    FILE* pipe = popen(cmd, "r");
    std::string output = "";
    if (!pipe){
    	std::exit(1);
    }
    else{
    	while(fgets(buffer, sizeof(buffer), pipe) != NULL){
    		output += buffer;
    	}
    }

    pclose(pipe);
    return output;
}


void toVector(std::ifstream& input, std::vector<Test>& v){

	std::string line;
	getline(input, line);

	while(getline(input, line)){
		v.push_back(toTest(line));
	}

}


Test toTest(const std::string& line){
    std::size_t p(line.find(','));
    std::size_t initialP(0);

    std::vector<std::string> temp;
    // Breaking the line into individual strings
    while(p != std::string::npos){
        temp.push_back(line.substr(initialP,(p - initialP)));
        initialP = p + 1;
        p = line.find(',', initialP);
    }

    //Add the last string which is the message
    temp.push_back(line.substr(initialP, (line.size() - initialP)));
    														//Convert the last part to an int
    Test tempt(temp[0], temp[1], temp[2], temp[3], temp[4], std::stoi(temp[5]), temp[6]);
    return tempt;
}


//Initially, we also added this function to output a .CSV file. Might be useful in the future when we fully implement MIPS IV (LOL)
/*
void toCSV(std::ofstream& output, const std::vector<Test>& v){
	for(int i(0); i < v.size(); i++){
		output << v[i].getId() << "," << v[i].getInstruction() << "," << v[i].getResult() << "," << v[i].getAuthor() << "," << v[i].getMessage() << std::endl;
	}
}
*/
