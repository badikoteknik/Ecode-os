#define VGA ((volatile unsigned short*)0xB8000)
#define GEN 80
#define YUK 25

static int x = 0, y = 0;
static unsigned char renk = 0x0F;

static void temizle(void) {
    for (int i = 0; i < GEN * YUK; i++)
        VGA[i] = (renk << 8) | ' ';
    x = 0; y = 0;
}

static void kaydir(void) {
    for (int i = 0; i < GEN * (YUK - 1); i++)
        VGA[i] = VGA[i + GEN];
    for (int i = GEN * (YUK - 1); i < GEN * YUK; i++)
        VGA[i] = (renk << 8) | ' ';
    y = YUK - 1;
}

static void harf_yaz(char c) {
    if (c == '\n') { x = 0; y++; }
    else {
        VGA[y * GEN + x] = (renk << 8) | (unsigned char)c;
        if (++x >= GEN) { x = 0; y++; }
    }
    if (y >= YUK) kaydir();
}

void yaz(const char *s) {
    for (int i = 0; s[i]; i++) harf_yaz(s[i]);
}

void kernel_main(void) {
    temizle();
    renk = 0x0A;  yaz("Ecode-os v0.1\n");
    renk = 0x0F;  yaz("Merhaba Dunya!\n");
    renk = 0x0E;  yaz("Kendi isletim sistemim calisiyor.\n");
    while (1);
}
