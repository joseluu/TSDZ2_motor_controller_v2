/**
 * @file uart_config.c
 * @date 2017-11-10
 *
 * NOTE:
 * This file is generated by DAVE-4. Any manual modification done to this file will be lost when the code is
 * regenerated.
 *
 * @cond
 ***********************************************************************************************************************
 * UART_CONFIG v4.0.10 - Configures a USIC channel to perform transmit & receive operations using UART protocol.
 *
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
 * 2015-07-09:
 *     - Initial version for DAVEv4
 *
 * 2017-11-10:
 *     - Renamed UART_CONFIG_t to UART_CH_CONFIG_t to avoid clash when using simultaneously UART and UART_CONFIG APP.
 *
 * @endcond
 */

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/
#include "uart_config.h"

/**********************************************************************************************************************
 * API IMPLEMENTATION
 **********************************************************************************************************************/

/**
 * @brief Get the UART_CONFIG APP version.
 * @return DAVE_APP_VERSION_t APP version information (major, minor and patch number)
 *
 */
DAVE_APP_VERSION_t UART_CONFIG_GetAppVersion()
{
  DAVE_APP_VERSION_t version;

  version.major = UART_CONFIG_MAJOR_VERSION;
  version.minor = UART_CONFIG_MINOR_VERSION;
  version.patch = UART_CONFIG_PATCH_VERSION;

  return version;
}

/**
 * @brief Function to initialize the UART module as per the configuration made
 * in GUI.
 * @param handle Pointer to static content of APP configuration.
 * @return UART_CONFIG_STATUS_t: Status of UART driver initialization.\n
 * @ref UART_CONFIG_STATUS_SUCCESS - on successful initialization.\n
 * @ref UART_CONFIG_STATUS_FAILURE - if initialization fails.\n
 */
UART_CONFIG_STATUS_t UART_CONFIG_Init(const UART_CH_CONFIG_t *const handle)
{
  UART_CONFIG_STATUS_t status;
  XMC_ASSERT("UART_CONFIG APP handle function pointer uninitialized", (((handle != NULL) &&
      (handle->config != NULL)) && ((handle->config->uart_config_init != NULL))));

  /* Initialize the multiplexers required for UART configuration */
  handle->config->uart_config_init();
  status = UART_CONFIG_STATUS_SUCCESS;

  return status;
}











