/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:38:32 by llebioda          #+#    #+#             */
/*   Updated: 2025/01/31 10:04:08 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

int replaceString(std::string& text, const std::string& s1, const std::string& s2)
{
    std::string result;
    size_t pos = 0;
    size_t found = 0;
    size_t found_count = 0;

    while ((found = text.find(s1, pos)) != std::string::npos)
	{
        result.append(text, pos, found - pos);
        result.append(s2);
        pos = found + s1.length();
        found_count++;
    }
    result.append(text, pos, text.length() - pos);
    text.swap(result);
    return found_count;
}

int main(int argc, char **argv)
{
    if (argc != 4)
	{
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream inputFile(filename.c_str());
    if (!inputFile)
	{
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string fileContent = buffer.str();
    inputFile.close();

    size_t found_count = replaceString(fileContent, s1, s2);

    std::cout << "Found " << found_count << " instances of '" << s1 << "' in '" << filename << "'" << std::endl;

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile)
	{
        std::cerr << "Error creating file: " << filename << ".replace" << std::endl;
        return 1;
    }

    outputFile << fileContent;
    outputFile.close();

    return 0;
}
