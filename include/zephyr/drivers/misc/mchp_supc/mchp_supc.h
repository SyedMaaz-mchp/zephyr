/*
 * Copyright (c) 2026 Microchip Technology Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @ingroup mchp_supc
 * @brief Microchip SUPC (Supply Controller) driver API header
 */

#ifndef ZEPHYR_DRIVERS_MISC_MCHP_SUPC_MCHP_SUPC_H_
#define ZEPHYR_DRIVERS_MISC_MCHP_SUPC_MCHP_SUPC_H_
#include <zephyr/device.h>

#if defined(CONFIG_SOC_FAMILY_MICROCHIP_PIC32CM_JH)
#include <zephyr/dt-bindings/misc/mchp_pic32cm_jh_supc.h>
#endif /* End of CONFIG_SOC_FAMILY_MICROCHIP_PIC32CM_JH */

#ifdef __cplusplus
extern "C" {
#endif

/** @brief callback function type for BOD Detection Event */
typedef void (* supc_bod_callback_t)(void *user_data);

/**
 * @brief Enable the SUPC reference voltage output for adc input channel.
 *
 * This function enables the internal reference voltage for adc input channel.
 *
 * @param dev Pointer to the SUPC device structure.
 *
 * @retval 0 If the reference voltage was enabled successfully.
 */
int supc_mchp_vref_enable(const struct device *dev);

/**
 * @brief Disable the SUPC reference voltage output for adc input channel.
 *
 * This function disables the internal reference voltage for adc input channel.
 *
 * @param dev Pointer to the SUPC device structure.
 *
 * @retval 0 If the reference voltage was disabled successfully.
 */
int supc_mchp_vref_disable(const struct device *dev);

/**
 * @brief Configure the SUPC reference voltage level.
 *
 * This function selects the reference voltage level for the SUPC VREF
 * peripheral.
 *
 * @param dev Pointer to the SUPC device structure.
 * @param val Reference voltage selection value. Checkout dt-bindings header
 *              for enum values
 *
 * @retval 0 If the reference voltage level was configured successfully.
 * @retval -ENOTSUP If the provided voltage selection value is invalid
 *                  or unsupported.
 */
int supc_mchp_vref_set_voltage(const struct device *dev, enum Vref_sel);

/**
 * @brief Get the SUPC reference voltage level.
 *
 * This function retrieves the currently configured reference voltage level
 * for the SUPC VREF peripheral.
 *
 * @param dev Pointer to the SUPC device structure.
 *
 * @return The reference voltage selection value.
 * @retval -ENOTSUP If the operation is not supported or voltage cannot be read.
 */
float supc_mchp_vref_get_voltage(const struct device *dev);

/**
 * @brief Register a callback for Brown-Out Detection (BOD) events.
 *
 * This function registers a user callback that will be invoked when a
 * brown-out detection event occurs.
 * 
 * Note: BOD Action should be configured to Interrupt mode 
 *       for event generation.
 *
 * @param dev Pointer to the SUPC device structure.
 * @param callback Pointer to the callback function.
 *
 * @retval 0 If the callback was registered successfully.
 * @retval -EINVAL If the callback pointer is invalid.
 */
int supc_mchp_bod_det_register(const struct device *dev, supc_bod_callback_t callback);

/**
 * @brief Unregister a callback for Brown-Out Detection (BOD) events.
 *
 * This function unregisters a previously registered BOD callback.
 *
 * @param dev Pointer to the SUPC device structure.
 *
 * @retval 0 If the callback was unregistered successfully.
 * @retval -EINVAL If no callback was previously registered.
 */
int supc_mchp_bod_det_deregister(const struct device *dev);

#ifdef __cplusplus
}
#endif

#endif /* ZEPHYR_DRIVERS_MISC_MCHP_SUPC_MCHP_SUPC_H_ */
