#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "limine.h"
#include "../ft/backends/fb.h"
#include "../ft/flanterm.h"
#include "../kd/mem.h"
#include "../pf/pf.h"
#include "../kt/kt.h"
#include "../mm/pfa.h"
#include "../ku/string.h"

__attribute__((used, section(".limine_requests")))
static volatile LIMINE_BASE_REVISION(3);


__attribute__((used, section(".limine_requests")))
static volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};

__attribute__((used, section(".limine_requests")))
static volatile struct limine_memmap_request memmap_request = {
    .id = LIMINE_MEMMAP_REQUEST,
    .revision = 0
};

__attribute__((used, section(".limine_requests_start")))
static volatile LIMINE_REQUESTS_START_MARKER;

__attribute__((used, section(".limine_requests_end")))
static volatile LIMINE_REQUESTS_END_MARKER;

void kmain(void) {
    if (LIMINE_BASE_REVISION_SUPPORTED == false) {
        PfProcessorHalt();
    }

    if (framebuffer_request.response == NULL
     || framebuffer_request.response->framebuffer_count < 1) {
        PfProcessorHalt();
    }

    struct limine_framebuffer *framebuffer = framebuffer_request.response->framebuffers[0];

    KtInitialize(framebuffer->address, framebuffer->width, framebuffer->height, framebuffer->pitch, framebuffer->red_mask_size, framebuffer->red_mask_shift, framebuffer->green_mask_size, framebuffer->green_mask_shift, framebuffer->blue_mask_size, framebuffer->blue_mask_shift);

    while (true) {
        KtWriteString("Hello World - yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\n");
    }

    PfProcessorHalt();
}
