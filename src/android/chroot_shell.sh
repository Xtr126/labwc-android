#!/bin/sh

CHROOT_PATH=""
TARGET_USER=""

usage() {
    echo "Usage: $0 --chroot-path <path> --user <username>"
    echo ""
    echo "  --chroot-path  The path to the chroot directory (replaces \$1)."
    echo "  --user         The target username inside the chroot (replaces \$2)."
    exit 1
}

while [ "$#" -gt 0 ]; do
    case "$1" in
        --chroot-path)
            if [ -n "$2" ] && [ "$2" != "--user" ]; then
                CHROOT_PATH="$2"
                shift 
            else
                echo "Error: --chroot-path requires a value."
                usage
            fi
            ;;
        --user)
            if [ -n "$2" ] && [ "$2" != "--chroot-path" ]; then
                TARGET_USER="$2"
                shift 
            else
                echo "Error: --user requires a value."
                usage
            fi
            ;;
        -h|--help)
            usage
            ;;
        *)
            echo "Unknown parameter passed: $1"
            usage
            ;;
    esac
    shift 
done

if [ -z "$CHROOT_PATH" ] || [ -z "$TARGET_USER" ]; then
    echo "Error: Both --chroot-path and --user are required."
    usage
fi

if [ -z "$XDG_RUNTIME_DIR_IN_CHROOT" ]; then
    echo "Error: XDG_RUNTIME_DIR_IN_CHROOT is empty."
    usage
fi

if [ -z "$XDG_RUNTIME_DIR" ]; then
    echo "Error: XDG_RUNTIME_DIR is empty."
    usage
fi

# Modify permissions for Wayland display socket (if it exists)
if [ -n "$WAYLAND_DISPLAY" ] && [ -e "$XDG_RUNTIME_DIR/$WAYLAND_DISPLAY" ]; then
    chmod 666 "$XDG_RUNTIME_DIR/$WAYLAND_DISPLAY"
fi

# Environment variables for programs inside the chroot
export XDG_RUNTIME_DIR=$XDG_RUNTIME_DIR_IN_CHROOT
unset TMPDIR
unset XKB_CONFIG_ROOT

su -c chroot $CHROOT_PATH su $TARGET_USER
