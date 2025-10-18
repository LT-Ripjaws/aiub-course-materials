#include <iostream>;
#include <cctype>;
using namespace std;



// Function to check if the input is a comment
bool isComment(const string& input) {
    // Check for single-line comment
    if (input.size() >= 2 && input[0] == '/' && input[1] == '/') return true;

    // Check for multi-line comment
    if (input.size() >= 4 && input.substr(0, 2) == "/*" && input.substr(input.size() - 2) == "*/") return true;

    // Not a comment
    return false;
}



 // Function to check if the input is a valid identifier
bool isValidIdentifier(const string& identifier) {
    // Check if input is empty
    if (identifier.empty()) return false;

    // Check if the first character is a letter or underscore
    if (!isalpha(identifier[0]) && identifier[0] != '_') return false;

    // Check remaining characters (must be alphanumeric or underscore)
    for (size_t i = 1; i < identifier.size(); ++i)
    {
        if (!isalnum(identifier[i]) && identifier[i] != '_') return false;
    }

    // If all checks pass, it's a valid identifier
    return true;
}


int main()
{
    string input;

    cout<<"Write down a valid identifier name: ";
    cin >> ws;           // Ignores any leading whitespace
    getline(cin, input); // Allows multi-line comment input

    // Check if the input is a comment
    if (isComment(input)) {
        cout << "\"" << input << "\" is a comment.\n";
    }
    else
    {
        cout << "\"" << input << "\" is not a comment.\n";
    }

    /*if (isValidIdentifier(input)) {
        cout << "\"" << input << "\" is a valid identifier.\n";
    } else {
        cout << "\"" << input << "\" is not a valid identifier.\n";
    }*/

    return 0;

}
