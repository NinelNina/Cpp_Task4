
#pragma once
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class Logger
{
public:
    static Logger& Instance();

    void Log(const string& message);

private:
    Logger();
    ~Logger();
    string GetCurrentTime();
};
