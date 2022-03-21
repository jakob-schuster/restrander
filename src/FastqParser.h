#ifndef FASTQPARSER_H
#define FASTQPARSER_H

#include <string>
#include <unordered_map>

typedef std::unordered_map<std::string, int> Stats;

class FastqParser
{
    private:
        std::string filename;
        Stats stats;

    public:
        FastqParser(std::string inFilename, std::string outFilename, std::string method);

        void
        parse(std::string inFilename, std::string outFilename, std::string method);

        void
        parseGz(std::string inFilenameGz, std::string outFilenameGz, std::string method);

        Stats
        getStats();
};

#endif