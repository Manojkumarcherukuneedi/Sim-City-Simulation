#ifndef CONFIG_H
#define CONFIG_H
#include <string>

bool readConfig(const std::string &filename, std::string &regionFile, int &timeLimit, int &refreshRate);

#endif