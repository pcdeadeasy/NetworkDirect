#include <iostream>
#include <boost/program_options.hpp>
#include "params.h"
#include "errors.h"

namespace po = boost::program_options;
using namespace std;

params_t get_params(int argc, char* argv[])
{
    params_t ans;
    ans.backlog = 3;

    po::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ("role", po::value<string>(&ans.role), "\"client\" or \"server\"")
        ("ip", po::value<string>(&ans.ip), "server ip address")
        ("port", po::value<uint16_t>(&ans.port), "port number (defaults to 54326)")
        ("size", po::value<size_t>(&ans.size), "size of buffer (defaults to 4048)")
        ("qdepth", po::value<uint32_t>(&ans.queue_depth), "queue depth (defaults to 0)")
        ("nsge", po::value<uint32_t>(&ans.nsge), "maximum number of sges supported")
        ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help"))
    {
        cout << desc << "\n";
        throw EX_HELP_CALLED;
    }

    // throw exceptions if required values have not been set
    if (!vm.count("role"))
        throw EX_INVALID_ROLE;
    if (!vm.count("ip"))
        throw EX_INVALID_IP;
    if (!vm.count("nsge"))
        throw EX_NSGE;
    // set default values if necessary
    if (!vm.count("port"))
        ans.port = 54326;
    if (!vm.count("size"))
        ans.size = 4048;
    if (!vm.count("qdepth"))
        ans.queue_depth = 0;

    return ans;
}

