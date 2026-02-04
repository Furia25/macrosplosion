/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadics.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:22:26 by vdurand           #+#    #+#             */
/*   Updated: 2026/02/04 18:46:01 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _MACROSPLOSION_VA_ARGS_H
# define _MACROSPLOSION_VA_ARGS_H

# include "basics.hpp"

#define _M_VA_ARGS_(...) __VA_ARGS__
#define M_VA_ARGS(...) _M_VA_ARGS_(__VA_ARGS__)

#define _M_CAT5_(_0, _1, _2, _3, _4) _0 ## _1 ## _2 ## _3 ## _4

#define _M_VA_ARGS_TAIL(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_30,_31,_32,_33,_34,_35,_36,_37,_38,_39,_40,_41,_42,_43,_44,_45,_46,_47,_48,_49,_50,_51,_52,_53,_54,_55,_56,_57,_58,_59,_60,_61,_62, x, ...) x
#define _M_VA_ARGS_SEQ64() 63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0

#define _M_HAS_COMMA(...) M_IDENTITY(_M_VA_ARGS_TAIL(__VA_ARGS__, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 0))

#define _M_IS_EMPTY_TRIGGER_PARENTHESIS_(...) ,

#define M_IS_EMPTY(...) _M_IS_EMPTY_(	\
	_M_HAS_COMMA(__VA_ARGS__),							\
	_M_HAS_COMMA(_M_IS_EMPTY_TRIGGER_PARENTHESIS_ __VA_ARGS__),					\
	_M_HAS_COMMA(__VA_ARGS__ (/*EMPTY*/)),				\
	_M_HAS_COMMA(_M_IS_EMPTY_TRIGGER_PARENTHESIS_ __VA_ARGS__ (/*EMPTY*/)))

#define _M_IS_EMPTY_(_0, _1, _2, _3) _M_HAS_COMMA(_M_CAT5_(_IS_EMPTY_IS_EMPTY_CASE_, _0, _1, _2, _3))
#define _IS_EMPTY_IS_EMPTY_CASE_0001 ,

#define _M_VA_ARGS_SIZE_(...) M_IDENTITY(_M_VA_ARGS_TAIL(__VA_ARGS__))
#define M_VA_ARGS_SIZE(...) M_IFF(M_IS_EMPTY(__VA_ARGS__))(0, _M_VA_ARGS_SIZE_(__VA_ARGS__, _M_VA_ARGS_SEQ64()))

#endif // _MACROSPLOSION_VA_ARGS_H