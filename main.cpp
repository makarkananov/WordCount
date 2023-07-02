#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
struct AllCounters
{
    size_t lines = 0;
    size_t bytes = 0;
    size_t words = 0;
    size_t chars = 0;
};
struct AllCounters Counter(const std::string& file_name)
{
    AllCounters Counters;
    std::ifstream fin(file_name);
    if (!(fin.is_open()))
    {
        std::cout << "no such file: " << file_name << std::endl
                  << "ended with error";
        exit(1);
    }
    fin.seekg (0, std::ios::end);
    Counters.bytes = fin.tellg();
    fin.seekg (0);
    bool ispace_flag = false;
    while (fin)
    {
        char ch = fin.get();
        if (isspace(ch) && !ispace_flag)
        {
            ispace_flag = true;
            Counters.words++;
        }
        if(!isspace(ch)){
            ispace_flag = false;
        }
        if (ch == '\n')
        {
            Counters.lines++;
        }
        if (isalpha(ch))
        {
            Counters.chars++;
        }
        if (fin.eof() && Counters.bytes != 0)
        {
            Counters.words++;
            Counters.lines++;
        }
    }
    return Counters;
}

int main(int argc, char **argv)
{
    struct AllOptions
    {
        bool lines = false;
        bool bytes = false;
        bool words = false;
        bool chars = false;
    };
    AllOptions Options;
    AllCounters Result_Counters;
    std::vector<std::string> files_list;
    for (int i = 1; i < argc; ++i)
    {
        if (argv[i][0] == '-')
        {
            if (strcmp(argv[i], "--lines") == 0)
            {
                Options.lines = true;
            }
            else if (strcmp(argv[i], "--bytes") == 0)
            {
                Options.bytes = true;
            }
            else if (strcmp(argv[i], "--words") == 0)
            {
                Options.words = true;
            }
            else if (strcmp(argv[i], "--chars") == 0)
            {
                Options.chars = true;
            }
            else
            {
                uint32_t arg_length = strlen(argv[i]);
                for (int j = 1; j < arg_length; ++j)
                {
                    if (argv[i][j] == 'l')
                    {
                        Options.lines = true;
                    }
                    else if (argv[i][j] == 'c')
                    {
                        Options.bytes = true;
                    }
                    else if (argv[i][j] == 'w')
                    {
                        Options.words = true;
                    }
                    else if (argv[i][j] == 'm')
                    {
                        Options.chars = true;
                    }
                }
            }
        }
        else
        {
            files_list.push_back(argv[i]);
        }
    }
    if (!(Options.lines || Options.bytes || Options.words || Options.chars))
    {
        Options = {true, true, true, true};
    }
    std::vector<std::size_t> result;
    for (int i = 0; i < files_list.size(); ++i)
    {
        Result_Counters = Counter(files_list[i]);
        if (Options.lines)
        {
            std::cout << Result_Counters.lines << " ";
        }
        if (Options.words)
        {
            std::cout << Result_Counters.words << " ";
        }
        if (Options.bytes)
        {
            std::cout << Result_Counters.bytes << " ";
        }

        if (Options.chars)
        {
            std::cout << Result_Counters.chars << " ";
        }
        std::cout << files_list[i];
        if ((i + 1) != files_list.size())
        {
            std::cout << std::endl;
        }
    }
    return 0;
}