void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void LAB2_init__(LAB2 *data__, BOOL retain) {
  __INIT_VAR(data__->COUNT,0,retain)
  __INIT_VAR(data__->COLOR0,0,retain)
  __INIT_VAR(data__->COLOR1,0,retain)
  __INIT_VAR(data__->COLOR2,0,retain)
  __INIT_VAR(data__->COLOR3,0,retain)
  __INIT_VAR(data__->COLOR4,0,retain)
  __INIT_VAR(data__->COLOR5,0,retain)
  __INIT_VAR(data__->COLOR6,0,retain)
  __INIT_VAR(data__->COLOR7,0,retain)
  __INIT_VAR(data__->RED_ANODE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GREEN_ANODE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BLUE_ANODE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BUTTON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MODE,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON0,retain);
  TON_init__(&data__->TON1,retain);
  __INIT_VAR(data__->COUNT_EN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AUTO_COUNT_EN,__BOOL_LITERAL(FALSE),retain)
  CTU_init__(&data__->CTU0,retain);
  __INIT_VAR(data__->CTU_RES,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MUX_OUT,0,retain)
  R_TRIG_init__(&data__->R_TRIG1,retain);
  __INIT_VAR(data__->_TMP_MUX32_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOD27_OUT,0,retain)
  __INIT_VAR(data__->_TMP_INT_TO_BOOL45_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_DIV26_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOD7_OUT,0,retain)
  __INIT_VAR(data__->_TMP_INT_TO_BOOL15_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_DIV16_OUT,0,retain)
  __INIT_VAR(data__->_TMP_DIV17_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOD20_OUT,0,retain)
  __INIT_VAR(data__->_TMP_INT_TO_BOOL22_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SEL49_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LAB2_body__(LAB2 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->TON0.,IN,,!(__GET_VAR(data__->AUTO_COUNT_EN,)));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 500, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  if (__GET_VAR(data__->TON0.Q,)) {
    __SET_VAR(data__->,AUTO_COUNT_EN,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->TON1.,IN,,__GET_VAR(data__->AUTO_COUNT_EN,));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 500, 0, 0, 0, 0));
  TON_body__(&data__->TON1);
  if (__GET_VAR(data__->TON1.Q,)) {
    __SET_VAR(data__->,AUTO_COUNT_EN,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->COUNT_EN,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->CTU0.,CU,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->CTU0.,R,,__GET_VAR(data__->CTU_RES,));
  __SET_VAR(data__->CTU0.,PV,,8);
  CTU_body__(&data__->CTU0);
  __SET_VAR(data__->,CTU_RES,,__GET_VAR(data__->CTU0.Q,));
  __SET_VAR(data__->,_TMP_MUX32_OUT,,MUX__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->COUNT,),
    (UINT)8,
    (INT)__GET_VAR(data__->COLOR0,),
    (INT)__GET_VAR(data__->COLOR1,),
    (INT)__GET_VAR(data__->COLOR2,),
    (INT)__GET_VAR(data__->COLOR3,),
    (INT)__GET_VAR(data__->COLOR4,),
    (INT)__GET_VAR(data__->COLOR5,),
    (INT)__GET_VAR(data__->COLOR6,),
    (INT)__GET_VAR(data__->COLOR7,)));
  __SET_VAR(data__->,MUX_OUT,,__GET_VAR(data__->_TMP_MUX32_OUT,));
  __SET_VAR(data__->,COUNT,,__GET_VAR(data__->CTU0.CV,));
  __SET_VAR(data__->,_TMP_MOD27_OUT,,MOD__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->MUX_OUT,),
    (INT)2));
  __SET_VAR(data__->,_TMP_INT_TO_BOOL45_OUT,,INT_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->_TMP_MOD27_OUT,)));
  __SET_VAR(data__->,BLUE_ANODE,,__GET_VAR(data__->_TMP_INT_TO_BOOL45_OUT,));
  __SET_VAR(data__->,_TMP_DIV26_OUT,,DIV__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->MUX_OUT,),
    (INT)2));
  __SET_VAR(data__->,_TMP_MOD7_OUT,,MOD__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->_TMP_DIV26_OUT,),
    (INT)2));
  __SET_VAR(data__->,_TMP_INT_TO_BOOL15_OUT,,INT_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->_TMP_MOD7_OUT,)));
  __SET_VAR(data__->,GREEN_ANODE,,__GET_VAR(data__->_TMP_INT_TO_BOOL15_OUT,));
  __SET_VAR(data__->,_TMP_DIV16_OUT,,DIV__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->MUX_OUT,),
    (INT)2));
  __SET_VAR(data__->,_TMP_DIV17_OUT,,DIV__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->_TMP_DIV16_OUT,),
    (INT)2));
  __SET_VAR(data__->,_TMP_MOD20_OUT,,MOD__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->_TMP_DIV17_OUT,),
    (INT)2));
  __SET_VAR(data__->,_TMP_INT_TO_BOOL22_OUT,,INT_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->_TMP_MOD20_OUT,)));
  __SET_VAR(data__->,RED_ANODE,,__GET_VAR(data__->_TMP_INT_TO_BOOL22_OUT,));
  __SET_VAR(data__->,_TMP_SEL49_OUT,,SEL__BOOL__BOOL__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->MODE,),
    (BOOL)__GET_VAR(data__->BUTTON,),
    (BOOL)__GET_VAR(data__->AUTO_COUNT_EN,)));
  __SET_VAR(data__->,COUNT_EN,,__GET_VAR(data__->_TMP_SEL49_OUT,));

  goto __end;

__end:
  return;
} // LAB2_body__() 





