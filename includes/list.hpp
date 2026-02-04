/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:11:50 by vdurand           #+#    #+#             */
/*   Updated: 2026/02/04 18:16:39 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MACROSPLOSION_LIST_H
# define _MACROSPLOSION_LIST_H

# define M_NIL	()
# define M_LIST_NIL	()
# define M_LIST_CONS(h, t) (h) t

# define _M_LIST_HEAD_(x, ...)	x
# define M_LIST_HEAD(list)	_M_LIST_HEAD_ list

# define M_LIST_TAIL(seq) _M_LIST_TAIL_I_ list
# define _M_LIST_TAIL_I_(x, ...) (__VA_ARGS__)

#endif // _MACROSPLOSION_LIST_H