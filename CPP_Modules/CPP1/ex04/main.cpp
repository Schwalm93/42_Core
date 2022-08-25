/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:51:58 by cschwalm          #+#    #+#             */
/*   Updated: 2022/07/19 12:01:58 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <fstream>
#define RED "\x1b[31m"
#define RESET "\x1b[0m"

void    print_error(std::string error)
{
	std::cout << RED << "Error: " << error << RESET << std::endl;
}

int main(int argc, char *argv[])
{
	std::ifstream 	myfile;
	std::ofstream	new_file;
	size_t			index;
	size_t			old_index;
	if (argc != 4)
	{
		print_error("too few/many arguments");
		return (0);
	}
	std::string filename(argv[1]);
	std::string replace(argv[2]);
	std::string set(argv[3]);
	std::string line;

	filename = filename + ".replace";

	myfile.open(argv[1]);
	if (myfile.fail())
	{
		print_error("file not reachable");
		return (0);
	}
	new_file.open(filename.c_str());

	if (!new_file.is_open())
	{
		print_error("file not reachable");
		return (0);
	}

	while (!myfile.eof())
	{
		getline(myfile, line);
		index = line.find(replace);
		if (index != std::string::npos)
		{
			new_file << line.substr(0, index);
			while (1)
			{
				new_file << set;
				index += replace.length();
				if (line.find(replace, index) == std::string::npos)
				{
					new_file << line.substr(index, line.length() - index);
					break;
				}
				else
				{
					old_index = index;
					index = line.find(replace, index);
					new_file << line.substr(old_index, index - old_index);
				}
			}
		}
		else
		{
			new_file << line;
		}
		if (!myfile.eof())
		{
			new_file << std::endl;
		}
	}
	return (0);
}