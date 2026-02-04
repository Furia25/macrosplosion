/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdurand <vdurand@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 00:16:31 by vdurand           #+#    #+#             */
/*   Updated: 2026/02/04 16:09:45 by vdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MACROSPLOSION_OPERATIONS_H
# define _MACROSPLOSION_OPERATIONS_H

# include "arithmetics/decrements.hpp"
# include "arithmetics/increments.hpp"

#define M_SUB_I(a,b) \
	M_IF(b) \
	( \
		M_OBSTRUCT(_M_SUB_INDIRECT)()(M_DEC(a), M_DEC(b)), \
		a \
	)

#define _M_SUB_INDIRECT() M_SUB_I
#define M_SUB(a, b) M_SUB_I(a, b)

#define M_ADD_I(a,b) \
	M_IF(a) \
	( \
		M_OBSTRUCT(_M_ADD_INDIRECT)()(M_DEC(a), M_INC(b)), \
		b \
	)

#define _M_ADD_INDIRECT() M_ADD_I
#define M_ADD(a, b) M_ADD_I(a, b)

#endif // _MACROSPLOSION_OPERATIONS_H

