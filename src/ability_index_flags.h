#ifndef _ABILITY_INDEX_FLAGS_H_
#define _ABILITY_INDEX_FLAGS_H_


#ifdef __cplusplus
extern "C" {
#endif

typedef enum AbilityIndexFlags {
    ai_None         = 0,
    ai_AbilityOne   = 1 << 0,
    ai_AbilityTwo   = 1 << 1,
    ai_AbilityThree = 1 << 2,
    ai_AbilityFour  = 1 << 3,
    ai_AbilityFive  = 1 << 4,
    ai_AbilitySix   = 1 << 5,
} AbilityIndexFlags;

#ifdef __cplusplus
}
#endif

#endif