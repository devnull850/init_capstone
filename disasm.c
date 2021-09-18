#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <capstone/capstone.h>

const char filename[] = "hello.bin";

int main(void) {
    FILE *fd;
    uint8_t *buf;
    long pos;

    csh handle;
    cs_insn *instructions;
    cs_err e;
    size_t cnt;

    if ((fd = fopen(filename, "rb")) == NULL) {
        printf("error opening file [%s]", filename);
        exit(EXIT_FAILURE);
    }

    fseek(fd, 0, SEEK_END);
    pos = ftell(fd);
    fseek(fd, 0, SEEK_SET);

    if ((buf = malloc(pos + 1)) == NULL) {
        puts("malloc failed");
        exit(EXIT_FAILURE);
    }

    if (fread(buf, 1, pos, fd) != pos) {
        puts("error reading file contents");
        exit(EXIT_FAILURE);
    }

    if (fd) {
        fclose(fd);
    }
    else {
        puts("file descriptor is null");
        exit(EXIT_FAILURE);
    }

    if (cs_open(CS_ARCH_X86, CS_MODE_64, &handle) != CS_ERR_OK) {
        e = cs_errno(handle);
        puts(cs_strerror(e));
        exit(e);
    }

    if (!(cnt = cs_disasm(handle, buf, pos, 0, 0, &instructions))) {
        e = cs_errno(handle);
        puts(cs_strerror(e));
        exit(e);
    }

    for (int i = 0; i < cnt; ++i) {
        printf("0x%lx:\t%s\t\t%s\n", instructions[i].address, instructions[i].mnemonic,
					instructions[i].op_str);
    }

    cs_free(instructions, cnt);

    cs_close(&handle);

    return EXIT_SUCCESS;
}