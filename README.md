# cyborg ring
![cyborg ring with red LEDs](/img/cyborg_ring_red.jpg)
cyborg ring is a cordwood-style bit of blinky jewelry powered by an ATtiny85 and a pair of size 10 Zn-air (hearing aide) batteries. The latest iteration includes several tension wires as well as other minor updates and has proven its durability to be sufficient to warrant an alpha release. Note that this ring is difficult to make, still quite delicate, not waterproof (even if you conformal coat most of it), and somewhat uncomfortable. But it's also quite unique.
## license
cyborg ring is released under the terms of the Creative Commons Attribution-ShareAlike 4.0 license, available here: http://creativecommons.org/licenses/by-sa/4.0/.
<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a>

The project recently received certification from the Open Source Hardware Association, US000141.
![OSHWA Certification](/img/oshwa.png)
## project status
![cyborg ring rear view](/img/cyborg_ring_back.jpg)
The ring works and seems to last at least a few weeks without breaking. but at this point, the project is very much in alpha as I have not had time to put together detailed build or programming instructions. By popular demand, I'll probably put together a CrowdSupply campaign for kits that will include good instructions, pre-programmed microcontrollers, and LED color / ring size choice. On the subject of size, this version is nominally equivalent to ring size 9. Practically, it's better as a 7 or 8 as the bare FR4 is a bit rough when worn too tight. 
## build instructions
I did a live stream in October 2018 that shows a complete ring build start-to-finish. You can view a recording of the stream [here](https://youtu.be/spNg8LhxJz0). I also made a brief video that just goes over the tools and materials, available [here](https://youtu.be/D9dDy7vboAA).
### step one: source PCBs
Use a service like [OSHpark](https://oshpark.com/shared_projects/sZ3MaKA4) (or any other high-quality PCB vendor) to fabricate the boards. They should be routed with mousebites, 0.8mm (1/32") FR4, ENIG, double-sided. Note that some traces are a bit close to the PCB edge so you may need to try a few services or have your bodge wires handy:
![cyborg ring pcb panel](/img/cyborg_ring_pcb_panel.jpg)
If necessary, _carefully_ sand down the mouse bites after removing excess FR4. Make sure to wear suitable PPE (safety glasses, a dust mask, etc) and clean up when you are finished:
![cyborg ring pcb](/img/cyborg_ring_pcb.jpg)
### step two: source all the parts
I did a short run of kits that were given away at the 2018 Supercon; if you did this, you already have all you need beyond the tools listed.. Otherwise, order the parts listed in bom.csv in the HARDWARE directory. I usually get parts from Digi-Key, but most large electronics distributors should have the parts. Make sure you buy 0508 resistors for the LEDs; they're a bit funky and substantially less common than 0805 devices (which you also need). And don't even _think_ about not ordering sufficient spares of _everything_.
### step three: assemble the resistor columns
You need six columns altogether. Four should be constructed from a pair of 10M 0805 resistors, marked '106', to give a total resistance of 20M. Two should be constructed from a pair of 0805 jumpers, marked '0'. To fabricate the columns, position the two resistors next to each other on a heat-resistant surface (such as a Teflon-jawed Stickvise):
![resistor column 1](/img/resistor_column_1.jpg)
Squeeze the two resistors together with a pair of tweezers. Make sure they are square to each other and don't squeeze so hard the resistors buckle up in the center; the column should be flat but firmly held:
![resistor column 2](/img/resistor_column_2.jpg)
Apply a bit of gel flux to the junction:
![resistor column 3](/img/resistor_column_3.jpg)
Touch your tinned soldering iron to the junction, allowing a bit of solder to flow around the joint:
![resistor column 4](/img/resistor_column_4.jpg)
The finished product should be straight and square, as seen here:
![resistor column 5](/img/resistor_column_5.jpg)
### step three: secure the ATtiny85 to one of the ring halves

- Head over to the Hackaday.io projects site and navigate to the build project log, available [here](https://hackaday.io/project/34160-cyborg-ring/log/84158-assembly-breakage-next-rev-plans). These instructions aren't comprehensive and don't cover the latest version (different clips, reinforcement wires, etc) but they should give you a general idea of techniques and tools. 
- Add the 'undocumented' connections: tack a 30 AWG bare wire to the ATtiny's ground pad and route it to an available ground pad (one of the resistor jumper stacks works for this). Then take eight lengths of this wire and solder it thru-hole-style to the eight tiny holes on each board. Trim the wires and admire the excellent reinforcements you have installed.
![cyborg ring programming diagram](/img/cyborg_ring_programming_diagram.png)
- Program the ATTiny85 (or -45, or -25) using the six pads shown above and a suitable AVR programmer, such as the USBtinyISP from Adafruit. The code in the FIRMWARE directory keeps the microcontroller sleeping until the switch is pressed, at which point the LEDs flash three times. 
- If desired, coat all the exposed bits (other than battery terminals and switch) with silicone modified conformal coating. The board won't be waterproof but this will at least help protect stuff a bit.
- Show me your builds, either via the Hackaday site or by tweet (@zakqwy). I'd love to see some cyborg rings in the wild.
![cyborg ring gif](/img/cyborg_ring.gif)
## known builds
- [F0cks' build](https://blog.f0cks.net/projects/Cyborg-ring/), remixed to ring size 6.5-7 in Eagle and used for a proposal!
