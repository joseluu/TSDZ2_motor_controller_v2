/*********************************************************************************************************************
* DAVE APP Name : PMSM_FOC       APP Version: 4.2.14
*
* NOTE:
* This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
*********************************************************************************************************************/

/**
 * @cond
 ***********************************************************************************************************************
 * Copyright (c) 2015-2020, Infineon Technologies AG
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
 * 2017-09-27:
 *     - Fixed code for XMC14
 *
 * 2018-02-14:
 * 	   - Anti windup Flag init added in PI controller.
 * 	   - Comment added for PT1 VoltageCompensation filter
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
  .channel_number        = (uint8_t)4,
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
  .channel_number        = (uint8_t)3,
  .trigger_needed        = (bool)false,
  .refill_needed         = (bool)true,
  .ch_event_notification = (bool)false,
  .rs_event_notification = (bool)false
};

ADC_QUEUE_ENTRY_t ADC_QUEUE_0_QEntry_v_dc_link = 
{
  .adc_event_callback    = NULL,
  .queue_position        = (uint8_t)3,
  .channel_number        = (uint8_t)6,
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
  .result_reg_number   = (uint32_t)12,
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
  .result_reg_number   = (uint32_t)11,
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
  .result_reg_number   = (uint32_t)10,
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
  .result_reg_number   = (uint32_t)4,
  .alias_channel       = -1
};

XMC_VADC_RESULT_CONFIG_t PMSM_FOC_0_v_dc_linkRes_InitHandle = 
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
                              {NULL,NULL},
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
                              NULL,
                              NULL
                            },
  .vadc_chhandle_array    = {
                              &PMSM_FOC_0_i_phase_uChan_InitHandle,
                              &PMSM_FOC_0_i_phase_vChan_InitHandle,
                              &PMSM_FOC_0_i_phase_wChan_InitHandle,
                              NULL,
                              &PMSM_FOC_0_v_dc_linkChan_InitHandle,
                              NULL,
                              NULL
                            },
  .channel_num_array      = {
                              (uint8_t)4,
                              (uint8_t)2,
                              (uint8_t)3,
                              (uint8_t)0xFF,
                              (uint8_t)6,
                              (uint8_t)0xFF,
                              (uint8_t)0xFF
                            },
  .result_num_array      = {
                              (uint8_t)12,
                              (uint8_t)11,
                              (uint8_t)10,
                              (uint8_t)0xFF,
                              (uint8_t)4,
                              (uint8_t)0xFF,
                              (uint8_t)0xFF
                            },
  .vadc_group_pointerarray= {
                              (XMC_VADC_GROUP_t*)(void*)VADC_G1,
                              (XMC_VADC_GROUP_t*)(void*)VADC_G1,
                              (XMC_VADC_GROUP_t*)(void*)VADC_G1,
                              NULL,
                              (XMC_VADC_GROUP_t*)(void*)VADC_G1,
                              NULL,
                              NULL
                            }
};

 /***************************Interrupts*********************************/
/* Fast Control Loop interrupt */
PMSM_FOC_ISRHandle_t PMSM_FOC_0_FCL_InterruptConfig =
{
#if(UC_SERIES == XMC14)
  .irqctrl = (XMC_SCU_IRQCTRL_t)0U,
#endif 
  .node_id      = (uint8_t)26, 
  .priority     = (uint8_t)2,
  .sub_priority = (uint8_t)0
};

/* Trap interrupt */
PMSM_FOC_ISRHandle_t PMSM_FOC_0_Trap_InterruptConfig =
{
#if(UC_SERIES == XMC14)
  .irqctrl = (XMC_SCU_IRQCTRL_t)0U,
#endif 
  .node_id      = (uint8_t)25, 
  .priority     = (uint8_t)1,
  .sub_priority = (uint8_t)0
};

 /***************************Scaling Details*********************************/

/* Scaling Value for Motor Control Parameters

* ActualValue         = Scale * TargetValue

* Speed Scale         = 0.5722133344283817
* Current Scale       = 0.0019569472
* Speed Kp, Ki Scale  = 4.8828125E-4
* Flux Kp, Ki Scale   = 4.8828125E-4
* Torque kp, Ki Scale = 4.8828125E-4
* PLL kp, Ki Scale    = 3.0517578125E-5
*/


PMSM_FOC_VF_t PMSM_FOC_0_Vf =
{
 .vf_constant        = 37U,
 .vf_offset          = 2837U,
 .vf_threshold_speed = 1048,
 .vf_time            = 1000U                /* 50 ms time */
};

PMSM_FOC_PI_Coefs_t PMSM_FOC_0_PI_Speed =
{
  .error           = 0,
  .Uk              = 0,
  .Ik              = 0,
  .Kp              = 32768U,
  .Ki              = 3U,
  .Scale_KpKi      = 11,
  .Ik_limit_min    = -30197145,
  .Ik_limit_max    = 30197145,
  .Uk_limit_min    = 16,
  .Uk_limit_max    = 32767,
  .Uk_limit_status = 0,
};

PMSM_FOC_PI_Coefs_t PMSM_FOC_0_PI_Torque =
{
  .error           = 0,
  .Uk              = 0,
  .Ik              = 0,
  .Kp              = 22527U,
  .Ki              = 1393U,
  .Scale_KpKi      = 11,
  .Ik_limit_min    = -67106816,
  .Ik_limit_max    = 67106816,
  .Uk_limit_min    = -32767,
  .Uk_limit_max    = 32767,
  .Uk_limit_status = 0,
};

PMSM_FOC_PI_Coefs_t PMSM_FOC_0_PI_Flux =
{
  .error           = 0,
  .Uk              = 0,
  .Ik              = 0,
  .Kp              = 22527U,
  .Ki              = 1393U,
  .Scale_KpKi      = 11,
  .Ik_limit_min    = -67106816,
  .Ik_limit_max    = 67106816,
  .Uk_limit_min    = -32767,
  .Uk_limit_max    = 32767,
  .Uk_limit_status = 0,
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
  .Uk_limit_min    = 262,
  .Uk_limit_max    = 9262,
};

PMSM_FOC_Output_t PMSM_FOC_0_Output;

PMSM_FOC_Input_t PMSM_FOC_0_Input =
{
  .Phase_L        = 22U,
  .Phase_R        = 18U,
  .Phase_L_Scale  = 17U,
  .CCU8_Period    = 1599U,
  .Res_Inc        = 2U,
  .LPF_N_BEMF     = 2U,
  .LPF_N_Speed    = 2U,
  .Threshold_LOW  = 16U,
  .Threshold_HIGH = 64U,
  .Flag_State     = 1U,
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
  .Ref_Iq         = 306,
  .Iq_PI_Flag     = 1U,
  .RotorAngleQ31  = 0,
  .RotorSpeed_In  = 0,
  .Flag_3or2_ADC  = 0U
};

/*******************************************FOC configuration structures ****************************************/

const PMSM_FOC_Config_t PMSM_FOC_0_Config=
{  
  .voltage_adc_scale           = 19772U,
  .pot_scale                   = 69918U,
  .speed_scale                 = 57263U,
  .inv_speed_scale             = 18749U,
  .current_scale               = 16743U,
  .inv_current_scale           = 64123U,
  .resistance_scale            = 12884U,   
  .inductance_scale            = 4762U, 
  .config_vf_rampup_rate       = 114U,
  .config_ramp_up_rate         = 3U,
  .config_ramp_down_rate       = 3U,
  .threshold_time_vp           = 90U,
  .current_amplifier_offset    = 8191U,
  .bootstrap_time              = 0U,
  .max_dclink_voltage          = 49150U,
  .min_dclink_voltage          = 16383U,
  .phase_current_measurement   = (uint8_t)PMSM_FOC_3PHASE,
  .speed_low_limit             = 873,
  .speed_openloop_max_limit    = 8738,
  .speed_openloop_min_limit    = 87,
  .pole_pair                   = 8U,
  .fcl_divider                 = 1U,
  .enable_speed_control        = 0U,
  .enable_biasvoltage          = 1U,
  .enable_voltage_compensation = 0U,
  .enable_pot_measurement      = 0U,
  .enable_vfstartup            = 0U,
  .enable_over_under_voltage   = 0U,
  .enable_vd_vq_decoupling     = 0U,
  .enable_direct_foc_startup   = 1U,
  .enable_transition           = 0U,
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
  .user_speed_set       = 3495,
  .speed_set_ptr        = &PMSM_FOC_0.user_speed_set,
  .bootstrap_index      = 0U,
  .bootstrap_count      = 0U,
  .motor_speed          = 0,
  .speed_set            = 17,
  .start_speed          = 17,
  .angle                = 0U,
  .amplitude            = 0U,
  .amplitude_max        = 1599U,
  .dclink_voltage       = 36U,
  .specified_volt       = 16383U,
  .threshold_adc_2shunt = 134U,
  .motor_direction      = PMSM_FOC_NEGATIVE_DIR,
  .feedback_type        = (uint8_t)PMSM_FOC_SENSORLESS,
  .state                = (uint8_t)PMSM_FOC_STATE_UNINITIALISED,
  .ph_v_group           = 2U,
  .ph_w_group           = 1U,
  .alignment_counter    = 0U,
  .alignment_time       = 1000U,
  .alignment_volt       = 2837U,
  .alignment_step       = 4U,
  .met_stable_time      = 5000U,                    /* 0.25 s time */
  .ramp_counter         = 0U,
  .vf_ramp_up_rate      = 114U,
  .ramp_up_rate         = 3U,
  .ramp_down_rate       = 3U,
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


