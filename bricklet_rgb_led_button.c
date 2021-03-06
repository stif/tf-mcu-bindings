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

#include "bricklet_rgb_led_button.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_rgb_led_button_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_RGBLEDButton *rgb_led_button = (TF_RGBLEDButton *) dev;
    (void)payload;

    switch(fid) {

        case TF_RGB_LED_BUTTON_CALLBACK_BUTTON_STATE_CHANGED: {
            TF_RGBLEDButtonButtonStateChangedHandler fn = rgb_led_button->button_state_changed_handler;
            void *user_data = rgb_led_button->button_state_changed_user_data;
            if (fn == NULL)
                return false;

            uint8_t state = tf_packetbuffer_read_uint8_t(payload);
            tf_tfp_packet_processed(&rgb_led_button->tfp);
            TF_HalCommon *common = tf_hal_get_common(rgb_led_button->tfp.spitfp.hal);
            common->locked = true;
            fn(rgb_led_button, state, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_rgb_led_button_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_rgb_led_button_create(TF_RGBLEDButton *rgb_led_button, const char *uid, TF_HalContext *hal) {
    memset(rgb_led_button, 0, sizeof(TF_RGBLEDButton));

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

    rc = tf_tfp_init(&rgb_led_button->tfp, numeric_uid, TF_RGB_LED_BUTTON_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_rgb_led_button_callback_handler);
    if (rc != TF_E_OK) {
        return rc;
    }
    rgb_led_button->response_expected[0] = 0x00;
    return TF_E_OK;
}

int tf_rgb_led_button_destroy(TF_RGBLEDButton *rgb_led_button) {
    return tf_tfp_destroy(&rgb_led_button->tfp);
}

int tf_rgb_led_button_get_response_expected(TF_RGBLEDButton *rgb_led_button, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_RGB_LED_BUTTON_FUNCTION_SET_COLOR:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rgb_led_button->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_RGB_LED_BUTTON_FUNCTION_SET_COLOR_CALIBRATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rgb_led_button->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_RGB_LED_BUTTON_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rgb_led_button->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_RGB_LED_BUTTON_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rgb_led_button->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_RGB_LED_BUTTON_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rgb_led_button->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_RGB_LED_BUTTON_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (rgb_led_button->response_expected[0] & (1 << 5)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_rgb_led_button_set_response_expected(TF_RGBLEDButton *rgb_led_button, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_RGB_LED_BUTTON_FUNCTION_SET_COLOR:
            if (response_expected) {
                rgb_led_button->response_expected[0] |= (1 << 0);
            } else {
                rgb_led_button->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_RGB_LED_BUTTON_FUNCTION_SET_COLOR_CALIBRATION:
            if (response_expected) {
                rgb_led_button->response_expected[0] |= (1 << 1);
            } else {
                rgb_led_button->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_RGB_LED_BUTTON_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                rgb_led_button->response_expected[0] |= (1 << 2);
            } else {
                rgb_led_button->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_RGB_LED_BUTTON_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                rgb_led_button->response_expected[0] |= (1 << 3);
            } else {
                rgb_led_button->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_RGB_LED_BUTTON_FUNCTION_RESET:
            if (response_expected) {
                rgb_led_button->response_expected[0] |= (1 << 4);
            } else {
                rgb_led_button->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_RGB_LED_BUTTON_FUNCTION_WRITE_UID:
            if (response_expected) {
                rgb_led_button->response_expected[0] |= (1 << 5);
            } else {
                rgb_led_button->response_expected[0] &= ~(1 << 5);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_rgb_led_button_set_response_expected_all(TF_RGBLEDButton *rgb_led_button, bool response_expected) {
    memset(rgb_led_button->response_expected, response_expected ? 0xFF : 0, 1);
}

int tf_rgb_led_button_set_color(TF_RGBLEDButton *rgb_led_button, uint8_t red, uint8_t green, uint8_t blue) {
    if(tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rgb_led_button_get_response_expected(rgb_led_button, TF_RGB_LED_BUTTON_FUNCTION_SET_COLOR, &response_expected);
    tf_tfp_prepare_send(&rgb_led_button->tfp, TF_RGB_LED_BUTTON_FUNCTION_SET_COLOR, 3, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&rgb_led_button->tfp);

    buf[0] = (uint8_t)red;
    buf[1] = (uint8_t)green;
    buf[2] = (uint8_t)blue;

    uint32_t deadline = tf_hal_current_time_us(rgb_led_button->tfp.spitfp.hal) + tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&rgb_led_button->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&rgb_led_button->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_button_get_color(TF_RGBLEDButton *rgb_led_button, uint8_t *ret_red, uint8_t *ret_green, uint8_t *ret_blue) {
    if(tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&rgb_led_button->tfp, TF_RGB_LED_BUTTON_FUNCTION_GET_COLOR, 0, 3, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_button->tfp.spitfp.hal) + tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&rgb_led_button->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_red != NULL) { *ret_red = tf_packetbuffer_read_uint8_t(&rgb_led_button->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&rgb_led_button->tfp.spitfp.recv_buf, 1); }
        if (ret_green != NULL) { *ret_green = tf_packetbuffer_read_uint8_t(&rgb_led_button->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&rgb_led_button->tfp.spitfp.recv_buf, 1); }
        if (ret_blue != NULL) { *ret_blue = tf_packetbuffer_read_uint8_t(&rgb_led_button->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&rgb_led_button->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&rgb_led_button->tfp);
    }

    result = tf_tfp_finish_send(&rgb_led_button->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_button_get_button_state(TF_RGBLEDButton *rgb_led_button, uint8_t *ret_state) {
    if(tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&rgb_led_button->tfp, TF_RGB_LED_BUTTON_FUNCTION_GET_BUTTON_STATE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_button->tfp.spitfp.hal) + tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&rgb_led_button->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_state != NULL) { *ret_state = tf_packetbuffer_read_uint8_t(&rgb_led_button->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&rgb_led_button->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&rgb_led_button->tfp);
    }

    result = tf_tfp_finish_send(&rgb_led_button->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_button_set_color_calibration(TF_RGBLEDButton *rgb_led_button, uint8_t red, uint8_t green, uint8_t blue) {
    if(tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rgb_led_button_get_response_expected(rgb_led_button, TF_RGB_LED_BUTTON_FUNCTION_SET_COLOR_CALIBRATION, &response_expected);
    tf_tfp_prepare_send(&rgb_led_button->tfp, TF_RGB_LED_BUTTON_FUNCTION_SET_COLOR_CALIBRATION, 3, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&rgb_led_button->tfp);

    buf[0] = (uint8_t)red;
    buf[1] = (uint8_t)green;
    buf[2] = (uint8_t)blue;

    uint32_t deadline = tf_hal_current_time_us(rgb_led_button->tfp.spitfp.hal) + tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&rgb_led_button->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&rgb_led_button->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_button_get_color_calibration(TF_RGBLEDButton *rgb_led_button, uint8_t *ret_red, uint8_t *ret_green, uint8_t *ret_blue) {
    if(tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&rgb_led_button->tfp, TF_RGB_LED_BUTTON_FUNCTION_GET_COLOR_CALIBRATION, 0, 3, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_button->tfp.spitfp.hal) + tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&rgb_led_button->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_red != NULL) { *ret_red = tf_packetbuffer_read_uint8_t(&rgb_led_button->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&rgb_led_button->tfp.spitfp.recv_buf, 1); }
        if (ret_green != NULL) { *ret_green = tf_packetbuffer_read_uint8_t(&rgb_led_button->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&rgb_led_button->tfp.spitfp.recv_buf, 1); }
        if (ret_blue != NULL) { *ret_blue = tf_packetbuffer_read_uint8_t(&rgb_led_button->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&rgb_led_button->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&rgb_led_button->tfp);
    }

    result = tf_tfp_finish_send(&rgb_led_button->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_button_get_spitfp_error_count(TF_RGBLEDButton *rgb_led_button, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&rgb_led_button->tfp, TF_RGB_LED_BUTTON_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_button->tfp.spitfp.hal) + tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&rgb_led_button->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&rgb_led_button->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&rgb_led_button->tfp.spitfp.recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&rgb_led_button->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&rgb_led_button->tfp.spitfp.recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&rgb_led_button->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&rgb_led_button->tfp.spitfp.recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&rgb_led_button->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&rgb_led_button->tfp.spitfp.recv_buf, 4); }
        tf_tfp_packet_processed(&rgb_led_button->tfp);
    }

    result = tf_tfp_finish_send(&rgb_led_button->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_button_set_bootloader_mode(TF_RGBLEDButton *rgb_led_button, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&rgb_led_button->tfp, TF_RGB_LED_BUTTON_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&rgb_led_button->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(rgb_led_button->tfp.spitfp.hal) + tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&rgb_led_button->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&rgb_led_button->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&rgb_led_button->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&rgb_led_button->tfp);
    }

    result = tf_tfp_finish_send(&rgb_led_button->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_button_get_bootloader_mode(TF_RGBLEDButton *rgb_led_button, uint8_t *ret_mode) {
    if(tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&rgb_led_button->tfp, TF_RGB_LED_BUTTON_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_button->tfp.spitfp.hal) + tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&rgb_led_button->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&rgb_led_button->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&rgb_led_button->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&rgb_led_button->tfp);
    }

    result = tf_tfp_finish_send(&rgb_led_button->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_button_set_write_firmware_pointer(TF_RGBLEDButton *rgb_led_button, uint32_t pointer) {
    if(tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rgb_led_button_get_response_expected(rgb_led_button, TF_RGB_LED_BUTTON_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(&rgb_led_button->tfp, TF_RGB_LED_BUTTON_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&rgb_led_button->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_button->tfp.spitfp.hal) + tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&rgb_led_button->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&rgb_led_button->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_button_write_firmware(TF_RGBLEDButton *rgb_led_button, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&rgb_led_button->tfp, TF_RGB_LED_BUTTON_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&rgb_led_button->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_button->tfp.spitfp.hal) + tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&rgb_led_button->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&rgb_led_button->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&rgb_led_button->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&rgb_led_button->tfp);
    }

    result = tf_tfp_finish_send(&rgb_led_button->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_button_set_status_led_config(TF_RGBLEDButton *rgb_led_button, uint8_t config) {
    if(tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rgb_led_button_get_response_expected(rgb_led_button, TF_RGB_LED_BUTTON_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(&rgb_led_button->tfp, TF_RGB_LED_BUTTON_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&rgb_led_button->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(rgb_led_button->tfp.spitfp.hal) + tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&rgb_led_button->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&rgb_led_button->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_button_get_status_led_config(TF_RGBLEDButton *rgb_led_button, uint8_t *ret_config) {
    if(tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&rgb_led_button->tfp, TF_RGB_LED_BUTTON_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_button->tfp.spitfp.hal) + tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&rgb_led_button->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&rgb_led_button->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&rgb_led_button->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&rgb_led_button->tfp);
    }

    result = tf_tfp_finish_send(&rgb_led_button->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_button_get_chip_temperature(TF_RGBLEDButton *rgb_led_button, int16_t *ret_temperature) {
    if(tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&rgb_led_button->tfp, TF_RGB_LED_BUTTON_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_button->tfp.spitfp.hal) + tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&rgb_led_button->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&rgb_led_button->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&rgb_led_button->tfp.spitfp.recv_buf, 2); }
        tf_tfp_packet_processed(&rgb_led_button->tfp);
    }

    result = tf_tfp_finish_send(&rgb_led_button->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_button_reset(TF_RGBLEDButton *rgb_led_button) {
    if(tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rgb_led_button_get_response_expected(rgb_led_button, TF_RGB_LED_BUTTON_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(&rgb_led_button->tfp, TF_RGB_LED_BUTTON_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_button->tfp.spitfp.hal) + tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&rgb_led_button->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&rgb_led_button->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_button_write_uid(TF_RGBLEDButton *rgb_led_button, uint32_t uid) {
    if(tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_rgb_led_button_get_response_expected(rgb_led_button, TF_RGB_LED_BUTTON_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(&rgb_led_button->tfp, TF_RGB_LED_BUTTON_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&rgb_led_button->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_button->tfp.spitfp.hal) + tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&rgb_led_button->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&rgb_led_button->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_button_read_uid(TF_RGBLEDButton *rgb_led_button, uint32_t *ret_uid) {
    if(tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&rgb_led_button->tfp, TF_RGB_LED_BUTTON_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(rgb_led_button->tfp.spitfp.hal) + tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&rgb_led_button->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&rgb_led_button->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&rgb_led_button->tfp.spitfp.recv_buf, 4); }
        tf_tfp_packet_processed(&rgb_led_button->tfp);
    }

    result = tf_tfp_finish_send(&rgb_led_button->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_rgb_led_button_get_identity(TF_RGBLEDButton *rgb_led_button, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&rgb_led_button->tfp, TF_RGB_LED_BUTTON_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(rgb_led_button->tfp.spitfp.hal) + tf_hal_get_common(rgb_led_button->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&rgb_led_button->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&rgb_led_button->tfp.spitfp.recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&rgb_led_button->tfp.spitfp.recv_buf, 8); }
        *tmp_connected_uid = tf_packetbuffer_read_char(&rgb_led_button->tfp.spitfp.recv_buf);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&rgb_led_button->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&rgb_led_button->tfp.spitfp.recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&rgb_led_button->tfp.spitfp.recv_buf);} else { tf_packetbuffer_remove(&rgb_led_button->tfp.spitfp.recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&rgb_led_button->tfp.spitfp.recv_buf);} else { tf_packetbuffer_remove(&rgb_led_button->tfp.spitfp.recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&rgb_led_button->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&rgb_led_button->tfp.spitfp.recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(rgb_led_button->tfp.spitfp.hal, rgb_led_button->tfp.spitfp.port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(&rgb_led_button->tfp);
    }

    result = tf_tfp_finish_send(&rgb_led_button->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_rgb_led_button_register_button_state_changed_callback(TF_RGBLEDButton *rgb_led_button, TF_RGBLEDButtonButtonStateChangedHandler handler, void *user_data) {
    if (handler == NULL) {
        rgb_led_button->tfp.needs_callback_tick = false;
        
    } else {
        rgb_led_button->tfp.needs_callback_tick = true;
    }
    rgb_led_button->button_state_changed_handler = handler;
    rgb_led_button->button_state_changed_user_data = user_data;
}
#endif
int tf_rgb_led_button_callback_tick(TF_RGBLEDButton *rgb_led_button, uint32_t timeout_us) {
    return tf_tfp_callback_tick(&rgb_led_button->tfp, tf_hal_current_time_us(rgb_led_button->tfp.spitfp.hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
