// Code generated by colf(1); DO NOT EDIT.
// The compiler used schema file test.colf for package gen.

#ifndef COLFER_H
#define COLFER_H

#include <limits.h>
#include <stdint.h>
#include <string.h>
#include <time.h>


#if CHAR_BIT != 8
#error "octet byte size"
#endif

#ifdef __cplusplus
extern "C" {
#endif


// colfer_size_max is the upper limit for serial octet sizes.
extern size_t colfer_size_max;

// colfer_list_max is the upper limit for the number of elements in a list.
extern size_t colfer_list_max;


// colfer_text is a UTF-8 CLOB.
typedef struct {
	const char*  utf8;
	size_t       len;
} colfer_text;

// colfer_binary is a BLOB.
typedef struct {
	uint8_t* octets;
	size_t   len;
} colfer_binary;


typedef struct gen_o gen_o;

typedef struct gen_dromedary_case gen_dromedary_case;

typedef struct gen_embed_o gen_embed_o;


// O contains all supported data types.
struct gen_o {
	// B tests booleans.
	char b;
	// U32 tests unsigned 32-bit integers.
	uint32_t u32;
	// U64 tests unsigned 64-bit integers.
	uint64_t u64;
	// I32 tests signed 32-bit integers.
	int32_t i32;
	// I64 tests signed 64-bit integers.
	int64_t i64;
	// F32 tests 32-bit floating points.
	float f32;
	// F64 tests 64-bit floating points.
	double f64;
	// T tests timestamps.
	struct timespec t;
	// S tests text.
	colfer_text s;
	// A tests binaries.
	colfer_binary a;
	// O tests nested data structures.
	gen_o* o;
	// Os tests data structure lists.
	struct {
		struct gen_o* list;
		size_t len;
	} os;
	// Ss tests text lists.
	struct {
		colfer_text* list;
		size_t len;
	} ss;
	// As tests binary lists.
	struct {
		colfer_binary* list;
		size_t len;
	} as;
	// U8 tests unsigned 8-bit integers.
	uint8_t u8;
	// U16 tests unsigned 16-bit integers.
	uint16_t u16;
	// F32s tests 32-bit floating point lists.
	struct {
		float* list;
		size_t len;
	} f32s;
	// F64s tests 64-bit floating point lists.
	struct {
		double* list;
		size_t len;
	} f64s;
};

// gen_o_marshal_len returns the Colfer serial octet size.
// When the return is zero then errno is set to EFBIG to indicate a breach of
// either colfer_size_max or colfer_list_max.
size_t gen_o_marshal_len(const gen_o* o);

// gen_o_marshal encodes o as Colfer into buf and returns the number
// of octets written.
size_t gen_o_marshal(const gen_o* o, void* buf);

// gen_o_unmarshal decodes data as Colfer into o and returns the
// number of octets read. The data is read up to a maximum of datalen or
// colfer_size_max, whichever occurs first.
// When the return is zero then errno is set to one of the following 3 values:
// EWOULDBLOCK on incomplete data, EFBIG on a breach of either colfer_size_max
// or colfer_list_max and EILSEQ on schema mismatch.
size_t gen_o_unmarshal(gen_o* o, const void* data, size_t datalen);

// DromedaryCase oposes name casings.
struct gen_dromedary_case {

	colfer_text pascal_case;
};

// gen_dromedary_case_marshal_len returns the Colfer serial octet size.
// When the return is zero then errno is set to EFBIG to indicate a breach of
// either colfer_size_max or colfer_list_max.
size_t gen_dromedary_case_marshal_len(const gen_dromedary_case* o);

// gen_dromedary_case_marshal encodes o as Colfer into buf and returns the number
// of octets written.
size_t gen_dromedary_case_marshal(const gen_dromedary_case* o, void* buf);

// gen_dromedary_case_unmarshal decodes data as Colfer into o and returns the
// number of octets read. The data is read up to a maximum of datalen or
// colfer_size_max, whichever occurs first.
// When the return is zero then errno is set to one of the following 3 values:
// EWOULDBLOCK on incomplete data, EFBIG on a breach of either colfer_size_max
// or colfer_list_max and EILSEQ on schema mismatch.
size_t gen_dromedary_case_unmarshal(gen_dromedary_case* o, const void* data, size_t datalen);

// EmbedO has an inner object only.
// Covers regression of issue #66.
struct gen_embed_o {

	gen_o* inner;
};

// gen_embed_o_marshal_len returns the Colfer serial octet size.
// When the return is zero then errno is set to EFBIG to indicate a breach of
// either colfer_size_max or colfer_list_max.
size_t gen_embed_o_marshal_len(const gen_embed_o* o);

// gen_embed_o_marshal encodes o as Colfer into buf and returns the number
// of octets written.
size_t gen_embed_o_marshal(const gen_embed_o* o, void* buf);

// gen_embed_o_unmarshal decodes data as Colfer into o and returns the
// number of octets read. The data is read up to a maximum of datalen or
// colfer_size_max, whichever occurs first.
// When the return is zero then errno is set to one of the following 3 values:
// EWOULDBLOCK on incomplete data, EFBIG on a breach of either colfer_size_max
// or colfer_list_max and EILSEQ on schema mismatch.
size_t gen_embed_o_unmarshal(gen_embed_o* o, const void* data, size_t datalen);


#ifdef __cplusplus
} // extern "C"
#endif

#endif
