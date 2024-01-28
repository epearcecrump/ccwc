#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>

struct Parser {
    bool option;
    bool file;
};

long countBytes(std::istream& in){
    long count = 0;
    std::string line;
    while (std::getline(in, line)){
       count += line.length() + 1; //add one for the newline character 
    }
    return count;
}

long countLines(std::istream& in){
    long count = 0;
    std::string line;
    while (std::getline(in, line)){
       count += 1; 
    }
    return count;
}

long countWords(std::istream& in){
    long count = 0;
    std::string line;
    std::string word;
    while (std::getline(in, line)){
        std::stringstream words(line);
        while (words >> word){
            count += 1;
        } 
    }
    return count;
}

void countAll(std::istream& in, long* countl, long* countw, long* countc){
    std::string line;
    std::string word;
    while (std::getline(in, line)){
        *countl += 1;
        *countc += line.length() + 1;
        std::stringstream words(line);
        while (words >> word){
            *countw += 1;
        } 
    }
}

Parser parseInput(int argc, char** argv){
    Parser parse = {false, false}; //argc = 1 case
    if (argc > 3){
         std::cerr << "Invalid input. Valid input is of the form ccwc [-Option] [File]." << std::endl;
         exit(1);
    }
    if (argc == 3){
        parse.option = true;
        parse.file = true; //at position argv[2]
    } 
    if (argc == 2){  
        if (argv[1][0] == '-'){
            parse.option = true;
        } else {
            parse.file = true; //at position argv[1]
        }
    }
    if (argc == 1){
        if (isatty(STDIN_FILENO)){ // if true, program is receiving input from the terminal.
            std::cerr << "Invalid input. Valid input is of the form ccwc [-Option] [File]." << std::endl;
            exit(1);
        }
    }
    return parse;
}

void printFile(char* file){
    if (file){
        std::cout << " " << file;
    } 
}

int main (int argc, char** argv){
    Parser parse = parseInput(argc, argv);

    // First check whether we are using a file or standard input. 
    std::ifstream in;
    std::istream& input = parse.file ? in : std::cin;
    char* file = nullptr;
    if (parse.file){
        if (argc == 2){
            file = argv[1];
            in.open(file);
        } else { //argc == 3
            file = argv[2];
            in.open(file);
        }
    } 

    long countc = 0;
    long countl = 0;
    long countw = 0;  
    //2) Then check if there is an option or not.
    if (parse.option){
        switch(argv[1][1]){
            case 'c': 
                countc = countBytes(input);
                std::cout << countc;
                printFile(file);
                std::cout << std::endl;
                break;
            case 'l':
                countl = countLines(input); 
                std::cout << countl;
                printFile(file);
                std::cout << std::endl;
                break;
            case 'w':
                countw = countWords(input); 
                std::cout << countw;
                printFile(file);
                std::cout << std::endl;
                break;
        }
    } else {
        countAll(input, &countl, &countw, &countc);
        std::cout << countl << "  "
                  << countw << "  "
                  << countc; 
        printFile(file);
        std::cout << std::endl;
    }
    in.close();

    return 0;
}