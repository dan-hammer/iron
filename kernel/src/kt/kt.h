#pragma once
#include <stdint.h>

void KtInitialize(uint32_t *framebuffer, uint64_t width, uint64_t height, uint64_t pitch, uint8_t red_mask_size, uint8_t red_mask_shift, uint8_t green_mask_size, uint8_t green_mask_shift, uint8_t blue_mask_size, uint8_t blue_mask_shift);
void KtWriteString(const char *string);