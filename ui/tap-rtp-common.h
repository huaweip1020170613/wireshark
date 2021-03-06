/* tap-rtp-common.h
 * RTP streams handler functions used by tshark and wireshark
 *
 * Copyright 2008, Ericsson AB
 * By Balint Reczey <balint.reczey@ericsson.com>
 *
 * most functions are copied from ui/gtk/rtp_stream.c and ui/gtk/rtp_analisys.c
 * Copyright 2003, Alcatel Business Systems
 * By Lars Ruoff <lars.ruoff@gmx.net>
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef __TAP_RTP_COMMON_H__
#define __TAP_RTP_COMMON_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "ui/rtp_stream.h"

/* type of error when saving voice in a file didn't succeed */
typedef enum {
    TAP_RTP_NO_ERROR,
    TAP_RTP_WRONG_CODEC,
    TAP_RTP_WRONG_LENGTH,
    TAP_RTP_PADDING_ERROR,
    TAP_RTP_SHORT_FRAME,
    TAP_RTP_FILE_OPEN_ERROR,
    TAP_RTP_FILE_WRITE_ERROR,
    TAP_RTP_NO_DATA,
} tap_rtp_error_type_t;

typedef struct _tap_rtp_save_info_t {
    FILE *fp;
    guint32 count;
    tap_rtp_error_type_t error_type;
    gboolean saved;
} tap_rtp_save_info_t;

/**
 * Compares two RTP stream infos (GCompareFunc style comparison function)
 *
 * @return -1,0,1
 */
gint rtpstream_info_cmp(gconstpointer aa, gconstpointer bb);

/**
* Compares the endpoints of two RTP streams.
*
* @return TRUE if the
*/
gboolean rtpstream_info_is_reverse(const rtpstream_info_t *stream_a, rtpstream_info_t *stream_b);

void rtpstream_reset_cb(void*);
void rtp_write_header(rtpstream_info_t*, FILE*);
int rtpstream_packet_cb(void*, packet_info*, epan_dissect_t *, const void *);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __TAP_RTP_COMMON_H__ */

/*
 * Editor modelines  -  https://www.wireshark.org/tools/modelines.html
 *
 * Local Variables:
 * c-basic-offset: 4
 * tab-width: 8
 * indent-tabs-mode: nil
 * End:
 *
 * ex: set shiftwidth=4 tabstop=8 expandtab:
 * :indentSize=4:tabSize=8:noTabs=true:
 */
