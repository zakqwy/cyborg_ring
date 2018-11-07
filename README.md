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
This is a fun and challenging project. Building a ring can be frustrating, especially if you aren't used to working with tiny parts, but if you take your time it is eminently possible even if you are fairly new to soldering. Make sure you are comfortable, not overly caffeinated (as shaky hands make it quite tough), and try to avoid interruptions for the next few hours. Remember that you have extra parts, and even if you damage a PCB the replacements are quite cheap (although they may take a week or two to arrive in the mail).
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
This is the most challenging part of the ring construction. The components are all in a delicate state (especially the brittle resistor columns), and the two halves need to be aligned within around 100 microns to ensure the QFN pads all land properly. I demonstrated this step on stage at the 2018 Supercon; [the video](https://www.youtube.com/watch?v=hiBTvdMfvWo) isn't great but hopefully the methodology comes through. I still need to pull together good images showing this part in action, but it's tough to photograph as both hands tend to be busy.

Pick up the bottom ring half (the part with most of the components) with your thumb and forefinger. Place the top ring half over the bottom half, gently squeezing the two PCBs together between your fingers. Adjust your grip so that the two boards are aligned, and ensure that there is some pressure holding them together; any gaps between the components and the PCB will be difficult to fix with solder. As you hold the PCB, notice how much fine control you have over component alignment by sliding your thumb and forefinger relative to each other. Practice getting the QFN pads perfectly in line and holding them that way for a few seconds. Keep an eye on the alignment of the two furthest structural columns; if all three of these joints are in line, the other resistors will fall into place as well.

When you are comfortable with your grip on the PCBs, add a blob of flux to the five unsoldered QFN pads, tin your iron, check alignment one final time, and swipe the iron tip across the pads to flow solder into the joint. Be sure to hold the boards steady during this process; don't let go until the iron has been off the joint for a few seconds, as you must ensure the solder is completely cool or you'll get a cold joint.

As soon as the solder on the QFN joint solidifies, start treating the ring with even greater care. The five pads holding the top PCB are tiny and easily ripped off. Without putting the ring down, add gel flux to the six structural resistor columns, re-tin your iron tip, and touch the six pads in sequence to flow solder into the joints. Now you can put the ring down and inspect your work; the ring is still too delicate to wear (which we will address next), but it shouldn't spontaneously disassemble if left on the workbench until the next morning.
### step six: install reinforcing wires
The major design update between the two hardware revisions to date added eight tension wires. The original ring was incredibly weak in tension or shear, as the resistors would easily lose their solder caps. Think of the columns as un-reinforced concrete: they're pretty decent in compression, but need a bit of help for real-world applications.

Each ring PCB has eight tiny plated holes designed for stripped 30 AWG wire wrap wire. The clearance is tight, so inserting the wire through both holes can be a trial-and-error process. Generally, if you kink or bend the wire in an attempt, you are better off clipping the wire back until you have a fresh straight section to work with. Some of the holes are marked here:
![cyborg ring programming diagram](/img/cyborg_ring_programming_diagram.png)

One at a time, blob flux onto the wire and holes and apply solder as you did with the other components. As you secure each joint, clip the wires flush. If the clipped wire is sharp, dab it with a tinned iron to add a tiny bit of additional solder to round off the joint.

Now you can wear the ring. But you will probably want to install the rest of the components first, as it's quite a bit more interesting to see when the LEDs work.

### step seven: install the LEDs
The LEDs straddle the gap between the 0508 resistors at the top of each ring PCB. This works because the resistors are 1.2 mm wide each, and 0603 LEDs are 1.6 mm wide. 1.2 + 1.6 + 1.2 = 4, and it means the LEDs are nicely centered. However, they are quite delicate and dependent on nominal tolerances, so they don't always fit quite right, and can easily break if you throw an unprotected ring in your backpack for a month (as I did on the broken-but-re-LED-able ring shown on the right here):
![cyborg ring pair](/img/cyborg_ring_pair.jpg)

LED polarity should always be confirmed on the LED datasheet, but in most cases the cathode (negative) terminal of a component can be identified by the black dot visible through the epoxy package. Install the LEDs according to this diagram:
![cyborg ring leds](/img/cyborg_ring_leds.png)

Don't worry if you get all of them backwards. The LEDs are Charlieplexed, so they will still light up but will be in a funky order. You can fix them, or you can fix the code. Just make sure the polarities alternate from one to the next.

Secure the ring upright. To install the LEDs, dab a bit of gel flux on the free pads of the 0508 resistors and the LED terminals. Hold each LED in sequence in its appropriate place and touch your tinned iron to the terminal to flow solder into the joint. This may take a bit of practice and rework, so take your time. Be sure to solder both sides of each LED before you move on to the next.
### step eight: final components
The ring has two components that must be soldered in traditional fashion to the PCBs. The 0402 bypass capacitor should be soldered to the top PCB, while the side-mounted switch should be soldered to the bottom PCB. The switch pads aren't terribly generous, so a good strategy is to tin the pads and switch terminals, deflux the whole ring with isopropyl alcohol (as the switch isn't sealed), and secure the switch by reflowing the pads from above.
### step nine: programming
The ring firmware (/FIRMWARE) runs on an ATtiny85 microcontroller, but can easily work with a -25 or -45 as well (these devices simply have less flash memory, not a problem for our tiny program). If you use an ATtiny25 or ATtiny45, be sure to change the DEVICE line of the Makefile as required.

You can program the ring with any suitable AVR programmer: a USBtinyISP, an Arduino, or one of Atmel's many official devices. Using these specific devices is outside the scope of these instructions; a good starting point is Adafruit's fantastic guide for their USBtinyISP, available [here](https://learn.adafruit.com/usbtinyisp). Connect your programmer of choice to the following pads on the ring:
![cyborg ring programming diagram](/img/cyborg_ring_programming_diagram.png)

The pads are 0.1" spaced so you _can_ build a clever pinchy programmer rig out of perfboard and pogo pins, like this:
![cyborg ring programmer](/img/cyborg_ring_programmer.jpg)

The programming rig works well enough, but it's fussy to get aligned so I usually just tack wires onto the pads. The current firmware zips the LEDs sequentially three times, then puts the microcontroller to sleep. Battery life should be in the 6-8 weeks range and is probably chemistry-limited rather than related to current draw (unless you play with the ring _constantly_)

Optionally, you can now coat the exposed parts of the ring with silicone modified conformal coating. The ring won't be waterproof, but it will be a bit better protected.

![cyborg ring gif](/img/cyborg_ring.gif)
## known builds
Building a cyborg ring and willing to share your process? Send me a link and I'll add it here!

[F0cks' build](https://blog.f0cks.net/projects/Cyborg-ring/), remixed to ring size 6.5-7 in Eagle and used for a proposal!
