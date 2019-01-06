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

std::vector<std::string> split (std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

int main(int argc, char* argv[]) {
    // get current exe name
    std::string fp(argv[0]);
    auto fpv = split(fp, PATH_DELIM);
    std::string filename = fpv[fpv.size()-1];

    // convert array to single string
    std::vector<std::string> argList(argv + 1, argv + argc);
    std::string args;
    for (const auto &a : argList) args += a + " ";

    // run
    std::string cmd = GetCurrentWorkingDir() + PATH_DELIM + filename + SUFFIX + PATH_DELIM + filename + " " + args;
    std::system(cmd.c_str());
    return 0;
}