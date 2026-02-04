/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 00:16:31 by vdurand           #+#    #+#             */
/*   Updated: 2026/02/04 02:44:33 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MACROSPLOSION_ADD_SUB_H
# define _MACROSPLOSION_ADD_SUB_H

# include "arithmetics/decrements.hpp"
# include "arithmetics/increments.hpp"

#define _M_ADD(a,b) \
	M_IF(M_BOOL(a)) \
	( \
		M_OBSTRUCT(_M_ADD_INDIRECT)()(M_DEC(a), M_INC(b)), \
		b \
	)
#define _M_ADD_INDIRECT() _M_ADD
#define M_ADD(a,b) M_EVAL(_M_ADD(a,b))

#define _M_SUB(a,b) \
	M_IF(b) \
	( \
		M_OBSTRUCT(_M_SUB_INDIRECT)()(M_DEC(a), M_DEC(b)), \
		a \
	)
#define _M_SUB_INDIRECT() _M_SUB
#define M_SUB(a, b) M_EVAL(_M_SUB(a, b))

#define _M_MULT_STEP(i, b, acc) M_ADD(acc, b)

#define M_MULT(a, b) \
	M_EVAL(M_REPEAT(a, _M_MULT_STEP, b, 0))

#endif // _MACROSPLOSION_ADD_SUB_H

