#include <hardware/flash.h>
#include "blockdevice/flash.h"
#include "filesystem/littlefs.h"
#include "filesystem/vfs.h"


bool __attribute__((weak)) fs_init(void) {
    filesystem_t *fs = filesystem_littlefs_create(500, 16);
    blockdevice_t *device = blockdevice_flash_create(PICO_FLASH_SIZE_BYTES - DEFAULT_FS_SIZE, 0);

    int err = fs_mount("/", fs, device) == 0;
    if (err != 0) {
        err = fs->format(fs, device);
        if (err != 0) {
            return false;
        }
        err = fs_mount("/", fs, device);
    }
    return err == 0;
}