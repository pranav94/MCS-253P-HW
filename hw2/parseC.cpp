#include <iostream>
using namespace std;

#define STRMAX 1000

int printNewLine(int parsing)
{
    if (parsing == 1)
        cout << endl;
    return 0;
}

int isComment(char *command)
{
    static int is_comment = 0;
    static char lastchar = '\0';
    if (command[0] == '/' && strlen(command) > 1 && command[1] == '*')
        is_comment = 1;
    if (is_comment && command[0] == '/' && lastchar == '*')
        return is_comment = 0;

    lastchar = *command;
    return is_comment;
}

int printStringLiterals(char *command)
{
    if (*command != '"')
        return 0;
    int i = 0;
    for (char lastchar = '\0'; *command != '\0'; lastchar = *command, command++, i++)
    {
        cout << *command;
        if (*command == '"' && lastchar != '\\' && lastchar != '\0')
        {
            cout << endl;
            return i+1;
        }
    }
    return i;
}

int printCharLiterals(char *command)
{
    if(command[0] != '\'')
        return 0;
    cout << command[0] << command[1] << command[2] << endl;
    return 3;
}

void printTokens(char *command)
{
    int is_parsing_command = 0;
    unsigned int n = strlen(command);
    for (unsigned int i = 0; i < n; i++)
    {
        if (isComment(&command[i]))
            continue;
        i += printStringLiterals(&command[i]) + printCharLiterals(&command[i]);
        switch (command[i])
        {
        case '&':
        case '>':
        case '<':
        case '|':
        case '+':
        case '-':
        case '=':
        case '^':
        case '%':
        case '!':
        case '?':
        case '~':
        case '#':
        case '[':
        case ']':
        case '(':
        case ')':
        case '{':
        case ',':
        case '}':
        case ';':
        case ':':
        case '*':
        case '.':
            is_parsing_command = printNewLine(is_parsing_command);
            cout << command[i] << endl;
            break;
        case '\n':
        case '\t':
        case ' ':
            is_parsing_command = printNewLine(is_parsing_command);
            break;
        default:
            cout << command[i];
            is_parsing_command = 1;
            break;
        }
    }
    printNewLine(is_parsing_command);
}

void readLine()
{
    char command[STRMAX];
    cin.getline(command, STRMAX);
    printTokens(command);
}

int main()
{
    while (!cin.eof())
        readLine();
    return 0;
}