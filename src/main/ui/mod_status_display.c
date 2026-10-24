#include "types.h"

// Pointer RAM untuk mendeteksi status scene/loading game
#define RAM_SCENE_ID_ADDR (*(volatile u8*)0x800712A8)

// Pointer nilai Stamina dan Fatigue bawaan game
#define RAM_STAMINA_ADDR (*(volatile u8*)0x80071A12)
#define RAM_FATIGUE_ADDR (*(volatile u8*)0x80071A13)

// Deklarasi fungsi cetak teks bawaan PS1 SDK
extern void FntPrint(int id, const char *fmt, ...);

void Draw_Custom_Stamina_Fatigue_UI(void) {
    // SEMUA VARIABEL WAJIB DI TARUH DI ATAS SINI (Sesuai aturan C jadul)
    u8 scene_id;
    u8 stamina;
    u8 fatigue;

    // Ambil data scene id lebih dulu
    scene_id = RAM_SCENE_ID_ADDR;

    // PENGAMAN: Jika game masih di layar judul, intro, atau loading awal, langsung batalkan eksekusi
    if (scene_id < 2) { 
        return; 
    }

    // Baru ambil data stamina dan fatigue saat game aktif
    stamina = RAM_STAMINA_ADDR;
    fatigue = RAM_FATIGUE_ADDR;

    // Tampilkan di pojok kiri atas
    FntPrint(0, "S: %d\n", stamina);
    FntPrint(0, "F: %d\n", fatigue);
}
