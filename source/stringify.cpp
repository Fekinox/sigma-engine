#include "stringify.h"

std::string Stringify::Int(int x)
{
    std::ostringstream o;

    o << x;

    return o.str();
}

std::string Stringify::Char(char* x)
{
    std::string o = x;

    return o;
}

std::string Stringify::Float(float x)
{
    std::ostringstream o;

    o << x;

    return o.str();
}

std::string Stringify::Double(double x)
{
    std::ostringstream o;

    o << x;

    return o.str();
}

int Stringify::ToInt(const std::string& s)
{
    if(s == "") return 0;

    int x;
    std::stringstream strStream(s);

    strStream >> x;

    return x;
}

float Stringify::ToFloat(const std::string& s)
{
    if(s == "") return 0;

    float x;
    std::stringstream strStream(s);

    strStream >> x;

    return x;
}

double Stringify::ToDouble(const std::string& s)
{
    if(s == "") return 0;

    double x;
    std::stringstream strStream(s);

    strStream >> x;

    return x;
}

std::vector<std::string> Stringify::Explode(std::string s, const std::string& sep)
{
    std::vector<std::string> res;

    unsigned int f;
    f = s.find_first_of(sep); //If a separator has been found
    while(f != std::string::npos) //While the end of string hasn't been reached
    {
        if(f > 0)
        {
            res.push_back(s.substr(0, f)); //Add string at found location to buffer
        }

        s = s.substr(f+1);
        f = s.find_first_of(sep);
    }

    if(s.length() > 0)
    {
        res.push_back(s);
    }

    return res;
}
