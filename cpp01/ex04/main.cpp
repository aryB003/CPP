#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

static std::string	replaceAll(const std::string &content, const std::string &s1, const std::string &s2)
{
	std::string		result;
	std::string::size_type	pos = 0;
	std::string::size_type	found;

	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		result.append(content, pos, found - pos);
		result.append(s2);
		pos = found + s1.length();
	}
	result.append(content, pos, std::string::npos);
	return (result);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "Error: s1 must not be empty" << std::endl;
		return (1);
	}

	std::ifstream	in(filename.c_str());
	if (!in.is_open())
	{
		std::cerr << "Error: cannot open " << filename << std::endl;
		return (1);
	}

	in.peek();
	if (in.bad())
	{
		std::cerr << "Error: cannot read " << filename << std::endl;
		return (1);
	}

	std::stringstream	buffer;
	buffer << in.rdbuf();
	in.close();

	std::ofstream	out((filename + ".replace").c_str());
	if (!out.is_open())
	{
		std::cerr << "Error: cannot create " << filename << ".replace" << std::endl;
		return (1);
	}
	out << replaceAll(buffer.str(), s1, s2);
	return (0);
}
