#ifndef _STATUS_EFFECT_H_
#define _STATUS_EFFECT_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum StatusEffectFlags { 
    se_None         = 0,
    se_Ablaze       = 1 << 0,
    se_Poison       = 1 << 1,
    se_Stun         = 1 << 2,
    se_CantMiss     = 1 << 3,
    se_FirstMove    = 1 << 4,
    se_LastMove     = 1 << 5,
    se_PerfectDodge = 1 << 6,
    se_Immovable    = 1 << 7
 } StatusEffectFlags;

#ifdef __cplusplus
}
#endif

#endif
