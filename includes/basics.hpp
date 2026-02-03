/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:53:04 by vdurand           #+#    #+#             */
/*   Updated: 2026/02/03 19:19:11 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _MACROSPLOSION_BASICS_H
# define _MACROSPLOSION_BASICS_H

#define MEMPTY()
#define MDEFER(id) id MEMPTY()
#define MOBSTRUCT(...) __VA_ARGS__ MDEFER(MEMPTY)()
#define MEXPAND(...) __VA_ARGS__

#define EVAL(...)  EVAL1(EVAL1(EVAL1(__VA_ARGS__)))
#define EVAL1(...) EVAL2(EVAL2(EVAL2(__VA_ARGS__)))
#define EVAL2(...) EVAL3(EVAL3(EVAL3(__VA_ARGS__)))
#define EVAL3(...) EVAL4(EVAL4(EVAL4(__VA_ARGS__)))
#define EVAL4(...) EVAL5(EVAL5(EVAL5(__VA_ARGS__)))
#define EVAL5(...) EVAL6(EVAL6(EVAL6(__VA_ARGS__)))
#define EVAL6(...) __VA_ARGS__

#define MPRIMITIVE_CAT(a, b)	a##b
#define MCAT(a, b)	MPRIMITIVE_CAT(a, b)

#define MPRIMITIVE_STR(a)	#a
#define MSTR(a)	MPRIMITIVE_STR(a)

#define _MIDENTITY_(x) x
#define MIDENTITY(x) _MIDENTITY_(x)

#define _MIFF_0(x, ...) __VA_ARGS__
#define _MIFF_1(x, ...) x
#define MIFF(c) MPRIMITIVE_CAT(_MIFF_, c)

#endif // _MACROSPLOSION_BASICS_H
