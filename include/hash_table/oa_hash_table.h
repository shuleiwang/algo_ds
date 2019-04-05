
#ifndef OA_HASH_TABLE
#define OA_HASH_TABLE

/** open addressed hash table knowledge background:
 *
 * 1. symbol definition:
 *   n - the number of elements
 *   m - the number of position of hash table
 *   alpha - load factor: alpha = n / m
 *   ep - expected probes: ep =  1 / (1 - alpha)
 *
 * 2. probe approach:
 *   2.1 linear probing: h(k, i) = (h'(k) + i) mod m
 *   2.2 double hashing: h(k, i) = (h1(k) + ih2(k)) mod m
 *       h1(k) = k mod m; h2(k) = 1 + (k mod m'), m' = m - 1
 */

#endif /* OA_HASH_TABLE */

