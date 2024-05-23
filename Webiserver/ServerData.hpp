/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerData.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:09:00 by bgannoun          #+#    #+#             */
/*   Updated: 2024/05/23 19:28:08 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef serverdata_hpp
#define serverdata_hpp

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

void setnonblocking(int sock);

struct Location
{
	std::string path;
	std::string root;
	std::vector<std::string> acceptedMethods;
	std::string index;
	bool autoIndex;
	std::string uploadPath;
	std::string cgiPath;
};

class ServerData{
	// private:
	public:
		std::vector<int> servSockets; //no
		
		std::string serverName;
		std::string host;
		std::vector<int> ports;

		//MaxBodySize
		// std::map<std::string, Location> locations;
		// Location loc;
		// loc.path = "fdsaf";
		// locations["/"] = loc;
		ServerData(){}
		ServerData(std::string servName, std::string ho, std::vector<int> portss);
		std::vector<int> &getServSockets();
		bool isIaSocket(int i);
		void addLocation(Location loc);
		std::string getServerName() const;
		std::string getHost() const;
		std::vector<Location> getLocation() const;
		std::vector<int> getPorts() const;
};

#endif