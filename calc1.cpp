#include <iostream>
#include <string>

const std::string INTEGER = "INTEGER";
const std::string PLUS = "PLUS";
const std::string EoF = "EoF";

using namespace std;
class Token
{
public:
    string type;
    string value;
    Token(string type1, string value1)
    {
        type = type1;
        value = value1;
    }
    void str()
    {
        cout << "tokenType => " << type << " tokenVal => " << value;
    }
};

int main(void)
{
    std::cout << "initialize -> " << INTEGER << std::endl;
    Token token = Token("Hello", "Bye");
    std::cout << "VAlue => " << token.value << std::endl;
    token.str();
}