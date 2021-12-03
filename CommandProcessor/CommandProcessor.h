//
// Created by Tam Nhu Tran on 2021-11-12.
//

#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "../LoggingObserver/LoggingObserver.h"
using namespace std;

class GameEngine;
class Player;

enum class Phases;

class Command : public Subject{
public:

    Command();
    Command(string command, string effect);

    //please read private members for explanation on the following two
    Command(string command, string effect, string instruction, string argument);
    Command(string command, string effect, string instruction);

    Command(const Command& c);
    ~Command();
    Command& operator =(const Command& c);
    friend std::ostream& operator<<(std::ostream& stream, const Command& c);

    //Accessors and mutators
    void setCommand(string command);
    string getCommand();
    void saveEffect(string effect);
    string getEffect();
    void setInstruction(string instruction);
    string getInstruction();
    void setArgument(string argument);
    string getArgument();

    // ILoggable
    virtual string stringToLog();
private:
    string command; //entire line of input from console or file by the user
    string effect; //effect of the command, a description
    string instruction; //first word of the command, tells engine what to do
    string argument; //second word of the command if any, an additional parameter such as file or name
};

class CommandProcessor : public Subject{
public:

    CommandProcessor();
    virtual ~CommandProcessor();

    //Methods requested from the assignment hand out
    virtual Command* getCommand(); //public get command method for other classes

    bool validate(Command* command, Phases* phase);

    Command* getLastCommandInList();

    vector<Command*> getCommandList(); //accessor for list of commands, just in case
    CommandProcessor& operator =(const CommandProcessor& c);
    friend std::ostream& operator<<(std::ostream& stream, const CommandProcessor& com);

    // ILoggable
    virtual string stringToLog();

protected:
    virtual string readCommand(); //takes input from the console
    void saveCommand(string command); //saves the command received by input into a command object
private:
    vector<Command*> commandList;

};

class FileLineReader {
public:

    FileLineReader();
    FileLineReader(string filename);
    ~FileLineReader();

    //mreading the text files
    bool readFromLine();
    string getCurrentLine();

    //mutator for the file input stream
    void setFStr(fstream* ifstr);
private:
    string filename;
    string currentLine;
    fstream* _ifstr; //file input stream from where lines are being read
};

class FileCommandProcessorAdapter : public CommandProcessor {
public:

    FileCommandProcessorAdapter();
    FileCommandProcessorAdapter(string filename);
    ~FileCommandProcessorAdapter();

    //adapter pattern: explained in definition
    Command* getCommand(); //public get command method for other classes

    FileCommandProcessorAdapter& operator =(const FileCommandProcessorAdapter& c);
    friend std::ostream& operator<<(std::ostream& stream, const FileCommandProcessorAdapter& com);

protected:
    //adapter pattern: explained in definition
    string readCommand(); //protected function to retrieve commands from a file
private:
    bool usingConsole; //for adapter pattern
    FileLineReader* flr;
    CommandProcessor* comPro;
};


