#ifndef _FIXED_POINT_H_
#define _FIXED_POINT_H

/* fixed point definition */
typedef int fixed_point;

/* shift value instead of scale factor */
#define FP_SHIFT_VALUE 14

/* Functions */
/* Convert int to FP. */
#define int_to_FP(A) ((fixed_point)(A << FP_SHIFT_VALUE))
/* Add two FP values. */
#define add_FP(A,B) (A + B)
/* Add FP value A and int value B. */
#define add_FP_int(A,B) (A + (B<<FP_SHIFT_VALUE))
/* Substract two FP values. */
#define sub_FP(A,B) (A-B)
/* Substract int value B from FP value A. */
#define sub_FP_int(A,B) (A - (B<<FP_SHIFT_VALUE))
/* Multiply a FP value A by int value B. */
#define mul_FP_int(A,B) (A * B)
/* Devide FP value A by int value B. */
#define div_FP_int(A,B) (A / B)
/* Multiply two FP values. */
#define mul_FP(A,B) ((fixed_point)(((int64_t)A)*B >> FP_SHIFT_VALUE))
/* Divide two FP valuess. */
#define div_FP(A,B) ((fixed_point)(((int64_t)A << FP_SHIFT_VALUE) / B))
/* Get integer part of a FP value. */
#define FP_int_part(A) (A >> FP_SHIFT_VALUE)
/* Get rounded integer of FP value. */
#define round_FP(A) (A>=0 ? ((A+(1<<(FP_SHIFT_VALUE-1)))>>FP_SHIFT_VALUE)\
			  : ((A-(1<<(FP_SHIFT_VALUE-1)))>>FP_SHIFT_VALUE))

#endif
