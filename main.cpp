#include <iostream>
#include <fstream>
#include <sstream>

int main (int argc, char** argv){
    if (argc == 3){
        std::ifstream in;
        in.open(argv[2]);

        long count = 0;
        std::string line;
        std::string word;
        while (std::getline(in, line)){
            if (argv[1][1] == 'c'){
                count += line.length() + 1; //add one for the newline character
            } else if (argv[1][1] == 'l'){
                count += 1;
            } else if (argv[1][1] == 'w'){
                std::stringstream words(line);
                while (words >> word){
                    count += 1;
                } 
            } 
        }
        in.close();
        std::cout << count << " " << argv[2] << std::endl;
    }
    else if (argc == 2){
        std::ifstream in;
        in.open(argv[1]);

        long countc = 0;
        long countl = 0;
        long countw = 0; 

        std::string line;
        std::string word;

        while (std::getline(in, line)){
                countc += line.length() + 1; //add one for the newline character
                countl += 1;
                std::stringstream words(line);
                while (words >> word){
                    countw += 1;
                } 
        }

        in.close();
        std::cout << countl << "  "
                  << countw << "  "
                  << countc << " " 
                  << argv[1] << std::endl;

    } else if (argc == 1) {
        long countc = 0;
        long countl = 0;
        long countw = 0; 

        std::string line;
        std::string word;

        while (std::getline(std::cin, line)){
                countc += line.length() + 1; //add one for the newline character
                countl += 1;
                std::stringstream words(line);
                while (words >> word){
                    countw += 1;
                } 
        }

        std::cout << countl << "  "
                  << countw << "  "
                  << countc << std::endl; 
    } else {
        std::cerr << "Not valid input." << std::endl;
    }

    return 0;
}