/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerData.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:37:13 by khaimer           #+#    #+#             */
/*   Updated: 2024/05/27 14:25:47 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ServerData.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

void    ServerData::setServerName(std::string const& Value)
{
    this->serverName = Value;
}

void	ServerData::setHost(std::string const& Value)
{
   this->host = Value;
}

void	ServerData::setmaxBodySize(std::string const& Value)
{
    this->maxBodySize = Value;
}

void ServerData::parse_server_ports(const std::string& ports, ServerData& server) 
{
  std::string port_str = ports;

    // std::cout << port_str << "   << HERE\n";
  size_t split = port_str.find(',');
  while (split != std::string::npos) 
  {
    std::string port_number = port_str.substr(0, split);
    int port = std::atoi(port_number.c_str());
    server.ports.push_back(port);
    port_str = port_str.substr(split + 1); // Remove the extracted part from the remaining string
    split = port_str.find(',');
  }
  if (!port_str.empty()) // Handle the last port (if no comma)
  {
    int port = std::atoi(port_str.c_str());
    if (port)
        server.ports.push_back(port);
  }
}

std::string    ServerData::getMaxbodysize() const
{
    return this->maxBodySize;
}

std::string ServerData::getServerName() const
{
    return this->serverName;
}

std::string ServerData::getHost() const
{
    return this->host;
}

std::vector<int> ServerData::getPorts() const
{
    return this->ports;
}

void	ServerData::printport() //solo
{
    for (size_t i = 0; i < this->ports.size(); i++)
    {
        std::cout << this->ports[i] << " ";
    }
    std::cout << "(port)\n";
}

void ServerData::setLocation(int number, Location* locationData)
{
    this->locations[number] = locationData;
}

void	ServerData::printLocation()
{
    for (std::map<int, Location*>::iterator it = this->locations.begin(); it != this->locations.end(); it++)
    {
        std::cout << "Location number: " << it->first << std::endl;
        std::cout << "Path: " << it->second->path << std::endl;
        std::cout << "Root: " << it->second->root << std::endl;
        std::cout << "Index: " << it->second->index << std::endl;
        std::cout << "AutoIndex: " << it->second->autoIndex << std::endl;
        std::cout << "UploadPath: " << it->second->uploadPath << std::endl;
        std::cout << "CgiPath: " << std::endl;
        std::cout << "AcceptedMethods: " << it->second->acceptedMethods.size() << std::endl;
        std::cout << "cgiExtentions: " << it->second->cgiPath << std::endl;
        for (size_t i = 0; i < it->second->acceptedMethods.size(); i++)
        {
            std::cout << it->second->acceptedMethods[i] << " ";
        }
        std::cout << std::endl;
    }
}