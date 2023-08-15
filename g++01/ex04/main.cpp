#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    if(ac != 4)
    {
        std::cerr << "Argument error!!!" << std::endl;
        return (-1);
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    std::ifstream inputFile(filename.c_str());//const char * turune donusturur.
    if(!inputFile)
    {
        std::cerr << "Input file error!!!" << std::endl;
        return (-1);
    }
    std::string o_fileName = filename + ".replace";
    std::ofstream outputFile(o_fileName.c_str());
    if(!outputFile)
    {
        std::cerr << "Output file error!!!" << std::endl;
        inputFile.close();
        return(-1);
    }
    /*find: Aranan string parçası bulunduğu durumda stringin yer aldığı index başlangıç değeri,aksi halde “std::string::npos”’a eşit bir değer döndürür.*/
    //NOT: “string::npos”,size_t maksimum değerini tutar.
    std::string line;
    size_t find_pos;
    while(std::getline(inputFile, line))
    {
        std::string replacedLine;
        find_pos = line.find(s1);
        while(find_pos != std::string::npos)
        {
            replacedLine += line.substr(0, find_pos);
            replacedLine += s2;
            line = line.substr(find_pos + s1.length());
            find_pos = line.find(s1);
        }
        replacedLine += line;
        outputFile << replacedLine << std::endl;
    }

    inputFile.close();
    outputFile.close();
}