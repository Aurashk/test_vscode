#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream main_out("program_output.txt");
    std::ifstream expected(".github/classroom/correct_output.txt");

    if (!main_out.is_open() || !expected.is_open()) {
        std::cerr << "Failed to open one or both files" << std::endl;
        return 1;
    }

    std::string main_output((std::istreambuf_iterator<char>(main_out)), std::istreambuf_iterator<char>());
    std::string expected_output((std::istreambuf_iterator<char>(expected)), std::istreambuf_iterator<char>());

    if (main_output != expected_output) {
        std::cerr << "Output does not match expected result" << std::endl;
        return 1;
    }

    std::cout << "Test passed!" << std::endl;
    return 0;
}
