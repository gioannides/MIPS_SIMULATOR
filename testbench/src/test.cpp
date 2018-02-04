#include "test.hpp"

Test::Test(const std::string& id, const std::string& instruction, const std::string& author, const std::string& bin, const  std::string& message, int exitCode, std::string output)
	:m_id(id), m_instruction(instruction), m_author(author), m_bin(bin), m_message(message), m_exitCode(exitCode), m_output(output){}

//getter functions
std::string Test::getId() const {return m_id;}
std::string Test::getInstruction() const {return m_instruction;}
std::string Test::getResult() const {return m_result;}
std::string Test::getAuthor() const {return m_author;}
std::string Test::getBin() const {return m_bin;}
std::string Test::getMessage() const {return m_message;}
int Test::getExitCode() const {return m_exitCode;}
std::string Test::getOutput() const {return m_output;}


//setter functions
void Test::setResult(const std::string& result){m_result = result;}


std::ostream& operator<<(std::ostream& out, const Test& test){
	//2 Ways to output the results of testbench (select one)
	//out << test.m_id << '\t' << test.m_instruction << '\t' << test.m_result << '\t' << test.m_message << '\t' << "Expected ExitCode:" << test.m_exitCode;
	out << test.m_id << '\t' << test.m_instruction << '\t' << test.m_result << '\t' << "Expected ExitCode: " << test.m_exitCode << '\t';
	return out;
}

