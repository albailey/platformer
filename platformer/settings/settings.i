
FT_DPCM_OFF                     =$ff00  ;samples offset, $c000 or higher, 64-byte steps

FT_SFX_STREAMS                  =4      ;number of sound effects played at once, can be 4 or less (faster)


.define FT_DPCM_ENABLE  0       ;zero to exclude all the DMC code

.define FT_SFX_ENABLE   1       ;zero to exclude all the sound effects code

.define SPEED_FIX       1       ;zero if you want to handle PAL/NTSC speed difference by yourself

.define FT_THREAD      1        ;undefine if you call sound effects in the same thread as sound update

