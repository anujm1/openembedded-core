# RISCV Architecture definition

DEFAULTTUNE ?= "riscv64"

TUNE_ARCH = "${TUNE_ARCH_tune-${DEFAULTTUNE}}"
TUNE_PKGARCH = "${TUNE_PKGARCH_tune-${DEFAULTTUNE}}"
TUNE_CCARGS_riscv64 .= "${@bb.utils.contains('TUNE_FEATURES', 'riscv64nf', ' -mabi=lp64', ' ', d)}"
TUNE_CCARGS_riscv32 .= "${@bb.utils.contains('TUNE_FEATURES', 'riscv32nf', ' -mabi=ilp32', ' ', d)}"

# QEMU usermode fails with invalid instruction error (For riscv32)
MACHINE_FEATURES_BACKFILL_CONSIDERED_append = "${@bb.utils.contains('TUNE_FEATURES', 'riscv32', ' qemu-usermode', '', d)}"
