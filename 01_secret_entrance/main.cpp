#include <iostream>
#include <fstream>
#include <string>

// return 
void turnDial(int& dial, const std::string &rotation)
{
    std::string direction = rotation.substr(0,1);
    int amount = std::stoi(rotation.substr(1, rotation.size() - 1));
    
    if (direction == "L") amount *= -1;
    dial = (dial + amount) % 100;
    if (dial < 0) dial += 100;

}

int main() {
    
    // load file
    std::ifstream input("input.txt");

    // iterate data
    int answer = 0;
    int dial = 50;
    std::string line;
    while(std::getline(input, line))
    {
        std::cout << dial << "\trotate " << line;
        turnDial(dial, line);
        std::cout << "\tresult: " << dial << std::endl;

        if (dial == 0) answer++;
    }
    
    std::cout << answer << std::endl;
}

