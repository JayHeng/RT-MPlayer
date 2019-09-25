/*
 * Copyright 2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _DISPLAY_SUPPORT_H_
#define _DISPLAY_SUPPORT_H_

#include "fsl_dc_fb.h"
#include "mp4.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DEMO_PANEL_RK055AHD091 0
#define DEMO_PANEL_RK055IQH091 1

#ifndef DEMO_PANEL
#if VIDEO_LCD_RESOLUTION_SVGA540 == 1
#define DEMO_PANEL DEMO_PANEL_RK055IQH091
#elif VIDEO_LCD_RESOLUTION_WXGA720 == 1
#define DEMO_PANEL DEMO_PANEL_RK055AHD091
#endif
#endif

#define DEMO_BUFFER_FIXED_ADDRESS 0

#if DEMO_BUFFER_FIXED_ADDRESS
#define DEMO_BUFFER0_ADDR 0x80000000
#define DEMO_BUFFER1_ADDR 0x80200000
#endif

/*
 * Use the MIPI dumb panel
 */

/* Definitions for the frame buffer. */
#define DEMO_BUFFER_COUNT 2 /* 2 is enough for DPI interface display. */

#define DEMO_BUFFER_PIXEL_FORMAT kVIDEO_PixelFormatRGB565
#define DEMO_BUFFER_BYTE_PER_PIXEL 2

#if (DEMO_PANEL_RK055AHD091 == DEMO_PANEL)

#define DEMO_PANEL_WIDTH (720)
#define DEMO_PANEL_HEIGHT (1280)

#elif (DEMO_PANEL_RK055IQH091 == DEMO_PANEL)

#define DEMO_PANEL_WIDTH (540)
#define DEMO_PANEL_HEIGHT (960)

#endif

#define DEMO_BUFFER_WIDTH DEMO_PANEL_WIDTH
#define DEMO_BUFFER_HEIGHT DEMO_PANEL_HEIGHT

#define DEMO_BUFFER_STRIDE_BYTE (DEMO_BUFFER_WIDTH * DEMO_BUFFER_BYTE_PER_PIXEL)
/* There is not frame buffer aligned requirement, consider the 64-bit AXI data
 * bus width and 32-byte cache line size, the frame buffer alignment is set to
 * 32 byte.
 */
#define FRAME_BUFFER_ALIGN 32

extern const dc_fb_t g_dc;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

status_t BOARD_PrepareDisplayController(void);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* _DISPLAY_SUPPORT_H_ */
