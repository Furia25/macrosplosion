/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:53:04 by vdurand           #+#    #+#             */
/*   Updated: 2026/02/03 20:22:23 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _MACROSPLOSION_BASICS_H
# define _MACROSPLOSION_BASICS_H

#define M_TRUE	1
#define M_FALSE	0

#define M_EMPTY()
#define M_DEFER(id) id M_EMPTY()
#define M_OBSTRUCT(...) __VA_ARGS__ M_DEFER(MEMPTY)()
#define M_EXPAND(...) __VA_ARGS__

#define M_EVAL(...)  M_EVAL1(M_EVAL1(M_EVAL1(__VA_ARGS__)))
#define M_EVAL1(...) M_EVAL2(M_EVAL2(M_EVAL2(__VA_ARGS__)))
#define M_EVAL2(...) M_EVAL3(M_EVAL3(M_EVAL3(__VA_ARGS__)))
#define M_EVAL3(...) M_EVAL4(M_EVAL4(M_EVAL4(__VA_ARGS__)))
#define M_EVAL4(...) M_EVAL5(M_EVAL5(M_EVAL5(__VA_ARGS__)))
#define M_EVAL5(...) __VA_ARGS__

#define M_PRIMITIVE_CAT(a, b)	a##b
#define M_CAT(a, b)	M_PRIMITIVE_CAT(a, b)

#define M_PRIMITIVE_STR(a)	#a
#define M_STR(a)	M_PRIMITIVE_STR(a)

#define _M_IDENTITY_(x) x
#define M_IDENTITY(x) _M_IDENTITY_(x)

#define _M_IFF_0(x, ...) __VA_ARGS__
#define _M_IFF_1(x, ...) x
#define M_IFF(c) M_PRIMITIVE_CAT(_M_IFF_, c)

#define _M_COMPL_0_ 1
#define _M_COMPL_1_ 0
#define M_COMPL(b) M_PRIMITIVE_CAT(_MCOMPL_, b)

#define _M_BITAND_0_(y) 0
#define _M_BITAND_1_(y) y
#define M_BITAND(x) M_PRIMITIVE_CAT(_MBITAND_, x)

#define _M_CHECK_N_(x, n, ...) n
#define M_CHECK(...) _M_CHECK_N_(__VA_ARGS__, 0,)

#define M_PROBE(x) x, 1,

#define _M_NOT_0_ M_PROBE(~)
#define M_NOT(x) M_CHECK(M_PRIMITIVE_CAT(_MNOT_, x))

#define M_EXIST(x) M_COMPL(M_NOT(x))
#define M_IF(c) M_IFF(M_EXIST(c))

#define M_EAT(...)
#define M_EXPAND(...) __VA_ARGS__
#define M_WHEN(c) M_IF(c)(M_EXPAND, M_EAT)

#define _M_REPEAT_INDIRECT()_ M_REPEAT
#define M_REPEAT(count, macro, ...) \
	WHEN(count) \
	( \
		OBSTRUCT(REPEAT_INDIRECT) () \
		( \
			DEC(count), macro, __VA_ARGS__ \
		) \
		OBSTRUCT(macro) \
		( \
			DEC(count), __VA_ARGS__ \
		) \
	)

#define M_COMMA	,

#endif // _MACROSPLOSION_BASICS_H
