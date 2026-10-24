#include "types.h"

// Pointer RAM untuk mendeteksi status scene/loading game
// Alamat 0x800712A8 biasanya melacak ID scene aktif di HMBTN
#define RAM_SCENE_ID_ADDR (*(volatile u8*)0x800712A8)

// Pointer nilai Stamina dan Fatigue bawaan game
#define RAM_STAMINA_ADDR (*(volatile u8*)0x80071A12)
#define RAM_FATIGUE_ADDR (*(volatile u8*)0x80071A13)

// Deklarasi fungsi cetak teks bawaan PS1 SDK
extern void FntPrint(int id, const char *fmt, ...);

void Draw_Custom_Stamina_Fatigue_UI(void) {
    // PENGAMAN: Jika game masih di layar judul, intro, atau loading awal,
    // langsung batalkan eksekusi agar game tidak stuck/freeze!
    u8 scene_id = RAM_SCENE_ID_ADDR;
    if (scene_id < 2) { 
        return; 
    }

    // Ambil data asli dari memori RAM
    u8 stamina = RAM_STAMINA_ADDR;
    u8 fatigue = RAM_FATIGUE_ADDR;

    // Tampilkan di pojok kiri atas
    FntPrint(0, "S: %d\n", stamina);
    FntPrint(0, "F: %d\n", fatigue);
}
