#ifndef _STRINGIFY_H_
#define _STRINGIFY_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Stringify
{
    public:
        static std::string Int(int x);
        static std::string Char(char* x);
        static std::string Float(float x);
        static std::string Double(double x);

        static int ToInt(const std::string& s);
        static float ToFloat(const std::string& s);
        static double ToDouble(const std::string& s);

        static std::vector<std::string> Explode(std::string s, const std::string& sep);
};

#endif //STRINGIFY_H
