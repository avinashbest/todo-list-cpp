#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <ctime>
#include <sstream>
using namespace std;

//Function to print date in yyyy-mm-dd format
string printDate()
{
    time_t rawtime;
    tm *timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = std::localtime(&rawtime);

    strftime(buffer, 80, "%Y-%m-%d", timeinfo);
    return buffer;
}

void readWriteTodo()
{
    //Opening Input file = todo.txt & Output file = done.txt
    ifstream inputTodo("todo.txt");
    ofstream outputTodo("done.txt");
    //String to store the data of the input file
    string line;
    string formatedDate;
    //writing output to the done.txt file
    if (inputTodo.is_open())
    {
        while (getline(inputTodo, line))
        {
            // outputTodo;
            formatedDate = printDate();
            outputTodo << "x " << formatedDate << " " << line << endl;
        }
        inputTodo.close();
        outputTodo.close();
    }
    else
    {
        cout << "Error! Unable to open file :(" << endl;
    }
}

void showList()
{
    //Opening Input file = todo.txt & Output file = done.txt
    ifstream inputTodo("todo.txt");
    //String to store the data of the input file
    string line;
    int x = 1;
    //writing output to the done.txt file
    if (inputTodo.is_open())
    {
        while (getline(inputTodo, line))
        {
            cout << "[" << x << "]"
                 << " " << line << endl;
            x++;
        }
        inputTodo.close();
    }
    else
    {
        cout << "Error! Unable to open file :(" << endl;
    }
}

void deleteTodoItem(int n = 1)
{
    //code
}
//Adding item in the todo list
void addItemInTodoList(string todoString)
{
    ofstream inputTodo("todo.txt", ios::app);
    string line;
    string formatedDate;
    formatedDate = printDate();
    inputTodo
        << todoString << endl;
    inputTodo.close();
}
//Driver Code
int main(int argc, char *argv[])
{
    readWriteTodo();
    string argument, number, todoString;

    for (int i = 1; i < argc; i++)
    {
        argument = argv[i];
        break;
    }

    if (argument == "help")
    {
        cout << "\nUsage :-" << endl;
        cout << "$ ./todo add \"todo item\"\t# Add a new todo\n";
        cout << "$ ./todo ls\t\t\t# Show remaining todos\n";
        cout << "$ ./todo del NUMBER\t\t# Delete a todo\n";
        cout << "$ ./todo done NUMBER\t\t# Complete a todo\n";
        cout << "$ ./todo help\t\t\t# Show usage\n";
        cout << "$ ./todo report\t\t\t# Statistics\n\n";
        return 0;
    }
    else if (argument == "ls")
    {
        showList();
    }
    else if (argument == "del")
    {
        number = argv[2];
        //Converting String argument into Integer
        stringstream parsingNumber(number);
        int x = 0;
        parsingNumber >> x;
        deleteTodoItem(x);
    }
    else if (argument == "done")
    {
        /* code */
    }
    else if (argument == "report")
    {
        /* code */
    }
    else if (argument == "add")
    {
        todoString = argv[2];
        addItemInTodoList(todoString);
    }

    return 0;
}
//Code By: Avinash Kumar