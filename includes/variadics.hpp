/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadics.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:22:26 by vdurand           #+#    #+#             */
/*   Updated: 2026/02/03 18:59:26 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _MACROSPLOSION_VA_ARGS_H
# define _MACROSPLOSION_VA_ARGS_H

# include "basics.hpp"

#define _MVA_ARGS_(...) __VA_ARGS__
#define MVA_ARGS(...) _MVA_ARGS_(__VA_ARGS__)

#define _MCAT5_(_0, _1, _2, _3, _4) _0 ## _1 ## _2 ## _3 ## _4

#define _MVA_ARGS_IDENTITY_(x, ...) x, __VA_ARGS__
#define _MVA_ARGS_IDENTITY(x, ...) _MVA_ARGS_IDENTITY_(x, __VA_ARGS__)

#define _MVA_ARGS_TAIL(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14, x, ...) x
#define _MVA_ARGS_SEQ16() 15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0

#define _MHAS_COMMA(...) MIDENTITY(_MVA_ARGS_TAIL(__VA_ARGS__, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0))
#define _MIS_EMPTY_TRIGGER_PARENTHESIS(...) ,

#define MVA_ARGS_IS_EMPTY(...) _MVA_ARGS_IS_EMPTY_(									\
	_MHAS_COMMA(__VA_ARGS__),												\
	_MHAS_COMMA(_MIS_EMPTY_TRIGGER_PARENTHESIS __VA_ARGS__),				\
	_MHAS_COMMA(__VA_ARGS__(/*EMPTY*/)),									\
	_MHAS_COMMA(_MIS_EMPTY_TRIGGER_PARENTHESIS __VA_ARGS__ (/*EMPTY*/)))

#define _MVA_ARGS_IS_EMPTY_(_0, _1, _2, _3) _MHAS_COMMA(_MCAT5_(_IS_EMPTY_IS_EMPTY_CASE_, _0, _1, _2, _3))
#define _IS_EMPTY_IS_EMPTY_CASE_0001 ,

#define _MVA_ARGS_SIZE_(...) MIDENTITY(_MVA_ARGS_TAIL(__VA_ARGS__))
#define MVA_ARGS_SIZE(...) MIFF(MVA_ARGS_IS_EMPTY(__VA_ARGS__))(0, _MVA_ARGS_SIZE_(__VA_ARGS__, _MVA_ARGS_SEQ16()))

#define MHEAD(x, ...) x

#endif // _MACROSPLOSION_VA_ARGS_H