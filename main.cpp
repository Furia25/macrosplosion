/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:01:25 by vdurand           #+#    #+#             */
/*   Updated: 2026/02/04 19:32:56 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macrosplosion.hpp"
#include <iostream>

#define static_assert(C1, C2) \
	do {\
		if (!(C1)) \
			throw (C2);\
	} while(0)
	
int	main(void)
{
	std::cout << M_VA_ARGS_SIZE(1, 5, 8, (4, 8, 8, 9, 7, 4, 1, 5), (template<typename T, typename C>)) << std::endl;
	
}
