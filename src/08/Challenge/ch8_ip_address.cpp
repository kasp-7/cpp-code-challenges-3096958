// C++ Code Challenges, LinkedIn Learning

// Challenge #8: IP Address Validation
// Write an application that reads a string from the terminal and responds with a message indicating whether the string is a valid IP address or not.
// Assume decimal IP addresses.
// 158.25.0.33
// All numbers between 0 and 255.

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

bool validateSegment(const std::string& ip)
{
    std::stringstream ss(std::cin);
    try
    {
        if(ip.empty())
            return false;
        if(ip.front() == ' ')
            return false;
        if(ip.front() == '0' && ip.size() > 1)
            return false;
        size_t pos = 0;
        int segment = std::stoi(ip, &pos);
        if(pos != ip.length())
            return false;
        if(segment < 0 || segment > 255)
            return false;
    }
    catch(const std::exception& e)
    {
        return false;
    }
    return true;
}

// is_valid_ip()
// Summary: This function validates an IP address.
// Arguments:
//           ip: The string to analyze with a potential ip address.
// Returns: A boolean value. True for valid ip addresses, false otherwise.
// bool is_valid_ip(std::string ip){

//     // Write your code here
   
//     short count = 0;
//     std::stringstream ss (ip);
    
//     std::string item;
//     while (getline (ss, item, '.')) {
//         ++count;
//         if(count > 4 || !validateSegment(item))
//             return false;
//     }
//     return 4 == count;
// }

bool is_valid_ip(std::string ip){

    // Write your code here
   
    short count = 0;
    size_t pos = 0;
    size_t last = 0;
    
    while(count < 4)
    {
        ++count;

        last = ip.find('.', pos);
        auto st = ip.substr(pos, last == std::string::npos ? last : last - pos);

        if(!validateSegment(st))
            return false;
        if (last == std::string::npos)
            return 4 == count;

        pos = last+1;
    }

    return false;
}

// Main function
int main(){
    std::string s;
    
    std::cout << std::endl << "Enter an IP address in decimal: " << std::flush;
    std::getline(std::cin,s);
    std::cout << " \n" << s << (is_valid_ip(s) ? " is" : " is not" ) << " a valid IP address.\n\n";
    return 0;
}
