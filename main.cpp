#include <iostream>
#include <string>

#define SUFFIX "-bin"

#ifdef _WIN32
    #include <direct.h>
    #define GetCurrentDir _getcwd
    #define PATH_DELIM "\"
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
    #define PATH_DELIM "/"
#endif

#include<iostream>
#include <vector>
#include <numeric>

std::string GetCurrentWorkingDir( void ) {
    char buff[FILENAME_MAX];
    GetCurrentDir( buff, FILENAME_MAX );
    std::string current_working_dir(buff);
    return current_working_dir;
}

std::string replaceStr(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return "";
    str.replace(start_pos, from.length(), to);
    return str;
}

int main(int argc, char* argv[]) {

    // get current exe name
    std::string fullpath(argv[0]);
    std::string filename = replaceStr(fullpath, GetCurrentWorkingDir() + PATH_DELIM, "");

    // convert array to single string
    std::vector<std::string> argList(argv + 1, argv + argc);
    std::string args;
    for (const auto &a : argList) args += a + " ";

    // run
    std::string cmd = fullpath + SUFFIX + PATH_DELIM + filename + " " + args;
    std::system(cmd.c_str());
    return 0;
}