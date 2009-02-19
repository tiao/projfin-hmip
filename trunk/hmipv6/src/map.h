/* $Id: map.h $ */

#ifndef __MAP_H__
#define __MAP_H__ 1

#include <stdlib.h>
#include <time.h>

#include <netinet/in.h>
#include <netinet/icmp6.h>

#include "list.h"
#include "mipv6.h"
#include "util.h"
#include "tqueue.h"
#include "prefix.h"
#include "movement.h"

 
struct nd_opt_map
{
    uint8_t   nd_opt_map_type;
    uint8_t   nd_opt_map_length;
    uint8_t   nd_opt_map_dist_pref;
    uint8_t   nd_opt_map_flags_reserved;
    uint32_t  nd_opt_map_valid_time;
    struct in6_addr  nd_opt_map_globaladdr;
};
#define  ND_OPT_MAP     201 
 
#define ND_OPT_MAP_FLAG_R        0x80
#define ND_OPT_MAP_FLAG_M        0x40
#define ND_OPT_MAP_FLAG_I        0x20
#define ND_OPT_MAP_FLAG_T        0x10
#define ND_OPT_MAP_FLAG_P        0x08
#define ND_OPT_MAP_FLAG_V        0x04

struct map_list_entry
{
	struct list_head list;
	struct timespec timestamp;
	struct tq_elem tqe;
	struct nd_opt_map map;
	struct in6_addr rcoa;
	int used;
#define mle_mlen map.nd_opt_map_length
#define mle_dist_pref map.nd_opt_map_dist_pref
#define mle_flags map.nd_opt_map_flags_reserved
#define mle_valid_time map.nd_opt_map_valid_time
#define mle_globaladdr map.nd_opt_map_globaladdr
};

static inline void map_list_free(struct list_head *ml)
{
	struct list_head *l, *n;
	list_for_each_safe(l, n, ml) {
		list_del(l);
		free(list_entry(l, struct map_list_entry, list));
	}
}

struct map_list_entry *
map_list_get(const struct list_head *, const struct in6_addr *, int);
int map_list_cmp(const struct list_head *, const struct list_head *);
int map_list_copy(const struct list_head *, struct list_head *);
struct map_list_entry *map_choose(struct md_router *);

static inline int  map_list_find(const struct list_head *ml,
				    const struct in6_addr *addr, int mlen)
{
	return map_list_get(ml, addr, mlen) != NULL;
}
#endif
