/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:01:25 by vdurand           #+#    #+#             */
/*   Updated: 2026/02/03 18:34:15 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macrosplosion.hpp"
#include <iostream>

#define EATER0(...)
#define EATER1(...) ,
#define EATER2(...) (/*empty*/)
#define EATER3(...) (/*empty*/),
#define EATER4(...) EATER1
#define EATER5(...) EATER2
#define MAC0() ()
#define MAC1(x) ()
#define MACV(...) ()
#define MAC2(x,y) whatever

#define static_assert(C1, C2) \
	do {\
		if (!(C1)) \
			throw (C2);\
	} while(0)

int	main(void)
{
	static_assert(MVA_ARGS_SIZE() == 0, "1");
	static_assert(MVA_ARGS_SIZE(/*comment*/) == 0, "2");
	static_assert(MVA_ARGS_SIZE(a) == 1, "3");
	static_assert(MVA_ARGS_SIZE(a, b) == 2, "4");
	static_assert(MVA_ARGS_SIZE(a, b, c) == 3, "5");
	static_assert(MVA_ARGS_SIZE(a, b, c, d) == 4, "6");
	static_assert(MVA_ARGS_SIZE(a, b, c, d, e) == 5, "7");
	static_assert(MVA_ARGS_SIZE((void)) == 1, "8");
	static_assert(MVA_ARGS_SIZE((void), b, c, d) == 4, "9");
	static_assert(MVA_ARGS_SIZE(_MIS_EMPTY_TRIGGER_PARENTHESIS) == 1, "10");
	static_assert(MVA_ARGS_SIZE(EATER0) == 1, "11");
	static_assert(MVA_ARGS_SIZE(EATER1) == 1, "12");
	static_assert(MVA_ARGS_SIZE(EATER2) == 1, "13");
	static_assert(MVA_ARGS_SIZE(EATER3) == 1, "14");
	static_assert(MVA_ARGS_SIZE(EATER4) == 1, "15");
	static_assert(MVA_ARGS_SIZE(MAC0) == 1, "16");
	// a warning in msvc
	static_assert(MVA_ARGS_SIZE(MAC1) == 1, "17");
	static_assert(MVA_ARGS_SIZE(MACV) == 1, "18");
	static_assert(MVA_ARGS_SIZE(MAC2(4, 5)) == 1, "19");
}
