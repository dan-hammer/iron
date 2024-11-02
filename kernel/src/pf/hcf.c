void PfProcessorHalt(void) {
    for (;;) {
        asm ("hlt");
    }
}