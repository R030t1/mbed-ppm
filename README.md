# mbed-ppm
Output PPM for a RC ESC.

## Building
1. Clone into `mbed-ppm/mbed-ppm`.
2. In top directory, `python3 -m venv venv` and `source venv/bin/activate`.
3. Create `mbed-ppm/mount` and mount the board to it, writeable by your user.
4. Enter the inner directory and run 'setup.sh`.
5. Use `mbed config` to set:
	1. TARGET to NUCLEO_L432KC,
	2. TOOLCHAIN to GCC_ARM,
	3. GCC_ARM_PATH to the compiler bindir.
6. `mbed compile [-f]`.
