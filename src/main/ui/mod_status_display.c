#include "types.h"

// Deklarasi variabel memori RAM internal bawaan game Harvest Moon BTN
// Alamat pointer ini merujuk langsung ke status Stamina dan Fatigue player di dalam RAM
#define RAM_STAMINA_ADDR (*(volatile u8*)0x80071A12)
#define RAM_FATIGUE_ADDR (*(volatile u8*)0x80071A13)

// Deklarasi fungsi teks bawaan PS1 SDK / decomp untuk cetak karakter ke layar
extern void FntPrint(int id, const char *fmt, ...);

// Fungsi Utama Mod Anda
void Draw_Custom_Stamina_Fatigue_UI(void) {
    u8 stamina = RAM_STAMINA_ADDR;
    u8 fatigue = RAM_FATIGUE_ADDR;

    // Menampilkan Teks di pojok kiri atas (Koordinat X=16, Y=16)
    // Karakter 'S' mewakili Stamina (Hati) dan 'F' mewakili Fatigue (Air)
    FntPrint(0, "S: %d\n", stamina);
    FntPrint(0, "F: %d\n", fatigue);
}
