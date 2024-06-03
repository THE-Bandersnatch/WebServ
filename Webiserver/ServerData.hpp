/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerData.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:09:00 by bgannoun          #+#    #+#             */
/*   Updated: 2024/06/03 17:55:05 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include  "fcntl.h"
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// struct Location
// {
// 	std::string path; //ready
// 	std::string root; //ready
// 	std::vector<std::string> acceptedMethods; //ready
// 	std::string index; //ready
// 	bool autoIndex; //ready
// 	std::string uploadPath; //done
// 	std::string cgiPath;
// };

class location{
	private:
		std::string path;
		std::map<std::string, std::string> directive;
	public:
		location(){}
		location(const std::string &p) : path(p) {}
		void addDirective(const std::string &direc, const std::string &value){
			directive[direc] = value;
		}
		std::string getDirective(const std::string &key)
		{
			std::map<std::string, std::string>::iterator it = directive.find(key);
			if (it != directive.end())
				return (it->second);
			return ("");
		}
};

class ServerData{
	private:
		// std::vector<int> servSockets; //no
		std::string serverName;
		std::vector<int> ports;
		std::string host;
		std::string maxBodySize;
		std::map<int, location> locations;
	public:
		void	setServerName(std::string const& Value);
		void	setHost(std::string const& Value);
		void	setmaxBodySize(std::string const& Value);
		void	parse_server_ports(const std::string& ports, ServerData& server);
		std::string		getMaxbodysize() const;
		std::string getHost() const;
		std::string getServerName()const;
		std::vector<int> getPorts() const;

		void	printport();
		// void	printLocation();
		// void setLocation(const std::string& locationPath, Location* locationData);
		void	setLocation(int number, location locationData);

		
};


		// std::map<std::string, Location> locations;
		// Location loc;
		// loc.path = "fdsaf";
		// locations["/"] = loc;
		