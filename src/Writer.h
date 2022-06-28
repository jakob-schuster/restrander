#ifndef WRITER_H
#define WRITER_H

#include <fstream>
#include <functional>
#include <zlib.h>

#include "Record.h"

class Writer;

using WriteFunc = std::function<void(Writer&, Record&)>;
using WriteLineFunc = std::function<void(Writer&, std::string&)>;
using WriterCloseFunc = std::function<void(Writer&)>;

class Writer
{
    private:
        std::ofstream file;
        gzFile gzippedFile;

        WriteFunc writeFunc;
        WriteLineFunc writeLineFunc;
        WriterCloseFunc closeFunc;

        void
        writeFq(Record& record);

        void 
        writeLine(std::string& line);
        
        void
        writeLineStandard(std::string& line);

        void
        writeLineGzipped(std::string& line);

        void
        closeStandard();

        void
        closeGzipped();

    public:
        Writer(std::string filename);

        void
        write(Record& record);

        void
        close();
};

#endif