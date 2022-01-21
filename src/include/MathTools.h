//==========================================================================================================
//  Used with pic30-gcc. and dsPIC.
//  Language tool versions: pic30-as.exe v3.30, pic30-gcc.exe v3.30, pic30-ld.exe v3.30, pic30-ar.exe v3.30
//==========================================================================================================
//    File name   :  mathtools.h
//    Description : mathematical tools and macros
//    V.Gyurov
// +----------+-------------+--------------------------------------------------------+
// |Date      | Version     | Description                                            |
// +----------+-------------+--------------------------------------------------------+
//  28.06.2011  V1.0            Initial release
//
//
//==========================================================================================================
#ifndef __MATHTOOLS_H
#define __MATHTOOLS_H

// Module Identification
#define MATHTOOLS

//==========================================================================================================
// Included files to resolve specific definitions in this file                
//==========================================================================================================
#include "basedef.h"

//==========================================================================================================
// Constant data                                                              
//==========================================================================================================
#define SINTAB_LEN          512 	// 2^9
#define	SIN_LEN_DIV         9

#define SQRT_TAB_LEN        512 	// 2^9
#define SQRT_LEN_DIV        9

#define ATAN_TABLE_LEN      129
#define DEC_PLACES_BEFORE 	7     	/* Corresponds to 128 values */
#define DEC_PLACES_AFTER    (15-DEC_PLACES_BEFORE)

/*
 *	arithmetic constants
 *	====================
 */
#ifndef PI
#define PI          3.1415926535897932384626433832795
#endif
#define SQRT2       1.4142135623730950488016887242097
#define SQRT3       1.7320508075688772935274463415059
#define SQRT3OV2		0.86602540378443864676372317075294
/*
 *	Fractional arithmetic constants
 *	================================
 */
#define qOneBySq3		0x49E7			// 1/SQRT(3)*32768 (Fractional format)
#define qOneBy3			0x2AAB			// 1/3 * 32768 in fractional format
#define qSQRT3OV2		0x6EDA			// SQRT(3)/2 in Fractional Format
#define qSQRT2			0xB504			// SQRT(2)   in Fractional Format
#define qOneBySq2   (32768.0 / SQRT2)
#define qSQRT3			0xDDB3			// SQRT(3)   in Fractional Format
#define qPI_deg			(32768ul)
#define qHalf_PI_deg	(qPI_deg / 2)
//==========================================================================================================
// Exported type                                                             
//==========================================================================================================
typedef struct
{
  S32 x;
  S16 sat;
}tSatLimit;

//==========================================================================================================
// Exported data                                                              
//==========================================================================================================
extern const S16	sintab[];

//==========================================================================================================
// Constant exported data                                                     
//==========================================================================================================

//==========================================================================================================
// Exported Macros                                                            
//==========================================================================================================
/******************************************************************************/
/*
 * Purpose:  Sine Function with linear interpolation in a small degrees input.
 * Input: 	alpha = 2^16*x/(2*PI)
 * Output:   sin(x)*32768
 */
/******************************************************************************/
static inline S16 sine(U16 alpha)	
{	
  if (  ( ((S16)alpha) <  (S16)( 0.25*65536.0/(2*PI)) ) && ( ((S16)alpha) >  (S16)(-0.25*65536.0/(2*PI)) )  )
    return((S32)(256*PI)*(S16)alpha >> 8);
  else
    return(sintab[(U16)(alpha)>>(16-SIN_LEN_DIV)]);
}

/******************************************************************************/
/*
 * Purpose:  
 * Input: 	
 * Output: 
 */
/******************************************************************************/
static inline S32 limit(S32 x, S32 min, S32 max)
{
  if(x > min && x < max) 
    return x;
  else if(x < min)
    return min;
  else if(x > max)
    return max;
  else
    return x;
}
/******************************************************************************/
/*
 * Purpose:  
 * Input: 	
 * Output: 
 */
/******************************************************************************/
static inline tSatLimit satlimit(S32 x, S32 min, S32 max)
{
  tSatLimit SatLimit = {0};
  
  if(x > min && x < max)
  {
    SatLimit.x = x;
    SatLimit.sat = 0;
  }
  else if(x < min)
  {
    SatLimit.x = min;
    SatLimit.sat = -1;
  }
  else if(x > max)
  {
    SatLimit.x = max;
    SatLimit.sat = 1;
  }
  
  return SatLimit;
}

/******************************************************************************/
/*
 * Purpose:  Cosine Function with linear interpolation in a small degrees input.
 * Input: 	alpha = 2^16*x/(2*PI)
 * Output:   cos(x)*32768
 */
/******************************************************************************/
#define cosine(alpha)	sine(16384 - (alpha))

/*
 *	macro definitions for arithmetic functions
 *	==========================================
 */
#define absi(x)             ((x)>=0 ? (x) : -(x))		/* absolute of integer */
#define sign(x)             ((x)>=0 ? 1 : -1)			/* sign function 1/-1 */
#define sigm(x)             ((x)>=0 ? 0 : 1)			/* sign function 0/1 */
#define signmul(x,y)        ((y)>=0 ? (x) : -(x))		/* set sign(x) according sign(y) */
#define max_int(x,y)        ((x)>=(y) ? (x) : (y))		/* return maximum of (x,y) */
#define min_int(x,y)        ((x)>=(y) ? (y) : (x))		/* return minimum of (x,y) */
#define boolean(x)	        ((x)==0 ? FALSE : TRUE)		/* integer to boolean conversion */
#define MulFracBy2(x,y)     ((((S32)(x)*(y))<<1)>>16)   /* operands word */
#define MulFracBy2L(x,y)    (((x)*(y))>>15)             /* operands long */
#define div_mod2(x,n)       (((x)+(1<<((n)-1)))>>(n))   /* division modulo 2 with rounding, n >= 1! */
#define HiPartBy2(x)        ((x)>>15)

/*
 *	macro definitions for bit/byte functions
 *	==========================================
 */
#define _putbit(value,dst,bitn)	 (		\
{                                     \
  if(value)                           \
  dst = ((dst) | (U16)(1u << bitn));	\
  else                                \
  dst = ((dst) & (U16)~(1u << bitn));	\
 })

#define _getbit(src,bitn)	((src) & (1 << (bitn)))

#define BIT(n)                                          (1ULL << (n))
#define BITMASK(len)                                    (BIT(len) - 1)
#define BITMAP_GET_VALUE(bitmap, bitlen, shift)         ( ((bitmap) >> (shift)) & (bitlen) )
#define BITMAP_SET_VALUE(bitmap, val, bitlen, shift)    ((bitmap) = ((bitmap) & ~((bitlen) << (shift))) | (((val) << (shift)) & ((bitlen) << (shift))))
#define BIT_GET(value, bit)                             ( ((value) >> (bit)) & 0x01uL  )
#define BIT_SET(value, bit)                             ( (value) |= 0x01uL << (bit) )
#define BIT_CLEAR(value, bit)                           ( (value) &= ~(0x01uL << (bit)) )
#define ROUND_UP(x)                                     (((x) < 0) ? ( (((x) * 2L) - 1L) / 2L ) : ( (((x) * 2L) + 1L) / 2L ))
#define fround(x)                                       (((x) < 0) ?  ((x) - 0.5 ) : ((x) + 0.5 ) )

#define Hi(LongVar)         (*((S16 *)&(LongVar)+1))
#define Lo(LongVar)         (*(S16 *)&(LongVar))
#define Hiu(LongVar)        (*((U16 *)&(LongVar)+1))
#define Lou(LongVar)        (*(U16 *)&(LongVar))
#define HiBy(WordVar)       (*((U8 *)&(WordVar)+1))
#define LoBy(WordVar)       (*(U8 *)&(WordVar))

// Built-in Functions Wrappers
#define _builtin_mulss(s16A, s16B)      __builtin_mulss((S16)(s16A), (S16)(s16B))       // Signed integer multiplication - S32 output
#define _builtin_mulsu(s16A, u16B)      __builtin_mulsu((S16)(s16A), (U16)(u16B))       // Signed mixed signs integer multiplication - S32 output
#define _builtin_mulus(u16A, s16B)      __builtin_mulus((U16)(u16A), (S16)(s16B))       // Signed mixed signs integer multiplication - S32 output
#define _builtin_muluu(u16A, u16B)      __builtin_mulus((U16)(u16A), (U16)(u16B))       // Unsigned integer multiplication - U32 output
#define _builtin_divsd(s32Num, s16Den)  __builtin_divsd((S32)(s32Num), (S16)(s16Den))   // Computes the quotient s32Num / s16Den - S16 output
#define _builtin_divud(u32Num, u16Den)  __builtin_divud((U32)(u32Num), (U16)(u16Den))   // Computes the quotient u32Num / u16Den - U16 output

//==========================================================================================================
// Exported functions                     				                        
//==========================================================================================================
extern U16 ATAN(S16 iY, S16 iX);
extern S16 sqrt_16(U16 rad);
extern S16 sqrt_32(U32 rad);
extern U32 pow_16(S16 x, U16 n);
extern S16 sdiv_32(_IN_ S32 s32Divident_long, _IN_ S16 s16Divider);
extern S16 udiv_32(_IN_ U32 u32Divident_long, _IN_ U16 u16Divider);
extern _Q15 fmul_q15(_Q15 qA, _Q15 qB);
extern U16 fmul_qu15(U16 quA, U16 quB);
extern S32 mul_s16(S16 A, S16 B);
extern void DSP_Engine_Init(void);

#endif /* MATHTOOLS */

