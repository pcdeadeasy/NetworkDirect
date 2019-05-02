#include "pch.h"
#include "Params.h"
#include "cxxopts.hpp"

Params::Params(int argc, char **argv)
{
    const char *psz;

    memset(Logfile, 0, sizeof(Logfile));
    memset(Ip, 0, sizeof(Ip));

    cxxopts::Options options("argparse", "A demonstration of the cxxopts command line parsing class");
    options.add_options()
        ("server", "start as server", cxxopts::value<bool>()->default_value("false"))
        ("client", "start as client", cxxopts::value<bool>()->default_value("false"))
        ("blocking", "Blocking I/O (wait for CQ notification", cxxopts::value<bool>()->default_value("false"))
        ("polling", "Polling I/O (polling on the CQ) (default)", cxxopts::value<bool>()->default_value("true"))
        ("write", "Use RMA Write (client only, default)", cxxopts::value<bool>()->default_value("true"))
        ("read", "Use RMA Read (client only)", cxxopts::value<bool>()->default_value("false"))
        ("h,help", "Print help and exit", cxxopts::value<bool>()->default_value("false"))
        ("nsge", "Number of scatter/gather entries per transfer (default: 1)", cxxopts::value<size_t>()->default_value("1"))
        ("npipeline", "Pipeline  limit", cxxopts::value<size_t>()->default_value("128"))
        ("maxxfer", "Maxiumum Transfer", cxxopts::value<size_t>()->default_value("4194304"))
        ("maxvol", "Maxiumum Volume", cxxopts::value<size_t>()->default_value("2097152000"))
        ("maxiter", "Maximum iterations", cxxopts::value<size_t>()->default_value("500000"))
        ("hdrlen", "Header length", cxxopts::value<size_t>()->default_value("40"))
        ("logfile", "log file path", cxxopts::value<std::string>()->default_value("log.json"))
        ("ip", "ip address", cxxopts::value<std::string>())
        ("port", "port number", cxxopts::value<unsigned short>()->default_value("54331"));

    auto result = options.parse(argc, argv);

    if (result["h"].as<bool>())
        throw Params::Exception();

    Server = result["server"].as<bool>();
    Client = result["client"].as<bool>();
    Blocking = result["blocking"].as<bool>();
    Polling = result["polling"].as<bool>();
    Write = result["write"].as<bool>();
    Read = result["read"].as<bool>();
    nSge = result["nsge"].as<size_t>();
    nPipeline = result["npipeline"].as<size_t>();
    MaxXfer = result["maxxfer"].as<size_t>();
    HdrLen = result["hdrlen"].as<size_t>();
    MaxVolume = result["maxvol"].as<size_t>();
    MaxIterations = result["maxiter"].as<size_t>();

    psz = result["logfile"].as<std::string>().c_str();
    if (strncpy_s(Logfile, sizeof(Logfile), psz, strlen(psz)) != 0)
        throw Params::Exception();

    psz = result["ip"].as<std::string>().c_str();
    if (strncpy_s(Ip, sizeof(Ip), psz, strlen(psz)) != 0)
        throw Params::Exception();

    Port = result["port"].as<unsigned short>();

    if (Client && Server || (!Client && !Server))
        throw Params::Exception();

    if (Blocking)
        Polling = false;
    if (Read)
        Write = false;
}


Params::~Params()
{
}

void Params::ShowUsage()
{
    static const char* const usage =
        "\n"
        "dmrping (--client | --server) [options] --ip <string>\n"
        "\n"
        "   Options:\n"
        "\n"
        "       -h                   Print this help message and exit\n"
        "       --server             Start as server (listen on IP/port)\n"
        "       --client             Start as client (connect to IP/port)\n"
        "       --blocking           Blocking I/O (wait for CQ notification) (default:false)\n"
        "       --polling            Polling I/O (polling on the CQ) (default:true)\n"
        "       --write              Use RMA Write (client only, default: true)\n"
        "       --read               Use RMA Read (client only, default: false)\n"
        "       --nsge <size_t>      Number of scatter/gather entries per transfer (default:1)\n"
        "       --npipeline <size_t> Pipeline limit of <size_t> requests (default: 128)\n"
        "       --maxxfer <size_t>   Maximum Transfe (default: 4 * 1024 * 1024)\n"
        "       --maxvol <size_t>    Maximum Volume (default: 4 * 1024 * 1024 * 500)\n"
        "       --hdrlen <size_t>    Header length (default: 40)\n"
        "       --logFile <string>   File to receive JSON logs (default: \"log.json\")\n"
        "       --ip <string>        IPv4 Address\n"
        "       --port <ushort>      Port number (default: 54331)\n"
        "\n"
        "       Notes:\n"
        "\n"
        "           - one and only one of --server or --client must be set\n"
        "           - if --blocking is set then --polling is assumed to be false\n"
        "           - if --read is set then --write is assumed to be false\n"
        "           - one and only one of --write or --read must be set, --write is true by default\n"
        "           - --ip must always be set\n"
        "\n"
        "    Examples:\n"
        "\n"
        "       dmrping --server --ip 10.10.1.4\n"
        "       dmrping --client --ip 10.10.1.4\n"
        "       dmrping --client --blocking --ip 10.10.1.4\n"
        ;
    printf("%s\n", usage);
}

void Params::Print(FILE* file)
{
    fprintf(file, "Params:\n");
    fprintf(file, "{\n");
    fprintf(file, "    \"Server\": %d,\n", Server);
    fprintf(file, "    \"Client\": %d,\n", Client);
    fprintf(file, "    \"Blocking\": %d,\n", Blocking);
    fprintf(file, "    \"Polling\": %d,\n", Polling);
    fprintf(file, "    \"Write\": %d,\n", Write);
    fprintf(file, "    \"Read\": %d,\n", Read);
    fprintf(file, "    \"nSge\": %zu,\n", nSge);
    fprintf(file, "    \"nPipeline\": %zu,\n", nPipeline);
    fprintf(file, "    \"MaxXfer\": %zu,\n", MaxXfer);
    fprintf(file, "    \"HdrLen\": %zu,\n", HdrLen);
    fprintf(file, "    \"MaxVolume\": %zu\n", MaxVolume);
    fprintf(file, "    \"MaxIterations\": %zu,\n", MaxIterations);
    fprintf(file, "    \"Logfile\": \"%s\",\n", Logfile);
    fprintf(file, "    \"Ip\": \"%s\",\n", Ip);
    fprintf(file, "    \"Port\": %u\n", Port);
    fprintf(file, "}\n");
}