/*
 * Generated by Bluespec Compiler, version 2021.12.1 (build fd501401)
 * 
 * On Sun Dec 10 02:13:30 IST 2023
 * 
 */

/* Generation options: keep-fires */
#ifndef __mkFPMul64_h__
#define __mkFPMul64_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkFPMul64 module */
class MOD_mkFPMul64 : public Module {
 
 /* Clock handles */
 private:
  tClock __clk_handle_0;
 
 /* Clock gate handles */
 public:
  tUInt8 *clk_gate[0];
 
 /* Instantiation parameters */
 public:
 
 /* Module state */
 public:
  MOD_Reg<tUInt64> INST_answer;
  MOD_Reg<tUInt32> INST_exponent_res_normalised_1;
  MOD_Reg<tUInt32> INST_exponent_res_normalised_2;
  MOD_Reg<tUInt32> INST_exponent_res_normalised_3;
  MOD_Reg<tUInt32> INST_exponent_res_overbiased_1;
  MOD_Reg<tUInt32> INST_exponent_res_overbiased_2;
  MOD_Reg<tUInt8> INST_got_A;
  MOD_Reg<tUInt8> INST_got_B;
  MOD_Reg<tUInt8> INST_got_final;
  MOD_Reg<tUInt64> INST_input_1_64;
  MOD_Reg<tUInt64> INST_input_2_64;
  MOD_Reg<tUInt64> INST_mantissa_A;
  MOD_Reg<tUInt64> INST_mantissa_B;
  MOD_Reg<tUWide> INST_mantissa_res_non_normalised;
  MOD_Reg<tUInt64> INST_mantissa_res_non_normalised_reduced;
  MOD_Reg<tUInt64> INST_mantissa_res_normalised;
  MOD_Reg<tUInt8> INST_sign_out;
  MOD_Reg<tUInt8> INST_stage1;
  MOD_Reg<tUInt8> INST_stage2;
  MOD_Reg<tUInt8> INST_stage3;
 
 /* Constructor */
 public:
  MOD_mkFPMul64(tSimStateHdl simHdl, char const *name, Module *parent);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
  tUInt8 PORT_EN_put_A;
  tUInt8 PORT_EN_put_B;
  tUInt8 PORT_EN_get_res;
  tUInt64 PORT_put_A_a_in;
  tUInt64 PORT_put_B_b_in;
  tUInt8 PORT_RDY_put_A;
  tUInt8 PORT_RDY_put_B;
  tUInt64 PORT_get_res;
  tUInt8 PORT_RDY_get_res;
 
 /* Publicly accessible definitions */
 public:
  tUInt8 DEF_WILL_FIRE_get_res;
  tUInt8 DEF_WILL_FIRE_put_B;
  tUInt8 DEF_WILL_FIRE_put_A;
  tUInt8 DEF_WILL_FIRE_RL_finalResult;
  tUInt8 DEF_CAN_FIRE_RL_finalResult;
  tUInt8 DEF_WILL_FIRE_RL_mantissaNormalisation;
  tUInt8 DEF_CAN_FIRE_RL_mantissaNormalisation;
  tUInt8 DEF_WILL_FIRE_RL_exponentNormalisation;
  tUInt8 DEF_CAN_FIRE_RL_exponentNormalisation;
  tUInt8 DEF_WILL_FIRE_RL_preprocessing;
  tUInt8 DEF_CAN_FIRE_RL_preprocessing;
  tUInt8 DEF_CAN_FIRE_get_res;
  tUInt8 DEF_got_B__h691;
  tUInt8 DEF_CAN_FIRE_put_B;
  tUInt8 DEF_CAN_FIRE_put_A;
  tUInt8 DEF_got_A__h689;
 
 /* Local definitions */
 private:
  tUWide DEF__read__h389;
  tUInt64 DEF_x__h6394;
  tUInt64 DEF_x__h6314;
  tUInt64 DEF_x__h6308;
  tUWide DEF_x__h1035;
  tUWide DEF__1_CONCAT_mantissa_A_9_0_MUL_1_CONCAT_mantissa__ETC___d23;
  tUWide DEF_mantissa_res_non_normalised_6_SL_IF_mantissa_r_ETC___d552;
  tUWide DEF__1_CONCAT_mantissa_A_9___d20;
  tUWide DEF__1_CONCAT_mantissa_B_1___d22;
 
 /* Rules */
 public:
  void RL_preprocessing();
  void RL_exponentNormalisation();
  void RL_mantissaNormalisation();
  void RL_finalResult();
 
 /* Methods */
 public:
  void METH_put_A(tUInt64 ARG_put_A_a_in);
  tUInt8 METH_RDY_put_A();
  void METH_put_B(tUInt64 ARG_put_B_b_in);
  tUInt8 METH_RDY_put_B();
  tUInt64 METH_get_res();
  tUInt8 METH_RDY_get_res();
 
 /* Reset routines */
 public:
  void reset_RST_N(tUInt8 ARG_rst_in);
 
 /* Static handles to reset routines */
 public:
 
 /* Pointers to reset fns in parent module for asserting output resets */
 private:
 
 /* Functions for the parent module to register its reset fns */
 public:
 
 /* Functions to set the elaborated clock id */
 public:
  void set_clk_0(char const *s);
 
 /* State dumping routine */
 public:
  void dump_state(unsigned int indent);
 
 /* VCD dumping routines */
 public:
  unsigned int dump_VCD_defs(unsigned int levels);
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkFPMul64 &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkFPMul64 &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkFPMul64 &backing);
};

#endif /* ifndef __mkFPMul64_h__ */