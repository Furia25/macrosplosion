/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadics.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:22:26 by vdurand           #+#    #+#             */
/*   Updated: 2026/02/04 01:19:45 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _MACROSPLOSION_VA_ARGS_H
# define _MACROSPLOSION_VA_ARGS_H

# include "basics.hpp"

#define _M_VA_ARGS_(...) __VA_ARGS__
#define M_VA_ARGS(...) _M_VA_ARGS_(__VA_ARGS__)

#define _M_CAT5_(_0, _1, _2, _3, _4) _0 ## _1 ## _2 ## _3 ## _4

#define _M_VA_ARGS_TAIL(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14, x, ...) x
#define _M_VA_ARGS_SEQ16() 15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0

#define _M_HAS_COMMA(...) M_IDENTITY(_M_VA_ARGS_TAIL(__VA_ARGS__, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0))

#define M_VA_ARGS_IS_EMPTY(...) _M_VA_ARGS_IS_EMPTY_(	\
	_M_HAS_COMMA(__VA_ARGS__),							\
	_M_HAS_COMMA(M_COMMA __VA_ARGS__),					\
	_M_HAS_COMMA(__VA_ARGS__(/*EMPTY*/)),				\
	_M_HAS_COMMA(M_COMMA __VA_ARGS__ (/*EMPTY*/)))

#define _M_VA_ARGS_IS_EMPTY_(_0, _1, _2, _3) _M_HAS_COMMA(_M_CAT5_(_IS_EMPTY_IS_EMPTY_CASE_, _0, _1, _2, _3))
#define _IS_EMPTY_IS_EMPTY_CASE_0001 ,

#define _M_VA_ARGS_SIZE_(...) M_IDENTITY(_M_VA_ARGS_TAIL(__VA_ARGS__))
#define M_VA_ARGS_SIZE(...) M_IFF(M_VA_ARGS_IS_EMPTY(__VA_ARGS__))(0, _M_VA_ARGS_SIZE_(__VA_ARGS__, _M_VA_ARGS_SEQ16()))

#define M_HEAD(x, ...) x

#endif // _MACROSPLOSION_VA_ARGS_H