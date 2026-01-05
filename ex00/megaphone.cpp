/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:49:11 by enchevri          #+#    #+#             */
/*   Updated: 2026/01/05 16:47:16 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::endl;

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; ++i)
	{
		int y = 0;
		while (argv[i][y])
		{
			std::cout << static_cast<char>(std::toupper(argv[i][y])) ;
			++y;
		}
	}
	std::cout << endl;
	return (0);
}
