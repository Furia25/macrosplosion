/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:01:25 by vdurand           #+#    #+#             */
/*   Updated: 2026/02/05 01:02:15 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macrosplosion.hpp"
#include <iostream>

#define static_assert(C1, C2) \
	do {\
		if (!(C1)) \
			throw (C2);\
	} while(0)

#define test_m(x, a, b, c, ...)	x##a##b##c
#define test (1, 2, 3, 4)

int	main(void)
{
	std::cout << M_STR(M_FOREACH(test_m, (a, b, c), 1, 2, 3, 4)) << std::endl;
	
}
