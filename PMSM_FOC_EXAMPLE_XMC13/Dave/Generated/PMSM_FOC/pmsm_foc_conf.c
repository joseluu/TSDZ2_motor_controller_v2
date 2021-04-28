/*********************************************************************************************************************
* DAVE APP Name : PMSM_FOC       APP Version: 4.2.2
*
* NOTE:
* This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
*********************************************************************************************************************/

/**
 * @cond
 ***********************************************************************************************************************
 * Copyright (c) 2015, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * To improve the quality of the software, users are encouraged to share modifications, enhancements or bug fixes
 * with Infineon Technologies AG (dave@infineon.com).
 ***********************************************************************************************************************
 *
 * Change History
 * --------------
 *
 * 2015-02-15:
 *     - Initial version<br>
 *
 * 2015-11-19:
 *     - FOC library code integrated
 *
 * @endcond
 *
 */
/***********************************************************************************************************************
 * HEADER FILES                                                                                                      
 **********************************************************************************************************************/
#include "pmsm_foc.h"
/**********************************************************************************************************************
* DATA STRUCTURES
**********************************************************************************************************************/

ADC_QUEUE_ENTRY_t ADC_QUEUE_0_QEntry_i_phase_u = 
{
  .adc_event_callback    = NULL,
  .queue_position        = (uint8_t)0,
  .channel_number        = (uint8_t)3,
  .trigger_needed        = (bool)true,
  .refill_needed         = (bool)true,
  .ch_event_notification = (bool)false,
  .rs_event_notification = (bool)false
};

ADC_QUEUE_ENTRY_t ADC_QUEUE_0_QEntry_i_phase_v = 
{
  .adc_event_callback    = NULL,
  .queue_position        = (uint8_t)1,
  .channel_number        = (uint8_t)2,
  .trigger_needed        = (bool)false,
  .refill_needed         = (bool)true,
  .ch_event_notification = (bool)false,
  .rs_event_notification = (bool)false
};

ADC_QUEUE_ENTRY_t ADC_QUEUE_0_QEntry_i_phase_w = 
{
  .adc_event_callback    = NULL,
  .queue_position        = (uint8_t)2,
  .channel_number        = (uint8_t)4,
  .trigger_needed        = (bool)false,
  .refill_needed         = (bool)true,
  .ch_event_notification = (bool)false,
  .rs_event_notification = (bool)false
};

ADC_QUEUE_ENTRY_t ADC_QUEUE_0_QEntry_v_dc_link = 
{
  .adc_event_callback    = NULL,
  .queue_position        = (uint8_t)3,
  .channel_number        = (uint8_t)5,
  .trigger_needed        = (bool)false,
  .refill_needed         = (bool)true,
  .ch_event_notification = (bool)false,
  .rs_event_notification = (bool)false
};

ADC_QUEUE_ENTRY_t ADC_QUEUE_0_QEntry_analog_speed_input = 
{
  .adc_event_callback    = NULL,
  .queue_position        = (uint8_t)4,
  .channel_number        = (uint8_t)7,
  .trigger_needed        = (bool)false,
  .refill_needed         = (bool)true,
  .ch_event_notification = (bool)false,
  .rs_event_notification = (bool)false
};


XMC_VADC_CHANNEL_CONFIG_t PMSM_FOC_0_i_phase_uChan_InitHandle =
{
  .input_class         = (uint32_t)XMC_VADC_CHANNEL_CONV_GROUP_CLASS0,
  .channel_priority    = (uint32_t)1,
  .alternate_reference = (uint32_t)XMC_VADC_CHANNEL_REF_INTREF,
  .result_reg_number   = (uint32_t)10,
  .alias_channel       = -1
};

XMC_VADC_RESULT_CONFIG_t PMSM_FOC_0_i_phase_uRes_InitHandle = 
{
  .wait_for_read_mode  = (bool)false,
  .part_of_fifo        = (bool)false
};


XMC_VADC_CHANNEL_CONFIG_t PMSM_FOC_0_i_phase_vChan_InitHandle =
{
  .input_class         = (uint32_t)XMC_VADC_CHANNEL_CONV_GROUP_CLASS0,
  .channel_priority    = (uint32_t)1,
  .alternate_reference = (uint32_t)XMC_VADC_CHANNEL_REF_INTREF,
  .result_reg_number   = (uint32_t)12,
  .alias_channel       = -1
};

XMC_VADC_RESULT_CONFIG_t PMSM_FOC_0_i_phase_vRes_InitHandle = 
{
  .wait_for_read_mode  = (bool)false,
  .part_of_fifo        = (bool)false
};


XMC_VADC_CHANNEL_CONFIG_t PMSM_FOC_0_i_phase_wChan_InitHandle =
{
  .input_class         = (uint32_t)XMC_VADC_CHANNEL_CONV_GROUP_CLASS0,
  .channel_priority    = (uint32_t)1,
  .alternate_reference = (uint32_t)XMC_VADC_CHANNEL_REF_INTREF,
  .result_reg_number   = (uint32_t)5,
  .alias_channel       = -1
};

XMC_VADC_RESULT_CONFIG_t PMSM_FOC_0_i_phase_wRes_InitHandle = 
{
  .wait_for_read_mode  = (bool)false,
  .part_of_fifo        = (bool)false
};


XMC_VADC_CHANNEL_CONFIG_t PMSM_FOC_0_v_dc_linkChan_InitHandle =
{
  .input_class         = (uint32_t)XMC_VADC_CHANNEL_CONV_GROUP_CLASS0,
  .channel_priority    = (uint32_t)1,
  .alternate_reference = (uint32_t)XMC_VADC_CHANNEL_REF_INTREF,
  .result_reg_number   = (uint32_t)11,
  .alias_channel       = -1
};

XMC_VADC_RESULT_CONFIG_t PMSM_FOC_0_v_dc_linkRes_InitHandle = 
{
  .wait_for_read_mode  = (bool)false,
  .part_of_fifo        = (bool)false
};


XMC_VADC_CHANNEL_CONFIG_t PMSM_FOC_0_analog_speed_inputChan_InitHandle =
{
  .input_class         = (uint32_t)XMC_VADC_CHANNEL_CONV_GROUP_CLASS0,
  .channel_priority    = (uint32_t)1,
  .alternate_reference = (uint32_t)XMC_VADC_CHANNEL_REF_INTREF,
  .result_reg_number   = (uint32_t)4,
  .alias_channel       = -1
};

XMC_VADC_RESULT_CONFIG_t PMSM_FOC_0_analog_speed_inputRes_InitHandle = 
{
  .wait_for_read_mode  = (bool)false,
  .part_of_fifo        = (bool)false
};

PMSM_FOC_ADCConfig_t PMSM_FOC_0_ADCConfig =
{
  .queue_entry_hdlarray   = {
                              {&ADC_QUEUE_0_QEntry_i_phase_u,NULL},
                              {&ADC_QUEUE_0_QEntry_i_phase_v,NULL},
                              {&ADC_QUEUE_0_QEntry_i_phase_w,NULL},
                              {NULL,NULL},
                              {&ADC_QUEUE_0_QEntry_v_dc_link,NULL},
                              {&ADC_QUEUE_0_QEntry_analog_speed_input,NULL},
                              {NULL,NULL}
                            },
  .queue_active           = {
                              (uint8_t)PMSM_FOC_QUEUE_ACTIVE,
                              (uint8_t)PMSM_FOC_QUEUE_INACTIVE
                            },
  .qapp_handlearray       = {
                              (ADC_QUEUE_t *)(void*)&ADC_QUEUE_0,
                              NULL
                            },
  .vadc_reshandle_array   = {
                              &PMSM_FOC_0_i_phase_uRes_InitHandle ,
                              &PMSM_FOC_0_i_phase_vRes_InitHandle ,
                              &PMSM_FOC_0_i_phase_wRes_InitHandle ,
                              NULL,
                              &PMSM_FOC_0_v_dc_linkRes_InitHandle ,
                              &PMSM_FOC_0_analog_speed_inputRes_InitHandle ,
                              NULL
                            },
  .vadc_chhandle_array    = {
                              &PMSM_FOC_0_i_phase_uChan_InitHandle,
                              &PMSM_FOC_0_i_phase_vChan_InitHandle,
                              &PMSM_FOC_0_i_phase_wChan_InitHandle,
                              NULL,
                              &PMSM_FOC_0_v_dc_linkChan_InitHandle,
                              &PMSM_FOC_0_analog_speed_inputChan_InitHandle,
                              NULL
                            },
  .channel_num_array      = {
                              (uint8_t)3,
                              (uint8_t)2,
                              (uint8_t)4,
                              (uint8_t)0xFF,
                              (uint8_t)5,
                              (uint8_t)7,
                              (uint8_t)0xFF
                            },
  .result_num_array      = {
                              (uint8_t)10,
                              (uint8_t)12,
                              (uint8_t)5,
                              (uint8_t)0xFF,
                              (uint8_t)11,
                              (uint8_t)4,
                              (uint8_t)0xFF
                            },
  .vadc_group_pointerarray= {
                              (XMC_VADC_GROUP_t*)(void*)VADC_G1,
                              (XMC_VADC_GROUP_t*)(void*)VADC_G1,
                              (XMC_VADC_GROUP_t*)(void*)VADC_G1,
                              NULL,
                              (XMC_VADC_GROUP_t*)(void*)VADC_G1,
                              (XMC_VADC_GROUP_t*)(void*)VADC_G1,
                              NULL
                            }
};

 /***************************Interrupts*********************************/
/* Fast Control Loop interrupt */
PMSM_FOC_ISRHandle_t PMSM_FOC_0_FCL_InterruptConfig =
{
  .node_id      = (uint8_t)25, 
  .priority     = (uint8_t)2,
  .sub_priority = (uint8_t)0
};

/* Trap interrupt */
PMSM_FOC_ISRHandle_t PMSM_FOC_0_Trap_InterruptConfig =
{
  .node_id      = (uint8_t)26, 
  .priority     = (uint8_t)1,
  .sub_priority = (uint8_t)0
};

 /***************************Scaling Details*********************************/

/* Scaling Value for Motor Control Parameters

* ActualValue         = Scale * TargetValue

* Speed Scale         = 0.28610666721419087
* Current Scale       = 0.0001861158
* Speed Kp, Ki Scale  = 1.220703125E-4
* Flux Kp, Ki Scale   = 2.44140625E-4
* Torque kp, Ki Scale = 2.44140625E-4
* PLL kp, Ki Scale    = 3.0517578125E-5
*/


PMSM_FOC_VF_t PMSM_FOC_0_Vf =
{
 .vf_constant        = 41U,
 .vf_offset          = 2837U,
 .vf_threshold_speed = 2097,
 .vf_time            = 1000U                /* 50 ms time */
};

PMSM_FOC_PI_Coefs_t PMSM_FOC_0_PI_Speed =
{
  .error           = 0,
  .Uk              = 0,
  .Ik              = 0,
  .Kp              = 32768U,
  .Ki              = 3U,
  .Scale_KpKi      = 13,
  .Ik_limit_min    = -120788582,
  .Ik_limit_max    = 120788582,
  .Uk_limit_min    = 16,
  .Uk_limit_max    = 32767,
};

PMSM_FOC_PI_Coefs_t PMSM_FOC_0_PI_Torque =
{
  .error           = 0,
  .Uk              = 0,
  .Ik              = 0,
  .Kp              = 29686U,
  .Ki              = 2630U,
  .Scale_KpKi      = 12,
  .Ik_limit_min    = -134213632,
  .Ik_limit_max    = 134213632,
  .Uk_limit_min    = -32767,
  .Uk_limit_max    = 32767,
};

PMSM_FOC_PI_Coefs_t PMSM_FOC_0_PI_Flux =
{
  .error           = 0,
  .Uk              = 0,
  .Ik              = 0,
  .Kp              = 29686U,
  .Ki              = 2630U,
  .Scale_KpKi      = 12,
  .Ik_limit_min    = -134213632,
  .Ik_limit_max    = 134213632,
  .Uk_limit_min    = -32767,
  .Uk_limit_max    = 32767,
};

PMSM_FOC_PI_Coefs_t PMSM_FOC_0_PI_PLL =
{
  .error           = 0,
  .Uk              = 0,
  .Ik              = 0,
  .Kp              = 256U,
  .Ki              = 64U,
  .Scale_KpKi      = 15,
  .Ik_limit_min    = -2147450880,
  .Ik_limit_max    = 2147450880,
  .Uk_limit_min    = 524,
  .Uk_limit_max    = 16881,
};

PMSM_FOC_Output_t PMSM_FOC_0_Output;

PMSM_FOC_Input_t PMSM_FOC_0_Input =
{
  .Phase_L        = 40U,
  .Phase_R        = 384U,
  .Phase_L_Scale  = 14U,
  .CCU8_Period    = 1599U,
  .Res_Inc        = 4U,
  .LPF_N_BEMF     = 2U,
  .LPF_N_Speed    = 2U,
  .Threshold_LOW  = 16U,
  .Threshold_HIGH = 64U,
  .Flag_State     = 0U,
  .BEMF1          = 0,
  .BEMF2          = 0U,
  .Vref32         = 0U,
  .Vref_AngleQ31  = 0,
  .I_U            = 0,
  .I_V            = 0,
  .I_W            = 0,
  .Ref_Speed      = 0,
  .Vq_Flag        = 0,
  .Vq             = 0,
  .Ref_Id         = 0,
  .Ref_Iq         = 5,
  .Iq_PI_Flag     = 0U,
  .RotorAngleQ31  = 0,
  .RotorSpeed_In  = 0,
  .Flag_3or2_ADC  = 0U
};

/*******************************************FOC configuration structures ****************************************/

const PMSM_FOC_Config_t PMSM_FOC_0_Config=
{  
  .voltage_adc_scale           = 17419U,
  .pot_scale                   = 126693U,
  .speed_scale                 = 114527U,
  .inv_speed_scale             = 9374U,
  .current_scale               = 176057U,
  .inv_current_scale           = 6098U,
  .resistance_scale            = 1838U,   
  .inductance_scale            = 679U, 
  .config_vf_rampup_rate       = 28U,
  .config_ramp_up_rate         = 11U,
  .config_ramp_down_rate       = 11U,
  .threshold_time_vp           = 90U,
  .current_amplifier_offset    = 8191U,
  .bootstrap_time              = 0U,
  .max_dclink_voltage          = 39320U,
  .min_dclink_voltage          = 26213U,
  .phase_current_measurement   = (uint8_t)PMSM_FOC_3PHASE,
  .speed_low_limit             = 1583,
  .speed_openloop_max_limit    = 3166,
  .speed_openloop_min_limit    = 158,
  .pole_pair                   = 4U,
  .fcl_divider                 = 1U,
  .enable_speed_control        = 1U,
  .enable_biasvoltage          = 1U,
  .enable_voltage_compensation = 0U,
  .enable_pot_measurement      = 1U,
  .enable_vfstartup            = 1U,
  .enable_over_under_voltage   = 0U,
  .enable_vd_vq_decoupling     = 0U,
  .enable_direct_foc_startup   = 0U,
  .enable_transition           = 1U,
  .enable_vf_only              = 0U,
};


PMSM_FOC_t PMSM_FOC_0 = 
{
  .foc_config_ptr       = &PMSM_FOC_0_Config,
  .pwm_svm_ptr          = &PWM_SVM_0,
  .fcl_config_ptr       = &PMSM_FOC_0_FCL_InterruptConfig,
  .trap_config_ptr      = &PMSM_FOC_0_Trap_InterruptConfig,
  .vf_startup_ptr       = &PMSM_FOC_0_Vf,

  .adc_config_ptr       = &PMSM_FOC_0_ADCConfig,
  .PI_Speed             = &PMSM_FOC_0_PI_Speed,
  .PI_Torque            = &PMSM_FOC_0_PI_Torque,
  .PI_Flux              = &PMSM_FOC_0_PI_Flux,
  .PI_PLL               = &PMSM_FOC_0_PI_PLL,
  .FOCInput             = &PMSM_FOC_0_Input,
  .FOCOutput            = &PMSM_FOC_0_Output,
  .msm_state            = PMSM_FOC_MSM_STOP,
  .mode_flag            = (uint8_t)PMSM_FOC_FLAG_TRANSITION,
  .user_speed_set       = 5242,
  .speed_set_ptr        = &PMSM_FOC_0.user_speed_set,
  .bootstrap_index      = 0U,
  .bootstrap_count      = 0U,
  .motor_speed          = 0,
  .speed_set            = 0,
  .start_speed          = 0,
  .angle                = 0U,
  .amplitude            = 0U,
  .amplitude_max        = 1599U,
  .dclink_voltage       = 24U,
  .specified_volt       = 16383U,
  .threshold_adc_2shunt = 134U,
  .motor_direction      = PMSM_FOC_POSITIVE_DIR,
  .feedback_type        = (uint8_t)PMSM_FOC_SENSORLESS,
  .state                = (uint8_t)PMSM_FOC_STATE_UNINITIALISED,
  .ph_v_group           = 1U,
  .ph_w_group           = 2U,
  .alignment_counter    = 0U,
  .alignment_time       = 1000U,
  .alignment_volt       = 2837U,
  .alignment_step       = 4U,
  .met_stable_time      = 5000U,                    /* 0.25 s time */
  .ramp_counter         = 0U,
  .vf_ramp_up_rate      = 28U,
  .ramp_up_rate         = 11U,
  .ramp_down_rate       = 11U,
  .ramp_s_ratio         = 4U,
  .counter              = 0U,
  .fcl_time             = 50U,
  .fcl_div_value        = 1U
};

PMSM_FOC_Output_t   * const FOCOutput = &PMSM_FOC_0_Output;
PMSM_FOC_Input_t    * const FOCInput = &PMSM_FOC_0_Input;
PMSM_FOC_PI_Coefs_t * const PI_Speed = &PMSM_FOC_0_PI_Speed;
PMSM_FOC_PI_Coefs_t * const PI_Flux = &PMSM_FOC_0_PI_Flux;
PMSM_FOC_PI_Coefs_t * const PI_Torque = &PMSM_FOC_0_PI_Torque;
PMSM_FOC_PI_Coefs_t * const PI_PLL = &PMSM_FOC_0_PI_PLL;


