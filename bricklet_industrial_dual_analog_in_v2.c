/* ***********************************************************
 * This file was automatically generated on 2020-09-10.      *
 *                                                           *
 * C/C++ for Microcontrollers Bindings Version 2.0.0         *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


//#define IPCON_EXPOSE_INTERNALS

#include "bricklet_industrial_dual_analog_in_v2.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_industrial_dual_analog_in_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2 = (TF_IndustrialDualAnalogInV2 *) dev;
    (void)payload;

    switch(fid) {

        case TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_CALLBACK_VOLTAGE: {
            TF_IndustrialDualAnalogInV2VoltageHandler fn = industrial_dual_analog_in_v2->voltage_handler;
            void *user_data = industrial_dual_analog_in_v2->voltage_user_data;
            if (fn == NULL)
                return false;

            uint8_t channel = tf_packetbuffer_read_uint8_t(payload);
            int32_t voltage = tf_packetbuffer_read_int32_t(payload);
            tf_tfp_packet_processed(&industrial_dual_analog_in_v2->tfp);
            TF_HalCommon *common = tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal);
            common->locked = true;
            fn(industrial_dual_analog_in_v2, channel, voltage, user_data);
            common->locked = false;
            break;
        }

        case TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_CALLBACK_ALL_VOLTAGES: {
            TF_IndustrialDualAnalogInV2AllVoltagesHandler fn = industrial_dual_analog_in_v2->all_voltages_handler;
            void *user_data = industrial_dual_analog_in_v2->all_voltages_user_data;
            if (fn == NULL)
                return false;
            size_t i;
            int32_t voltages[2]; for (i = 0; i < 2; ++i) voltages[i] = tf_packetbuffer_read_int32_t(payload);
            tf_tfp_packet_processed(&industrial_dual_analog_in_v2->tfp);
            TF_HalCommon *common = tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal);
            common->locked = true;
            fn(industrial_dual_analog_in_v2, voltages, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_industrial_dual_analog_in_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_industrial_dual_analog_in_v2_create(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, const char *uid, TF_HalContext *hal) {
    memset(industrial_dual_analog_in_v2, 0, sizeof(TF_IndustrialDualAnalogInV2));

    uint32_t numeric_uid;
    int rc = tf_base58_decode(uid, &numeric_uid);
    if (rc != TF_E_OK) {
        return rc;
    }

    uint8_t port_id;
    int inventory_index;
    rc = tf_hal_get_port_id(hal, numeric_uid, &port_id, &inventory_index);
    if (rc < 0) {
        return rc;
    }

    rc = tf_tfp_init(&industrial_dual_analog_in_v2->tfp, numeric_uid, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_industrial_dual_analog_in_v2_callback_handler);
    if (rc != TF_E_OK) {
        return rc;
    }
    industrial_dual_analog_in_v2->response_expected[0] = 0x21;
    industrial_dual_analog_in_v2->response_expected[1] = 0x00;
    return TF_E_OK;
}

int tf_industrial_dual_analog_in_v2_destroy(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2) {
    return tf_tfp_destroy(&industrial_dual_analog_in_v2->tfp);
}

int tf_industrial_dual_analog_in_v2_get_response_expected(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_VOLTAGE_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_dual_analog_in_v2->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_SAMPLE_RATE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_dual_analog_in_v2->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_CALIBRATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_dual_analog_in_v2->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_CHANNEL_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_dual_analog_in_v2->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_CHANNEL_LED_STATUS_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_dual_analog_in_v2->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_ALL_VOLTAGES_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_dual_analog_in_v2->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_dual_analog_in_v2->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_dual_analog_in_v2->response_expected[0] & (1 << 7)) != 0;
            break;
        case TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_dual_analog_in_v2->response_expected[1] & (1 << 0)) != 0;
            break;
        case TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_dual_analog_in_v2->response_expected[1] & (1 << 1)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_industrial_dual_analog_in_v2_set_response_expected(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_VOLTAGE_CALLBACK_CONFIGURATION:
            if (response_expected) {
                industrial_dual_analog_in_v2->response_expected[0] |= (1 << 0);
            } else {
                industrial_dual_analog_in_v2->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_SAMPLE_RATE:
            if (response_expected) {
                industrial_dual_analog_in_v2->response_expected[0] |= (1 << 1);
            } else {
                industrial_dual_analog_in_v2->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_CALIBRATION:
            if (response_expected) {
                industrial_dual_analog_in_v2->response_expected[0] |= (1 << 2);
            } else {
                industrial_dual_analog_in_v2->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_CHANNEL_LED_CONFIG:
            if (response_expected) {
                industrial_dual_analog_in_v2->response_expected[0] |= (1 << 3);
            } else {
                industrial_dual_analog_in_v2->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_CHANNEL_LED_STATUS_CONFIG:
            if (response_expected) {
                industrial_dual_analog_in_v2->response_expected[0] |= (1 << 4);
            } else {
                industrial_dual_analog_in_v2->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_ALL_VOLTAGES_CALLBACK_CONFIGURATION:
            if (response_expected) {
                industrial_dual_analog_in_v2->response_expected[0] |= (1 << 5);
            } else {
                industrial_dual_analog_in_v2->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                industrial_dual_analog_in_v2->response_expected[0] |= (1 << 6);
            } else {
                industrial_dual_analog_in_v2->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                industrial_dual_analog_in_v2->response_expected[0] |= (1 << 7);
            } else {
                industrial_dual_analog_in_v2->response_expected[0] &= ~(1 << 7);
            }
            break;
        case TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_RESET:
            if (response_expected) {
                industrial_dual_analog_in_v2->response_expected[1] |= (1 << 0);
            } else {
                industrial_dual_analog_in_v2->response_expected[1] &= ~(1 << 0);
            }
            break;
        case TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_WRITE_UID:
            if (response_expected) {
                industrial_dual_analog_in_v2->response_expected[1] |= (1 << 1);
            } else {
                industrial_dual_analog_in_v2->response_expected[1] &= ~(1 << 1);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_industrial_dual_analog_in_v2_set_response_expected_all(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, bool response_expected) {
    memset(industrial_dual_analog_in_v2->response_expected, response_expected ? 0xFF : 0, 2);
}

int tf_industrial_dual_analog_in_v2_get_voltage(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t channel, int32_t *ret_voltage) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_VOLTAGE, 1, 4, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_dual_analog_in_v2->tfp);

    buf[0] = (uint8_t)channel;

    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_voltage != NULL) { *ret_voltage = tf_packetbuffer_read_int32_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 4); }
        tf_tfp_packet_processed(&industrial_dual_analog_in_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_set_voltage_callback_configuration(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t channel, uint32_t period, bool value_has_to_change, char option, int32_t min, int32_t max) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_dual_analog_in_v2_get_response_expected(industrial_dual_analog_in_v2, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_VOLTAGE_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_VOLTAGE_CALLBACK_CONFIGURATION, 15, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_dual_analog_in_v2->tfp);

    buf[0] = (uint8_t)channel;
    period = tf_leconvert_uint32_to(period); memcpy(buf + 1, &period, 4);
    buf[5] = value_has_to_change ? 1 : 0;
    buf[6] = (uint8_t)option;
    min = tf_leconvert_int32_to(min); memcpy(buf + 7, &min, 4);
    max = tf_leconvert_int32_to(max); memcpy(buf + 11, &max, 4);

    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_get_voltage_callback_configuration(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t channel, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, int32_t *ret_min, int32_t *ret_max) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_VOLTAGE_CALLBACK_CONFIGURATION, 1, 14, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_dual_analog_in_v2->tfp);

    buf[0] = (uint8_t)channel;

    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 1); }
        if (ret_option != NULL) { *ret_option = tf_packetbuffer_read_char(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 1); }
        if (ret_min != NULL) { *ret_min = tf_packetbuffer_read_int32_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 4); }
        if (ret_max != NULL) { *ret_max = tf_packetbuffer_read_int32_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 4); }
        tf_tfp_packet_processed(&industrial_dual_analog_in_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_set_sample_rate(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t rate) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_dual_analog_in_v2_get_response_expected(industrial_dual_analog_in_v2, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_SAMPLE_RATE, &response_expected);
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_SAMPLE_RATE, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_dual_analog_in_v2->tfp);

    buf[0] = (uint8_t)rate;

    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_get_sample_rate(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t *ret_rate) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_SAMPLE_RATE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_rate != NULL) { *ret_rate = tf_packetbuffer_read_uint8_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&industrial_dual_analog_in_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_set_calibration(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, int32_t offset[2], int32_t gain[2]) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_dual_analog_in_v2_get_response_expected(industrial_dual_analog_in_v2, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_CALIBRATION, &response_expected);
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_CALIBRATION, 16, 0, response_expected);

    size_t i;
    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_dual_analog_in_v2->tfp);

    for (i = 0; i < 2; i++) { int32_t tmp_offset = tf_leconvert_int32_to(offset[i]); memcpy(buf + 0 + (i * sizeof(int32_t)), &tmp_offset, sizeof(int32_t)); }
    for (i = 0; i < 2; i++) { int32_t tmp_gain = tf_leconvert_int32_to(gain[i]); memcpy(buf + 8 + (i * sizeof(int32_t)), &tmp_gain, sizeof(int32_t)); }

    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_get_calibration(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, int32_t ret_offset[2], int32_t ret_gain[2]) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_CALIBRATION, 0, 16, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_offset != NULL) { for (i = 0; i < 2; ++i) ret_offset[i] = tf_packetbuffer_read_int32_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf);} else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 8); }
        if (ret_gain != NULL) { for (i = 0; i < 2; ++i) ret_gain[i] = tf_packetbuffer_read_int32_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf);} else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 8); }
        tf_tfp_packet_processed(&industrial_dual_analog_in_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_get_adc_values(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, int32_t ret_value[2]) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_ADC_VALUES, 0, 8, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_value != NULL) { for (i = 0; i < 2; ++i) ret_value[i] = tf_packetbuffer_read_int32_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf);} else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 8); }
        tf_tfp_packet_processed(&industrial_dual_analog_in_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_set_channel_led_config(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t channel, uint8_t config) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_dual_analog_in_v2_get_response_expected(industrial_dual_analog_in_v2, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_CHANNEL_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_CHANNEL_LED_CONFIG, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_dual_analog_in_v2->tfp);

    buf[0] = (uint8_t)channel;
    buf[1] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_get_channel_led_config(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t channel, uint8_t *ret_config) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_CHANNEL_LED_CONFIG, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_dual_analog_in_v2->tfp);

    buf[0] = (uint8_t)channel;

    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&industrial_dual_analog_in_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_set_channel_led_status_config(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t channel, int32_t min, int32_t max, uint8_t config) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_dual_analog_in_v2_get_response_expected(industrial_dual_analog_in_v2, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_CHANNEL_LED_STATUS_CONFIG, &response_expected);
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_CHANNEL_LED_STATUS_CONFIG, 10, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_dual_analog_in_v2->tfp);

    buf[0] = (uint8_t)channel;
    min = tf_leconvert_int32_to(min); memcpy(buf + 1, &min, 4);
    max = tf_leconvert_int32_to(max); memcpy(buf + 5, &max, 4);
    buf[9] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_get_channel_led_status_config(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t channel, int32_t *ret_min, int32_t *ret_max, uint8_t *ret_config) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_CHANNEL_LED_STATUS_CONFIG, 1, 9, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_dual_analog_in_v2->tfp);

    buf[0] = (uint8_t)channel;

    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_min != NULL) { *ret_min = tf_packetbuffer_read_int32_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 4); }
        if (ret_max != NULL) { *ret_max = tf_packetbuffer_read_int32_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 4); }
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&industrial_dual_analog_in_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_get_all_voltages(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, int32_t ret_voltages[2]) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_ALL_VOLTAGES, 0, 8, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_voltages != NULL) { for (i = 0; i < 2; ++i) ret_voltages[i] = tf_packetbuffer_read_int32_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf);} else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 8); }
        tf_tfp_packet_processed(&industrial_dual_analog_in_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_set_all_voltages_callback_configuration(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint32_t period, bool value_has_to_change) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_dual_analog_in_v2_get_response_expected(industrial_dual_analog_in_v2, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_ALL_VOLTAGES_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_ALL_VOLTAGES_CALLBACK_CONFIGURATION, 5, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_dual_analog_in_v2->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);
    buf[4] = value_has_to_change ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_get_all_voltages_callback_configuration(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint32_t *ret_period, bool *ret_value_has_to_change) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_ALL_VOLTAGES_CALLBACK_CONFIGURATION, 0, 5, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 4); }
        if (ret_value_has_to_change != NULL) { *ret_value_has_to_change = tf_packetbuffer_read_bool(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&industrial_dual_analog_in_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_get_spitfp_error_count(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 4); }
        tf_tfp_packet_processed(&industrial_dual_analog_in_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_set_bootloader_mode(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_dual_analog_in_v2->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&industrial_dual_analog_in_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_get_bootloader_mode(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t *ret_mode) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&industrial_dual_analog_in_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_set_write_firmware_pointer(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint32_t pointer) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_dual_analog_in_v2_get_response_expected(industrial_dual_analog_in_v2, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_dual_analog_in_v2->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_write_firmware(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_dual_analog_in_v2->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&industrial_dual_analog_in_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_set_status_led_config(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t config) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_dual_analog_in_v2_get_response_expected(industrial_dual_analog_in_v2, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_dual_analog_in_v2->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_get_status_led_config(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint8_t *ret_config) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&industrial_dual_analog_in_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_get_chip_temperature(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, int16_t *ret_temperature) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 2); }
        tf_tfp_packet_processed(&industrial_dual_analog_in_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_reset(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_dual_analog_in_v2_get_response_expected(industrial_dual_analog_in_v2, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_write_uid(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint32_t uid) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_dual_analog_in_v2_get_response_expected(industrial_dual_analog_in_v2, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_dual_analog_in_v2->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_read_uid(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint32_t *ret_uid) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 4); }
        tf_tfp_packet_processed(&industrial_dual_analog_in_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_dual_analog_in_v2_get_identity(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_dual_analog_in_v2->tfp, TF_INDUSTRIAL_DUAL_ANALOG_IN_V2_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_dual_analog_in_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_dual_analog_in_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 8); }
        *tmp_connected_uid = tf_packetbuffer_read_char(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf);} else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf);} else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_dual_analog_in_v2->tfp.spitfp.recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(industrial_dual_analog_in_v2->tfp.spitfp.hal, industrial_dual_analog_in_v2->tfp.spitfp.port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(&industrial_dual_analog_in_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_dual_analog_in_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_industrial_dual_analog_in_v2_register_voltage_callback(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, TF_IndustrialDualAnalogInV2VoltageHandler handler, void *user_data) {
    if (handler == NULL) {
        industrial_dual_analog_in_v2->tfp.needs_callback_tick = false;
        industrial_dual_analog_in_v2->tfp.needs_callback_tick |= industrial_dual_analog_in_v2->all_voltages_handler != NULL;
    } else {
        industrial_dual_analog_in_v2->tfp.needs_callback_tick = true;
    }
    industrial_dual_analog_in_v2->voltage_handler = handler;
    industrial_dual_analog_in_v2->voltage_user_data = user_data;
}


void tf_industrial_dual_analog_in_v2_register_all_voltages_callback(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, TF_IndustrialDualAnalogInV2AllVoltagesHandler handler, void *user_data) {
    if (handler == NULL) {
        industrial_dual_analog_in_v2->tfp.needs_callback_tick = false;
        industrial_dual_analog_in_v2->tfp.needs_callback_tick |= industrial_dual_analog_in_v2->voltage_handler != NULL;
    } else {
        industrial_dual_analog_in_v2->tfp.needs_callback_tick = true;
    }
    industrial_dual_analog_in_v2->all_voltages_handler = handler;
    industrial_dual_analog_in_v2->all_voltages_user_data = user_data;
}
#endif
int tf_industrial_dual_analog_in_v2_callback_tick(TF_IndustrialDualAnalogInV2 *industrial_dual_analog_in_v2, uint32_t timeout_us) {
    return tf_tfp_callback_tick(&industrial_dual_analog_in_v2->tfp, tf_hal_current_time_us(industrial_dual_analog_in_v2->tfp.spitfp.hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
