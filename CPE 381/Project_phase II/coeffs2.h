/*
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool
 * Generated by MATLAB(R) 9.14 and Signal Processing Toolbox 9.2.
 * Generated on: 13-Apr-2023 19:48:00
 */

/*
 * Discrete-Time FIR Filter (real)
 * -------------------------------
 * Filter Structure  : Direct-Form FIR
 * Filter Length     : 165
 * Stable            : Yes
 * Linear Phase      : Yes (Type 1)
 */

/* General type conversion for MATLAB generated C-code  */
#include "tmwtypes.h"
/* 
 * Expected path to tmwtypes.h 
 * C:\Program Files\MATLAB\R2023a\extern\include\tmwtypes.h 
 */
const int BLen2 = 165;
const real64_T B1[165] = {
   -0.00422571535343, 0.009737237951398,-0.002285229601326,-0.002936620138758,
   0.000474831538202, 0.003335720698456, 0.003856412387731, 0.002376851793333,
   0.000244401011951,-0.001272426202771,-0.001593743108874,-0.000938655164099,
  -1.094940195588e-06,0.0005096026828123,0.0002535979928872,-0.0006189092290526,
  -0.001564033246285,-0.001946361701834,-0.001359844633497,0.0001427622289745,
   0.002052640926613, 0.003576052072403, 0.003991036869678, 0.002971507196889,
  0.0007745541553437,-0.001831543365218,-0.003868868185181,-0.004578691804305,
  -0.003733583224637,-0.001769868829998,0.0004363139091406, 0.001965128297899,
   0.002299687938065, 0.001582379777066,0.0005167378782841,-1.948556501468e-06,
  0.0005810485907622,  0.00211760827879,  0.00373128160351, 0.004207329685202,
    0.00263828096163,-0.001007519337407,-0.005653732349126,-0.009449769129796,
   -0.01051629778516,-0.007851641702293,  -0.0019233004254, 0.005351831092463,
     0.0113137064894,  0.01365018218298,  0.01143122491749, 0.005550290455664,
   -0.00160521213557,-0.007214785542716,-0.009300475807351,-0.007647588689943,
  -0.003866792572392,-0.0005501373647506,0.0001356759453885, -0.00230005920349,
  -0.006190201205626,-0.008383534899385,-0.005833385002939, 0.002569379145933,
    0.01485403029321,  0.02623657609328,  0.03080823163924,  0.02422841079803,
   0.006034566412311, -0.01919749634206, -0.04295923939459,  -0.0556845155382,
   -0.05056035062499, -0.02675255626707, 0.009559262341651,  0.04671365537813,
    0.07151361154177,  0.07414760775116,  0.05212207272277,  0.01162101124909,
   -0.03427799113031, -0.07012301582452,   0.9163771955034, -0.07012301582452,
   -0.03427799113031,  0.01162101124909,  0.05212207272277,  0.07414760775116,
    0.07151361154177,  0.04671365537813, 0.009559262341651, -0.02675255626707,
   -0.05056035062499,  -0.0556845155382, -0.04295923939459, -0.01919749634206,
   0.006034566412311,  0.02422841079803,  0.03080823163924,  0.02623657609328,
    0.01485403029321, 0.002569379145933,-0.005833385002939,-0.008383534899385,
  -0.006190201205626, -0.00230005920349,0.0001356759453885,-0.0005501373647506,
  -0.003866792572392,-0.007647588689943,-0.009300475807351,-0.007214785542716,
   -0.00160521213557, 0.005550290455664,  0.01143122491749,  0.01365018218298,
     0.0113137064894, 0.005351831092463,  -0.0019233004254,-0.007851641702293,
   -0.01051629778516,-0.009449769129796,-0.005653732349126,-0.001007519337407,
    0.00263828096163, 0.004207329685202,  0.00373128160351,  0.00211760827879,
  0.0005810485907622,-1.948556501468e-06,0.0005167378782841, 0.001582379777066,
   0.002299687938065, 0.001965128297899,0.0004363139091406,-0.001769868829998,
  -0.003733583224637,-0.004578691804305,-0.003868868185181,-0.001831543365218,
  0.0007745541553437, 0.002971507196889, 0.003991036869678, 0.003576052072403,
   0.002052640926613,0.0001427622289745,-0.001359844633497,-0.001946361701834,
  -0.001564033246285,-0.0006189092290526,0.0002535979928872,0.0005096026828123,
  -1.094940195588e-06,-0.000938655164099,-0.001593743108874,-0.001272426202771,
   0.000244401011951, 0.002376851793333, 0.003856412387731, 0.003335720698456,
   0.000474831538202,-0.002936620138758,-0.002285229601326, 0.009737237951398,
   -0.00422571535343
};
