// C++ Code Challenges, LinkedIn Learning

// Challenge #11: Finding Relatives
// Write an application that reads a list of people's names in a CSV file and outputs the first pair of people it finds to be possibly related based on their family names.
// Assume that all entries have one name and one family name.
// Entries are separated by commas.
// Names and family names are separated by spaces.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

// Finding Relatives, main()
// Summary: This application displays the first pair of possible relatives from a list of names in a CSV file.
int main(){
    std::fstream file ("names.csv", std::ios::in);
    std::unordered_map<std::string, std::string> m;
    bool found = false;

    // Read the CSV file.
    if(file.is_open()){

        // Write your code here

        
        std::string s;
        while(std::getline(file, s, ','))
        {
            std::string name, surname;
            std::istringstream iss(s);
            iss >> name >> surname;

            if(m.count(surname))
            {
                std::cout << "Relatives are\n" << std::flush;
                std::cout << surname << " " << name << " " << m[surname] << std::flush;
                found = true;
                break;
            }
            else
            {
                m.emplace(std::move(surname), std::move(name));
            }
        }
    
        file.close();
    }
    else{
        std::cout << "Something went wrong\n" << std::flush;
        return 1;
    }

    // Write your code here

if(!found)
    std::cout << "No relatives found.\n\n" << std::flush;    
    return 0;
}
 