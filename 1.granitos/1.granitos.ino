#include <VGAX.h>
#include <math.h>

VGAX vga;

void setup() {
  vga.begin();
}
void loop() {
  static unsigned cnt;
  cnt++;
  vga.putpixel(rand()%VGAX_WIDTH, rand()%VGAX_HEIGHT, cnt%6);
 delay(1500);
  cnt++;
  vga.putpixel(rand()%VGAX_HEIGHT, rand()%VGAX_WIDTH, cnt%2);
   delay(1500); 
   cnt++;
  vga.putpixel(rand()%VGAX_HEIGHT, rand()%VGAX_WIDTH, cnt%10);
   delay(1500);
}
