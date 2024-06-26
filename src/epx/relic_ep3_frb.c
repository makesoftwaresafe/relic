/*
 * RELIC is an Efficient LIbrary for Cryptography
 * Copyright (c) 2022 RELIC Authors
 *
 * This file is part of RELIC. RELIC is legal property of its developers,
 * whose names are not listed here. Please refer to the COPYRIGHT file
 * for contact information.
 *
 * RELIC is free software; you can redistribute it and/or modify it under the
 * terms of the version 2.1 (or later) of the GNU Lesser General Public License
 * as published by the Free Software Foundation; or version 2.0 of the Apache
 * License as published by the Apache Software Foundation. See the LICENSE files
 * for more details.
 *
 * RELIC is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE. See the LICENSE files for more details.
 *
 * You should have received a copy of the GNU Lesser General Public or the
 * Apache License along with RELIC. If not, see <https://www.gnu.org/licenses/>
 * or <https://www.apache.org/licenses/>.
 */

/**
 * @file
 *
 * Implementation of frobenius action on prime elliptic curves over a cubic
 * extension field.
 *
 * @ingroup epx
 */

#include "relic_core.h"

/*============================================================================*/
/* Public definitions                                                         */
/*============================================================================*/

void ep3_frb(ep3_t r, const ep3_t p, int i) {
	ctx_t *ctx = core_get();

	ep3_copy(r, p);
	for (; i > 0; i--) {
		fp3_frb(r->x, r->x, 1);
		fp3_frb(r->y, r->y, 1);
		fp3_frb(r->z, r->z, 1);
		fp3_mul(r->x, r->x, ctx->ep3_frb[0]);
		fp3_mul(r->y, r->y, ctx->ep3_frb[1]);
	}
}
