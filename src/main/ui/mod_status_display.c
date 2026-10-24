#include "types.h"
#include "player.h"  // Mengimpor struktur player asli game
#include "menu_window.h" // Mengimpor fungsi grafis bawaan game jika diperlukan

// Asumsi alamat/variabel global dari decompilation HMBTN:
// Biasanya disimpan di struktur g_farmState.playerStamina atau sejenisnya.
// Jika proyek Anda menggunakan pointer langsung atau variabel eksternal:
extern u16 player_stamina;
extern u16 player_fatigue;

// Fungsi kustom buatan Anda untuk menggambar UI di pojok kiri atas
void Draw_Custom_Stamina_Fatigue_UI(void) {
    
    // 1. Tentukan posisi koordinat layar (Pojok Kiri Atas)
    // X = 15, Y = 15 (Jam bawaan game biasanya di X = 240an, Y = 15)
    s32 screen_x = 15;
    s32 screen_y = 15;
    
    // 2. Format string untuk menampilkan angka Stamina & Fatigue
    // Menggunakan fungsi cetak teks bawaan engine PS1 / decompilation Anda.
    // Contoh di bawah berasumsi engine Anda menggunakan fungsi cetak bawaan seperti FntPrint atau TextDraw
    
    // Menggambar Ikon Hati / Teks Stamina
    // Format output:  100  (Diikuti nilai variabel)
    TextDraw(screen_x, screen_y, "♥ %d", player_stamina);
    
    // Menggambar Ikon Air / Teks Fatigue tepat di bawahnya atau di sebelahnya
    // Geser Y kebawah sedikit (ditambah 12 pixel)
    TextDraw(screen_x, screen_y + 12, "💧 %d", player_fatigue);
}
