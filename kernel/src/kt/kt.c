#include "../ft/backends/fb.h"
#include "../ft/flanterm.h"

struct flanterm_context *ft_ctx = NULL;

void KtInitialize(uint32_t *framebuffer, uint64_t width, uint64_t height, uint64_t pitch, uint8_t red_mask_size, uint8_t red_mask_shift, uint8_t green_mask_size, uint8_t green_mask_shift, uint8_t blue_mask_size, uint8_t blue_mask_shift) {
    ft_ctx = flanterm_fb_init(
        NULL,
        NULL,
        framebuffer,
        width,
        height,
        pitch,
        red_mask_size,
        red_mask_shift,
        green_mask_size,
        green_mask_shift,
        blue_mask_size,
        blue_mask_shift,
        NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 1, 0, 0, 0
    );
}

void KtPutChar(char c) {
    flanterm_write(ft_ctx, &c, 1);
}

void KtWriteString(const char *string) {
    while (*string != '\0') {
        KtPutChar(*string);
        string++;
    }
}