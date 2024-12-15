# Cluster-IPS

![Cluster-IPS](https://raw.githubusercontent.com/gargum/Cluster-IPS/refs/heads/main/Cluster-IPS_Photos/Cluster-IPS_1.jpg)

The `Cluster-IPS` is a power supply and debug probe designed to make cluster computing easier.
Each unit allows a single USB-C cable to provide power to a maximum of four single board computers.

Each unit uses two RP2040 microcontrollers, allowing one machine to probe up to 12 nodes simultaneously.
This is possible because each MCU can support up to two hardware serial connections and four PIO serial connections.

![Cluster-IPS](https://raw.githubusercontent.com/gargum/Cluster-IPS/refs/heads/main/Cluster-IPS_Photos/Cluster-IPS_2.jpg)

The `Cluster-IPS` uses one TP4056 to power two RP2040 microcontrollers alongside two DRV8833 stepper motor drivers.
The RP2040 microcontrollers drive the DRV8833 units, with each DRV8833 providing power to two TP4056 units for a total of four.

![Cluster-IPS](https://raw.githubusercontent.com/gargum/Cluster-IPS/refs/heads/main/Cluster-IPS_Photos/Cluster-IPS_3.jpg)

By connecting batteries to every TP4056 unit, each TP4056 driven by a DRV8833 can power SBCs like the Raspberry Pi.
In testing, one `Cluster-IPS` can power two Orange Pi Zero 3 units with 4GB of RAM for more than one week without additional power.

![Cluster-IPS](https://raw.githubusercontent.com/gargum/Cluster-IPS/refs/heads/main/Cluster-IPS_Photos/Cluster-IPS_4.jpg)

The firmware running on the pair of RP2040 microcontrollers is actually QMK.
This choice was made because the Picoprobe source code can be added easily, and because this allows users to more easily add buttons and screens should they so desire.

* Maintainer: [Gareth Gummow](https://github.com/gargum)
* Hardware: TP4056 x 5, RP2040 MCU x 2, DRV8833 x 2, Rechargeable battery x 5
* Firmware: QMK, included firmware folder must be added to your local `qmk_firmware/keyboards/` directory before flashing

Make example for this machine (after setting up your QMK build environment):

    make cluster_ips:default

Flashing example for this machine:

    make cluster_ips:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 2 ways:

* **Physical reset button**: Briefly press the button on the top of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
