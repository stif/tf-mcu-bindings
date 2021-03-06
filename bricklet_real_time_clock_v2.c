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

#include "bricklet_real_time_clock_v2.h"
#include "base58.h"
#include "endian_convert.h"
#include "errors.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef TF_IMPLEMENT_CALLBACKS
static bool tf_real_time_clock_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    TF_RealTimeClockV2 *real_time_clock_v2 = (TF_RealTimeClockV2 *) dev;
    (void)payload;

    switch(fid) {

        case TF_REAL_TIME_CLOCK_V2_CALLBACK_DATE_TIME: {
            TF_RealTimeClockV2DateTimeHandler fn = real_time_clock_v2->date_time_handler;
            void *user_data = real_time_clock_v2->date_time_user_data;
            if (fn == NULL)
                return false;

            uint16_t year = tf_packetbuffer_read_uint16_t(payload);
            uint8_t month = tf_packetbuffer_read_uint8_t(payload);
            uint8_t day = tf_packetbuffer_read_uint8_t(payload);
            uint8_t hour = tf_packetbuffer_read_uint8_t(payload);
            uint8_t minute = tf_packetbuffer_read_uint8_t(payload);
            uint8_t second = tf_packetbuffer_read_uint8_t(payload);
            uint8_t centisecond = tf_packetbuffer_read_uint8_t(payload);
            uint8_t weekday = tf_packetbuffer_read_uint8_t(payload);
            int64_t timestamp = tf_packetbuffer_read_int64_t(payload);
            tf_tfp_packet_processed(&real_time_clock_v2->tfp);
            TF_HalCommon *common = tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal);
            common->locked = true;
            fn(real_time_clock_v2, year, month, day, hour, minute, second, centisecond, weekday, timestamp, user_data);
            common->locked = false;
            break;
        }

        case TF_REAL_TIME_CLOCK_V2_CALLBACK_ALARM: {
            TF_RealTimeClockV2AlarmHandler fn = real_time_clock_v2->alarm_handler;
            void *user_data = real_time_clock_v2->alarm_user_data;
            if (fn == NULL)
                return false;

            uint16_t year = tf_packetbuffer_read_uint16_t(payload);
            uint8_t month = tf_packetbuffer_read_uint8_t(payload);
            uint8_t day = tf_packetbuffer_read_uint8_t(payload);
            uint8_t hour = tf_packetbuffer_read_uint8_t(payload);
            uint8_t minute = tf_packetbuffer_read_uint8_t(payload);
            uint8_t second = tf_packetbuffer_read_uint8_t(payload);
            uint8_t centisecond = tf_packetbuffer_read_uint8_t(payload);
            uint8_t weekday = tf_packetbuffer_read_uint8_t(payload);
            int64_t timestamp = tf_packetbuffer_read_int64_t(payload);
            tf_tfp_packet_processed(&real_time_clock_v2->tfp);
            TF_HalCommon *common = tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal);
            common->locked = true;
            fn(real_time_clock_v2, year, month, day, hour, minute, second, centisecond, weekday, timestamp, user_data);
            common->locked = false;
            break;
        }
        default:
            return false;
    }

    return true;
}
#else
static bool tf_real_time_clock_v2_callback_handler(void *dev, uint8_t fid, TF_Packetbuffer *payload) {
    return false;
}
#endif
int tf_real_time_clock_v2_create(TF_RealTimeClockV2 *real_time_clock_v2, const char *uid, TF_HalContext *hal) {
    memset(real_time_clock_v2, 0, sizeof(TF_RealTimeClockV2));

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

    rc = tf_tfp_init(&real_time_clock_v2->tfp, numeric_uid, TF_REAL_TIME_CLOCK_V2_DEVICE_IDENTIFIER, hal, port_id, inventory_index, tf_real_time_clock_v2_callback_handler);
    if (rc != TF_E_OK) {
        return rc;
    }
    real_time_clock_v2->response_expected[0] = 0x0C;
    return TF_E_OK;
}

int tf_real_time_clock_v2_destroy(TF_RealTimeClockV2 *real_time_clock_v2) {
    return tf_tfp_destroy(&real_time_clock_v2->tfp);
}

int tf_real_time_clock_v2_get_response_expected(TF_RealTimeClockV2 *real_time_clock_v2, uint8_t function_id, bool *ret_response_expected) {
    switch(function_id) {
        case TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_DATE_TIME:
            if(ret_response_expected != NULL)
                *ret_response_expected = (real_time_clock_v2->response_expected[0] & (1 << 0)) != 0;
            break;
        case TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_OFFSET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (real_time_clock_v2->response_expected[0] & (1 << 1)) != 0;
            break;
        case TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_DATE_TIME_CALLBACK_CONFIGURATION:
            if(ret_response_expected != NULL)
                *ret_response_expected = (real_time_clock_v2->response_expected[0] & (1 << 2)) != 0;
            break;
        case TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_ALARM:
            if(ret_response_expected != NULL)
                *ret_response_expected = (real_time_clock_v2->response_expected[0] & (1 << 3)) != 0;
            break;
        case TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if(ret_response_expected != NULL)
                *ret_response_expected = (real_time_clock_v2->response_expected[0] & (1 << 4)) != 0;
            break;
        case TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if(ret_response_expected != NULL)
                *ret_response_expected = (real_time_clock_v2->response_expected[0] & (1 << 5)) != 0;
            break;
        case TF_REAL_TIME_CLOCK_V2_FUNCTION_RESET:
            if(ret_response_expected != NULL)
                *ret_response_expected = (real_time_clock_v2->response_expected[0] & (1 << 6)) != 0;
            break;
        case TF_REAL_TIME_CLOCK_V2_FUNCTION_WRITE_UID:
            if(ret_response_expected != NULL)
                *ret_response_expected = (real_time_clock_v2->response_expected[0] & (1 << 7)) != 0;
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

int tf_real_time_clock_v2_set_response_expected(TF_RealTimeClockV2 *real_time_clock_v2, uint8_t function_id, bool response_expected) {
    switch(function_id) {
        case TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_DATE_TIME:
            if (response_expected) {
                real_time_clock_v2->response_expected[0] |= (1 << 0);
            } else {
                real_time_clock_v2->response_expected[0] &= ~(1 << 0);
            }
            break;
        case TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_OFFSET:
            if (response_expected) {
                real_time_clock_v2->response_expected[0] |= (1 << 1);
            } else {
                real_time_clock_v2->response_expected[0] &= ~(1 << 1);
            }
            break;
        case TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_DATE_TIME_CALLBACK_CONFIGURATION:
            if (response_expected) {
                real_time_clock_v2->response_expected[0] |= (1 << 2);
            } else {
                real_time_clock_v2->response_expected[0] &= ~(1 << 2);
            }
            break;
        case TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_ALARM:
            if (response_expected) {
                real_time_clock_v2->response_expected[0] |= (1 << 3);
            } else {
                real_time_clock_v2->response_expected[0] &= ~(1 << 3);
            }
            break;
        case TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER:
            if (response_expected) {
                real_time_clock_v2->response_expected[0] |= (1 << 4);
            } else {
                real_time_clock_v2->response_expected[0] &= ~(1 << 4);
            }
            break;
        case TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_STATUS_LED_CONFIG:
            if (response_expected) {
                real_time_clock_v2->response_expected[0] |= (1 << 5);
            } else {
                real_time_clock_v2->response_expected[0] &= ~(1 << 5);
            }
            break;
        case TF_REAL_TIME_CLOCK_V2_FUNCTION_RESET:
            if (response_expected) {
                real_time_clock_v2->response_expected[0] |= (1 << 6);
            } else {
                real_time_clock_v2->response_expected[0] &= ~(1 << 6);
            }
            break;
        case TF_REAL_TIME_CLOCK_V2_FUNCTION_WRITE_UID:
            if (response_expected) {
                real_time_clock_v2->response_expected[0] |= (1 << 7);
            } else {
                real_time_clock_v2->response_expected[0] &= ~(1 << 7);
            }
            break;
        default:
            return TF_E_INVALID_PARAMETER;
    }
    return TF_E_OK;
}

void tf_real_time_clock_v2_set_response_expected_all(TF_RealTimeClockV2 *real_time_clock_v2, bool response_expected) {
    memset(real_time_clock_v2->response_expected, response_expected ? 0xFF : 0, 1);
}

int tf_real_time_clock_v2_set_date_time(TF_RealTimeClockV2 *real_time_clock_v2, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second, uint8_t centisecond, uint8_t weekday) {
    if(tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_real_time_clock_v2_get_response_expected(real_time_clock_v2, TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_DATE_TIME, &response_expected);
    tf_tfp_prepare_send(&real_time_clock_v2->tfp, TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_DATE_TIME, 9, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&real_time_clock_v2->tfp);

    year = tf_leconvert_uint16_to(year); memcpy(buf + 0, &year, 2);
    buf[2] = (uint8_t)month;
    buf[3] = (uint8_t)day;
    buf[4] = (uint8_t)hour;
    buf[5] = (uint8_t)minute;
    buf[6] = (uint8_t)second;
    buf[7] = (uint8_t)centisecond;
    buf[8] = (uint8_t)weekday;

    uint32_t deadline = tf_hal_current_time_us(real_time_clock_v2->tfp.spitfp.hal) + tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&real_time_clock_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&real_time_clock_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_real_time_clock_v2_get_date_time(TF_RealTimeClockV2 *real_time_clock_v2, uint16_t *ret_year, uint8_t *ret_month, uint8_t *ret_day, uint8_t *ret_hour, uint8_t *ret_minute, uint8_t *ret_second, uint8_t *ret_centisecond, uint8_t *ret_weekday, int64_t *ret_timestamp) {
    if(tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&real_time_clock_v2->tfp, TF_REAL_TIME_CLOCK_V2_FUNCTION_GET_DATE_TIME, 0, 17, response_expected);

    uint32_t deadline = tf_hal_current_time_us(real_time_clock_v2->tfp.spitfp.hal) + tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&real_time_clock_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_year != NULL) { *ret_year = tf_packetbuffer_read_uint16_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 2); }
        if (ret_month != NULL) { *ret_month = tf_packetbuffer_read_uint8_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 1); }
        if (ret_day != NULL) { *ret_day = tf_packetbuffer_read_uint8_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 1); }
        if (ret_hour != NULL) { *ret_hour = tf_packetbuffer_read_uint8_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 1); }
        if (ret_minute != NULL) { *ret_minute = tf_packetbuffer_read_uint8_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 1); }
        if (ret_second != NULL) { *ret_second = tf_packetbuffer_read_uint8_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 1); }
        if (ret_centisecond != NULL) { *ret_centisecond = tf_packetbuffer_read_uint8_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 1); }
        if (ret_weekday != NULL) { *ret_weekday = tf_packetbuffer_read_uint8_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 1); }
        if (ret_timestamp != NULL) { *ret_timestamp = tf_packetbuffer_read_int64_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 8); }
        tf_tfp_packet_processed(&real_time_clock_v2->tfp);
    }

    result = tf_tfp_finish_send(&real_time_clock_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_real_time_clock_v2_get_timestamp(TF_RealTimeClockV2 *real_time_clock_v2, int64_t *ret_timestamp) {
    if(tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&real_time_clock_v2->tfp, TF_REAL_TIME_CLOCK_V2_FUNCTION_GET_TIMESTAMP, 0, 8, response_expected);

    uint32_t deadline = tf_hal_current_time_us(real_time_clock_v2->tfp.spitfp.hal) + tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&real_time_clock_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_timestamp != NULL) { *ret_timestamp = tf_packetbuffer_read_int64_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 8); }
        tf_tfp_packet_processed(&real_time_clock_v2->tfp);
    }

    result = tf_tfp_finish_send(&real_time_clock_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_real_time_clock_v2_set_offset(TF_RealTimeClockV2 *real_time_clock_v2, int8_t offset) {
    if(tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_real_time_clock_v2_get_response_expected(real_time_clock_v2, TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_OFFSET, &response_expected);
    tf_tfp_prepare_send(&real_time_clock_v2->tfp, TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_OFFSET, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&real_time_clock_v2->tfp);

    buf[0] = (uint8_t)offset;

    uint32_t deadline = tf_hal_current_time_us(real_time_clock_v2->tfp.spitfp.hal) + tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&real_time_clock_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&real_time_clock_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_real_time_clock_v2_get_offset(TF_RealTimeClockV2 *real_time_clock_v2, int8_t *ret_offset) {
    if(tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&real_time_clock_v2->tfp, TF_REAL_TIME_CLOCK_V2_FUNCTION_GET_OFFSET, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(real_time_clock_v2->tfp.spitfp.hal) + tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&real_time_clock_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_offset != NULL) { *ret_offset = tf_packetbuffer_read_int8_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&real_time_clock_v2->tfp);
    }

    result = tf_tfp_finish_send(&real_time_clock_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_real_time_clock_v2_set_date_time_callback_configuration(TF_RealTimeClockV2 *real_time_clock_v2, uint32_t period) {
    if(tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_real_time_clock_v2_get_response_expected(real_time_clock_v2, TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_DATE_TIME_CALLBACK_CONFIGURATION, &response_expected);
    tf_tfp_prepare_send(&real_time_clock_v2->tfp, TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_DATE_TIME_CALLBACK_CONFIGURATION, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&real_time_clock_v2->tfp);

    period = tf_leconvert_uint32_to(period); memcpy(buf + 0, &period, 4);

    uint32_t deadline = tf_hal_current_time_us(real_time_clock_v2->tfp.spitfp.hal) + tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&real_time_clock_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&real_time_clock_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_real_time_clock_v2_get_date_time_callback_configuration(TF_RealTimeClockV2 *real_time_clock_v2, uint32_t *ret_period) {
    if(tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&real_time_clock_v2->tfp, TF_REAL_TIME_CLOCK_V2_FUNCTION_GET_DATE_TIME_CALLBACK_CONFIGURATION, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(real_time_clock_v2->tfp.spitfp.hal) + tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&real_time_clock_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_period != NULL) { *ret_period = tf_packetbuffer_read_uint32_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 4); }
        tf_tfp_packet_processed(&real_time_clock_v2->tfp);
    }

    result = tf_tfp_finish_send(&real_time_clock_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_real_time_clock_v2_set_alarm(TF_RealTimeClockV2 *real_time_clock_v2, int8_t month, int8_t day, int8_t hour, int8_t minute, int8_t second, int8_t weekday, int32_t interval) {
    if(tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_real_time_clock_v2_get_response_expected(real_time_clock_v2, TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_ALARM, &response_expected);
    tf_tfp_prepare_send(&real_time_clock_v2->tfp, TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_ALARM, 10, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&real_time_clock_v2->tfp);

    buf[0] = (uint8_t)month;
    buf[1] = (uint8_t)day;
    buf[2] = (uint8_t)hour;
    buf[3] = (uint8_t)minute;
    buf[4] = (uint8_t)second;
    buf[5] = (uint8_t)weekday;
    interval = tf_leconvert_int32_to(interval); memcpy(buf + 6, &interval, 4);

    uint32_t deadline = tf_hal_current_time_us(real_time_clock_v2->tfp.spitfp.hal) + tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&real_time_clock_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&real_time_clock_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_real_time_clock_v2_get_alarm(TF_RealTimeClockV2 *real_time_clock_v2, int8_t *ret_month, int8_t *ret_day, int8_t *ret_hour, int8_t *ret_minute, int8_t *ret_second, int8_t *ret_weekday, int32_t *ret_interval) {
    if(tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&real_time_clock_v2->tfp, TF_REAL_TIME_CLOCK_V2_FUNCTION_GET_ALARM, 0, 10, response_expected);

    uint32_t deadline = tf_hal_current_time_us(real_time_clock_v2->tfp.spitfp.hal) + tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&real_time_clock_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_month != NULL) { *ret_month = tf_packetbuffer_read_int8_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 1); }
        if (ret_day != NULL) { *ret_day = tf_packetbuffer_read_int8_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 1); }
        if (ret_hour != NULL) { *ret_hour = tf_packetbuffer_read_int8_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 1); }
        if (ret_minute != NULL) { *ret_minute = tf_packetbuffer_read_int8_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 1); }
        if (ret_second != NULL) { *ret_second = tf_packetbuffer_read_int8_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 1); }
        if (ret_weekday != NULL) { *ret_weekday = tf_packetbuffer_read_int8_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 1); }
        if (ret_interval != NULL) { *ret_interval = tf_packetbuffer_read_int32_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 4); }
        tf_tfp_packet_processed(&real_time_clock_v2->tfp);
    }

    result = tf_tfp_finish_send(&real_time_clock_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_real_time_clock_v2_get_spitfp_error_count(TF_RealTimeClockV2 *real_time_clock_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
    if(tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&real_time_clock_v2->tfp, TF_REAL_TIME_CLOCK_V2_FUNCTION_GET_SPITFP_ERROR_COUNT, 0, 16, response_expected);

    uint32_t deadline = tf_hal_current_time_us(real_time_clock_v2->tfp.spitfp.hal) + tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&real_time_clock_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_error_count_ack_checksum != NULL) { *ret_error_count_ack_checksum = tf_packetbuffer_read_uint32_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 4); }
        if (ret_error_count_message_checksum != NULL) { *ret_error_count_message_checksum = tf_packetbuffer_read_uint32_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 4); }
        if (ret_error_count_frame != NULL) { *ret_error_count_frame = tf_packetbuffer_read_uint32_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 4); }
        if (ret_error_count_overflow != NULL) { *ret_error_count_overflow = tf_packetbuffer_read_uint32_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 4); }
        tf_tfp_packet_processed(&real_time_clock_v2->tfp);
    }

    result = tf_tfp_finish_send(&real_time_clock_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_real_time_clock_v2_set_bootloader_mode(TF_RealTimeClockV2 *real_time_clock_v2, uint8_t mode, uint8_t *ret_status) {
    if(tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&real_time_clock_v2->tfp, TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_BOOTLOADER_MODE, 1, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&real_time_clock_v2->tfp);

    buf[0] = (uint8_t)mode;

    uint32_t deadline = tf_hal_current_time_us(real_time_clock_v2->tfp.spitfp.hal) + tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&real_time_clock_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&real_time_clock_v2->tfp);
    }

    result = tf_tfp_finish_send(&real_time_clock_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_real_time_clock_v2_get_bootloader_mode(TF_RealTimeClockV2 *real_time_clock_v2, uint8_t *ret_mode) {
    if(tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&real_time_clock_v2->tfp, TF_REAL_TIME_CLOCK_V2_FUNCTION_GET_BOOTLOADER_MODE, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(real_time_clock_v2->tfp.spitfp.hal) + tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&real_time_clock_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_mode != NULL) { *ret_mode = tf_packetbuffer_read_uint8_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&real_time_clock_v2->tfp);
    }

    result = tf_tfp_finish_send(&real_time_clock_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_real_time_clock_v2_set_write_firmware_pointer(TF_RealTimeClockV2 *real_time_clock_v2, uint32_t pointer) {
    if(tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_real_time_clock_v2_get_response_expected(real_time_clock_v2, TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, &response_expected);
    tf_tfp_prepare_send(&real_time_clock_v2->tfp, TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&real_time_clock_v2->tfp);

    pointer = tf_leconvert_uint32_to(pointer); memcpy(buf + 0, &pointer, 4);

    uint32_t deadline = tf_hal_current_time_us(real_time_clock_v2->tfp.spitfp.hal) + tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&real_time_clock_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&real_time_clock_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_real_time_clock_v2_write_firmware(TF_RealTimeClockV2 *real_time_clock_v2, uint8_t data[64], uint8_t *ret_status) {
    if(tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&real_time_clock_v2->tfp, TF_REAL_TIME_CLOCK_V2_FUNCTION_WRITE_FIRMWARE, 64, 1, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&real_time_clock_v2->tfp);

    memcpy(buf + 0, data, 64);

    uint32_t deadline = tf_hal_current_time_us(real_time_clock_v2->tfp.spitfp.hal) + tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&real_time_clock_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_status != NULL) { *ret_status = tf_packetbuffer_read_uint8_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&real_time_clock_v2->tfp);
    }

    result = tf_tfp_finish_send(&real_time_clock_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_real_time_clock_v2_set_status_led_config(TF_RealTimeClockV2 *real_time_clock_v2, uint8_t config) {
    if(tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_real_time_clock_v2_get_response_expected(real_time_clock_v2, TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_STATUS_LED_CONFIG, &response_expected);
    tf_tfp_prepare_send(&real_time_clock_v2->tfp, TF_REAL_TIME_CLOCK_V2_FUNCTION_SET_STATUS_LED_CONFIG, 1, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&real_time_clock_v2->tfp);

    buf[0] = (uint8_t)config;

    uint32_t deadline = tf_hal_current_time_us(real_time_clock_v2->tfp.spitfp.hal) + tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&real_time_clock_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&real_time_clock_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_real_time_clock_v2_get_status_led_config(TF_RealTimeClockV2 *real_time_clock_v2, uint8_t *ret_config) {
    if(tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&real_time_clock_v2->tfp, TF_REAL_TIME_CLOCK_V2_FUNCTION_GET_STATUS_LED_CONFIG, 0, 1, response_expected);

    uint32_t deadline = tf_hal_current_time_us(real_time_clock_v2->tfp.spitfp.hal) + tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&real_time_clock_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_config != NULL) { *ret_config = tf_packetbuffer_read_uint8_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 1); }
        tf_tfp_packet_processed(&real_time_clock_v2->tfp);
    }

    result = tf_tfp_finish_send(&real_time_clock_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_real_time_clock_v2_get_chip_temperature(TF_RealTimeClockV2 *real_time_clock_v2, int16_t *ret_temperature) {
    if(tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&real_time_clock_v2->tfp, TF_REAL_TIME_CLOCK_V2_FUNCTION_GET_CHIP_TEMPERATURE, 0, 2, response_expected);

    uint32_t deadline = tf_hal_current_time_us(real_time_clock_v2->tfp.spitfp.hal) + tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&real_time_clock_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_temperature != NULL) { *ret_temperature = tf_packetbuffer_read_int16_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 2); }
        tf_tfp_packet_processed(&real_time_clock_v2->tfp);
    }

    result = tf_tfp_finish_send(&real_time_clock_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_real_time_clock_v2_reset(TF_RealTimeClockV2 *real_time_clock_v2) {
    if(tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_real_time_clock_v2_get_response_expected(real_time_clock_v2, TF_REAL_TIME_CLOCK_V2_FUNCTION_RESET, &response_expected);
    tf_tfp_prepare_send(&real_time_clock_v2->tfp, TF_REAL_TIME_CLOCK_V2_FUNCTION_RESET, 0, 0, response_expected);

    uint32_t deadline = tf_hal_current_time_us(real_time_clock_v2->tfp.spitfp.hal) + tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&real_time_clock_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&real_time_clock_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_real_time_clock_v2_write_uid(TF_RealTimeClockV2 *real_time_clock_v2, uint32_t uid) {
    if(tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_real_time_clock_v2_get_response_expected(real_time_clock_v2, TF_REAL_TIME_CLOCK_V2_FUNCTION_WRITE_UID, &response_expected);
    tf_tfp_prepare_send(&real_time_clock_v2->tfp, TF_REAL_TIME_CLOCK_V2_FUNCTION_WRITE_UID, 4, 0, response_expected);

    uint8_t *buf = tf_tfp_get_payload_buffer(&real_time_clock_v2->tfp);

    uid = tf_leconvert_uint32_to(uid); memcpy(buf + 0, &uid, 4);

    uint32_t deadline = tf_hal_current_time_us(real_time_clock_v2->tfp.spitfp.hal) + tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&real_time_clock_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    result = tf_tfp_finish_send(&real_time_clock_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_real_time_clock_v2_read_uid(TF_RealTimeClockV2 *real_time_clock_v2, uint32_t *ret_uid) {
    if(tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&real_time_clock_v2->tfp, TF_REAL_TIME_CLOCK_V2_FUNCTION_READ_UID, 0, 4, response_expected);

    uint32_t deadline = tf_hal_current_time_us(real_time_clock_v2->tfp.spitfp.hal) + tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&real_time_clock_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        if (ret_uid != NULL) { *ret_uid = tf_packetbuffer_read_uint32_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 4); }
        tf_tfp_packet_processed(&real_time_clock_v2->tfp);
    }

    result = tf_tfp_finish_send(&real_time_clock_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}

int tf_real_time_clock_v2_get_identity(TF_RealTimeClockV2 *real_time_clock_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
    if(tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->locked) {
        return TF_E_LOCKED;
    }

    bool response_expected = true;
    tf_tfp_prepare_send(&real_time_clock_v2->tfp, TF_REAL_TIME_CLOCK_V2_FUNCTION_GET_IDENTITY, 0, 25, response_expected);

    size_t i;
    uint32_t deadline = tf_hal_current_time_us(real_time_clock_v2->tfp.spitfp.hal) + tf_hal_get_common(real_time_clock_v2->tfp.spitfp.hal)->timeout;

    uint8_t error_code = 0;
    int result = tf_tfp_transmit_packet(&real_time_clock_v2->tfp, response_expected, deadline, &error_code);
    if(result < 0)
        return result;

    if (result & TF_TICK_TIMEOUT) {
        //return -result;
        return TF_E_TIMEOUT;
    }

    if (result & TF_TICK_PACKET_RECEIVED && error_code == 0) {
        char tmp_connected_uid[8] = {0};
        if (ret_uid != NULL) { tf_packetbuffer_pop_n(&real_time_clock_v2->tfp.spitfp.recv_buf, (uint8_t*)ret_uid, 8);} else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 8); }
        *tmp_connected_uid = tf_packetbuffer_read_char(&real_time_clock_v2->tfp.spitfp.recv_buf);
        if (ret_position != NULL) { *ret_position = tf_packetbuffer_read_char(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 1); }
        if (ret_hardware_version != NULL) { for (i = 0; i < 3; ++i) ret_hardware_version[i] = tf_packetbuffer_read_uint8_t(&real_time_clock_v2->tfp.spitfp.recv_buf);} else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 3); }
        if (ret_firmware_version != NULL) { for (i = 0; i < 3; ++i) ret_firmware_version[i] = tf_packetbuffer_read_uint8_t(&real_time_clock_v2->tfp.spitfp.recv_buf);} else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 3); }
        if (ret_device_identifier != NULL) { *ret_device_identifier = tf_packetbuffer_read_uint16_t(&real_time_clock_v2->tfp.spitfp.recv_buf); } else { tf_packetbuffer_remove(&real_time_clock_v2->tfp.spitfp.recv_buf, 2); }
        if (tmp_connected_uid[0] == 0 && ret_position != NULL) {
            *ret_position = tf_hal_get_port_name(real_time_clock_v2->tfp.spitfp.hal, real_time_clock_v2->tfp.spitfp.port_id);
        }
        if (ret_connected_uid != NULL) {
            memcpy(ret_connected_uid, tmp_connected_uid, 8);
        }
        tf_tfp_packet_processed(&real_time_clock_v2->tfp);
    }

    result = tf_tfp_finish_send(&real_time_clock_v2->tfp, result, deadline);
    if(result < 0)
        return result;

    return tf_tfp_get_error(error_code);
}
#ifdef TF_IMPLEMENT_CALLBACKS
void tf_real_time_clock_v2_register_date_time_callback(TF_RealTimeClockV2 *real_time_clock_v2, TF_RealTimeClockV2DateTimeHandler handler, void *user_data) {
    if (handler == NULL) {
        real_time_clock_v2->tfp.needs_callback_tick = false;
        real_time_clock_v2->tfp.needs_callback_tick |= real_time_clock_v2->alarm_handler != NULL;
    } else {
        real_time_clock_v2->tfp.needs_callback_tick = true;
    }
    real_time_clock_v2->date_time_handler = handler;
    real_time_clock_v2->date_time_user_data = user_data;
}


void tf_real_time_clock_v2_register_alarm_callback(TF_RealTimeClockV2 *real_time_clock_v2, TF_RealTimeClockV2AlarmHandler handler, void *user_data) {
    if (handler == NULL) {
        real_time_clock_v2->tfp.needs_callback_tick = false;
        real_time_clock_v2->tfp.needs_callback_tick |= real_time_clock_v2->date_time_handler != NULL;
    } else {
        real_time_clock_v2->tfp.needs_callback_tick = true;
    }
    real_time_clock_v2->alarm_handler = handler;
    real_time_clock_v2->alarm_user_data = user_data;
}
#endif
int tf_real_time_clock_v2_callback_tick(TF_RealTimeClockV2 *real_time_clock_v2, uint32_t timeout_us) {
    return tf_tfp_callback_tick(&real_time_clock_v2->tfp, tf_hal_current_time_us(real_time_clock_v2->tfp.spitfp.hal) + timeout_us);
}

#ifdef __cplusplus
}
#endif
