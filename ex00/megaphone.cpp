/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:49:11 by enchevri          #+#    #+#             */
/*   Updated: 2025/12/03 13:07:51 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (!std::cout.good())
		return (1);
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; argv[i]; i++)
	{
		std::string str = argv[i];
		if (!str.empty())
		{
			for (size_t i = 0; i < str.size(); i++)
				str[i] = std::toupper(str[i]);
			std::cout << str;
		}
	}
	std::cout << std::endl;
	return (0);
}
