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

#include "bricklet_industrial_digital_out_4_v2.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_industrial_digital_out_4_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2 = (TF_IndustrialDigitalOut4V2 *) dev;
    (void)payload;

    switch(fid) {

        case TF_INDUSTRIAL_DIGITAL_OUT_4_V2_CALLBACK_MONOFLOP_DONE: {
            TF_IndustrialDigitalOut4V2MonoflopDoneHandler fn = industrial_digital_out_4_v2->monoflop_done_handler;
            void *user_data = industrial_digital_out_4_v2->monoflop_done_user_data;
            if (fn == NULL)
                return false;

            uint8_t channel = tf_packetbuffer_read_uint8_t(payload);
            bool value = tf_packetbuffer_read_bool(payload);
            tf_tfp_packet_processed(&industrial_digital_out_4_v2->tfp);
            TF_HalCommon *common = tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal);
            common->locked = true;
            fn(industrial_digital_out_4_v2, channel, value, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_industrial_digital_out_4_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_industrial_digital_out_4_v2_create(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, const char *uid, TF_HalContext *hal) {
    memset(industrial_digital_out_4_v2, 0, sizeof(TF_IndustrialDigitalOut4V2));

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

    rc = tf_tfp_init(&industrial_digital_out_4_v2->tfp, numeric_uid, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_industrial_digital_out_4_v2_callback_handler);
    if (rc != TF_E_OK) {
        return rc;
    }
    industrial_digital_out_4_v2->response_expected[0] = 0x00;
    industrial_digital_out_4_v2->response_expected[1] = 0x00;
    return TF_E_OK;
}

int tf_industrial_digital_out_4_v2_destroy(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2) {
    return tf_tfp_destroy(&industrial_digital_out_4_v2->tfp);
}

int tf_industrial_digital_out_4_v2_get_response_expected(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_VALUE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_digital_out_4_v2->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_SELECTED_VALUE:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_digital_out_4_v2->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_MONOFLOP:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_digital_out_4_v2->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_CHANNEL_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_digital_out_4_v2->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_PWM_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_digital_out_4_v2->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_digital_out_4_v2->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_digital_out_4_v2->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_digital_out_4_v2->response_expected[0] & (1 << 7)) != 0;
            break;
        case TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (industrial_digital_out_4_v2->response_expected[1] & (1 << 0)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_industrial_digital_out_4_v2_set_response_expected(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_VALUE:
            if (response_expected) {
                industrial_digital_out_4_v2->response_expected[0] |= (1 << 0);
            } else {
                industrial_digital_out_4_v2->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_SELECTED_VALUE:
            if (response_expected) {
                industrial_digital_out_4_v2->response_expected[0] |= (1 << 1);
            } else {
                industrial_digital_out_4_v2->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_MONOFLOP:
            if (response_expected) {
                industrial_digital_out_4_v2->response_expected[0] |= (1 << 2);
            } else {
                industrial_digital_out_4_v2->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_CHANNEL_LED_CONFIG:
            if (response_expected) {
                industrial_digital_out_4_v2->response_expected[0] |= (1 << 3);
            } else {
                industrial_digital_out_4_v2->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_PWM_CONFIGURATION:
            if (response_expected) {
                industrial_digital_out_4_v2->response_expected[0] |= (1 << 4);
            } else {
                industrial_digital_out_4_v2->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                industrial_digital_out_4_v2->response_expected[0] |= (1 << 5);
            } else {
                industrial_digital_out_4_v2->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                industrial_digital_out_4_v2->response_expected[0] |= (1 << 6);
            } else {
                industrial_digital_out_4_v2->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_RESET:
            if (response_expected) {
                industrial_digital_out_4_v2->response_expected[0] |= (1 << 7);
            } else {
                industrial_digital_out_4_v2->response_expected[0] &= ~(1 << 7);
            }
            break;
        case TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_WRITE_UID:
            if (response_expected) {
                industrial_digital_out_4_v2->response_expected[1] |= (1 << 0);
            } else {
                industrial_digital_out_4_v2->response_expected[1] &= ~(1 << 0);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_industrial_digital_out_4_v2_set_response_expected_all(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, bool response_expected) {
    memset(industrial_digital_out_4_v2->response_expected, response_expected ? 0xFF : 0, 2);
}

int tf_industrial_digital_out_4_v2_set_value(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, bool value[4]) {
    if(tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_digital_out_4_v2_get_response_expected(industrial_digital_out_4_v2, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_VALUE, &response_expected);
    tf_tfp_prepare_send(&industrial_digital_out_4_v2->tfp, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_VALUE, 1, 0, response_expected);

    size_t i;
    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_digital_out_4_v2->tfp);

    memset(buf + 0, 0, 1); for (i = 0; i < 4; ++i) buf[0 + (i / 8)] |= (value[i] ? 1 : 0) << (i % 8);

    uint32_t deadline = tf_hal_current_time_us(industrial_digital_out_4_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_digital_out_4_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&industrial_digital_out_4_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_digital_out_4_v2_get_value(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, bool ret_value[4]) {
    if(tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_digital_out_4_v2->tfp, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_GET_VALUE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_digital_out_4_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_digital_out_4_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_value != NULL) { tf_packetbuffer_read_bool_array(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf, ret_value, 4);} else { tf_packetbuffer_remove(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&industrial_digital_out_4_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_digital_out_4_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_digital_out_4_v2_set_selected_value(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t channel, bool value) {
    if(tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_digital_out_4_v2_get_response_expected(industrial_digital_out_4_v2, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_SELECTED_VALUE, &response_expected);
    tf_tfp_prepare_send(&industrial_digital_out_4_v2->tfp, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_SELECTED_VALUE, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_digital_out_4_v2->tfp);

    buf[0] = (uint8_t)channel;
    buf[1] = value ? 1 : 0;

    uint32_t deadline = tf_hal_current_time_us(industrial_digital_out_4_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_digital_out_4_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&industrial_digital_out_4_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_digital_out_4_v2_set_monoflop(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t channel, bool value, uint32_t time) {
    if(tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_digital_out_4_v2_get_response_expected(industrial_digital_out_4_v2, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_MONOFLOP, &response_expected);
    tf_tfp_prepare_send(&industrial_digital_out_4_v2->tfp, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_MONOFLOP, 6, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_digital_out_4_v2->tfp);

    buf[0] = (uint8_t)channel;
    buf[1] = value ? 1 : 0;
    time = tf_leconvert_uint32_to(time); memcpy(buf + 2, &time, 4);

    uint32_t deadline = tf_hal_current_time_us(industrial_digital_out_4_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_digital_out_4_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&industrial_digital_out_4_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_digital_out_4_v2_get_monoflop(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t channel, bool *ret_value, uint32_t *ret_time, uint32_t *ret_time_remaining) {
    if(tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_digital_out_4_v2->tfp, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_GET_MONOFLOP, 1, 9, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_digital_out_4_v2->tfp);

    buf[0] = (uint8_t)channel;

    uint32_t deadline = tf_hal_current_time_us(industrial_digital_out_4_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_digital_out_4_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_value != NULL) { *ret_value = tf_packetbuffer_read_bool(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf, 1); }
        if (ret_time != NULL) { *ret_time = tf_packetbuffer_read_uint32_t(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf, 4); }
        if (ret_time_remaining != NULL) { *ret_time_remaining = tf_packetbuffer_read_uint32_t(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf, 4); }
        tf_tfp_packet_processed(&industrial_digital_out_4_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_digital_out_4_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_digital_out_4_v2_set_channel_led_config(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t channel, uint8_t config) {
    if(tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_digital_out_4_v2_get_response_expected(industrial_digital_out_4_v2, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_CHANNEL_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(&industrial_digital_out_4_v2->tfp, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_CHANNEL_LED_CONFIG, 2, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_digital_out_4_v2->tfp);

    buf[0] = (uint8_t)channel;
    buf[1] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(industrial_digital_out_4_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_digital_out_4_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&industrial_digital_out_4_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_digital_out_4_v2_get_channel_led_config(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t channel, uint8_t *ret_config) {
    if(tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_digital_out_4_v2->tfp, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_GET_CHANNEL_LED_CONFIG, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_digital_out_4_v2->tfp);

    buf[0] = (uint8_t)channel;

    uint32_t deadline = tf_hal_current_time_us(industrial_digital_out_4_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_digital_out_4_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&industrial_digital_out_4_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_digital_out_4_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_digital_out_4_v2_set_pwm_configuration(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t channel, uint32_t frequency, uint16_t duty_cycle) {
    if(tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_digital_out_4_v2_get_response_expected(industrial_digital_out_4_v2, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_PWM_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(&industrial_digital_out_4_v2->tfp, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_PWM_CONFIGURATION, 7, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_digital_out_4_v2->tfp);

    buf[0] = (uint8_t)channel;
    frequency = tf_leconvert_uint32_to(frequency); memcpy(buf + 1, &frequency, 4);
    duty_cycle = tf_leconvert_uint16_to(duty_cycle); memcpy(buf + 5, &duty_cycle, 2);

    uint32_t deadline = tf_hal_current_time_us(industrial_digital_out_4_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_digital_out_4_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&industrial_digital_out_4_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_digital_out_4_v2_get_pwm_configuration(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t channel, uint32_t *ret_frequency, uint16_t *ret_duty_cycle) {
    if(tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_digital_out_4_v2->tfp, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_GET_PWM_CONFIGURATION, 1, 6, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_digital_out_4_v2->tfp);

    buf[0] = (uint8_t)channel;

    uint32_t deadline = tf_hal_current_time_us(industrial_digital_out_4_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_digital_out_4_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_frequency != NULL) { *ret_frequency = tf_packetbuffer_read_uint32_t(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf, 4); }
        if (ret_duty_cycle != NULL) { *ret_duty_cycle = tf_packetbuffer_read_uint16_t(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf, 2); }
        tf_tfp_packet_processed(&industrial_digital_out_4_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_digital_out_4_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_digital_out_4_v2_get_spitfp_error_count(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_digital_out_4_v2->tfp, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_digital_out_4_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_digital_out_4_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf, 4); }
        tf_tfp_packet_processed(&industrial_digital_out_4_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_digital_out_4_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_digital_out_4_v2_set_bootloader_mode(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_digital_out_4_v2->tfp, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_digital_out_4_v2->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(industrial_digital_out_4_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_digital_out_4_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&industrial_digital_out_4_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_digital_out_4_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_digital_out_4_v2_get_bootloader_mode(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t *ret_mode) {
    if(tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_digital_out_4_v2->tfp, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_digital_out_4_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_digital_out_4_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&industrial_digital_out_4_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_digital_out_4_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_digital_out_4_v2_set_write_firmware_pointer(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint32_t pointer) {
    if(tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_digital_out_4_v2_get_response_expected(industrial_digital_out_4_v2, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(&industrial_digital_out_4_v2->tfp, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_digital_out_4_v2->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(industrial_digital_out_4_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_digital_out_4_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&industrial_digital_out_4_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_digital_out_4_v2_write_firmware(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_digital_out_4_v2->tfp, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_digital_out_4_v2->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(industrial_digital_out_4_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_digital_out_4_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&industrial_digital_out_4_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_digital_out_4_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_digital_out_4_v2_set_status_led_config(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t config) {
    if(tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_digital_out_4_v2_get_response_expected(industrial_digital_out_4_v2, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(&industrial_digital_out_4_v2->tfp, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_digital_out_4_v2->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(industrial_digital_out_4_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_digital_out_4_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&industrial_digital_out_4_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_digital_out_4_v2_get_status_led_config(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint8_t *ret_config) {
    if(tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_digital_out_4_v2->tfp, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_digital_out_4_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_digital_out_4_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&industrial_digital_out_4_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_digital_out_4_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_digital_out_4_v2_get_chip_temperature(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, int16_t *ret_temperature) {
    if(tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_digital_out_4_v2->tfp, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_digital_out_4_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_digital_out_4_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf, 2); }
        tf_tfp_packet_processed(&industrial_digital_out_4_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_digital_out_4_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_digital_out_4_v2_reset(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2) {
    if(tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_digital_out_4_v2_get_response_expected(industrial_digital_out_4_v2, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(&industrial_digital_out_4_v2->tfp, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_digital_out_4_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_digital_out_4_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&industrial_digital_out_4_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_digital_out_4_v2_write_uid(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint32_t uid) {
    if(tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_industrial_digital_out_4_v2_get_response_expected(industrial_digital_out_4_v2, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(&industrial_digital_out_4_v2->tfp, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&industrial_digital_out_4_v2->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(industrial_digital_out_4_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_digital_out_4_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&industrial_digital_out_4_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_digital_out_4_v2_read_uid(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint32_t *ret_uid) {
    if(tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_digital_out_4_v2->tfp, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(industrial_digital_out_4_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_digital_out_4_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf, 4); }
        tf_tfp_packet_processed(&industrial_digital_out_4_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_digital_out_4_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_industrial_digital_out_4_v2_get_identity(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&industrial_digital_out_4_v2->tfp, TF_INDUSTRIAL_DIGITAL_OUT_4_V2_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(industrial_digital_out_4_v2->tfp.spitfp.hal) + tf_hal_get_common(industrial_digital_out_4_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&industrial_digital_out_4_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf, 8); }
        *tmp_connected_uid = tf_packetbuffer_read_char(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf);} else { tf_packetbuffer_remove(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf);} else { tf_packetbuffer_remove(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&industrial_digital_out_4_v2->tfp.spitfp.recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(industrial_digital_out_4_v2->tfp.spitfp.hal, industrial_digital_out_4_v2->tfp.spitfp.port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(&industrial_digital_out_4_v2->tfp);
    }

    result = tf_tfp_finish_send(&industrial_digital_out_4_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_industrial_digital_out_4_v2_register_monoflop_done_callback(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, TF_IndustrialDigitalOut4V2MonoflopDoneHandler handler, void *user_data) {
    if (handler == NULL) {
        industrial_digital_out_4_v2->tfp.needs_callback_tick = false;
        
    } else {
        industrial_digital_out_4_v2->tfp.needs_callback_tick = true;
    }
    industrial_digital_out_4_v2->monoflop_done_handler = handler;
    industrial_digital_out_4_v2->monoflop_done_user_data = user_data;
}
#endif
int tf_industrial_digital_out_4_v2_callback_tick(TF_IndustrialDigitalOut4V2 *industrial_digital_out_4_v2, uint32_t timeout_us) {
    return tf_tfp_callback_tick(&industrial_digital_out_4_v2->tfp, tf_hal_current_time_us(industrial_digital_out_4_v2->tfp.spitfp.hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
