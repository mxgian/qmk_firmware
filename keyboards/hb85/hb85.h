/* Copyright 2019 'minhg'
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 * 8 x 15
 * Physical Layout CA0P
 * Layout:
 *            ┌────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───┐
 *    ________│ESC │ F1  │F2   │F3   │F4   │F5   │F6   │F7   │F8   │F9   │F10  │F11  │F12  │FN │    
 *   │        │    │     │     │     │     │     │     │     │     │     │     │     │         │     │     │     │ 
 *   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─
 *   │  ~  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │   BCKSPC  │ PDIV│ PMLT│PMIN │
 *   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─
 *   │TAB     │ Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  |  \|     │  P7 │ P8  │ P9  │
 *   │        │    │     │     │     │     │     │     │     │     │     │     │     │         │     │     │     │ 
 *   ├─ ───--─┴── ─┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─---──┼─────┼─────┼─────┼─         
 *   │CAPS      │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │ Enter      │  P4 │ P5  │ P6  │       
 *   │          │     │     │     │     │     │     │     │     │     │     │     │            │     │     │     │           
 *   ├──────--──┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴-----─┬─────┼─────┼─────┼─────┼─      
 *   │SHIFT       │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │SHIFT     │ UP  │  P1 │  P2 │  P3 │     
 *   │            │     │     │     │     │     │     │     │     │     │     │          │     │     │     │     │       
 *   ├───────┬─--─┴-┬─--─┴──┬──┴────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──-----┴─────┬─-───┼─────┼─────┼─    
 *           │ALT   │ CTRL  │     SPACE                              │CTRL │WIN│ALT  │LFT|DWN  │RGHT │  P0 │
 *           │      │       │                                        │     │   │     │   │     │     │     │  
 *           └─────-┴───────┴────────────────────────────────────────┴─────┴───┴─────┴───┴────-┴─────┴──--─┴─
 *  
 */


/* Layout:
               ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 *   _________ |K0C  │ K0B │ K0A │ K00 │ K01 │ K02 │K03  │K04  │K05  │K06  │K07  │K08  │K09  │K0E  │    
 *   │         │     │     │     │     │     │     │     │     │     │     │     │     │     │     │  
 *   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─
 *   │ K1E │ K1D │ K1C │ K1B │ K1A │ K10 │ K11 │ K12 │ K13 │ K14 │ K15 │ K16 │ K17 │  K18 K19  │ K59 │ K58 │ K57 │
 *   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─
 *   │K2E     │ K2D│  K2C│ K2B │ K2A │ K20 │K21  │ K22 │ K23 │ K24 │ K25 │ K26 │ K27 |  K28    │ K29 │ K56 │ K55 │
 *   │        │    │     │     │     │     │     │     │     │     │     │     │     │         │     │     │     │ 
 *   ├─ ───--─┴── ─┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─---──┼─────┼─────┼─────┼─         
 *   │K3E       │ K3D │ K3C │ K3B │ K3A │  K30│ K31 │ K32 │ K33 │ K34 │ K35 │ K36 │ K37        │ K39 │ K76 │ K75 │       
 *   │          │     │     │     │     │     │     │     │     │     │     │     │            │     │     │     │           
 *   ├──────--──┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴-----─┬─────┼─────┼─────┼─────┼─      
 *   │K4E         │ K4C │ K4B │ K4A │ K40 │ K41 │ K42 │ K43 │ K44 │ K45 │ K46 │K47       │ K48 │ K49 │ K78 │ K77 │     
 *   │            │     │     │     │     │     │     │     │     │     │     │          │     │     │     │     │       
 *   ├───────┬─--─┴-┬─--─┴──┬──┴────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─┬──------┴─────┬─-───┼─────┼─────┼─    
 *           │K6D   │ K6C   │     K61                                │K63  │K64 │K65 │K66|K67  │K68  │ K79 │
 *           │      │       │                                        │     │    │    │   │     │     │     │  
 *           └─────-┴───────┴────────────────────────────────────────┴─────┴─── ┴────┴───┴────-┴──--─┴──--─┴─
 *  
 *

 *  
 *

the top is logical layout of keys

bottom has to be a full 8x15 matrix with KC_NO in the spots where there are no switches, like the bottom corners and around the numpad

the physical matrix is a full grid, but in the logical matrix, you will see that the key codes jump around, this is because of how the 
PCB is actually mapped, it starts in the middle of the board and wraps around

this PCB is wired funny, it starts from the middle and wraps around
 */



// Arrow keys and 1.75u right shift

#define LAYOUT_default( \
  K0C, K0B, K0A, K00, K01, K02, K03, K04, K05, K06, K07, K08, K09,      K0E,  \
  K1E, K1D, K1C, K1B, K1A, K10, K11, K12, K13, K14, K15, K16, K17, K18, K19,  K59, K58, K57, \
  K2E,   K2D, K2C, K2B, K2A, K20, K21, K22, K23, K24, K25, K26, K27,   K28,  K29, K56, K55, \
  K3E,    K3D, K3C, K3B, K3A, K30, K31, K32, K33, K34, K35, K36,       K37,  K39, K76, K75,      \
  K4E,     K4C, K4B, K4A, K40, K41, K42, K43, K44, K45, K46, K47,    K48,    K49, K78, K77,  \
       K6D,  K6C,                K61,             K65, K64,K66, K67, K68,    K69, K79       \
) \
{ \
  { K00,    K01,    K02,  K03,    K04,   K05,  K06,  K07,  K08,  K09,  K0A,  K0B,   K0C,    KC_NO, K0E   }, \
  { K10,    K11,    K12,  K13,    K14,   K15,  K16,  K17,  K18,  K19,  K1A,  K1B,   K1C,    K1D,   K1E    }, \
  { K20,    K21,    K22,  K23,    K24,   K25,  K26,  K27,  K28,  K29,  K2A,  K2B,   K2C,    K2D,   K2E    }, \
  { K30,    K31,    K32,  K33,    K34,   K35,  K36,  K37,  KC_NO,K39,  K3A,  K3B,   K3C,    K3D,  K3E    }, \
  { K40,    K41,    K42,  K43,    K44,   K45,  K46,  K47,  K48,  K49,  K4A,  K4B,   K4C,    KC_NO, K4E    }, \
  { KC_NO,  KC_NO,  KC_NO,KC_NO,  KC_NO, K55,  K56,  K57,  K58,  K59,  KC_NO,KC_NO, KC_NO,  KC_NO, KC_NO   }, \
  { KC_NO,  K61,    KC_NO, KC_NO, K64,   K65,  K66,  K67,  K68,  K69,KC_NO,KC_NO, K6C,    K6D,   KC_NO    }, \
  { KC_NO,  KC_NO,  KC_NO,KC_NO,  KC_NO, K75,  K76,  K77,  K78,  K79,  KC_NO,KC_NO, KC_NO,  KC_NO, KC_NO    }  \
}