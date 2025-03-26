// C++ Code Challenges, LinkedIn Learning

// Challenge #14: The Reflex Game
// Write an application that waits a random delay between 4 and 10 seconds, and then asks the user to type in a random word.
// This random word comes from a list of 10 3-letter words.
// If the user enters the correct word in less than 2 seconds, print a success message on the screen.
// Otherwise, print a failure message.
// Ignore the case ("CAT" = "cat" = "CaT").

#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>

#include <random> 
#include <thread>
 
std::string words[3]={"CAT","RAT","BAT"};

// The Reflex Game, main()
// Summary: This application measures the time it takes a user to type in a random 3-letter word.
int main(){
    std::cout << "\n";
    std::cout << "                   The Reflex Game\n";
    std::cout << "                   === ====== ====\n";
    std::cout << "After a random delay, you'll be asked to type in a 3-letter word.\n";
    std::cout << "When that happens, type in the word as fast as you can, and hit Enter.\n";
    std::cout << "Don't worry about the character case (\"CAT\" = \"cat\" = \"CaT\").\n\n";
    std::cout << "            Press Enter when you're ready to start." << std::flush;

    std::string try_again;
    std::getline(std::cin, try_again);

    std::default_random_engine generator;
  
    std::uniform_int_distribution<int> distribution_words(0, 2);
    std::uniform_int_distribution<int> distribution_time(4, 8);
    do{

        // Write your code here
        std::this_thread::sleep_for(std::chrono::seconds(distribution_time(generator)));

        auto word = words[distribution_words(generator)];
        std::cout << "WRITE A WORD!\n" << std::flush;

        auto begin = std::chrono::system_clock::now();
        std::getline(std::cin, try_again);
        auto end = std::chrono::system_clock::now();

        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
        
        bool success = false;
        if(elapsed < 2000)
        {
            std::transform(try_again.begin(), try_again.end(), try_again.begin(), ::toupper);

            if(try_again == word)
            success = true;
        }
        else
        {
            std::cout << "Too slow...\n" << std::flush;
        }

        if(success)
        std::cout << "Success!\n" << std::flush;
        else
        std::cout << "Good luck next time...\n" << std::flush;


        std::cout << "Try again? (Y/N): " << std::flush;
        std::getline(std::cin, try_again);
    }while(try_again[0]=='Y' || try_again[0]=='y');
    return 0;
}
