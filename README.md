# cyborg ring
![cyborg ring with red LEDs](/img/cyborg_ring_red.jpg)
cyborg ring is a cordwood-style bit of blinky jewelry powered by an ATtiny85 and a pair of size 10 Zn-air (hearing aide) batteries. The latest iteration includes several tension wires as well as other minor updates and has proven its durability to be sufficient to warrant a beta release. Note that this ring is difficult to make, still quite delicate, not waterproof (even if you conformal coat most of it), and somewhat uncomfortable. But it's also quite unique.
## license
cyborg ring is released under the terms of the Creative Commons Attribution-ShareAlike 4.0 license, available here: http://creativecommons.org/licenses/by-sa/4.0/.
<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a>

The project recently received certification from the Open Source Hardware Association, US000141.
![OSHWA Certification](/img/oshwa.png)
## project status
![cyborg ring rear view](/img/cyborg_ring_back.jpg)
The ring works and seems to last at least a few weeks without breaking; having said that, the ring is still delicate and should be treated like a beta-release concept still in need of some polishing. By popular demand, I'll probably put together a CrowdSupply campaign for kits that will include good instructions, pre-programmed microcontrollers, and LED color / ring size choice. On the subject of size, this version is nominally equivalent to ring size 9. Practically, it's better as a 7 or 8 as the bare FR4 is a bit rough when worn too tight.
## build instructions
I did a live stream in October 2018 that shows a complete ring build start-to-finish. You can view an unedited recording of the stream [here](https://youtu.be/spNg8LhxJz0). I also made a brief video that just goes over the tools and materials, available [here](https://youtu.be/D9dDy7vboAA). These are both great starting points if you are new to the project.
### step zero: prepare thyself
This is a fun and challenging project. Building a ring can be quite frustrating, especially if you aren't used to working with tiny parts, but if you take your time it is eminently possible even if you are fairly new to soldering. Make sure you are comfortable, not overly caffeinated (as shaky hands make it quite tough), and try to avoid interruptions for the next few hours. Remember that you have extra parts, and even if you damage a PCB the replacements are quite cheap (although they may take a week or two to arrive in the mail).
### step one: source PCBs
Use a service like [OSHpark](https://oshpark.com/shared_projects/sZ3MaKA4) (or any other high-quality PCB vendor) to fabricate the boards. They should be routed with mousebites, 0.8mm (1/32") FR4, ENIG, double-sided. Note that some traces are a bit close to the PCB edge so you may need to try a few services or have your bodge wires handy:
![cyborg ring pcb panel](/img/cyborg_ring_pcb_panel.jpg)

If necessary, _carefully_ sand down the mouse bites after removing excess FR4. Make sure to wear suitable PPE (safety glasses, a dust mask, etc) and clean up when you are finished:
![cyborg ring pcb](/img/cyborg_ring_pcb.jpg)
### step two: source all the parts
I did a short run of kits that were given away at the 2018 Supercon; if you got one, you already have all you need beyond the tools listed:
![parts](/img/parts.jpg)

Otherwise, order the parts listed in bom.csv in the HARDWARE directory. I usually get parts from Digi-Key, but most large electronics distributors should have the parts. Make sure you buy 0508 resistors for the LEDs; they're a bit funky and substantially less common than 0805 devices (which you also need). And don't even _think_ about not ordering sufficient spares of _everything_.
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

Repeat as needed until you have two jumper columns and four structural (10M + 10M) columns.
### step four: solder parts to individual ring halves
Identify the bottom half of the ring. This half has two round pads on the back, along with two rectangular pads for the switch. On the front, the ATtiny85 silkscreen has a tiny circle to indicate the location of Pin 1. It also says "cyborg ring" opposite the LEDs:
![cyborg ring pcb bottom](/img/cyborg_ring_pcb_bottom.jpg)

Start by soldering the QFN ATtiny85 to the PCB. You should carefully mount the board in a vise of some kind, or tape it to a work surface (such as an old bit of wood) so it doesn't move around. Use tweezers to orient the QFN so its ground pad faces the bottom part of the ring, and the outline lines up with the white silkscreen square. Be sure the notch on the ground pad, which indicates pin 1, is down and to the right:
![qfn soldering 1](/img/qfn_soldering_1.jpg)

Squeeze a healthy blob of gel flux onto the joint (not shown). Tin your soldering iron, keep your tweezers steady, confirm alignment one last time, and slide the iron tip across the joint to flow sufficient solder onto the pads. If you form any bridges, clean off the iron and gently dab it on the pads to remove excess solder:
![qfn soldering 2](/img/qfn_soldering_2.jpg)

The resultant joint should be shiny, convex, aligned front-to-back and side-to-side, and as vertical as you can manage. Examine this joint carefully, ideally with a loupe, and redo if necessary to fix problems:
![qfn soldering 3](/img/qfn_soldering_3.jpg)

Next, solder the six resistor columns to the ring. The two jumper columns guard the QFN, while the four structural columns live near the ring's corners (if round things had corners). Follow the same method as you did with the QFN: add a blob of flux, align the column with tweezers, tin your iron, and touch the hot iron tip to the joint to flow a bit of solder onto the pad and component:
![cyborg ring placement 1](/img/cyborg_ring_placement_1.png)

Now solder all 0508 resistors to the appropriate pads on the top and bottom of the ring. Orient the resistors so their top edge is flush with the top of the ring. When you are done, the bottom half should look something like this:
![cyborg ring bottom components](/img/cyborg_ring_bottom_components.jpg)

Solder the battery tabs to the smaller of the round pads on the left side of each half of the ring. Orient the tabs so the battery can be inserted and removed from the bottom of the ring after assembly. Again, add flux to the pad, align and hold the part, and touch the joint with a tinned iron tip to flow sufficient solder into the joint. Note that the tab in this image is an older version; your parts are sturdier but otherwise similar (and your QFN is straighter than the one in this picture):
![cyborg ring battery tab](/img/cyborg_ring_battery_tab.jpg)

### step five: join the two ring halves
This is the most challenging part of the ring construction. The components are all in a delicate state (especially the brittle resistor columns), and the two halves need to be aligned within around 100 microns to ensure the QFN pads all land properly. I demonstrated this step on stage at the 2018 Supercon; [the video](https://www.youtube.com/watch?v=hiBTvdMfvWo) isn't great but hopefully the methodology comes through.

I still need to pull together good images showing this part in action, but it's tough to image as both hands tend to be busy. 

- Head over to the Hackaday.io projects site and navigate to the build project log, available [here](https://hackaday.io/project/34160-cyborg-ring/log/84158-assembly-breakage-next-rev-plans). These instructions aren't comprehensive and don't cover the latest version (different clips, reinforcement wires, etc) but they should give you a general idea of techniques and tools.
- Add the 'undocumented' connections: tack a 30 AWG bare wire to the ATtiny's ground pad and route it to an available ground pad (one of the resistor jumper stacks works for this). Then take eight lengths of this wire and solder it thru-hole-style to the eight tiny holes on each board. Trim the wires and admire the excellent reinforcements you have installed.
![cyborg ring programming diagram](/img/cyborg_ring_programming_diagram.png)
- Program the ATTiny85 (or -45, or -25) using the six pads shown above and a suitable AVR programmer, such as the USBtinyISP from Adafruit. The code in the FIRMWARE directory keeps the microcontroller sleeping until the switch is pressed, at which point the LEDs flash three times.
- If desired, coat all the exposed bits (other than battery terminals and switch) with silicone modified conformal coating. The board won't be waterproof but this will at least help protect stuff a bit.
- Show me your builds, either via the Hackaday site or by tweet (@zakqwy). I'd love to see some cyborg rings in the wild.
![cyborg ring gif](/img/cyborg_ring.gif)
## known builds
- [F0cks' build](https://blog.f0cks.net/projects/Cyborg-ring/), remixed to ring size 6.5-7 in Eagle and used for a proposal!
