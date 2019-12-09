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
        ("ip", po::value<string>(&ans.ip), "ip address")
        ("port", po::value<uint16_t>(&ans.port), "port number")
        ("size", po::value<size_t>(&ans.size), "size of buffer")
        ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help"))
    {
        cout << desc << "\n";
        throw EX_HELP_CALLED;
    }

    if (!vm.count("role"))
        throw EX_INVALID_ROLE;
    if (!vm.count("ip"))
        throw EX_INVALID_IP;
    if (!vm.count("port"))
        throw EX_INVALID_PORT;
    if (!vm.count("size"))
        throw EX_INVALID_SIZE;

    return ans;
}

