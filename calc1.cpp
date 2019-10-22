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
    Token(string type, string value)
    {
        type = type;
        value = value;
    }
};

int main(void)
{
    std::cout << "initialize -> " << INTEGER << std::endl;
}