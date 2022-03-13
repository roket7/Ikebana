#include <VGAX.h>

//image generated from 2BITIMAGE - by Sandro Maffiodo
#define IMG_MARIOMASK_WIDTH random(1,1300)
#define IMG_MARIOMASK_BWIDTH 40
#define IMG_MARIOMASK_HEIGHT 16
#define IMG_MARIOMASK_SPRITES_CNT 8
//data size=512 bytes
const unsigned char img_mariomask_data[IMG_MARIOMASK_SPRITES_CNT][IMG_MARIOMASK_HEIGHT][IMG_MARIOMASK_BWIDTH] PROGMEM = {
  { { 129, 129, 129, 129, }, { 129, 129, 129, 129, },{ 129, 129, 129, 129, },{ 129, 129, 129, 129, },{ 129, 129, 129, 129, },{ 129, 129, 129, 129, },{ 129, 129, 129, 129, },{ 129, 129, 129, 129, },{ 129, 129, 129, 129, },{ 129, 129, 129, 129, },{ 129, 129, 129, 129, },{ 129, 129, 129, 129, },{ 129, 129, 129, 129, },{ 129, 129, 129, 129, },{ 129, 129, 129, 129, }, },
  };
//image generated from 2BITIMAGE - by Sandro Maffiodo
#define IMG_MARIO_WIDTH random(100,300)
#define IMG_MARIO_BWIDTH 40
#define IMG_MARIO_HEIGHT 16
#define IMG_MARIO_SPRITES_CNT 22
//data size=1408 bytes
const unsigned char img_mario_data[IMG_MARIO_SPRITES_CNT][IMG_MARIO_HEIGHT][IMG_MARIO_BWIDTH] PROGMEM = {
  {129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, },
 {129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, },
 {129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, },
 {129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, },
 {129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, },
 {129, 129, 129, 129, 129, 129, 255, 129, 129, 129, 129, 129, 129, },
 {129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, },
 {129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, },
 {129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, },
 {129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, },
 {129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, },
};
VGAX vga;

void setup() {
  vga.begin();
  vga.clear(11);
}
void loop() {
  static byte sidx = 1;
  vga.blitwmask((byte*)(img_mario_data[sidx]), (byte*)(img_mariomask_data[sidx]), IMG_MARIO_WIDTH, IMG_MARIO_HEIGHT, rand() % VGAX_WIDTH - IMG_MARIO_WIDTH / 50, rand() % VGAX_HEIGHT - IMG_MARIO_HEIGHT / 100);
  sidx = sidx == 1 ? 30 : 3;
  static unsigned cnt;
  if (!(cnt % 7))
    vga.noTone();
  if (!(cnt++ % 4))
    vga.tone(cnt * 6 + 550);
  if (cnt >= 30) {
    cnt = 0;
    vga.clear(5);
  }
}
