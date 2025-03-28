// C++ Code Challenges, LinkedIn Learning

// Challenge #15: JSON File Validation
// Write an application that reads a JSON file and checks if it's valid or not.
// Test the bracket balance (curly and square), and quote balance. 
// Assume simple content with no escape characters inside strings.
// Only count double quotes ("), not single quotes (').
// The application outputs a message indicating if the JSON file passed the tests or not.

#include <iostream>
#include <fstream>
#include <string>
#include <stack>

// is_valid_JSON()
// Summary: This function returns true if the file in the argument is a valid JSON file based on its balance of braces, brackets, and quotes.
// Arguments:
//           filename: A string with the name of the file to open.
// Returns: An integer enconding: 1 for valid JSON files, 0 for invalid, and -1 on failure to open file. 

bool checkChar(char c, bool finish = false)
{
    static std::stack<char> sym;
    static bool openedQuote = false;

    if(finish)
        return sym.empty();
    else
    {
        if(c == '"')
        {
            openedQuote = !openedQuote;
            return true;
        }

        if(openedQuote)
            return true;

        switch(c)
        {
            case '[':
                sym.push('[');
            break;
            case '{':
            sym.push('{');
            break;
            case ']':
                if(!sym.empty() && sym.top() == '[')
                    sym.pop();
                else
                    return false;
                break;
                    case '}':
                    if(!sym.empty() && sym.top() == '{')
                        sym.pop();
                    else
                        return false;
                    break;
            default:
            return true;
        }

        return true;
    }
}


int is_valid_JSON(std::string filename){
    std::string line;
    bool res = true; 

    std::fstream file (filename, std::ios::in);
    if(file.is_open()){
 
        // Write your code here

        typedef std::istreambuf_iterator<char> buf_iter;
        int count = 0;
        for(buf_iter i(file), e; i != e; ++i){
          char c = *i;

          if(!checkChar(c))
          {
          res = false;
          std::cout << "The JSON file is invalid! Char = "<<c << " " << count <<"\n\n";
          break;
          }
          ++count;
        }

        file.close();
        return res && checkChar(' ', true);
    }
    else
        return -1;
}

// JSON File Validation, main()
int main(){
    int x = is_valid_JSON("jason.json");

    if(x == 1)
        std::cout << "The JSON file is valid!\n\n";
    else if(x == 0)
        std::cout << "The JSON file is invalid!\n\n";
    else
        std::cout << "Could not open the file!\n\n";  
    std::cout << std::flush;
    return 0;
}
 