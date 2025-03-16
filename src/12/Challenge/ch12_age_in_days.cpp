// C++ Code Challenges, LinkedIn Learning

// Challenge #12: Age in Days Calculator
// Write an application that asks the user's birth date and responds with the user's age in days. 
// If the user claims to be over 120 years old, output a message calling the bluff.

#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

// Age in Days, main()
// Summary: This application asks the user's birth date and prints their age in days.
int main(){
    int birth_y, birth_m, birth_d, today_y, today_m, today_d;

    std::cout << "Enter your birth date's month as a number: " << std::flush;
    std::cin >> birth_m;
    std::cout << "Enter your birth date's day: " << std::flush;
    std::cin >> birth_d;
    std::cout << "Enter your birth date's year: " << std::flush;
    std::cin >> birth_y;
    
    if(birth_m < 1)
        birth_m = 1;
    if(birth_m > 12)
        birth_m = 12;

    // Write your code here
    std::tm tm = { /* .tm_sec  = */ 0,
        /* .tm_min  = */ 0,
        /* .tm_hour = */ 0,
        /* .tm_mday = */ (birth_d),
        /* .tm_mon  = */ (birth_m) - 1,
        /* .tm_year = */ (birth_y) - 1900,
      };

auto tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
auto now = std::chrono::system_clock::now();

int32_t age = std::chrono::duration_cast<std::chrono::duration<int32_t, std::ratio<86400>>>(now - tp).count();

    if(age < 43830)
        std::cout << "You are " << age << " days old.";
    else
        std::cout << "Come on. You can't be " << age << " days old!";
    std::cout << "\n\n" << std::flush;
}
