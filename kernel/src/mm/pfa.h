#pragma once

void PfaInitialize(struct limine_memmap_response *memmap);
void *PfaAllocate();
void PfaFree(void *page);