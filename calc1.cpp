#include <iostream>
#include <string>

using namespace std;

const string INTEGER = "INTEGER";
const string PLUS = "PLUS";
const string EoF = "EoF";

class Token
{
public:
    string type;
    char value;
    Token(string type1, char value1)
    {
        type = type1;
        value = value1;
    }
    // void str()
    // {
    //     cout << "tokenType => " << type << " tokenVal => " << value;
    // }
};

class Interpreter
{
public:
    string text;
    int pos;
    Token current_token = Token("None", '!');
    Interpreter(string text1)
    {
        text = text1;
        pos = 0;
    };

    void error()
    {
        throw invalid_argument("Error parsing input");
    }

    Token get_next_token()
    {
        // Lexical analyzer (also known as scanner or tokenizer)
        // This method is responsible for breaking a sentence
        // apart into tokens. One token at a time.

        string t = text;

        if (pos > (int)t.length() - 1)
        {
            return Token(EoF, '!');
        }

        char current_char = t[pos];

        if (isdigit(current_char))
        {
            pos += 1;
            return Token(INTEGER, int(current_char));
        }

        if (current_char == '+')
        {
            pos += 1;
            return Token(PLUS, current_char);
        }

        error();
    }

    void eat(string token_type)
    {
        if (this->current_token.type == token_type)
        {
            this->current_token = get_next_token();
        }
        else
        {
            error();
        }
    }

    int expr()
    {
        this->current_token = get_next_token();

        Token left = this->current_token;
        eat(INTEGER);

        Token op = this->current_token;
        eat(PLUS);

        Token right = this->current_token;
        eat(INTEGER);

        int result = (int)left.value - 48 + (int)right.value - 48;
        return result;
    }
};

int main(void)
{
    // std::cout << "initialize -> " << INTEGER << endl;
    // Token token = Token("Hello", '!');
    // std::cout << "VAlue => " << token.value << endl;
    // token.str();
    // Interpreter inter = Interpreter("3+2");
    // Token token2 = inter.get_next_token();
    // std::cout << token2.type << " <- token val ->" << token2.value << endl;
    // token2 = inter.get_next_token();
    // std::cout << token2.type << " <- token val ->" << token2.value << endl;
    // token2 = inter.get_next_token();
    // std::cout << token2.type << " <- token val ->" << token2.value << endl;
    // inter.expr();

    while (true)
    {
        string text;
        try
        {
            cout << "Calc >";
            cin >> text;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return -1;
        }
        if (text.empty() == true)
        {
            cout << "not a number";
            continue;
        }
        else
        {
            Interpreter inter = Interpreter(text);
            cout << inter.expr() << endl;
        }
    }
}