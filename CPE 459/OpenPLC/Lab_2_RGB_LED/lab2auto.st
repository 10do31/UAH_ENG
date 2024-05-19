PROGRAM lab2
  VAR
    count AT %MW8 : INT;
    color0 AT %MW0 : INT;
    color1 AT %MW1 : INT;
    color2 AT %MW2 : INT;
    color3 AT %MW3 : INT;
    color4 AT %MW4 : INT;
    color5 AT %MW5 : INT;
    color6 AT %MW6 : INT;
    color7 AT %MW7 : INT;
    red_anode AT %QX100.0 : BOOL;
    green_anode AT %QX100.1 : BOOL;
    blue_anode AT %QX100.2 : BOOL;
    button AT %IX100.0 : BOOL;
    mode AT %QX0.0 : BOOL;
  END_VAR
  VAR
    TON0 : TON;
    TON1 : TON;
    count_en : BOOL;
    auto_count_en : BOOL;
    CTU0 : CTU;
    CTU_Res : BOOL;
    Mux_Out : INT;
    R_TRIG1 : R_TRIG;
    _TMP_MUX32_OUT : INT;
    _TMP_MOD27_OUT : INT;
    _TMP_INT_TO_BOOL45_OUT : BOOL;
    _TMP_DIV26_OUT : INT;
    _TMP_MOD7_OUT : INT;
    _TMP_INT_TO_BOOL15_OUT : BOOL;
    _TMP_DIV16_OUT : INT;
    _TMP_DIV17_OUT : INT;
    _TMP_MOD20_OUT : INT;
    _TMP_INT_TO_BOOL22_OUT : BOOL;
    _TMP_SEL49_OUT : BOOL;
  END_VAR

  TON0(IN := NOT(auto_count_en), PT := T#500ms);
  IF TON0.Q THEN
    auto_count_en := TRUE; (*set*)
  END_IF;
  TON1(IN := auto_count_en, PT := T#500ms);
  IF TON1.Q THEN
    auto_count_en := FALSE; (*reset*)
  END_IF;
  R_TRIG1(CLK := count_en);
  CTU0(CU := R_TRIG1.Q, R := CTU_Res, PV := 8);
  CTU_Res := CTU0.Q;
  _TMP_MUX32_OUT := MUX(count, color0, color1, color2, color3, color4, color5, color6, color7);
  Mux_Out := _TMP_MUX32_OUT;
  count := CTU0.CV;
  _TMP_MOD27_OUT := MOD(Mux_Out, 2);
  _TMP_INT_TO_BOOL45_OUT := INT_TO_BOOL(_TMP_MOD27_OUT);
  blue_anode := _TMP_INT_TO_BOOL45_OUT;
  _TMP_DIV26_OUT := DIV(Mux_Out, 2);
  _TMP_MOD7_OUT := MOD(_TMP_DIV26_OUT, 2);
  _TMP_INT_TO_BOOL15_OUT := INT_TO_BOOL(_TMP_MOD7_OUT);
  green_anode := _TMP_INT_TO_BOOL15_OUT;
  _TMP_DIV16_OUT := DIV(Mux_Out, 2);
  _TMP_DIV17_OUT := DIV(_TMP_DIV16_OUT, 2);
  _TMP_MOD20_OUT := MOD(_TMP_DIV17_OUT, 2);
  _TMP_INT_TO_BOOL22_OUT := INT_TO_BOOL(_TMP_MOD20_OUT);
  red_anode := _TMP_INT_TO_BOOL22_OUT;
  _TMP_SEL49_OUT := SEL(mode, button, auto_count_en);
  count_en := _TMP_SEL49_OUT;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : lab2;
  END_RESOURCE
END_CONFIGURATION
