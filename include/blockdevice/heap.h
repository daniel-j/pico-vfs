/*
 * Copyright 2024, Hiroyuki OYAMA. All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 */
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "blockdevice/blockdevice.h"

/** Create RAM heap memory block device
 *
 * Create a block device object that uses RAM heap memory.  The size of heap memory allocated to the block device is specified by size.
 *
 * @param size Size in bytes to be allocated to the block device.
 * @return Block device object. Returnes NULL in case of failure.
 * @retval NUL Failed to create block device object.
 */
blockdevice_t *blockdevice_heap_create(size_t size);

/** Release the heap memory device.
 *
 * @param device Block device object.
 */
void blockdevice_heap_free(blockdevice_t *device);

#ifdef __cplusplus
}
#endif