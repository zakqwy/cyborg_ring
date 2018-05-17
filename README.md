# cyborg ring
![cyborg ring with red LEDs](/cyborg_ring_red.jpg)
cyborg ring is a cordwood-style bit of blinky jewelry powered by an ATtiny85 and a pair of size 10 Zn-air (hearing aide) batteries. The latest iteration includes several tension wires as well as other minor updates and has proven its durability to be sufficient to warrant an alpha release. Note that this ring is difficult to make, still quite delicate, not waterproof (even if you conformal coat most of it), and somewhat uncomfortable. But it's also quite unique.
## license
cyborg ring is released under the terms of the Creative Commons Attribution-ShareAlike 4.0 license, available here: http://creativecommons.org/licenses/by-sa/4.0/.
<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a>
## project status
![cyborg ring rear view](/cyborg_ring_back.jpg)
The ring works and seems to last at least a few weeks without breaking. but at this point, the project is very much in alpha as I have not had time to put together detailed build or programming instructions. By popular demand, I'll probably put together a CrowdSupply campaign for kits that will include good instructions, pre-programmed microcontrollers, and LED color / ring size choice. On the subject of size, this version is nominally equivalent to ring size 9. Practically, it's better as a 7 or 8 as the bare FR4 is a bit rough when worn too tight. 
## build instructions
- Use a service like OSHpark (or any other high-quality PCB vendor) to fabricate the boards. They should be routed, 0.8mm (1/32"), ENIG, double-sided, FR4. Note that some of the traces are a bit close to the PCB edge so you may need to try a few services or have your bodge wires handy. 
- Source all the parts. I get stuff from Digi-Key (buy local!) but most other places should have the parts too. See bom.csv in the HARDWARE directory.
- Head over to the Hackaday.io projects site and navigate to the build project log, available [here](https://hackaday.io/project/34160-cyborg-ring/log/84158-assembly-breakage-next-rev-plans). These instructions aren't comprehensive and don't cover the latest version (different clips, reinforcement wires, etc) but they should give you a general idea of techniques and tools. 
- Add the 'undocumented' connections: tack a 30 AWG bare wire to the ATtiny's ground pad and route it to an available ground pad (one of the resistor jumper stacks works for this). Then take eight lengths of this wire and solder it thru-hole-style to the eight tiny holes on each board. Trim the wires and admire the excellent reinforcements you have installed.
- Program the ATTiny85 (or -45, or -25) using the six pads and a suitable AVR programmer, such as the USBtinyISP from Adafruit. On the side of the ring with the tiny pushbutton switch, the left pad is RESET and the right pad is GND; on the side opposite the switch, the pads are (left to right) VCC, SCK, MISO, and MOSI.The code in the FIRMWARE directory keeps the microcontroller sleeping until the switch is pressed, at which point the LEDs flash three times. 
- If desired, coat all the exposed bits (other than battery terminals and switch) with silicone modified conformal coating. The board won't be waterproof but this will at least help protect stuff a bit.
- Show me your builds, either via the Hackaday site or by tweet (@zakqwy). I'd love to see some cyborg rings in the wild.  

![cyborg ring gif](/cyborg_ring.gif)
