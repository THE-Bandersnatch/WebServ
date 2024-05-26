#include "ServerData.hpp"


std::vector<std::string> parse_accepted_methods(const std::string& methods_string) 
{
  std::string trimmed_methods = methods_string;
  size_t start = trimmed_methods.find_first_not_of(" \t\n;");
  if (start != std::string::npos) 
  {
      size_t end = trimmed_methods.find_last_not_of(" \t\n;");
      trimmed_methods = trimmed_methods.substr(start, end - start + 1);
  } 
  else
      trimmed_methods = ""; // Handle empty string case
  std::vector<std::string> methods;
  std::istringstream method_stream(trimmed_methods);
  std::string method;
  while (std::getline(method_stream, method, ',')) {
    size_t start = method.find_first_not_of(" \t\n");
    size_t end = method.find_last_not_of(" \t\n");
    if (start != std::string::npos && end != std::string::npos)
        method = method.substr(start, end - start + 1);
    else
        method = ""; // Handle empty method case
    methods.push_back(method);
  }

  return methods;
}

int main() 
{
    std::vector<ServerData> servers;
    std::ifstream file("ourconfig.conf");
    std::string line;

    while (std::getline(file, line)) 
    {
        if (line.empty()) //skip empty lines
            continue;
        if (line.find("[server]") != std::string::npos)
        {
            ServerData server; // Start of a new server block
            while (std::getline(file, line)) 
            {
                if (line.empty()) //end of server
                    break;
                std::istringstream line_stream(line);
                std::string key, value;
                line_stream >> key;
                line_stream >> value;
                if (std::strstr(key.c_str(), "port") != nullptr)
                    server.parse_server_ports(value,server);
                else if (std::strstr(key.c_str(), "serverName") != nullptr)
                    server.setServerName(value);
                else if (std::strstr(key.c_str(), "host") != nullptr)
                    server.setHost(value);
                else if (std::strstr(key.c_str(), "maxBodySize") != nullptr)
                    server.setmaxBodySize(value);
                if (std::strstr(line.c_str(), "location:") != nullptr)
                {
                    Location *tmp = new Location;
                    
                    int start = line.find_first_of("(") + 1;
                    int end = line.find_first_of(")");
                    tmp->path = line.substr(start, end - start); //Path ready
                    for (size_t i = 0; i < 6; i++)
                    {
                        std::getline(file, line);
                        if(std::strstr(line.c_str(), "root") != nullptr)
                        {
                            start = line.find_first_of("=") + 1;
                            tmp->root = line.substr(start, line.size());
                            std::cout << tmp->root << "   ID: " << i << "    <\n";
                        }
                        else if(std::strstr(line.c_str(), "acceptedMethods") != nullptr)
                        {
                            start = line.find_first_of("=") + 1;
                            tmp->acceptedMethods = parse_accepted_methods(line.substr(start, line.size())); 
                        }
                    }
                    exit(0);
                    


                    // server.setLocation(tmp->path, tmp);
                }
            }
            servers.push_back(server); // Add the server to the vector of servers
        }   
    }
    return 0;
}
    // for (size_t i = 0; i < servers.size(); i++)
    // {
    //     std::cout << std::endl << "[ SERVER " << i << " ]\n";
    //     std::cout << servers[i].getServerName() << "  (server name)\n";
    //     std::cout << servers[i].getHost() << "  (host)\n";
    //     std::cout << servers[i].getMaxbodysize() << "  (Max Size)\n";
    //     servers[i].printport();
        
    // }