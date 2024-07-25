# Kanduril

My configuration for anduril 2 firmware on my D4K single channel

It may not work properly on other flashlights, so I'm describing everything I changed and where I changed it in each drop-down list.

## Changes

<details>
  <summary>Recreate a muggle mode like Anduril 1 (replace simple ui)</summary> 

- Limit the ceiling of simple ui \
set `#define SIMPLE_UI_CEIL` to `40` \
*anduril2/hw/hank/noctigon-dm11/boost/anduril.h*

- Limit the steps of simple ui \
set `#define SIMPLE_UI_STEPS` to `3` \
*anduril2/hw/hank/noctigon-dm11/boost/anduril.h*

- Disable battery check on simple ui \
add `&& cfg.simple_ui_active != 1` as a condition in the else if of `#ifdef USE_BATTCHECK` \
*anduril2/ui/anduril/off-mode.c*

- Disable strobe mode on simple ui \
add `&& cfg.simple_ui_active != 1` as a condition in the else if of `#ifdef USE_STROBE_STATE` \
*anduril2/ui/anduril/off-mode.c*

- Disable boring strobe mode on simple ui \
add `&& cfg.simple_ui_active != 1` as a condition in the else if of `#ifdef USE_BORING_STROBE_STATE` \
*anduril2/ui/anduril/off-mode.c*

- Disable lockout mode on simple ui \
add `&& cfg.simple_ui_active != 1` as a condition in the else if of `#ifdef USE_LOCKOUT_MODE` \
*anduril2/ui/anduril/off-mode.c*

- Disable version check on simple ui \
add `&& cfg.simple_ui_active != 1` as a condition in the else if of `#ifdef USE_VERSION_CHECK` \
*anduril2/ui/anduril/off-mode.c*
</details>

<details>
  <summary>Switch SOS and Beacon mode to make SOS first</summary>

- Change order on battery check state 
  ```
  else if (event == EV_2clicks) {
      #if defined(USE_THERMAL_REGULATION)
      set_state(tempcheck_state, 0);
      #elif defined(USE_SOS_MODE) && defined(USE_SOS_MODE_IN_BLINKY_GROUP)
      set_state(sos_state, 0);
      #elif defined(USE_BEACON_MODE)
      set_state(beacon_state, 0);
      #endif
      return EVENT_HANDLED;
  }
  ```
  *anduril2/ui/anduril/battcheck-mode.c*

- Change order on temperature check state 
  ```
  else if (event == EV_2clicks) {
      #if defined(USE_SOS_MODE) && defined(USE_SOS_MODE_IN_BLINKY_GROUP)
      set_state(sos_state, 0);
      #elif defined(USE_BEACON_MODE)
      set_state(beacon_state, 0);
      #elif defined(USE_BATTCHECK)
      set_state(battcheck_state, 0);
      #endif
      return EVENT_HANDLED;
  }
  ```
  *anduril2/ui/anduril/tempcheck-mode.c*

- Change order on sos mode state 
  ```
  else if (event == EV_2clicks) {
      #if defined(USE_BEACON_MODE)
      set_state(beacon_state, 0);
      #elif defined(USE_BATTCHECK_MODE)
      set_state(battcheck_state, 0);
      #elif defined(USE_THERMAL_REGULATION)
      set_state(tempcheck_state, 0);
      #endif
      return EVENT_HANDLED;
  }
  ```
  *anduril2/ui/anduril/sos-mode.c*

- Change order on beacon mode state 
  ```
  else if (event == EV_2clicks) {
      #if defined(USE_BATTCHECK)
      set_state(battcheck_state, 0);
      #elif defined(USE_THERMAL_REGULATION)
      set_state(tempcheck_state, 0);
      #elif defined(USE_SOS_MODE) && defined(USE_SOS_MODE_IN_BLINKY_GROUP)
      set_state(sos_state, 0);
      #endif
      return EVENT_HANDLED;
  }
  ```
  *anduril2/ui/anduril/beacon-mode.c*
</details>

<details>
  <summary>Set default RGB aux to my preferences</summary>

- Disable the Hank's hardware preset for the aux \
comment `#define RGB_LED_OFF_DEFAULT 0x18` \
*anduril2/hw/hank/anduril.h*

- Set the aux on low cyan when off \
set `#define RGB_LED_OFF_DEFAULT` to `0x13` \
*anduril2/ui/anduril/aux-leds.h*

- Set the aux on low voltage when lock \
set `#define RGB_LED_LOCKOUT_DEFAULT` to `0x19` \
*anduril2/ui/anduril/aux-leds.h*
</details>

<details>
  <summary>Don't ramp after moon by default</summary>

- Deactivate option to ramp after moon \
add `#define DEFAULT_DONT_RAMP_AFTER_MOON 1` \
*anduril2/ui/anduril/config-default.h*
</details>

<details>
  <summary>Set the post off voltage to 1sec by default</summary>

- add `#define DEFAULT_POST_OFF_VOLTAGE_SECONDS 1` \
*anduril2/ui/anduril/config-default.h*
</details>

<details>
  <summary>Set floor to 8 by default to avoid flickering</summary>

- Set 8 for smooth floor \
set `#define RAMP_SMOOTH_FLOOR` to `8` \
*anduril2/hw/hank/noctigon-dm11/boost/anduril.h*

- Set 8 for discrete floor \
set `#define RAMP_DISCRETE_FLOOR` to `8` \
*anduril2/hw/hank/noctigon-dm11/boost/anduril.h*
</details>

<details>
  <summary>Set ramp speed a 1/2 speed</summary>

- Set to 2 for 1/2 \
add `#define DEFAULT_RAMP_SPEED 2` \
*anduril2/ui/anduril/config-default.h*
</details>

<details>
  <summary>Disable moon mode when lock</summary>

- comment `#define USE_MOON_DURING_LOCKOUT_MODE` \
*anduril2/ui/anduril/config-default.h*
</details>

<details>
  <summary>Blink with the red channel instead of main</summary>

- set `#define DEFAULT_BLINK_CHANNEL` to `CM_AUXRED` \
*anduril2/hw/hank/noctigon-dm11/boost/anduril.h*
</details>

<details>
  <summary>Disable the blink in the middle</summary>

- comment `#define BLINK_AT_RAMP_MIDDLE` \
*anduril2/ui/anduril/config-default.h*
</details>

<details>
  <summary>Enable police strobe</summary>

- uncomment `#define USE_POLICE_STROBE_MODE` \
*anduril2/ui/anduril/config-default.h*
</details>

<details>
  <summary>Set 55 for temp limit</summary>

- For sloppy temperature sensor \
set `#define DEFAULT_THERM_CEIL` to `50` \
*anduril2/ui/anduril/config-default.h*

- For accurate temperature sensor \
set `#define DEFAULT_THERM_CEIL` to `55` \
*anduril2/ui/anduril/config-default.h*
</details>

<details>
  <summary>Disable tactical mode</summary>

- Kinda useless mode in my use \
comment `#define USE_TACTICAL_MODE` \
*anduril2/ui/anduril/config-default.h*
</details>

<details>
  <summary>Battery check on 5C instead of momentary</summary>

- Disable momentary \
comment `#define USE_MOMENTARY_MODE` \
*anduril2/ui/anduril/config-default.h*

- Change shortcut to USE_BATTCHECK \
replace `event == EV_3clicks` with `event == EV_5clicks` \
*anduril2/ui/anduril/off-mode.c*
</details>

<details>
  <summary>2C goes to turbo advanced and ceiling simple (like anduril 1)</summary>

- Set the default style for advanced \
uncomment `#define DEFAULT_2C_STYLE` and set it to `1` \
*anduril2/ui/anduril/config-default.h*

- Set the default style for simple \
uncomment `#define DEFAULT_2C_STYLE_SIMPLE` and set it to `0` \
*anduril2/ui/anduril/config-default.h*
</details>

# Anduril Flashlight Firmware + FSM Flashlight UI Toolkit

Anduril is a user interface for flashlights.  It is written with FSM, a UI
toolkit for flashlights.

What is FSM?  The "SM" means "Spaghetti Monster", and the "F" can be any F word
you like, such as "Flashlight" or whatever suits your mood.  FSM also means
"Finite State Machine", which is the type of abstraction used for defining user
interfaces.  It is like a flowchart turned into executable code.


## Using Anduril

Anduril has many features, but the only things a person *really* needs to know
to use it are:

  - Click for on/off
  - Hold to change brightness

For more in-depth use, read its [user manual](docs/anduril-manual.md)
for full details.

If you want to know what changed recently, check the [ChangeLog](ChangeLog.md).

For info about hardware-specific features, like what the channel modes are on
multi-channel lights, browse into the [hw/](hw/) directories to find the
hardware model and any hardware-specific documentation.


## Flashing Firmware

Get the latest updates by flashing new firmware!

A few things are needed to flash firmware:

  - A firmware ".hex" file.  Here's
    [how to find the right .hex file](docs/which-hex-file.md).

  - A flashing adapter.  The type of adapter depends on which MCU chip your
    light uses.  It may be an UPDI 3-pin adapter (attiny1616 and newer) or an
    AVR ISP 6-pin adapter (attiny85, attiny1634).

    **UPDI** typically uses a "pogo pin" adapter, with spring-loaded pins to
    hold against copper pads on the driver circuit.

    **AVR ISP** typically has two parts -- a USB device (like a USBASP), and a
    physical adapter (like a pogo pin adapter or SOIC8 clip).  SOIC8 is the
    least convenient, and is mostly only used on old models with attiny85
    chips.

  - A firmware flashing program.  A few compatible programs include
    `avrdude`, `pymcuprog`, and `ZFlasher`.

  - A computer or phone.  Almost any modern computer or phone should be able to
    do it, as long as you can plug the adapter in and run a flashing program.

One particularly useful guide is at https://anduril.click/ .

More info about installing flashing programs is below, in
[Flashing Programs](#flashing-programs).


## Compiling

The firmware can be deeply customized by modifying it and compiling your own
versions, and this is encouraged.

To compile the firmware, it is strongly recommended that you use a Linux
computer, ideally running Debian or Ubuntu (but almost any distro should work).
Virtual machines work well, such as running WSL inside Windows.  There is also
a Docker container available (TODO: add link(s) here), if that is more
convenient.

### Prerequisites:

- AVR toolchain packages:  
  `sudo apt install gcc-avr avr-libc binutils-avr`

- Other misc packages:  
  `sudo apt install git wget unzip bash`

- Atmel DFPs (Device Family Packs).  A small script is included to
  download and install these for you:  
  `./make dfp`

### Building

Use the `make` script included in this repo.  Run `./make --help` for details
about how to use it.  In most cases though, you should be able to just run
`./make` by itself to compile all available build targets.  Or give it a search
term to limit builds to only a few, like `./make hank boost` to build all
firmwares for Hanklights with optional boost drivers.

The compiled firmware goes into the `hex/` directory, ready to be used by any
firmware flashing program.


## Customizing Settings Per User

The build can be [customized per user](docs/per-user-config.md) by placing
overrides into the `users/myname/` directory and letting the build script know
your username.  That way, your favorite settings can be applied automatically
without having to modify the original source files.


## Flashing Programs

### AVRdude

Usually avrdude installs in a single command:

`sudo apt install avrdude`

### PyMCUprog

If you use `pymcuprog` to flash firmware, a few extras are needed:

```sh
sudo apt install python3 python3-pip python3-venv
python3 -m venv .venv
source .venv/bin/activate
pip install pymcuprog
```

You'll need to `source .venv/bin/activate` every time you start a fresh shell,
if you want to use pymcuprog.  The activation lasts until the shell is
closed or until you run `deactivate`.


## Contributing

If you'd like to help, there are several ways...

  - ToyKeeper has a [Patreon site](https://patreon.com/ToyKeeper) for
    donations, to help figuratively and literally keep the lights on.

  - Send pull requests or patches, to improve things directly.  These can be
    code, documentation, tools, or anything you think is useful.

  - File bug reports for any problems you find.

  - Answer people's questions on public forums.  If the same questions come up
    a lot, consider adding it to the documentation here.

  - Ask manufacturers to use this firmware, and to support its development.


