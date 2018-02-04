#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include "test.hpp"
#include "io.hpp"
#include <sys/wait.h>


int main(int argc, char* argv[]){

	if(argc != 2){
		std::cerr << "Error: Expected the simulator as input." << std::endl;
		exit(1);
	}
	std::string simulator(argv[1]);
	std::string fileName = "testbench/tests.txt";

	//Vector in which we will store the tests
	std::vector<Test> v;

	std::ifstream input(fileName);

	if(!input.is_open()){
		std::cerr << "Error: Could not open file " << fileName << std::endl;
	}
	else{
		toVector(input, v);
	}


	input.close();


	for(unsigned int i(0); i < v.size(); i++){

		std::string command = (simulator + " " + "testbench/tests/bin/" + v[i].getBin()).c_str();

		//This will run a command on the bash and return the exit-code of that command
		int s = std::system(command.c_str());

		s = WEXITSTATUS(s);

		//std::cout << "out " << s << std::endl;

		if(v[i].getOutput() == "0"){
			if (s == v[i].getExitCode()){
				v[i].setResult("PASS");
			}
			else{
				v[i].setResult("FAIL");
			}
		}
		else{
			std::string output = exec(command.c_str());
			if(s == v[i].getExitCode() && output == v[i].getOutput()){
				v[i].setResult("PASS");
			}
			else{
				v[i].setResult("FAIL");
			}
		}

		std::cout << v[i] << " Actual ExitCode: " << s << std::endl;
	}

	/*
	std::ofstream output("testbench/results.csv");

	if(!output.is_open()){
		std::cerr << "Error: Could not open file ../results.csv" << std::endl;
	}
	else{
		toCSV(output, v);
	}

	output.close();
	*/

	//std::string output = exec((simulator + " " + testBin).c_str());

	//std::cout << "The output of the command you ran was: " << std::endl;
	//std::cout << output;

	return 0;
}
