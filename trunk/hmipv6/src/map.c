/*
 * $Id: map.c  $
 *
 * This file is part of the MIPL Mobile IPv6 for Linux.
 * 
 * Author: Cleiber Marques da Silva <cleiber.dev@gmail.com>
 *
 *
 * MIPL Mobile IPv6 for Linux is free software; you can redistribute
 * it and/or modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; version 2 of
 * the License.
 *
 * MIPL Mobile IPv6 for Linux is distributed in the hope that it will
 * be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with MIPL Mobile IPv6 for Linux; if not, write to the Free
 * Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 * 02111-1307 USA.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "map.h"
#include "util.h"

struct map_list_entry *map_list_get(const struct list_head *ml, 
					  const struct in6_addr *addr, 
					  int mlen)
{
	struct list_head *l;
	struct map_list_entry *m1 = NULL;
	list_for_each(l, ml) {
		struct map_list_entry *m2;
		m2 = list_entry(l, struct map_list_entry, list);
		if (!ipv6_pfx_cmp(&m2->mle_globaladdr, addr, m2->mle_mlen)) {
			if (mlen > 0) {
				if (m2->mle_mlen == mlen) {
					m1 = m2;
					break;
				}
			} else if (m1 == NULL || m1->mle_mlen < m2->mle_mlen)
				/* get the longest matching map */
				m1 = m2;
		}
	}
	return m1;
}

static inline int map_list_len(const struct list_head *ml)
{
	struct list_head *l;
	int res = 0;
	list_for_each(l, ml)
		res++;
	return res;
}

int map_list_cmp(const struct list_head *ml1, const struct list_head *ml2)
{
	struct list_head *l1, *l2;
	int ml1_len, ml2_len;
	int match = 0;

	ml1_len = map_list_len(ml1);
	ml2_len = map_list_len(ml2);

	list_for_each(l1, ml1) {
		printf("lista 1\n\n\n");
		struct map_list_entry *m1;
		m1 = list_entry(l1, struct map_list_entry, list);

		list_for_each(l2, ml2) {
			
		printf("lista 2\n\n\n");
			struct map_list_entry *m2;
			m2 = list_entry(l2, struct map_list_entry, list);

			if (m1->mle_mlen != m2->mle_mlen ||
			    ipv6_pfx_cmp(&m1->mle_globaladdr, 
					 &m2->mle_globaladdr, m1->mle_mlen))
				continue;
			match++;
			break;
		}
	}
	return ml1_len == match && ml2_len == match;
}

int map_list_copy(const struct list_head *pl1, struct list_head *pl2)
{
	struct list_head *l;
	int res = 0;
	list_for_each(l, pl1) {
		struct map_list_entry *p1, *p2;
		p1 = list_entry(l, struct map_list_entry, list);
		p2 = malloc(sizeof(struct map_list_entry));
		if (p2 == NULL) {
			map_list_free(pl2);
			return -1;
		}
		memcpy(p2, p1, sizeof(struct map_list_entry));
		list_add_tail(&p2->list, pl2);
		res++;
	}
	return res;
}

struct map_list_entry *map_choose(struct md_router *rtr)
{
	struct list_head *list;
	struct map_list_entry *best_map = NULL;

	list_for_each(list, &rtr->maps) {
		struct map_list_entry *m;
		m = list_entry(list, struct map_list_entry, list);
		if (!m)
			return NULL;
		if(!best_map || (m->mle_dist_pref < best_map->mle_dist_pref))
			best_map = m;
	}
	return best_map;
}

